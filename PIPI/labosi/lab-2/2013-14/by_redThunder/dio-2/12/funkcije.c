#include "funkcije.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int trazi ( char *s ){
	int i, koliko, pom1, freq[256]={0};
	char pom2, znak;
	struct slova{
		char ch; /*o kojem slovu se radi*/
		int hm; /*koliko puta se pojavljuje u tekstu*/
	} polje[2];
	polje[0].ch=' '; polje[0].hm = 0;
	polje[1].ch=' '; polje[1].hm = 0;

	for( i=0; s[i] ; i++ ){
		if( !isalpha(s[i]) ) continue;
		znak = toupper( s[i] );
		koliko = ++freq[ (int) znak ];

		if ( koliko > polje[0].hm ){
			if ( znak == polje[0].ch ){
				++polje[0].hm;
				continue;
			}
			
			pom1 = polje[0].hm;
			pom2 = polje[0].ch;
			polje[0].hm = koliko;
			polje[0].ch = znak;
			polje[1].hm = pom1;
			polje[1].ch = pom2;
		}
		else if ( koliko > polje[1].hm ){
			polje[1].hm = koliko;
			polje[1].ch = znak;
		}
	}

	if ( ( polje[0].ch == 'A' && polje[1].ch == 'I' ) || ( polje[0].ch == 'I' && polje[1].ch == 'A' ) ) return 1;
	if ( ( polje[0].ch == 'T' && polje[1].ch == 'E' ) || ( polje[0].ch == 'E' && polje[1].ch == 'T' ) ) return 2;
	if ( ( polje[0].ch == 'N' && polje[1].ch == 'E' ) || ( polje[0].ch == 'E' && polje[1].ch == 'N' ) ) return 3;

	return 0;
}