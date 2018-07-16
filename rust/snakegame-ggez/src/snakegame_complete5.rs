extern crate ggez;
extern crate rand;

use rand::Rng;

// speed of the snake
const DEFAULT_ACCEL: i16 = 1;

// number of frames per second
const DEFAULT_FPS: i8 = 8;

// initial position for the snake
const SNAKE_INIT_POS: (i16, i16) = (5, 5);

// initial position for the fruit
const FRUIT_INIT_POS: (i16, i16) = (10, 10);

// size of each pixel for the snake and fruit
const PIXEL_SIZE: (i16, i16) = (20, 20);

// size of the window, measured using the above pixels
const SIZE_IN_PIXELS: (i16, i16) = (20, 20);

// the screen size using common pixels
// it will be used to tell ggez to create the window
const SCREEN_SIZE: (u32, u32) = (
    (PIXEL_SIZE.0 * SIZE_IN_PIXELS.0) as u32,
    (PIXEL_SIZE.1 * SIZE_IN_PIXELS.1) as u32,
);

// color constants
// it will be used to avoid magic numbers throughout the code
const GREEN: [f32; 4] = [0.0, 1.0, 0.0, 1.0];
const RED: [f32; 4] = [1.0, 0.0, 0.0, 1.0];

use ggez::{event, graphics, timer, Context, ContextBuilder, GameResult};

// All members are here
struct Game {
    snake: Snake,
    fruit: Fruit,
}

// And here is the implementation for them
//
// The good part of it is that you know all members at once without
// having to skim the whole code
impl Game {
    pub fn new() -> Self {
        Self {
            snake: Snake::new(SNAKE_INIT_POS.0, SNAKE_INIT_POS.1),
            fruit: Fruit::new(FRUIT_INIT_POS.0, FRUIT_INIT_POS.1),
        }
    }

    // just quit the game
    pub fn gameover(ctx: &mut Context) {
        if let Err(e) = ctx.quit() {
            println!("Could not exit the game 😬: {}", e);
        }
    }
}

// implements the game loop for our Game object
impl event::EventHandler for Game {
    fn draw(&mut self, ctx: &mut Context) -> GameResult<()> {
        ggez::graphics::clear(ctx);

        self.fruit.draw(ctx)?;
        self.snake.draw(ctx)?;

        ggez::graphics::present(ctx);

        Ok(())
    }

    fn update(&mut self, ctx: &mut Context) -> GameResult<()> {
        while timer::check_update_time(ctx, DEFAULT_FPS as u32) {
            self.snake.update(&self.fruit)?;

            match self.snake.state {
                Some(SnakeState::AteFruit) => self.fruit.regenerate(),
                Some(SnakeState::SelfCollision) => self.snake.reset(),
                None => (),
            }
        }
        Ok(())
    }

    fn key_down_event(
        &mut self,
        ctx: &mut Context,
        keycode: event::Keycode,
        _keymod: event::Mod,
        _repeat: bool,
    ) {
        if keycode == event::Keycode::Escape {
            Self::gameover(ctx);
        }

        if let Some(direction) = Direction::from_keycode(keycode) {
            self.snake.direction = direction;
        }
    }
}

// we should be able to copy and clone this enum
#[derive(Copy, Clone)]
enum Direction {
    Up,
    Down,
    Left,
    Right,
}

impl Direction {
    pub fn from_keycode(key: event::Keycode) -> Option<Self> {
        match key {
            event::Keycode::Up => Some(Direction::Up),
            event::Keycode::Down => Some(Direction::Down),
            event::Keycode::Left => Some(Direction::Left),
            event::Keycode::Right => Some(Direction::Right),
            _ => None,
        }
    }
}

enum SnakeState {
    SelfCollision,
    AteFruit,
}

struct Snake {
    head: Position,
    body: Vec<Position>,
    direction: Direction,
    state: Option<SnakeState>,
}

impl Snake {
    pub fn new(x: i16, y: i16) -> Self {
        let direction = Direction::Right;
        let mut body = Vec::<Position>::new();
        body.push(Position::new_by_direction(x, y, direction, true));

        Self {
            body,
            direction,
            state: None,
            head: Position::new(x, y),
        }
    }

