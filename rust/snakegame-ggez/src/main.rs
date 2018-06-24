extern crate ggez;

use std::collections::LinkedList;

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

struct Game {
    snake: Snake,
    fruit: Fruit,
}

impl Game {
    pub fn new() -> Self {
        Game {
            snake: Snake::new(SNAKE_INIT_POS.into()),
            fruit: Fruit::new(),
        }
    }
}

impl ggez::event::EventHandler for Game {
    fn update(&mut self, ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        const DESIRED_FPS: i8 = 10;

        while ggez::timer::check_update_time(ctx, DESIRED_FPS as u32) {
            self.snake.update();
            self.fruit.update();
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
            let result = ctx.quit();
            match result {
                Err(e) => println!("Cannot leave the game right now: {}", e),
                Ok(_) => (),
            }
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

#[derive(Clone, Copy, Debug)]
struct Position {
    x: i16,
    y: i16,
}

impl Position {
    pub fn new(x: i16, y: i16) -> Self {
        Self { x, y }
    }

    pub fn random(max_x: i16, max_y: i16) -> Self {
        Self { x: max_x, y: max_y }
    }

    pub fn new_by_direction(pos: Position, direction: Direction) -> Self {
        match direction {
            Direction::Up => Position::new(pos.x, pos.y - 1),
            Direction::Down => Position::new(pos.x, pos.y + 1),
            Direction::Left => Position::new(pos.x - 1, pos.y),
            Direction::Right => Position::new(pos.x + 1, pos.y),
        }
    }
}

impl From<(i16, i16)> for Position {
    fn from(pos: (i16, i16)) -> Self {
        Self { x: pos.0, y: pos.1 }
    }
}

impl From<Position> for ggez::graphics::Rect {
    fn from(pos: Position) -> Self {
        ggez::graphics::Rect::new_i32(
            pos.x as i32 * PIXEL_SIZE.0 as i32,
            pos.y as i32 * PIXEL_SIZE.1 as i32,
            PIXEL_SIZE.0 as i32,
            PIXEL_SIZE.1 as i32,
        )
    }
}

impl<'a> From<&'a Position> for ggez::graphics::Rect {
    fn from(pos: &'a Position) -> Self {
        ggez::graphics::Rect::new_i32(
            pos.x as i32 * PIXEL_SIZE.0 as i32,
            pos.y as i32 * PIXEL_SIZE.1 as i32,
            PIXEL_SIZE.0 as i32,
            PIXEL_SIZE.1 as i32,
        )
    }
}

struct Snake {
    head: Position,
    body: LinkedList<Position>,
    direction: Direction,
}

impl Snake {
    pub fn new(pos: Position) -> Self {
        let mut body = LinkedList::new();
        body.push_front(Position {
            x: pos.x - 1,
            y: pos.y,
        });

        Self {
            head: pos,
            body: body,
            direction: Direction::Right,
        }
    }

    fn update(&mut self) {
        let new_head = Position::new_by_direction(self.head, self.direction);
        self.body.push_front(self.head);
        self.head = new_head;

        self.body.pop_back();
    }

    fn draw(&self, ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        for pos in self.body.iter() {
            ggez::graphics::set_color(ctx, GREEN.into())?;
            ggez::graphics::rectangle(ctx, ggez::graphics::DrawMode::Fill, pos.into())?;
        }

        ggez::graphics::set_color(ctx, GREEN.into())?;
        ggez::graphics::rectangle(ctx, ggez::graphics::DrawMode::Fill, self.head.into())?;

        Ok(())
    }
}

struct Fruit {
    pos: Position,
}

impl Fruit {
    pub fn new() -> Self {
        Self {
            pos: Position::new(FRUIT_INIT_POS.0, FRUIT_INIT_POS.1),
        }
    }

    fn update(&mut self) {}

    fn draw(&self, ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        ggez::graphics::set_color(ctx, RED.into())?;
        ggez::graphics::rectangle(ctx, ggez::graphics::DrawMode::Fill, self.pos.into())?;

        Ok(())
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
