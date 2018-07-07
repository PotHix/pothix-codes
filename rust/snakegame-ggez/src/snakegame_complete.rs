extern crate ggez;
extern crate rand;

use rand::Rng; // For the result of thread_rng()

const SNAKE_INIT_POS: (i16, i16) = (5, 5);
const FRUIT_INIT_POS: (i16, i16) = (10, 10);

const SIZE_IN_PIXEL: (i16, i16) = (20, 20);
const PIXEL_SIZE: (i16, i16) = (20, 20);

const SCREEN_SIZE: (i16, i16) = (
    SIZE_IN_PIXEL.0 * PIXEL_SIZE.0,
    SIZE_IN_PIXEL.1 * PIXEL_SIZE.1,
);

const GREEN: [f32; 4] = [0.0, 1.0, 0.0, 1.0];
const RED: [f32; 4] = [1.0, 0.0, 0.0, 1.0];

const DESIRED_FPS: u32 = 8;

struct Game {
    snake: Snake,
    fruit: Fruit,
}

impl Game {
    pub fn new() -> Self {
        Game {
            snake: Snake::new(SNAKE_INIT_POS.into()),
            fruit: Fruit::new(FRUIT_INIT_POS.into()),
        }
    }

    fn gameover(ctx: &mut ggez::Context) {
        if let Err(e) = ctx.quit() {
            println!("Cannot leave the game right now: {}", e);
        }
    }
}

impl ggez::event::EventHandler for Game {
    fn update(&mut self, ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        while ggez::timer::check_update_time(ctx, DESIRED_FPS) {
            self.snake.update(&self.fruit);
            self.fruit.update();

            match self.snake.state {
                SnakeState::SelfCollision => self.snake.reset(),
                SnakeState::AteFruit => self.fruit.regenerate(),
                SnakeState::Moving => (),
            }
        }

        Ok(())
    }

    fn draw(&mut self, ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        ggez::graphics::clear(ctx);

        self.fruit.draw(ctx)?;
        self.snake.draw(ctx)?;

        ggez::graphics::present(ctx);
        Ok(())
    }

    fn key_down_event(
        &mut self,
        ctx: &mut ggez::Context,
        keycode: ggez::event::Keycode,
        _keymod: ggez::event::Mod,
        _repeat: bool,
    ) {
        if keycode == ggez::event::Keycode::Escape {
            Self::gameover(ctx);
        }

        if let Some(direction) = Direction::from_keycode(keycode) {
            self.snake.direction = direction;
        }
    }
}

#[derive(Clone, Copy, Debug)]
enum Direction {
    Up,
    Down,
    Left,
    Right,
}

impl Direction {
    pub fn from_keycode(key: ggez::event::Keycode) -> Option<Direction> {
        match key {
            ggez::event::Keycode::Up => Some(Direction::Up),
            ggez::event::Keycode::Down => Some(Direction::Down),
            ggez::event::Keycode::Left => Some(Direction::Left),
            ggez::event::Keycode::Right => Some(Direction::Right),
            _ => None,
        }
    }
}

#[derive(Clone, Copy, Debug, PartialEq)]
struct Position {
    x: i16,
    y: i16,
}

impl Position {
    pub fn new(x: i16, y: i16) -> Self {
        Self { x, y }
    }

    pub fn random(max_x: i16, max_y: i16) -> Self {
        let mut rng = rand::thread_rng();

        let rand_x = rng.gen_range(0, max_x as u32);
        let rand_y = rng.gen_range(0, max_y as u32);

        Self {
            x: rand_x as i16,
            y: rand_y as i16,
        }
    }

    pub fn new_by_direction(x: i16, y: i16, direction: Direction, reverse: bool) -> Self {
        let mut accel = 1;
        if reverse {
            accel *= -1;
        }

        let (mut x, mut y) = match direction {
            Direction::Up => (x, y - accel),
            Direction::Down => (x, y + accel),
            Direction::Left => (x - accel, y),
            Direction::Right => (x + accel, y),
        };

        if x < 0 {
            x = SIZE_IN_PIXEL.0 - 1;
        } else if x >= SIZE_IN_PIXEL.0 {
            x = 0;
        }

        if y >= SIZE_IN_PIXEL.1 {
            y = 0;
        } else if y < 0 {
            y = SIZE_IN_PIXEL.1 - 1;
        }

        Position::new(x, y)
    }
}

