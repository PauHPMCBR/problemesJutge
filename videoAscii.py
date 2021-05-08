import toascii

lel = toascii.VideoConverter("badapple.mp4", 0.0225, 3, "  ##")
lel.convert()
with open("ba.txt", 'w') as f:
	for i in lel.ascii_frames:
		f.write(i)