require "gosu"

class SnakeGame < Gosu::Window
  WIDTH, HEIGHT = 400, 400
  TILE = 10

  WIDTH_IN_TILE = WIDTH/TILE

  def initialize
    super WIDTH, HEIGHT, false, 1000/15

    @snake = Snake.new
    @fruit = Fruit.new
  end

  def update
    if @snake.x == @fruit.x && @snake.y == @fruit.y
      @snake.increase
      @fruit.regenerate
    end

    @fruit.update
    @snake.update

    @snake.pos[0..-2].each do |x,y|
      @snake.reset if x == @snake.x && y == @snake.y
    end
  end

  def draw
    @fruit.draw
    @snake.draw
  end

  def button_down(id)
    case id
    when Gosu::KbUp    then @snake.up
    when Gosu::KbDown  then @snake.down
    when Gosu::KbLeft  then @snake.left
    when Gosu::KbRight then @snake.right
    end
  end
end

class Snake
  attr_accessor :x, :y
  attr_reader :pos

  MIN_TAIL = 3

  def initialize
    @x = 10
    @y = 10

    @velx = 0
    @vely = 0

    @tail = MIN_TAIL

    @pos = []
  end

  def update
    @x += @velx
    @y += @vely

    @x = 0 if @x > SnakeGame::WIDTH_IN_TILE
    @x = SnakeGame::WIDTH_IN_TILE if @x < 0
    @y = 0 if @y > SnakeGame::WIDTH_IN_TILE
    @y = SnakeGame::WIDTH_IN_TILE if @y < 0

    @pos << [@x, @y]

    @pos.shift until @pos.size <= @tail
  end

  def draw
    @pos.each do |x,y|
      Gosu.draw_rect(
        x * SnakeGame::TILE,
        y * SnakeGame::TILE,
        SnakeGame::TILE - 1,
        SnakeGame::TILE - 1,
        Gosu::Color::GREEN
      )
    end
  end

  def reset
    @tail = MIN_TAIL
  end

  def increase
    @tail += 1
  end

  def up;    @velx = 0;  @vely = -1; end
  def down;  @velx = 0;  @vely = 1;  end
  def left;  @velx = -1; @vely = 0;  end
  def right; @velx = 1;  @vely = 0;  end
end

class Fruit
  attr_accessor :x, :y

  def initialize
    @x = 15
    @y = 15
  end

  def update
  end

  def draw
    Gosu.draw_rect(
      @x * SnakeGame::TILE,
      @y * SnakeGame::TILE,
      SnakeGame::TILE - 1,
      SnakeGame::TILE - 1,
      Gosu::Color::RED
    )
  end

  def regenerate
    @x = (rand * SnakeGame::TILE).floor
    @y = (rand * SnakeGame::TILE).floor
  end
end

SnakeGame.new.show
