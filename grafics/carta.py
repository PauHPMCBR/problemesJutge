from PIL import Image, ImageDraw

b = input()
c = input()
n = int(input())
m = int(input())

img = Image.new('RGB', (n, m), b)
dib = ImageDraw.Draw(img)

dib.polygon([(0, 0), (n-1, 0), (n//2, n//2)], c)



img.save('output.png')
img.show()
