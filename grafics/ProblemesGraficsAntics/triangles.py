from PIL import Image, ImageDraw
from math import sqrt, pow

c = int(input())
f = int(input())

img = Image.new('RGB', (c, f), 'Beige')
dib = ImageDraw.Draw(img)

n = int(input())
for x in range(n):
    rectangle = 0
    x1 = int(input())
    y1 = int(input())
    x2 = int(input())
    y2 = int(input())
    x3 = int(input())
    y3 = int(input())
    l1 = (pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2))
    l2 = (pow(abs(x2 - x3), 2) + pow(abs(y2 - y3), 2))
    l3 = (pow(abs(x3 - x1), 2) + pow(abs(y3 - y1), 2))

    if (l2 + l3 == l1):
        rectangle = 1
    elif (l2 + l1 == l3):
        rectangle = 1
    elif (l1 + l3 == l2):
        rectangle = 1

    if (rectangle == 1):
        dib.polygon([(x1, y1), (x2, y2), (x3, y3)], 'Blue')
    else:
        dib.polygon([(x1, y1), (x2, y2), (x3, y3)], 'Red')


img.save('output.png')
img.show()