    fn reset(&mut self) {
        self.body = vec![Position::new_by_direction(
            self.head.x,
            self.head.y,
            self.direction,
            true,
        )];
    }

    fn self_collision(&self) -> bool {
        for segment in &self.body {
            if self.head == *segment {
                return true;
            }
        }

        false
    }

    fn update(&mut self, fruit: &Fruit) -> GameResult<()> {
        let new_head = Position::new_by_direction(self.head.x, self.head.y, self.direction, false);
        self.body.insert(0, self.head);
        self.head = new_head;

        if self.head == fruit.pos {
            self.state = Some(SnakeState::AteFruit)
        } else if self.self_collision() {
            self.state = Some(SnakeState::SelfCollision)
        } else {
            self.state = None;
            self.body.pop();
        }

        Ok(())
    }

    // draws the snake
    fn draw(&self, ctx: &mut Context) -> GameResult<()> {
        graphics::set_color(ctx, GREEN.into())?;
        graphics::rectangle(ctx, graphics::DrawMode::Fill, self.head.into())?;

        for segment in &self.body {
            graphics::rectangle(ctx, graphics::DrawMode::Fill, segment.clone().into())?;
        }

        Ok(())
    }
}

struct Fruit {
    pos: Position,
}

impl Fruit {
    pub fn new(x: i16, y: i16) -> Self {
        Self {
            pos: Position::new(x, y),
        }
    }

    fn regenerate(&mut self) {
        let mut rng = rand::thread_rng();

        let rand_x = rng.gen_range(0, SIZE_IN_PIXELS.0);
        let rand_y = rng.gen_range(0, SIZE_IN_PIXELS.1);

        let x = rand_x as i16;
        let y = rand_y as i16;

        self.pos = Position::new(x, y);
    }

    // draws the fruit, it's the same as the snake
    fn draw(&self, ctx: &mut Context) -> GameResult<()> {
        graphics::set_color(ctx, RED.into())?;
        graphics::rectangle(ctx, graphics::DrawMode::Fill, self.pos.into())?;

        Ok(())
    }
}

impl From<Position> for graphics::Rect {
    fn from(pos: Position) -> Self {
        graphics::Rect::new_i32(
            (pos.x * PIXEL_SIZE.0).into(),
            (pos.y * PIXEL_SIZE.1).into(),
            (PIXEL_SIZE.0 - 1).into(),
            (PIXEL_SIZE.1 - 1).into(),
        )
    }
}

#[derive(Copy, Clone, PartialEq)]
struct Position {
    x: i16,
    y: i16,
}

impl Position {
    pub fn new(x: i16, y: i16) -> Self {
        Self { x, y }
    }

    // we should be able to add a new segment based on the direction
    // e.g. if it's going right, we should add a new segment on the left
    pub fn new_by_direction(x: i16, y: i16, direction: Direction, reverse: bool) -> Self {
        let mut accel = DEFAULT_ACCEL;
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
            x = SIZE_IN_PIXELS.0 - 1;
        } else if x > SIZE_IN_PIXELS.0 - 1 {
            x = 0;
        }

        if y < 0 {
            y = SIZE_IN_PIXELS.1 - 1;
        } else if y > SIZE_IN_PIXELS.1 - 1 {
            y = 0;
        }

        Self { x, y }
    }
}

fn main() {
    let ctx = &mut ContextBuilder::new("snakegame", "Rust TDC")
        .window_setup(ggez::conf::WindowSetup::default().title("Jogo fantastico do TDC"))
        .window_mode(ggez::conf::WindowMode::default().dimensions(SCREEN_SIZE.0, SCREEN_SIZE.1))
        .build()
        .expect("Failed to build ggez context builder");

    ggez::graphics::set_background_color(ctx, (0, 0, 0).into());

    let game = &mut Game::new();

    match event::run(ctx, game) {
        Err(e) => println!("Ouch! Error raised: {}", e),
        Ok(_) => println!("Thanks for playing!"),
    }
}
