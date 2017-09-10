#!/usr/bin/python

from typing import List, Tuple

import pygame  # type: ignore
import random

WINDOW_WIDTH = 400
WINDOW_HEIGHT = 400
FPS = 10


class Snake(object):
    WIDTH = 20
    HEIGHT = 20
    MIN_TAIL = 3

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

        # add the current position to the list
        self.trail.append((self.pos_x, self.pos_y))

        # remove the first tuple of positions
        while len(self.trail) > self.tail:
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
                    self.HEIGHT - 1
                ), 0
            )

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

    def check_borders(self) -> None:
        if self.pos_x > WINDOW_WIDTH / self.WIDTH - 1:
            self.pos_x = 0
        elif self.pos_x < 0:
            self.pos_x = int(WINDOW_WIDTH / self.WIDTH) - 1
        elif self.pos_y > WINDOW_HEIGHT / self.HEIGHT - 1:
            self.pos_y = 0
        elif self.pos_y < 0:
            self.pos_y = int(WINDOW_HEIGHT / self.HEIGHT) - 1

    def increase(self) -> None:
        self.tail += 1

    def reset(self) -> None:
        self.tail = self.MIN_TAIL

    def tail_collision(self) -> bool:
        # ignore the last value. It should not be considered because
        # it was just added and will always match
        for x, y in self.trail[:-2]:
            if self.pos_x == x and self.pos_y == y:
                return True

        return False


class Fruit(object):
    WIDTH = 20
    HEIGHT = 20

    def __init__(self) -> None:
        self.pos_x = 10
        self.pos_y = 10

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
                self.HEIGHT - 1
            ), 0
        )

    def regenerate(self) -> None:
        self.pos_x = random.randint(0, self.WIDTH)
        self.pos_y = random.randint(0, self.HEIGHT)


def game_loop(screen: pygame.Surface) -> None:
    clock = pygame.time.Clock()
    snake = Snake()
    fruit = Fruit()

    while True:
        events = pygame.event.get()
        handle_quit(events)

        # fills the whole screen in black
        screen.fill(pygame.color.Color("black"))

        if snake.pos_x == fruit.pos_x and snake.pos_y == fruit.pos_y:
            fruit.regenerate()
            snake.increase()

        snake.update(events)
        snake.draw(screen)

        fruit.update()
        fruit.draw(screen)

        if snake.tail_collision():
            snake.reset()

        pygame.display.update()
        clock.tick(FPS)


def handle_quit(events: List[pygame.event.Event]) -> None:
    for ev in events:
        if ev.type == pygame.QUIT:
            exit(0)
        elif ev.type == pygame.KEYDOWN and ev.key == pygame.K_ESCAPE:
            exit(0)


def run() -> None:
    pygame.init()

    screen = pygame.display.set_mode(
        (WINDOW_WIDTH, WINDOW_HEIGHT),
        pygame.HWSURFACE
    )
    pygame.display.set_caption("Snakegame")

    game_loop(screen)


run()
