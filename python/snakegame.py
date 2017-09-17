# pip install pygame # game itsel
# pip install mypy   # type checking

from typing import List, Tuple

import pygame  # type: ignore
from random import randint  # type: ignore

WINDOW_WIDTH = 400
WINDOW_HEIGHT = 400
FPS = 10


class Snake(object):
    WIDTH = 20
    HEIGHT = 20
    MIN_TAIL = 3
    WIDTH_TILES_PER_WINDOW = WINDOW_WIDTH / WIDTH
    HEIGHT_TILES_PER_WINDOW = WINDOW_HEIGHT / HEIGHT

    def __init__(self) -> None:
        self.pos_x = 1
        self.pos_y = 1
        self.vel_x = 0
        self.vel_y = 0

        self.tail = self.MIN_TAIL
        self.trail = []  # type: List[Tuple[int, int]]

    def update(self, events: List[pygame.event.Event]) -> None:
        self.pos_x += self.vel_x
        self.pos_y += self.vel_y

        self.vel_x, self.vel_y = self.handle_mov(events)
        self.check_borders()

        self.trail.append((self.pos_x, self.pos_y))

        while(len(self.trail) > self.tail):
            self.trail.pop(0)

    def draw(self, screen: pygame.Surface) -> None:
        for x, y in self.trail:
            pygame.draw.rect(
                screen,
                pygame.color.Color("red"),
                (
                    x * self.WIDTH,
                    y * self.HEIGHT,
                    self.WIDTH - 1,
                    self.HEIGHT - 1,
                ), 0
            )

    def check_borders(self) -> None:
        if self.pos_x > self.WIDTH_TILES_PER_WINDOW - 1:
            self.pos_x = 0
        if self.pos_x < 0:
            self.pos_x = int(self.WIDTH_TILES_PER_WINDOW - 1)
        if self.pos_y > self.HEIGHT_TILES_PER_WINDOW - 1:
            self.pos_y = 0
        if self.pos_y < 0:
            self.pos_y = int(self.HEIGHT_TILES_PER_WINDOW - 1)

    def handle_mov(self, events: List[pygame.event.Event]) -> Tuple[int, int]:
        movement = (self.vel_x, self.vel_y)

        for ev in events:
            if ev.type == pygame.KEYDOWN:
                if ev.key == pygame.K_UP:
                    movement = (0, -1)
                elif ev.key == pygame.K_DOWN:
                    movement = (0, 1)
                elif ev.key == pygame.K_LEFT:
                    movement = (-1, 0)
                elif ev.key == pygame.K_RIGHT:
                    movement = (1, 0)

        return movement

    def increase(self) -> None:
        self.tail += 1

    def reset(self) -> None:
        self.tail = self.MIN_TAIL

    def tail_collision(self) -> bool:
        # we're not considering the last item because it will always
        # match with the current one being checked
        for x, y in self.trail[:-2]:
            if x == self.pos_x and y == self.pos_y:
                return True

        return False


class Fruit(object):
    WIDTH = 20
    HEIGHT = 20

    def __init__(self) -> None:
        self.pos_x = 5
        self.pos_y = 5

    def update(self) -> None:
        pass

    def draw(self, screen: pygame.Surface) -> None:
        pygame.draw.rect(
            screen,
            pygame.color.Color("green"),
            (
                self.pos_x * self.WIDTH,
                self.pos_y * self.HEIGHT,
                self.WIDTH - 1,
                self.HEIGHT - 1,
            )
        )

    def regenerate(self) -> None:
        self.pos_x = randint(0, self.WIDTH - 1)
        self.pos_y = randint(0, self.HEIGHT - 1)


def game_loop(screen: pygame.Surface, font: pygame.font.Font) -> None:
    clock = pygame.time.Clock()
    snake = Snake()
    fruit = Fruit()

    # sound = pygame.mixer.Sound("/tmp/peep.ogg")

    while True:
        events = pygame.event.get()
        handle_quit(events)

        # paint the entire screen
        screen.fill(pygame.color.Color("black"))

        if snake.pos_x == fruit.pos_x and snake.pos_y == fruit.pos_y:
            # sound.play()
            snake.increase()
            fruit.regenerate()

        if snake.tail_collision():
            snake.reset()

        # paint the snake
        snake.update(events)
        snake.draw(screen)

        # paint the fruit
        fruit.update()
        fruit.draw(screen)

        score = font.render(
            "score: %s" % snake.tail, 1, pygame.color.Color("white"))
        screen.blit(score, (0, 0))

        # update the screen
        pygame.display.update()

        # deal with frames per second
        clock.tick(FPS)


def handle_quit(events: List[pygame.event.Event]) -> None:
    for ev in events:
        if ev.type == pygame.QUIT:
            exit(0)
        if ev.type == pygame.KEYDOWN and ev.key == pygame.K_ESCAPE:
            exit(0)


def run() -> None:
    pygame.font.init()
    pygame.init()

    screen = pygame.display.set_mode(
        (WINDOW_WIDTH, WINDOW_HEIGHT),
        pygame.HWSURFACE
    )
    pygame.display.set_caption("Snakegame")
    font = pygame.font.SysFont("monospace", 15)

    game_loop(screen, font)


run()
