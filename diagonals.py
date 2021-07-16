from PIL import Image, ImageDraw

f = input()
n = int(input())
a = int(input())
r1 = int(input())
g1 = int(input())
b1 = int(input())
r2 = int(input())
g2 = int(input())
b2 = int(input())

img = Image.new('RGB', (n*a, n*a), f)
dib = ImageDraw.Draw(img)

for i in range(n):
    dib.polygon([(i*a, i*a), (a*(i+1)-1, i*a), (a*(i+1)-1, a*(i+1)-1), (i*a, a*(i+1)-1)], (r1, g1, b1))

max = n*a-1
for i in range(n):
    dib.polygon([(max-i*a, i*a), (max-a*(i+1)+1, i*a), (max-a*(i+1)+1, a*(i+1)-1), (max-i*a, a*(i+1)-1)], (r2, g2, b2))

if (n % 2 == 1):
    i = n//2
    r = (r1+r2)//2
    g = (g1+g2)//2
    b = (b1+b2)//2
    dib.polygon([(max-i*a, i*a), (max-a*(i+1)+1, i*a), (max-a*(i+1)+1, a*(i+1)-1), (max-i*a, a*(i+1)-1)], (r, g, b))

img.save('output.png')
img.show()
