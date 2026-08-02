import turtle
import colorsys

screen = turtle.Screen()
screen.bgcolor("black")

t = turtle.Turtle()
t.speed(0)

h = 0

for i in range(180):
    c = colorsys.hsv_to_rgb(h, 1, 1)
    h += 0.01

    t.color(c)

    for j in range(36):
        t.circle(100)
        t.left(10)

    t.left(2)

turtle.done()