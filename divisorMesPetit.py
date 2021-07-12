from PIL import Image, ImageDraw
from math import sqrt

f = input()
c = input()
n = int(input())
d = n

for i in range(int(sqrt(n))+1):
    if (i < 2): continue
    if (n%i == 0):
        d = i
        break

m = n // d

img = Image.new('RGB', (50*d, 50*m), f)
dib = ImageDraw.Draw(img)


for x in range(d):
    for y in range(m):
        dib.ellipse([(50*x, 50*y), (50*(x+1)-1, 50*(y+1)-1)], c)



img.save('output.png')
img.show()