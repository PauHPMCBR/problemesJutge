from PIL import Image, ImageDraw


img = Image.new('RGB', (900, 300), 'Black')
dib = ImageDraw.Draw(img)

r = int(input())
g = int(input())
b = int(input())

for x in range(6):
    dib.polygon([(x*150, 0), ((x+1)*150, 0), ((x+1)*150, 300), (x*150, 300)], (int((r*(5-x))/5), int((g*(5-x))/5), int((b*(5-x))/5)))

img.save('output.png')
img.show()
