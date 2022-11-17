import fileinput

n = int(raw_input().rstrip())

s = [[0 for i in range(n)] for j in range(n)]
b = [[0 for i in range(n)] for j in range(n)]
g = [[0 for i in range(n)] for j in range(n)]
w = [[0 for i in range(n)] for j in range(n)]
p = [[0 for i in range(n)] for j in range(n)]
t = [[0 for i in range(n)] for j in range(n)]

inp = []
dx = [-1,0,0,1]
dy = [0,-1,1,0]

for line in fileinput.input():
	inp.append(line)

for i in range(n):
	for j in range(n):
		if inp[i][j] == 'W':
			w[i][j] = 1
			for k in range(4):
				X = i + dx[k]
				Y = j + dy[k]
				if X >= 0 and Y >= 0 and X < n and Y < n:
					s[X][Y] = 1
		if inp[i][j] == 'T':
			t[i][j] = 1
			for k in range(4):
				X = i + dx[k]
				Y = j + dy[k]
				if X >= 0 and Y >= 0 and X < n and Y < n:
					g[X][Y] = 1
		if inp[i][j] == 'P':
			p[i][j] = 1
			for k in range(4):
				X = i + dx[k]
				Y = j + dy[k]
				if X >= 0 and Y >= 0 and X < n and Y < n:
					b[X][Y] = 1

for i in range(n):
	for j in range(n):
		print "(" + str(i+1) + "," + str(j+1) + ") S=" + str(s[n-1-j][i]) + \
		" B=" + str(b[n-1-j][i]) + " G=" + str(g[n-1-j][i]) + " W=" + str(w[n-1-j][i]) + \
		" P=" + str(p[n-1-j][i]) + " T=" + str(t[n-1-j][i])