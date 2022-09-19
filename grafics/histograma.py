from PIL import Image, ImageDraw

f = input()
c = input()
n = int(input())
v = [None] * n
largest = 0

for i in range(n):
    v[i] = int(input())
    if (v[i] > largest): largest = v[i]


img = Image.new('RGB', (100 + 50*n, 100 + largest*50), f)
dib = ImageDraw.Draw(img)

for (i) in range(n):
    dib.polygon([(50*(i+1), 50*(largest+1)-1), (50*(i+1), 50*(largest-v[i]+1)), (50*(i+2)-1, 50*(largest-v[i]+1)), (50*(i+2)-1, 50*(largest+1)-1)], c)


img.save('output.png')
img.show()
