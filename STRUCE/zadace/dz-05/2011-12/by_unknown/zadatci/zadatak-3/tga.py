import struct, array, math

SIZE = 800
## begin tga header fields:
## structure seen at 
## http://gpwiki.org/index.php/TGA, 2009-09-20
Offset = 0
ColorType = 0
ImageType = 2
PaletteStart = 0
PaletteLen = 0
PalBits = 8
XOrigin = 0
YOrigin = 0
Width = SIZE
Height = SIZE
BPP = 24
Orientation = 1 << 5 # da bude koordinatni sustav gore lijevo

# Struct format string documentation at:
# http://docs.python.org/library/struct.html
# (c 'short' stays for 16 bit data)
StructFmt = "<BBBHHBHHHHBB"

header = struct.pack(StructFmt, Offset, ColorType, ImageType,
                                PaletteStart, PaletteLen, PalBits,
                                XOrigin, YOrigin, Width, Height,
                                BPP, Orientation)

# Array mdule and format documentation at:
# http://docs.python.org/library/array.html
data = array.array("B", (255 for i in xrange(SIZE ** 2 * 3)))

def put(x, y, c):
	if x < 0 or y < 0 or x > 799 or y > 799: return
	for i in xrange(3):
		try:
			data[(y * SIZE + x) * 3 + i] = c[i]
		except IndexError:
			print x, y, i, c

def hline(y, x1, x2, c):
    for x in xrange(x1, x2):
        put(x, y, c)

def vline(x, y1, y2, c):
    for y in xrange(y1, y2):
        put(x, y, c)

def rect (x, y, w, h, c):
	for i in xrange(0, int(h)):
	    hline(int(y + i), int(x), int(x) + int(w), c)

def circle(x,y,r,c):
	x *= 8; y *= 8; r *= 8;
	r=int(r)
	n = 10*r
	for i in xrange(0,n):
		put(int(x+math.sin(i*math.pi*2/n)*r),int(y+math.cos(i*math.pi*2/n)*r),c)


def emptyrect(x, y, w, h, c):
		hline(y,x,x+w+1,c)
		hline(y+h,x,x+w+1,c)
		vline(x,y,y+h,c)
		vline(x+w,y,y+h,c)

def save(filename):
    datafile = open(filename, "wt")
    datafile.write(header)
    data.write(datafile)
    datafile.close()

boje_klasa = {
1: (0,255,255),
2: (0,255,0),
3: (255,200,0),
4: (0,128,255),
5: (255,255,255),
6: (0,0,0),
505: (0,0,0)
}

def draw(x,y,klasa):
	x *= 8; y *= 8;
	if x < 3: x=3; klasa=6 # err klasa
	if y < 3: y=3; klasa=6
	if x > 796: x=796; klasa=6
	if y > 796: y=796; klasa=6

	rect(x-3,y-3,6,6,(0,0,0))
	rect(x-2,y-2,4,4,boje_klasa[klasa])
