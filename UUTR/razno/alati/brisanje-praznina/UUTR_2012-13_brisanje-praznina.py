from sys import argv
script, dat=argv
txt=open(dat,"r")
pod=txt.read()
txt.close()
pod=pod.replace(" ","")
txt=open(dat,"w")
txt.write(pod)
txt.close()
print "Napravio!"