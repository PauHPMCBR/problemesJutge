from PIL import Image, ImageDraw

n = int(input())

img = Image.new('RGB', (3*n, 3*n), 'Red')
dib = ImageDraw.Draw(img)

dib.polygon([(0, 0), (0, n-1), (n-1, 0)], 'Beige')
dib.polygon([(3*n-1, 3*n-1), (2*n, 3*n-1), (3*n-1, 2*n)], 'Beige')
dib.polygon([(3*n-1, 0), (2*n, 0), (3*n-1, n-1)], 'Beige')
dib.polygon([(0, 3*n-1), (n-1, 3*n-1), (0, n*2)], 'Beige')

img.save('output.png')
img.show()
