from PIL import Image, ImageDraw

f = input()
c = input()
b = int(input())
a = int(input())
x = int(input())

img = Image.new("RGB", (b, a), f)
dib = ImageDraw.Draw(img)

dib.polygon([(0,a-1), (b-1,a-1), (x,0)], c)

img.save("output.png")
img.show()
