from PIL import Image, ImageDraw
from math import sin
import random

m = 1000
n = 1000
d = random.randint(10, 300)

rx = random.randint(1, 300)
ry = random.randint(1, 300)
gx = random.randint(1, 300)
gy = random.randint(1, 300)
bx = random.randint(1, 300)
by = random.randint(1, 300)


img = Image.new('RGB', (m, n))
dib = ImageDraw.Draw(img)

for x in range(m):
    for y in range(n):
        dib.point((x, y), (int(rx*sin(x/d) + ry*sin(y/d))%256, int(gx*sin(x/d) + gy*sin(y/d))%256, int(bx*sin(x/d) + by*sin(y/d))%256))

img.save('output.png')
img.show()
