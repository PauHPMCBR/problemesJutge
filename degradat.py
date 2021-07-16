from PIL import Image, ImageDraw

g = int(input())

img = Image.new('RGB', (256, 256))
dib = ImageDraw.Draw(img)

for r in range(256):
    for b in range(256):
        dib.point([r, b], (r, g, b))

img.save('output.png')
img.show()
