import unicodedata


def simplify(text):
	text = unicodedata.normalize('NFD', text).encode('ascii', 'ignore').decode("utf-8")
	text = text.replace('-', '')
	text = text.replace("'", '')
	return str(text.lower())

file = open("transformedCatDic.txt", "w", encoding="utf8")
s = set()
with open("diccionariCatala.txt", "r", encoding="utf8") as dic:
	for line in dic:
		word = simplify(line[:-1])
		if not word in s:
			file.write(word + '\n')
			s.add(word)
