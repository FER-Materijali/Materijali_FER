var map = function () {
    var words = this.text.split(' ');
    for (var i = 0; i < words.length; i++) {
        emit(this.author, words[i]);
    }
};

var reduce = function (key, values) {
    var rv = {
        words: []
    };

    var words = [];
    var words_dict = [];
    values.forEach(function (value) {
        if (words.indexOf(value) > -1) {
            for (var i = 0; i < words_dict.length; i++) {
                if (words_dict[i].word === value)
                    words_dict[i].count += 1;
            }
        } else {
            words.push(value);
            words_dict.push({ word: value, count: 1 });
        }
    });
    words_dict.sort(function (a, b) { return b.count - a.count; });
    rv.words = words_dict
    return rv;
};

var fin = function (key, reducedVal) {
    var rv = [];
    for (var i = 0; i < 10; i++) {
        rv.push(reducedVal.words[i].word);
    }
    return rv;
}

db.news.mapReduce(
	map,
	reduce,
	{
	    out: "mr_author",
	    finalize: fin
	});

db.mr_author.find();