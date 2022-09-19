from PIL import Image, ImageDraw

c1 = input()
c2 = input()
n = int(input())
l = 0

for x in range(n):
    l += pow(2, (x+2))-1
h = pow(2, n)

img = Image.new('RGB', (l, h), c1)
dib = ImageDraw.Draw(img)

o = 0
for y in range(n):
    dib.polygon([(o, h-1), (o+pow(2, (y+1))-1, h-pow(2, (y+1))), (o+pow(2, (y+2))-2, h-1)], c2)
    o += pow(2, (y+2))-1

img.save('output.png')
img.show()
