from PIL import Image, ImageDraw
from math import sin
import random


img = Image.new('RGB', (16, 16), 'White')
dib = ImageDraw.Draw(img)

d = random.randint(1, 8)
bx = random.randint(1, 300)
by = random.randint(1, 300)

for x in range(16):
    for y in range(16):
        r = random.randint(0, 1)
        if (r == 1):
            dib.point((x, y), (int(bx*sin(x/d) + by*sin(y/d))%256, int(bx*sin(x/d) + by*sin(y/d))%256, int(bx*sin(x/d) + by*sin(y/d))%256))

img.save('output.png')
img.show()
