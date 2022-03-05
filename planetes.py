from PIL import Image, ImageDraw


n = int(input())
d = []
col = []
sum = 0
biggest = 0
for x in range(n):
    d.append(int(input()))
    sum = sum + d[x]
    if (d[x] > biggest):
        biggest = d[x]
    col.append(input())


img = Image.new('RGB', (sum, biggest), 'Black')
dib = ImageDraw.Draw(img)
start = 0

for x in range(n):
    dib.ellipse([start, ((biggest / 2) - d[x] / 2), (start + d[x]) -1, ((biggest / 2) + d[x] / 2) -1], col[x])
    start += d[x]


img.save('output.png')