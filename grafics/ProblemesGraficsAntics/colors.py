from PIL import Image, ImageDraw

color = input()

img = Image.new('RGB', (500, 500), color)

img.save('output.png')
img.show()
