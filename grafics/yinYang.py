from PIL import Image, ImageDraw


f = input()
c = input()
n = int(input())

img = Image.new('RGB', (16*n, 16*n), f)
dib = ImageDraw.Draw(img)


dib.ellipse([0, 0, 16*n - 1, 16*n - 1], c)
dib.chord([0, 0, 16*n - 1, 16*n - 1], 90, 270, f, c)

dib.ellipse([4*n, 0, 12*n-1, 8*n-1], f)
dib.ellipse([4*n, 8*n, 12*n-1, 16*n-1], c)

dib.ellipse([7*n, 3*n, 9*n-1, 5*n-1], c)
dib.ellipse([7*n, 11*n, 9*n-1, 13*n-1], f)

img.save('output.png')
img.show()
