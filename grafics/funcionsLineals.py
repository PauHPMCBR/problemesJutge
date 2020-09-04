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
        r = (x*xr+y*yr)%256
        g = (x*xg+y*yg)%256
        b = (x*xb+y*yb)%256
        dib.point((x, y), (r, g, b))

img.save('output.png')
img.show()
