import pygame
import time
import os

os.system("cls")

from colorama import Fore, Style, init
init()

colors = [
    Fore.RED,
    Fore.GREEN,
    Fore.CYAN,
    Fore.YELLOW,
    Fore.MAGENTA,
    Fore.BLUE
]

print(colors[index % len(colors)] + lyrics[index][1] + Style.RESET_ALL)

import sys,time

def typewriter(text):
    for ch in text:
        print(ch,end="",flush=True)
        time.sleep(0.02)
    print()

typewriter(lyrics[index][1])



pygame.init()
pygame.mixer.init()

MP3_FILE = "saiyara.mp3.mp3"
LRC_FILE = "demo.lrc"

# ---------- Read LRC ----------
lyrics = []

with open(LRC_FILE, "r", encoding="utf-8") as file:
    for line in file:
        if "]" in line:
            timestamp, text = line.strip().split("]", 1)
            timestamp = timestamp.replace("[", "")
            minute, second = timestamp.split(":")
            total = int(minute) * 60 + float(second)
            lyrics.append((total, text))

# ---------- Play Music ----------
pygame.mixer.music.load(MP3_FILE)
pygame.mixer.music.play()

print("\n🎵 Music Started...\n")

start = time.time()
index = 0

while pygame.mixer.music.get_busy():

    current = time.time() - start

    if index < len(lyrics):

        if current >= lyrics[index][0]:
            print("♪", lyrics[index][1])
            index += 1

    time.sleep(0.05)

print("\nSong Finished.") 