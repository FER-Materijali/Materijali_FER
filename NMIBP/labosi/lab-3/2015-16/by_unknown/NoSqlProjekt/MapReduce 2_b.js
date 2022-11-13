
var map = function() {
	var words = this.text.split(' ');
	if(words){
		for(var i=0; i<words.length; i++){
			var value = {word: words[i], count:1}
			emit(this.author, value);
		}
	}
};

var reduce = function(key, values) {
	var reduceValue = {
		words:[]
	};
	//imamo listu riječi da znamo kada se počnu ponavljati
	var words = [];
	//dictionary koji ima {riječ, ponavljanje} u sebi
	var countedList = [];
	values.forEach( function(value) {
		//ako je već ponovljena riječ
		if( words.indexOf(value.word) > -1){
		for(var i=0; i<countedList.length; i++){
			if(countedList[i].word === value.word)
				countedList[i].count += 1;
		}
		//ako se prvi put pojavljuje
		}else{
			words.push(value.word);
			countedList.push({word: value.word, count:value.count});
		}
	});
	//soritramo listu tako da su najčešće riječi na vrhu
	countedList = countedList.sort(function(a,b){
		return b.count-a.count;
	});
	reduceValue.words = countedList
	return reduceValue;
};

var fin = function(key, reducedVal){
		var counter = 1;
		var finVal = [];
	//uzimamo 10 najčešćih riječi
	for(var i =0; i<reducedVal.words.length; i++){
		if(counter <11){
			finVal.push(reducedVal.words[i].word);
		}else{
			break;
		}
		counter +=1;
	};
	return finVal;
}

db.articles.mapReduce(
	map,
	reduce,
	{ out: "mr_author",
	finalize:fin
	});