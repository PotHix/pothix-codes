extern crate ggez;

const SNAKE_INIT_POS: (i16, i16) = (5, 5);

use ggez::{event, Context, ContextBuilder};

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
    fn draw(&mut self, ctx: &mut Context) -> ggez::GameResult<()> {
        Ok(())
    }
    fn update(&mut self, ctx: &mut Context) -> ggez::GameResult<()> {
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
        .build()
        .expect("Failed to build ggez context builder");

    let game = &mut Game::new();

    match event::run(ctx, game) {
        Err(e) => println!("Ouch! Error raised: {}", e),
        Ok(_) => println!("Thanks for playing!"),
    }
}
