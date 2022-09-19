from PIL import Image, ImageDraw

n = int(input())*50
c = input()
b = input()


img = Image.new('RGB', (n, n), b)
dib = ImageDraw.Draw(img)

for x in range(n//100):
    dib.polygon([(x*50, x*100), (n-x*100, x*100), (n-x*100, x*100+50), (x*100, x*100+50)], c)

img.save('output.png')
img.show()
