#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <fstream>
#include <string>

using namespace std;
#define N 100200 
const int MAX = 20;

vector<int> gr[N];

// bridovi
void Add_edge(int x, int y)
{
	gr[x].push_back(y);
	gr[y].push_back(x);
}


int struk(int n)
{
	// pomocna varijabla za dulj ciklusa 
	int ans = INT_MAX;

	// za sve vrhove
	for (int i = 0; i < n; i++)
	{

		// neka je udaljenost max 
		vector<int> dist(n, (int)(1e9));
		vector<int> par(n, -1);

		// udaljenost od sourcea do sourcea je 0 
		dist[i] = 0;
		queue<int> q;

		// Push source 
		q.push(i);

		// Nastavi sve dok queue ne bude prazan 
		while (!q.empty())
		{

			// uzmi prvi
			int x = q.front();
			q.pop();

			// i idi po redu 
			for (int child : gr[x])
			{

				// ako nije jos posjecen, dist ++ 
				if (dist[child] == (int)(1e9)) 
				{
					dist[child] = 1 + dist[x];
					par[child] = x;
					q.push(child);
				}

				// ako vec je posjecen
				else if (par[x] != child and par[child] != x)
					ans = min(ans, dist[x] + dist[child] + 1);
			}
		}
	}

	// nema ciklusa 
	if (ans == INT_MAX)
		return -1;

	// ima ciklusa 
	else
		return ans;
}


int main()
{
	int rez;
	int i, j;

	ifstream stream;
	string fileName;
	cout << "Unesite ime datoteke: ";
	cin >> fileName;
	stream.open(fileName);

	int n = 0;
	stream >> n;
	int mat[MAX][MAX];
	stream.ignore(1, '\n');

	for ( i = 0; i < n; i++) {
		for ( j = 0; j < n; j++) {
			stream >> mat[i][j];
		}
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (mat[i][j] == 1)
				Add_edge(i, j);
		}
	}
	rez = struk(n);
	if (rez == -1)
		cout << "Graf nema ciklusa";
	else
		cout << "Minimalni ciklus grafa je " << rez;
	getchar();
	getchar();
	return 0;
}