f = open("sitemap.xml", "r")
s = set()
for x in f:
	if x.startswith("<url><loc>https://www.cangur.org/esprint/"):
		prov = x[41:].split('/')[0]
		if not prov in s:
			print(prov)
			s.add(prov)