# libgosu
# gem install gosu

require "gosu"

class SnakeGame < Gosu::Window
  WIDTH, HEIGHT = 400,400
  FULLSCREEN = false
  FPS = 1000/10

  TILE = 20
  WIDTH_IN_TILE = WIDTH / TILE

  def initialize
    super(WIDTH, HEIGHT, FULLSCREEN, FPS)

    @snake = Snake.new
    @fruit = Fruit.new

    @score = Gosu::Font.new(self, "Arial", 15)
  end

  def update
    if @snake.posx == @fruit.posx && @snake.posy == @fruit.posy
      @fruit.regenerate!
      @snake.increase!
    end

    @fruit.update
    @snake.update

    @snake.pos[0..-2].each do |posx, posy|
      if @snake.posx == posx && @snake.posy == posy
        @snake.reset!
      end
    end
  end

  def draw
    @fruit.draw
    @snake.draw

    @score.draw("score: #{@snake.tail - Snake::MIN_TAIL}", 5, 5, 0)
  end

  def button_down(event)
    case event
    when Gosu::KbEscape then close!
    when Gosu::KbUp     then @snake.up
    when Gosu::KbDown   then @snake.down
    when Gosu::KbLeft   then @snake.left
    when Gosu::KbRight  then @snake.right
    end
  end
end

class Snake
  attr_reader :posx, :posy, :pos, :tail

  MIN_TAIL = 5

  def initialize
    @posx = 2
    @posy = 2

    @velx = 0
    @vely = 0

    @tail = MIN_TAIL

    @pos = []
  end

  def update
    @posx += @velx
    @posy += @vely

    @posx = 0 if @posx > SnakeGame::WIDTH_IN_TILE - 1
    @posx = SnakeGame::WIDTH_IN_TILE - 1 if @posx < 0
    @posy = 0 if @posy > SnakeGame::WIDTH_IN_TILE - 1
    @posy = SnakeGame::WIDTH_IN_TILE - 1 if @posy < 0

    @pos << [@posx, @posy]
    @pos.shift until @pos.size <= @tail
  end

  def draw
    @pos.each do |posx, posy|
      Gosu.draw_rect(
        posx * SnakeGame::TILE, # posicao x
        posy * SnakeGame::TILE, # posicao y
        SnakeGame::TILE - 1, # tamanho
        SnakeGame::TILE - 1, # altura
        Gosu::Color::GREEN
      )
    end
  end

  def increase!
    @tail += 1
  end

  def reset!
    @tail = MIN_TAIL
  end

  def up;    @vely = -1; @velx = 0; end
  def down;  @vely = 1;  @velx = 0; end
  def left;  @velx = -1; @vely = 0; end
  def right; @velx = 1;  @vely = 0; end
end

class Fruit
  attr_reader :posx, :posy

  def initialize
    @posx = 5
    @posy = 5

    @tick = Gosu::Sample.new("/tmp/tick.ogg")
  end

  def update;  end

  def draw
    Gosu.draw_rect(
      @posx * SnakeGame::TILE, # posicao x
      @posy * SnakeGame::TILE, # posicao y
      SnakeGame::TILE - 1, # tamanho
      SnakeGame::TILE - 1, # altura
      Gosu::Color::RED
    )
  end

  def regenerate!
    @tick.play
    @posx = (rand * SnakeGame::TILE).floor
    @posy = (rand * SnakeGame::TILE).floor
  end
end

SnakeGame.new.show
