extern crate ggez;
extern crate rand;

struct Game {
}

impl Game {
    pub fn new() -> Self {
        Game {}
    }
}

impl ggez::event::EventHandler for Game {
    fn update(&mut self, _ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        Ok(())
    }

    fn draw(&mut self, ctx: &mut ggez::Context) -> ggez::GameResult<()> {
        ggez::graphics::clear(ctx);
        ggez::graphics::present(ctx);
        Ok(())
    }
}

fn main() {
    let ctx = &mut ggez::ContextBuilder::new("snakegame", "PotHix")
        .window_setup(ggez::conf::WindowSetup::default().title("Rust snake game"))
        .window_mode(ggez::conf::WindowMode::default().dimensions(640, 480))
        .build().expect("Could not build ggez context");

    ggez::graphics::set_background_color(ctx, (0, 0, 0).into());

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
