Ovo su rješeni zadaci 1. skupine zadataka za 2. labos iz PPI-a 2013./2014.

Zadatke nisam posebno testirao, ak su radili njihovi primjeri, smatrao sam da rade svi.
Rjesavao sam na brzinu, tak da molim Vas nemojte mi slati poruke/komentare tipa "u if-u trebaš staviti <1 a ne <0".
Ako baš ima većih problema sa zadatkom, npr da skroz krivo radi, onda me obavijestite.

Nisam znao da li smijemo koristiti neke od funkcija koje sam koristio.
Npr one iz ctype.h (isdigit, isalnum ...). Sve te funkcije nalaze se na refrence cardu pa sam zaključio da se smije.
Ali one se i lako napišu, bez da se koristi ctype.h tak da tu nebi trebalo bit puno problema.
Iz string.h mislim da sam koristio samo strlen u dosta zadataka, a u zadnjem sam koristio i strcpy za kopiranje stringova.
To se isto na lagan način može izvesti (uz uvjet da je zabranjeno koristenje string.h funkcija)

primjer za isdigit:

```
int isdigit( char x ){
	if ( x>='0' && x<='9' ) return 1;
	return 0;
}
```

primjer za strlen:

```
int strlen( char *str ){
	int len = 0;
	while( *(str+len++) != '\0' );
	return len;
}
```

i tako dalje...

Vjerojatno ću sutra rješavati drugu skupinu zadataka, tak da očekujte navečer, najkasnije u ponedjeljak.

Do slušanja, peace