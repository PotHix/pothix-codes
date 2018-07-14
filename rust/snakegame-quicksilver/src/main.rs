// Draw some multi-colored geometry to the screen
extern crate quicksilver;
extern crate rand;

use quicksilver::{
    geom::Rectangle, graphics::{Color, Draw, Window, WindowBuilder}, input::ButtonState,
    input::Event, input::Key, run, State,
};

//use rand::Rng;

// speed of the snake
const _DEFAULT_ACCEL: i16 = 1;

// number of frames per second
const _DEFAULT_FPS: i8 = 8;

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

// All members are here
struct Game {
    snake: Snake,
    fruit: Fruit,
}

impl State for Game {
    fn new() -> Self {
        Self {
            snake: Snake::new(SNAKE_INIT_POS.0, SNAKE_INIT_POS.1),
            fruit: Fruit::new(FRUIT_INIT_POS.0, FRUIT_INIT_POS.1),
        }
    }

    fn update(&mut self, window: &mut Window) {
        self.snake.update(window);
    }

    fn draw(&mut self, window: &mut Window) {
        window.clear(Color::black());

        self.fruit.draw(window);
        self.snake.draw(window);

        window.present();
    }

    fn event(&mut self, event: &Event, _window: &mut Window) {
        if let Event::Key(Key::Escape, ButtonState::Pressed) = event {
            panic!("cegelaaaa");
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

    fn update(&mut self, _window: &mut Window) {
        let new_head = Position::new_by_direction(self.head.x + 1, self.head.y, self.direction);
        self.head = new_head;
    }

    fn draw(&self, window: &mut Window) {
        let rect = Rectangle::new(
            self.head.x * SIZE_IN_PIXELS.0,
            self.head.y * SIZE_IN_PIXELS.1,
            PIXEL_SIZE.0,
            PIXEL_SIZE.1,
        );
        window.draw(&Draw::rectangle(rect).with_color(Color::green()));
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

    fn draw(&self, window: &mut Window) {
        let rect = Rectangle::new(
            FRUIT_INIT_POS.0 * SIZE_IN_PIXELS.0,
            FRUIT_INIT_POS.1 * SIZE_IN_PIXELS.1,
            PIXEL_SIZE.0,
            PIXEL_SIZE.1,
        );
        window.draw(&Draw::rectangle(rect).with_color(Color::red()));
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
    pub fn new_by_direction(x: i16, y: i16, _direction: Direction) -> Self {
        Self { x, y }
    }
}

fn main() {
    run::<Game>(WindowBuilder::new(
        "Quicksilver game",
        SCREEN_SIZE.0,
        SCREEN_SIZE.1,
    ));
}
