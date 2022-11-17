// Kolika je veličina ulazne abecede? Prema zadatku, ovo je 3.
#define VELICINA_ABECEDE 3

// Korišteno prilikom aritmetičkog kodiranja i dekodiranja.
// Svaki simbol je zastupljen svojim rasponom između 0.0 i 1.0.
// Što je raspon veći, to je veća vjerojatnost njegovog generiranja.
const double GRANICE[] = { 0.0, 0.2, 0.4, 1.0 };

// Koliko ćemo simbola generirati? Prema zadatku, ovo je 10000.
#define BROJ_SIMBOLA 10000

// Vjerojatnost pogreške u prijenosu jednog bita.
#define ERROR_PROB 0.1


// Prilikom razlamanja poruka radi aritmetičkog kodiranja, koliko
// će te poruke biti velike?
#define VELICINA_PORUKE 5

// Ovo mora biti cijeli broj.
#define BROJ_PORUKA (BROJ_SIMBOLA / VELICINA_PORUKE)

// Kolike će veličine biti najveća kodna riječ nakon aritmetičkog
// kodiranja? Premala - dolazi do grešaka pri prijenosu čak i ako
// nema smetnji nad kanalom, jer se gubi informacija zbog nedovoljne
// preciznosti koju nudi ta premalena količina bitova. 13 je donje
// ograničenje ukoliko je VELICINA_PORUKE 5.
#define VELICINA_KODIRANE 18


// Sveukupna duljina poruke kodirane Hammingovim kodom.
#define HAM_DULJINA 13

// Broj informacijskih bitova unutar te poruke.
#define HAM_INF_BITOVI 9

// Broj zaštitnih bitova unutar te poruke.
#define HAM_ZAS_BITOVI (HAM_DULJINA - HAM_INF_BITOVI)

// Koliko će poruka kodirati Hammingov koder?
#define HAM_BROJ_PORUKA ((BROJ_PORUKA * VELICINA_KODIRANE) / HAM_INF_BITOVI)

// Koliko će bitova pročitati Hammingov koder i zapisati Hammingov dekoder?
#define HAM_INPUT_BITOVA (HAM_BROJ_PORUKA * HAM_INF_BITOVI)

// Koliko će bitova zapisati Hammingov koder i pročitati Hammingov dekoder?
#define HAM_OUTPUT_BITOVA (HAM_BROJ_PORUKA * HAM_DULJINA)

// Koliko će zadnjih ulaznih bitova zanemariti Hammingov koder?
#define HAM_IGNORIRANI (BROJ_PORUKA*VELICINA_KODIRANE - HAM_INPUT_BITOVA)
