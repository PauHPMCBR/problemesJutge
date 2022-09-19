from PIL import Image, ImageDraw

n = int(input())
v = [None] * n

img = Image.new('RGB', (50*n, 50), 'White')
dib = ImageDraw.Draw(img)

for i in range(n): dib.polygon([(50*i, 0), (50*i, 50), (50*(i+1)-1, 50), (50*(i+1)-1, 0)], input())

img.save('output.png')
img.show()
