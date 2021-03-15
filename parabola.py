from PIL import Image, ImageDraw




a = int(input())
b = int(input())
c = int(input())
z = int(input())
e = int(input())
d = int(input())
x = d - e + 1
v = [0] * x

min = max = (a*e*e + b*e + c)//z

for n in range(e + 1, d + 1):
    v[n] = (a*n*n + b*n + c) //z
    if (v[n] < min): min = v[n]
    if (v[n] > max): max = v[n]

lol = max-min+1

img = Image.new('RGB', (x, lol), 'Beige')
dib = ImageDraw.Draw(img)

for m in range(e, d+1):
    dib.point((m - e, lol-(v[m]-min)-1), 'Blue')


img.save('output.png')
img.show()
