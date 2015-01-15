#Joshua Pepperman
#jdpepperman@crimson.ua.edu

import urllib2
import os

link = "http://songlib.cs.ua.edu/samples/"

response = urllib2.urlopen(link)

html = response.read()

#a for loop through response.read() yields each character, so here we break it into lines
htmlLines = []
lineToAdd = ""
for char in html:
	if '\n' in char:
		htmlLines.append(lineToAdd)
		lineToAdd = ""
	else:
		lineToAdd = lineToAdd + char

#now that we have the lines of the html, we can get the instrument names to use in our getpack command later
instrumentNames = []
for line in htmlLines:
	#if there is a link in the line
	if "href=" in line:
		#get the name of the link
		part1 = line[line.index("href=\"")+6:]
		part2 = part1[:part1.index("\"")]
		#make sure it follows our instrumentName.tgz format
		if part2.count('.') == 1:
			#then add it to the list without the ".tgz" at the end
			instrumentNames.append(part2[:-4])
print("Current instrument packs available:")
for instrument in instrumentNames:
	print("\t" + instrument)	
print("If you want to get all instrument packs enter 'all', otherwise list the packs\nyou want to install as they appear above separated by spaces (or 'quit'\nto exit): ")
instrumentList = raw_input()

if instrumentList == "quit":
	pass
elif instrumentList == "all":
	#we have the list of all available instrument packs on the website. We just have to use getpack with each 
	#	one, which is what we do next
	print("This should be done in a temporary directory. It also takes a long time and uses about 7gb. Are you sure you want to contimue? (y/n)")
	proceed = raw_input()
	if proceed == 'y':
		for instrument in instrumentNames:
			os.system("getpack " + instrument)
	else:
		pass
else:
	#split input into instuments and getpack them
	selectedInstruments = instrumentList.split(' ')
	for instrument in selectedInstruments:
		os.system("getpack " + instrument)

print("Done.")	
