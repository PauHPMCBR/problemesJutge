from PIL import Image, ImageDraw

n = int(input())

img = Image.new('RGB', (8*n, 8*n), 'White')
dib = ImageDraw.Draw(img)

dib.ellipse([0, 0, 8*n-1, 8*n-1], 'Blue')
dib.ellipse([n, n, 7*n-1, 7*n-1], 'Yellow')
dib.ellipse([2*n, 2*n, 6*n-1, 6*n-1], 'Red')
dib.ellipse([3*n, 3*n, 5*n-1, 5*n-1], 'Green')

img.save('output.png')
