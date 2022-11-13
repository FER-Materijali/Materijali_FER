//*****************************************************************IZVJEŠĆE ZA 3. PROJEKT IZ KOLEGIJA NMBP*************************************************************
//																	    Petar Ilijašić  0036470102

1. Zadatak (Minimalni portal temeljen na MongoDB (10 bodova))

Portal se pokreće na serveru koji je pokrenut na virtualnom stroju. Koristeći upute predmeta pokrenut je virtualni stroj i skripta za pokretanje sustava mongo
naredbom mongod -journal. Pomocu Puttya je nastavljen rad na mongo bazi podataka. S obzirom da su bili potrebni podaci, koristeći json generator (json-generator.com)
generirano je 13 članaka koji će se koristiti na portalu. Struktura jednog JSON zapisa izgleda ovako:

[
  '{{repeat(5, 12)}}',
  {
    _id: '{{objectId()}}',
    index: '{{index()}}',
    guid: '{{guid()}}',
    slika: 'http://placehold.it/32x32',
    naslov: '{{firstName()}}',
    sadrzaj: '{{lorem(1, "paragraphs")}}',
    datumClanka: '{{date(new Date(2014, 0, 1), new Date(), "YYYY-MM-ddThh:mm:ss Z")}}',
    
    komentari: [
      '{{repeat(3)}}',
      {
        datum: '{{date(new Date(2014, 0, 1), new Date(), "YYYY-MM-ddThh:mm:ss Z")}}',
        id: '{{index()}}',
        komentar: '{{firstName()}} {{surname()}}'
      }
    ]
  }
]

Koristeći naredbu db.vijesti.insert{[...]} uneseni su JSON zapisi u bazu podataka, čime je kreirana kolekcija "vijesti".
S obzirom da u CentOS-u nije bio integriran php driver, ručno je instaliran u sustav (jer za izradu portala je korišten programski jezik PHP,
čije skripte ne bi funkcionirale niti bi spajanje na mongo bazu bilo uspješno bez PHP drivera). Nakon što je apache server pokrenut na virtualnom stroju,
u browseru je potrebno upisati sljedeći URL:
192.168.56.12/Projekt3/

Na taj način se otvara portal. Portal se sastoji od skripte za povezivanje sa bazom, index.php i za dodavanje komentara.
S obzirom da je potreban ispis članaka kronološki, kreiran je index s obzirom na datum objave članka.

db.vijesti.createIndex({datumClanka: -1});

U skripti za povezivanje sa bazom se omogućuje stvaranje veze između index.php i mongo baze podataka tako što se instancirao MongoClient.
Koristeći foreach petlju prolazilo se kroz podatke u kolekciji i na taj način se kreirao zaseban div koji je sadržavao po jedan JSON objekt u kojem je
jedna vijest.

Činjenica da svaki JSON objekt ima svoj _id olakšava dodavanje komentara u specifični članak. Prilikom POST metode u PHP-u osim sadržaja također se 
prosljeđuje hidden _id tog članka tako da je lakše odrediti o kojem se članku radi i pritom je lakše dodati novi komentar u polje komentara
(pogledati strukturu JSON objekta).

2. Zadatak (MapReduce upiti)

//prvi zadatak

var map =  function() {
    emit(this._id, this.komentari.length);
};

var reduce = function(key, valuesComments) {
	return valuesComments;
}; 

db.vijesti.mapReduce(
 map,
 reduce,
 { out: "mr_komentari" }
 ) 

db.mr_komentari.find().sort({value: -1})


//drugi zadatak
var map = function() {  
    var sadrzaj = this.sadrzaj;
    sadrzaj = sadrzaj.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g,"");
    sadrzaj = sadrzaj.replace(/\s{2,}/g," ");
    if (sadrzaj) { 
        sadrzaj = sadrzaj.toLowerCase().split(" "); 
        for (var i = sadrzaj.length - 1; i >= 0; i--) {           
            if (sadrzaj[i])  {      
               emit(this._id, sadrzaj[i]); 
            }
        }
    }
};

var reduce = function(key, values) {
	var obj = { };
	var rv = { };
	var sorted = [];
	for (var i = 0, j = values.length; i < j; i++) {
	   obj[values[i]] = (obj[values[i]] || 0) + 1;
	}
	//sortiranje po vrijednosti
	for(var rijec in obj){
      sorted.push([rijec, obj[rijec]])
    }
	sorted.sort(function(a, b) {return a[1] - b[1]})

	var tenWords = sorted.length - 11;
	//ispis 10 najcescih rijeci u objekt
	for (var i = sorted.length-1; i > tenWords; --i)
    	rv[i] = sorted[i];
    return rv;
}; 

db.vijesti.mapReduce(map, reduce, {out: "word_count"})
