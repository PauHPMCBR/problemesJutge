from PIL import Image, ImageDraw


cola = input()
colb = input()
n = int(input())
m = int(input())

img = Image.new('RGB', (n, m), cola)
dib = ImageDraw.Draw(img)
dib.polygon([(0, 0), (n-1, 0), (n/2, n/2)], colb)

img.save('output.png')
img.show()
