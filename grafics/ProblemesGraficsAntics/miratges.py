from PIL import Image, ImageDraw
from math import sin

m = int(input())
n = int(input())
d = int(input())

rx = int(input())
ry = int(input())
gx = int(input())
gy = int(input())
bx = int(input())
by = int(input())


img = Image.new('RGB', (m, n))
dib = ImageDraw.Draw(img)

for x in range(m):
    for y in range(n):
        dib.point((x, y), (int(rx*sin(x/d) + ry*sin(y/d))%256, int(gx*sin(x/d) + gy*sin(y/d))%256, int(bx*sin(x/d) + by*sin(y/d))%256))

img.save('output.png')
img.show()
