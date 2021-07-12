from PIL import Image, ImageDraw
from math import sqrt

c1 = input()
c2 = input()
n = int(input())

x = 2
while n % x != 0:
    x += 1
y = n//x

if x > y:
    x, y = y, x

if x == 1:
    y = 1
    x = n


img = Image.new('RGB', (50*x, 50*y), c1)
dib = ImageDraw.Draw(img)


for i in range(x):
    for j in range(y):
        dib.ellipse([(50*i, 50*j), (50*i+49, 50*j+49)], c2)


img.save('output.png')
