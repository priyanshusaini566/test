import pygame
import time
import os
from mutagen.mp3 import MP3

pygame.init()

WIDTH, HEIGHT = 1200,700

screen = pygame.display.set_mode((WIDTH,HEIGHT))

pygame.display.set_caption("Lyrics Player")

clock = pygame.time.Clock()

WHITE=(255,255,255)
GREEN=(0,255,170)
GRAY=(180,180,180)
BLACK=(20,20,20)

title_font=pygame.font.SysFont("Segoe UI",40,True)
lyric_font=pygame.font.SysFont("Segoe UI",42,True)
small_font=pygame.font.SysFont("Segoe UI",25)

background=pygame.image.load("background.jpg")
background=pygame.transform.scale(background,(WIDTH,HEIGHT))

album=pygame.image.load("album.png")
album=pygame.transform.scale(album,(250,250))

pygame.mixer.music.load("saiyara.mp3")

audio=MP3("saiyara.mp3")

duration=audio.info.length

lyrics=[]

with open("demo.lrc","r",encoding="utf8") as file:

    for line in file:

        if "]" in line:

            t,text=line.split("]",1)

            t=t.replace("[","")

            m,s=t.split(":")

            total=int(m)*60+float(s)

            lyrics.append((total,text.strip()))

pygame.mixer.music.play()

start=time.time()

index=0

current_line=""

next_line=""

running=True

while running:

    for event in pygame.event.get():

        if event.type==pygame.QUIT:
            running=False

    current=time.time()-start

    if index<len(lyrics):

        if current>=lyrics[index][0]:

            current_line=lyrics[index][1]

            if index+1<len(lyrics):
                next_line=lyrics[index+1][1]

            index+=1

    screen.blit(background,(0,0))

    pygame.draw.rect(screen,(25,25,25),(0,0,WIDTH,HEIGHT),0)

    screen.blit(album,(70,180))

    title=title_font.render("Saiyaara",True,WHITE)
    singer=small_font.render("Singer",True,GRAY)

    screen.blit(title,(400,70))
    screen.blit(singer,(400,120))

    lyric=lyric_font.render(current_line,True,GREEN)

    screen.blit(lyric,(400,300))

    nxt=small_font.render(next_line,True,GRAY)

    screen.blit(nxt,(400,360))

    progress=current/duration

    pygame.draw.rect(screen,(60,60,60),(400,600,650,10))

    pygame.draw.rect(screen,GREEN,(400,600,int(650*progress),10))

    timer=small_font.render(
        f"{int(current//60):02}:{int(current%60):02} / {int(duration//60):02}:{int(duration%60):02}",
        True,
        WHITE
    )

    screen.blit(timer,(400,625))

    pygame.display.update()

    clock.tick(60)

pygame.quit()