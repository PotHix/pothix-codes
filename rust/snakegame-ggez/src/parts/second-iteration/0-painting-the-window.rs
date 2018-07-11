extern crate ggez;

const SNAKE_INIT_POS: (i16, i16) = (5, 5);

const PIXEL_SIZE: (i16, i16) = (20, 20);
const SIZE_IN_PIXELS: (i16, i16) = (20, 20);

const SCREEN_SIZE: (u32, u32) = (
    (PIXEL_SIZE.0 * SIZE_IN_PIXELS.0) as u32,
    (PIXEL_SIZE.1 * SIZE_IN_PIXELS.1) as u32,
);

use ggez::{event, Context, ContextBuilder, GameResult};

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
    fn draw(&mut self, ctx: &mut Context) -> GameResult<()> {
        ggez::graphics::clear(ctx);
        ggez::graphics::present(ctx);

        Ok(())
    }

    fn update(&mut self, ctx: &mut Context) -> GameResult<()> {
        Ok(())
    }
}

struct Snake {
    head: Position,
}

impl Snake {
    pub fn new(x: i16, y: i16) -> Self {
        Self {
            head: Position::new(x, y),
        }
    }

    fn draw(ctx: &mut Context) -> GameResult<()> {
        Ok(())
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
