import pygame
import time
import random

#window settings
WINDOW_WIDTH = 800
WINDOW_HEIGHT = 600
clearColor = (0, 128, 128)

#inits pygame
pygame.init()
window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))

#game loop
window.fill(clearColor) #clear screen

#game logic

pygame.display.flip() #updates screen
time.sleep(3)

#clear resources
pygame.quit()