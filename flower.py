import turtle
import colorsys

screen = turtle.Screen()
screen.bgcolor("black")

t = turtle.Turtle()
t.speed(0)

h = 0

for i in range(200):
    c = colorsys.hsv_to_rgb(h, 1, 1)
    t.color(c)
    h += 0.01

    for j in range(6):
        t.circle(i / 3, 60)
        t.left(60)

    t.left(10)

turtle.done()