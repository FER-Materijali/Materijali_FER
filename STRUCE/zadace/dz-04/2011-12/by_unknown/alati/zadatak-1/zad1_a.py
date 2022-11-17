# ovo je moja helper skripta za izracunavanje informacijske dobiti za 
# prvi zadatak 4. domace zadace. koristi se rucno iz komandne linije,
# nije nista automatizirano, sluzi samo da olaksa racunanje.
import math

def ent(plus, all):
	if plus == 0: return 0
	all = float(all)
	return -(plus/all) * math.log(plus/all,2)

print ent(1,3) + ent(2,3)
a = ent(0,3) + ent(3,3)
b = ent(4,5) + ent(1,5)

print a,b
print 1 - (3/8.)*a - (5/8.)*b