impl From<(i16, i16)> for Position {
    fn from(pos: (i16, i16)) -> Self {
        Self { x: pos.0, y: pos.1 }
    }
}

impl<'a> From<&'a Position> for ggez::graphics::Rect {
    fn from(pos: &'a Position) -> Self {
        ggez::graphics::Rect::new_i32(
            i32::from(pos.x) * i32::from(PIXEL_SIZE.0),
            i32::from(pos.y) * i32::from(PIXEL_SIZE.1),
            i32::from(PIXEL_SIZE.0),
            i32::from(PIXEL_SIZE.1),
        )
    }
}

enum SnakeState {
    Moving,
    SelfCollision,
    AteFruit,
}

struct Snake {
    head: Position,
    body: Vec<Position>,
    state: SnakeState,
    direction: Direction,
}

impl Snake {
    pub fn new(pos: Position) -> Self {
        let direction = Direction::Right;
        let mut body = Vec::<Position>::new();
        body.push(Position::new_by_direction(pos.x, pos.y, direction, true));

        Self {
            body,
            direction,
            head: pos,
            state: SnakeState::Moving,
        }
    }

    fn reset(&mut self) {
        let mut new_body = Vec::<Position>::new();
        new_body.push(Position::new_by_direction(
            self.head.x,
            self.head.y,
            self.direction,
            true,
        ));
        self.body = new_body;
    }

    fn self_collision(&self) -> bool {
        for segment in &self.body {
            if self.head == *segment {
                return true;
            }
        }

        false
    }

    fn update(&mut self, fruit: &Fruit) {
        let new_head = Position::new_by_direction(self.head.x, self.head.y, self.direction, false);
        self.body.insert(0, self.head);
        self.head = new_head;

        // check collision
        if self.head == fruit.pos {
            self.state = SnakeState::AteFruit;
        } else if self.self_collision() {
            self.state = SnakeState::SelfCollision;
            self.body.pop();
        } else {
            self.state = SnakeState::Moving;
            self.body.pop();
        }
    }

    fn draw(&self, ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        for pos in &self.body {
            ggez::graphics::set_color(ctx, GREEN.into())?;
            ggez::graphics::rectangle(ctx, ggez::graphics::DrawMode::Fill, pos.into())?;
        }

        ggez::graphics::set_color(ctx, GREEN.into())?;
        ggez::graphics::rectangle(ctx, ggez::graphics::DrawMode::Fill, (&self.head).into())?;

        Ok(())
    }
}

struct Fruit {
    pos: Position,
}

impl Fruit {
    pub fn new(pos: Position) -> Self {
        Self { pos }
    }

    fn update(&self) {}

    fn draw(&self, ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        ggez::graphics::set_color(ctx, RED.into())?;
        ggez::graphics::rectangle(ctx, ggez::graphics::DrawMode::Fill, (&self.pos).into())?;

        Ok(())
    }

    fn regenerate(&mut self) {
        self.pos = Position::random(SIZE_IN_PIXEL.0, SIZE_IN_PIXEL.1);
    }
}

fn main() {
    let ctx = &mut ggez::ContextBuilder::new("snakegame", "PotHix")
        .window_setup(ggez::conf::WindowSetup::default().title("Rust snake game"))
        .window_mode(
            ggez::conf::WindowMode::default()
                .dimensions(SCREEN_SIZE.0 as u32, SCREEN_SIZE.1 as u32),
        )
        .build()
        .expect("Could not build ggez context");

    ggez::graphics::set_background_color(ctx, (0, 0, 0).into());

    let game = &mut Game::new();

    match ggez::event::run(ctx, game) {
        Err(e) => println!("x.x error raised: {}", e),
        Ok(_) => println!("Thanks for playing!"),
    }
}

// implementation steps:
//
// 1. extern ggez
// 2. create the struct and implement ::new for it returning the initialized struct
// 3. implement the EventHandler for the Game. Implementing `update` and `draw`
// 4. prepare the window in main and run event::run for the game
// 5. create the snake struct and implement new
// 6. initialize snake on the game new
// 7. implement ctx.quit() for the event handler
// 8. implement Direction
// 9. use direction to add a new head (following that direction) and pop one piece of the body
//10. implement FPS
//11. implement the basics of a fruit to be able to print (update and draw)
//12. implement the logic to deal with the screen boundaries
//13. increase the player size when he gets a fruit
//14. regenerate the fruit when the snake eats it
//15. implement a reset for the snake instead of a gameover
