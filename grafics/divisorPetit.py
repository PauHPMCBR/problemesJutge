from PIL import Image, ImageDraw
from math import sqrt, gcd

c1 = input()
c2 = input()
n = int(input())
m = int(input())
d = gcd(n, m)

img = Image.new('RGB', (n, m))
dib = ImageDraw.Draw(img)


for x in range(n//d):
    for y in range(m//d):
        if ((x+y)%2 == 0): c = c1
        else: c = c2
        dib.polygon([(x*d, y*d), ((x+1)*d-1, y*d), ((x+1)*d-1, (y+1)*d-1), (x*d, (y+1)*d-1)], c)



img.save('output.png')
img.show()
