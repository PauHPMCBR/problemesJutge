from PIL import Image, ImageDraw

n = int(input())

img = Image.new('RGB', [n,1])
dib = ImageDraw.Draw(img)

for i in range(n):
	dib.point((i,0), input())

img = img.resize((50*n,50), Image.BOX)

img.save('output.png')