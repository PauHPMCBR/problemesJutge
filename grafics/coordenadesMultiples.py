from PIL import Image, ImageDraw

f = input()
c = input()
n = int(input())


img = Image.new('RGB', (n, n), f)
dib = ImageDraw.Draw(img)

dib.line([(0, 0), (0, n-1)], c)
dib.line([(0, 0), (n-1, 0)], c)

for x in range(n):
    if (x == 0): continue
    for y in range(n):
        if (y == 0): continue
        if (x % y == 0): dib.point((x, y), c)
        elif (y % x == 0): dib.point((x, y), c)

img.save('output.png')
img.show()
