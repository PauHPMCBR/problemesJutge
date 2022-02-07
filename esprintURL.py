f = open("sitemap.xml", "r")
s = set()
for x in f:
	if x.startswith("  <loc>"):
		prov = x[38:-7]
		prov = prov.split('/')
		if not prov[0] in s:
			print(prov[0])
			s.add(prov[0])
