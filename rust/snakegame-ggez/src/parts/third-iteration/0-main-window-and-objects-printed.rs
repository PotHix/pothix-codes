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
        self.snake.update(&self.fruit)?;
        Ok(())
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

enum SnakeState {
    SelfCollision,
    AteFruit,
}

struct Snake {
    head: Position,
    direction: Direction,
    state: Option<SnakeState>,
}

impl Snake {
    pub fn new(x: i16, y: i16) -> Self {
        let direction = Direction::Right;

        Self {
            direction,
            head: Position::new(x, y),
            state: None,
        }
    }

    fn update(&mut self, fruit: &Fruit) -> GameResult<()> {
        let new_head = Position::new_by_direction(self.head.x, self.head.y, self.direction);
        self.head = new_head;

        if self.head == fruit.pos {
            self.state = Some(SnakeState::AteFruit)
        } else {
            self.state = None;
        }

        Ok(())
    }

    // draws the snake
    fn draw(&self, ctx: &mut Context) -> GameResult<()> {
        // this is the Rect we are going to print. The params are:
        // x position
        // y position
        // x size
        // y size
        let rect = graphics::Rect::new_i32(
            (self.head.x).into(),
            (self.head.y).into(),
            (PIXEL_SIZE.0 - 1).into(),
            (PIXEL_SIZE.1 - 1).into(),
        );

        graphics::set_color(ctx, GREEN.into())?;
        graphics::rectangle(ctx, graphics::DrawMode::Fill, rect)?;

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

    // draws the fruit, it's the same as the snake
    fn draw(&self, ctx: &mut Context) -> GameResult<()> {
        let rect = graphics::Rect::new_i32(
            (self.pos.x).into(),
            (self.pos.y).into(),
            (PIXEL_SIZE.0 - 1).into(),
            (PIXEL_SIZE.1 - 1).into(),
        );

        graphics::set_color(ctx, RED.into())?;
        graphics::rectangle(ctx, graphics::DrawMode::Fill, rect)?;

        Ok(())
    }
}

#[derive(PartialEq)]
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
    pub fn new_by_direction(x: i16, y: i16, direction: Direction) -> Self {
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
