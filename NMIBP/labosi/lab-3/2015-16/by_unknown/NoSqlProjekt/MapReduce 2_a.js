//brojimo koliko ima komentara po članku, tj. "printamo" 1 
//kada god naiđemo na komentar 
var map = function() {
	if (this.comment !== undefined){
		var count = 0;
	this.comment.forEach( function(comment) {
		count +=1;
	});
	emit(this._id, count);
	//ili stavimo headline ako želimo baš naslov, ali je jako neuredno
	}
};

//ovdje zbrajamo vrijednosti koje smo gore izbacili
var reduce = function(key, values) {
	var rv = {
		comment: key,
		count:0
	};
	values.forEach( function(value) {
		rv.count += value.count;
	});
	return rv;
};

db.articles.mapReduce(
	map,
	reduce,
	{ out: "mr_comment"});
	
db.mr_comment.find().sort({value:-1})
db.articles.find({comment: {$exists:true}}, {picture:0, text:0, headline:0}).pretty();