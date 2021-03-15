gran = 2
for x in range(10000):
    primer = 0
    for i in range(int((x+2)/2)):
        if ((x+2) % (i+2) == 0):
            primer = 1
    if (primer == 0):
        gran = x
print(gran)
