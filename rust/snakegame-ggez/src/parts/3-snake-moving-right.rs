extern crate ggez;

const SNAKE_INIT_POS: (i16, i16) = (5, 5);

const PIXEL_SIZE: (i16, i16) = (20, 20);
const SIZE_IN_PIXELS: (i16, i16) = (20, 20);

const SCREEN_SIZE: (u32, u32) = (
    (PIXEL_SIZE.0 * SIZE_IN_PIXELS.0) as u32,
    (PIXEL_SIZE.1 * SIZE_IN_PIXELS.1) as u32,
);

const DEFAULT_FPS: u32 = 8;

const GREEN: [f32; 4] = [0.0, 1.0, 0.0, 1.0];

const DEFAULT_ACCEL: i16 = 1;

use ggez::{event, timer, Context, ContextBuilder, GameResult};

// All members are here
struct Game {
    snake: Snake,
}

// And here is the implementation for them
//
// The good part of it is that you know all members at once without
// having to skim the whole code
impl Game {
    pub fn new() -> Self {
        Self {
            snake: Snake::new(SNAKE_INIT_POS.0, SNAKE_INIT_POS.1),
        }
    }
}

impl event::EventHandler for Game {
    fn update(&mut self, ctx: &mut Context) -> GameResult<()> {
        while timer::check_update_time(ctx, DEFAULT_FPS) {
            self.snake.update()?;
        }

        Ok(())
    }

    fn draw(&mut self, ctx: &mut Context) -> GameResult<()> {
        ggez::graphics::clear(ctx);

        self.snake.draw(ctx)?;

        ggez::graphics::present(ctx);

        Ok(())
    }
}

impl<'a> From<&'a Position> for ggez::graphics::Rect {
    fn from(pos: &'a Position) -> Self {
        ggez::graphics::Rect::new(
            pos.x.into(),
            pos.y.into(),
            SIZE_IN_PIXELS.0.into(),
            SIZE_IN_PIXELS.1.into(),
        )
    }
}

#[derive(Copy, Clone)]
enum Direction {
    Up,
    Down,
    Right,
    Left,
}

struct Snake {
    head: Position,
    direction: Direction,
}

impl Snake {
    pub fn new(x: i16, y: i16) -> Self {
        Self {
            head: Position::new(x, y),
            direction: Direction::Right,
        }
    }

    fn update(&mut self) -> GameResult<()> {
        let new_head = Position::new_by_direction(self.head.x, self.head.y, self.direction, false);
        self.head = new_head;

        Ok(())
    }

    fn draw(&self, ctx: &mut Context) -> GameResult<()> {
        ggez::graphics::set_color(ctx, GREEN.into())?;
        //ggez::graphics::rectangle(ctx, ggez::graphics::DrawMode::Fill, (&self.head).into())
        ggez::graphics::rectangle(
            ctx,
            ggez::graphics::DrawMode::Fill,
            ggez::graphics::Rect::new(
                (self.head.x * PIXEL_SIZE.0).into(),
                (self.head.y * PIXEL_SIZE.1).into(),
                SIZE_IN_PIXELS.0.into(),
                SIZE_IN_PIXELS.1.into(),
            ),
        )
    }
}

struct Position {
    x: i16,
    y: i16,
}

impl Position {
    pub fn new(x: i16, y: i16) -> Self {
        Self { x, y }
    }

    pub fn new_by_direction(x: i16, y: i16, direction: Direction, reverse: bool) -> Self {
        let mut accel = DEFAULT_ACCEL;
        if reverse {
            accel *= -1;
        }

        let (x, y) = match direction {
            Direction::Up => (x, y - accel),
            Direction::Down => (x, y + accel),
            Direction::Left => (x - accel, y),
            Direction::Right => (x + accel, y),
        };

        Position::new(x, y)
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
