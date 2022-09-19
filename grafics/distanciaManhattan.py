from PIL import Image, ImageDraw

n = int(input())
m = int(input())
xr = int(input())
yr = int(input())
xg = int(input())
yg = int(input())
xb = int(input())
yb = int(input())

img = Image.new('RGB', (n, m))
dib = ImageDraw.Draw(img)

for x in range(n):
    for y in range(m):
        r = (abs(x-xr)+abs(y-yr))%256
        g = (abs(x-xg)+abs(y-yg))%256
        b = (abs(x-xb)+abs(y-yb))%256
        if (xr == -1): r = 0
        if (xg == -1): g = 0
        if (xb == -1): b = 0
        dib.point((x, y), (r, g, b))

img.save('output.png')
img.show()
