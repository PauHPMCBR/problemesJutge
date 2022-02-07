import mouse
import time, sys
sys.setrecursionlimit(10000)


#intro = [1075, 700]
#coords = [
#	[960, 485],		#central
#	[900, 400],		#dalt esquerra
#	[1000, 400],	#dalt dreta
#	[1070, 485],	#dreta
#	[1000, 580],	#baix dreta
#	[900, 580],		#baix esquerra
#	[855, 485]		#esquerra
#]

intro = (855, 573)
coords = [
	(762, 390),
	(717, 321),
	(801, 316),
	(845, 394),
	(800, 463),
	(716, 459),
	(670, 386)
]


def printWord(word):
	for i in word:
		mouse.move(i[0], i[1])
		mouse.click()
		time.sleep(0.001)
	mouse.move(intro[0], intro[1])
	mouse.click()
	time.sleep(0.001)

def checkWord(word):
	if coords[0] in word:
		return True
	return False

def searchAll(wordLen, pos, word):
	if wordLen == pos:
		if checkWord(word):
			printWord(word)
		return
	for i in coords:
		if pos == 0 or word[pos-1] != i:
			word[pos] = i
			searchAll(wordLen, pos+1, word)



time.sleep(2)
searchAll(3, 0, [None, None, None])