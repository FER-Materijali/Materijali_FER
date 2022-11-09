def add_edge(edge1: int, edge2: int, edge_list: int) -> bool:
    try:
        edge_list.append((edge1, edge2))
        return True
    except:
        return False

#bruteforce search
f=lambda n,e,m=1:any(all(t*m//m**a%m!=t*m//m**b%m for(a,b)in e)for t in range(m**n))and m or f(n,e,m+1)

if __name__ == "__main__":
    filename = input("Unesite ime datoteke: ")
    mat = []
    upis =[] #novo
    with open(filename, 'r') as file:
        n = int(file.readline())
        file.readline() # skip newline
        for _ in range(n):
            mat.append(list(map(int, file.readline().split(' '))))

    for i, row in enumerate(mat):
        for j, elem in enumerate(row):
            if elem == 1:
                add_edge(i, j, upis) #novi poziv

    print (f(n, upis))