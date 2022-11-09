
# [-10.189108290882482, 5.138121448354753]
# [-24.23288079198283, -28.231098893787486]

n=2
a=1.3
Xc= [-10.189108290882482, 5.138121448354753]
Xh= [0.6137936330408635, 30.80675248077186]
def refleksija(xh, xc):
    for i in range(n):
        xh[i] = (1 + a) * xc[i] - a * xh[i]
    return xh


print(str(refleksija(Xh, Xc)))

print("zelis li %f sve ko i ja?" %Xh[0])