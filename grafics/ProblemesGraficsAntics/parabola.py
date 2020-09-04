from PIL import Image, ImageDraw

a = int(input())
b = int(input())
c = int(input())
z = int(input())
e = int(input())
d = int(input())
x = d - e + 1
v = [0] * x
min = 100000
max = 0
for n in range(d-e+1):
    v[n] = (pow(a*(n+e), 2) + b*(n+e) + c) // z
    if (v[n] < min): min = v[n]
    if (v[n] > max): max = v[n]


img = Image.new('RGB', (x, (max-min+1)), 'Beige')
dib = ImageDraw.Draw(img)

for m in range(x):
    dib.point((m, max-v[m]), 'Blue')


img.save('output.png')
img.show()
