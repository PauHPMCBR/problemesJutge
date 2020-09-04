from PIL import Image, ImageDraw

def copy(x, y, it):
    n = 3**(it)
    region = img.crop((0, 0, n, n))
    
    img.paste(region, (x+n, y, x+2*n, y+n))
    img.paste(region, (x+2*n, y, x+3*n, y+n))
    img.paste(region, (x, y+n, x+n, y+2*n))
    img.paste(region, (x, y+2*n, x+n, y+3*n))
    img.paste(region, (x+n, y+2*n, x+2*n, y+3*n))
    img.paste(region, (x+2*n, y+n, x+3*n, y+2*n))
    img.paste(region, (x+2*n, y+2*n, x+3*n, y+3*n))


c = input()
f = input()
it = int(input())
l = 3
w = 3
img = Image.new('RGB', [l**it, w**it], f)
dib = ImageDraw.Draw(img)


dib.point([0, 0], c)
dib.point([0, 1], c)
dib.point([0, 2], c)
dib.point([1, 0], c)
dib.point([1, 2], c)
dib.point([2, 0], c)
dib.point([2, 1], c)
dib.point([2, 2], c)

for i in range(it):
    if i == 0:
        continue
    copy(0, 0, i)


img.show()
img.save('output.png')
