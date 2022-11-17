#include <stdio.h>
int currentState=1;
struct STATES
{
	char ime[6];
	int jelDozvoljeno;
	int nextState[6];

} states[25]={  {"q1"},
		{"q0",   0,0,0,0,2,3,4},
		{"A",    0,5,6,7},
		{"B",    0,8,9,10},
		{"C",    0,11,12,13},
		{"A1",   1,0,0,0,0,14,15},
		{"A2",   1,0,0,0,0,0,16},
		{"A3",   1,0,0,0,0,17,15},
		{"B1",   1,0,0,0,18,0,19},
		{"B2",   1},
		{"B3",   1,0,0,0,20,0,21},
		{"C1",   1,0,0,0,22,14},
		{"C2",   1,0,0,0,23},
		{"C3",   1,0,0,0,22,17},
		{"A-C1B",0,0,0,10},
		{"A1-3C",0,0,12},
		{"A2C",  0,11,0,13},
		{"A-C3B",0,8},
		{"B1A",  0,0,0,7},
		{"B1C",  0,0,0,13},
		{"B3A",  0,5},
		{"B3C",  0,11},
		{"C1-3A",0,0,6},
		{"C2A",  0,5,0,7},
};
void automat(char c);
int main()
{
	FILE *f;
	char c,i;
	f=fopen("input.txt","r");
	while(fscanf(f,"%c",&c)!=EOF)
	{
		if(c==\\' \\' || c==\\'\n\\' || c==\\'\t\\')
		{
			printf("\n+++++++++++++++\nnovi niz\n");
			currentState=1;
			continue;
		}
		automat(c);
	}
	getchar();
	return 0;
}
void automat(char c)
{
	int input;
	input=(c>\\'3\\')?c-62:c-49;
	printf("\ntrenutno se ucitava:%c\n",c);
	printf("trenutno stanje:%s\n",states[currentState].ime);
	printf("prijelaz:(%s,%c)=%s\n",states[currentState].ime,c,states[states[currentState].nextState[input]].ime);
	currentState=states[currentState].nextState[input];
	printf("novo stanje:%s\n",states[currentState].ime);
	if(states[currentState].jelDozvoljeno==0)
		printf("niz se ne prihvaca\n");
	else printf("niz se prihvaca\n");
}