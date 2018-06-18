extern crate ggez;

use std::collections::LinkedList;

const INIT_POS: (i16, i16) = (10, 10);
const PIXEL_SIZE: (i16, i16) = (20, 20);

struct Game {
    snake: Snake,
}

impl Game {
    pub fn new() -> Self {
        Game {
            snake: Snake::new(INIT_POS.into()),
        }
    }
}

impl ggez::event::EventHandler for Game {
    fn update(&mut self, _ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        self.snake.update();
        Ok(())
    }

    fn draw(&mut self, ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        ggez::graphics::clear(ctx);
        self.snake.draw(ctx)?;
        ggez::graphics::present(ctx);
        Ok(())
    }
}


#[derive(Clone, Copy, Debug)]
struct Position {
    x: i16,
    y: i16,
}

impl From<(i16, i16)> for Position {
    fn from(pos: (i16, i16)) -> Self {
        Position {x: pos.0, y:pos.1}
    }
}

impl From<Position> for ggez::graphics::Rect {
    fn from(pos: Position) -> Self {
        ggez::graphics::Rect::new_i32(
            pos.x as i32,
            pos.y as i32,
            PIXEL_SIZE.0 as i32,
            PIXEL_SIZE.1 as i32,
        )
    }
}

impl<'a> From<&'a Position> for ggez::graphics::Rect {
    fn from(pos: &'a Position) -> Self {
        ggez::graphics::Rect::new_i32(
            pos.x as i32,
            pos.y as i32,
            PIXEL_SIZE.0 as i32,
            PIXEL_SIZE.1 as i32,
        )
    }
}


struct Snake {
    head: Position,
    body: LinkedList<Position>,
}

impl Snake {
    pub fn new(pos: Position) -> Self {
        let mut body = LinkedList::new();
        body.push_front(Position{x: pos.x-1, y: pos.y});
        
        Snake {
            head: pos,
            body: body,
        }
    }

    fn update(&mut self) {
    }

    fn draw(&self, ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        for pos in self.body.iter() {
            ggez::graphics::set_color(ctx, (1, 0, 0).into())?;
            ggez::graphics::rectangle(ctx, ggez::graphics::DrawMode::Fill, pos.into())?;
        }

        ggez::graphics::set_color(ctx, (0, 1, 0).into())?;
        ggez::graphics::rectangle(ctx, ggez::graphics::DrawMode::Fill, self.head.into())?;

        Ok(())
    }
}


fn main() {
    let ctx = &mut ggez::ContextBuilder::new("snakegame", "PotHix")
        .window_setup(ggez::conf::WindowSetup::default().title("Rust snake game"))
        .window_mode(ggez::conf::WindowMode::default().dimensions(640, 480))
        .build().expect("Could not build ggez context");

    // ggez::graphics::set_background_color(ctx, (0, 0, 1).into()); 

    let game = &mut Game::new();

    match ggez::event::run(ctx, game) {
        Err(e) => println!("x.x error raised: {}", e),
        Ok(_) => println!("Thanks for playing!")
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
