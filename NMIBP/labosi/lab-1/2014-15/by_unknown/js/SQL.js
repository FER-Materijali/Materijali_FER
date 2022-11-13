function SQL()
{
    var op1 = $("#ili")[0].checked ? " | " : " &   ";
    var op2 = $("#ili")[0].checked ? " OR " : " AND ";

    var tokeni = document.getElementById("pretraga").value.match(/(\"[^\"]+\"|[^ ]+)/g);
    var q1 = "";
    for (i in tokeni) {
        if (tokeni[i].indexOf(' ') === -1) {
            if (q1.length == 0) q1 += tokeni[i];
            else q1 += " " + op1 + " " + tokeni[i];
        } else {
            if (q1.length > 0) q1 += " " + op1 + " ";
            q1 += "(";
            var subtokeni = tokeni[i].split(" ");
            for(j in subtokeni) {
                var subtoken = subtokeni[j];
                subtoken = subtoken.replace('\"','');
                if (j == 0) {
                    q1 += subtoken;
                } else q1 += " & " + subtoken;
            }
            q1 += ")";
        }
    }

    var q = "";
    var q2 = "";
    if(document.getElementById("fuzzy").checked) {
        for (i in tokeni) {
            var token = tokeni[i].replace("\"", "");
            if (token.substring(token.length-1) == "\"") {
                token = token.substring(0, token.length-1);
            }
            if(q2.length == 0) {
                q2 = "serija_naziv % '" + token + "'";
            } else {
                q2 +=  op2 + " serija_naziv % '" + token + "'";
            }
        }
        // sa slajdova
        q = "select serija_id,\n ts_headline(serija_naziv, to_tsquery('english', '" + q1 + "')),\n serija_naziv,\n"
            + "ts_rank(naziv_tsvector, to_tsquery('" + q1 + "')) rank\n from serije\n where " + q2
            + "\n order by rank DESC";
    }
    else if (document.getElementById("rjecnik").checked) {
        for (i in tokeni) {
            var token = tokeni[i].replace("\"", "");
            if (token.substring(token.length-1) == "\"") token = token.substring(0, token.length-1);
            var sadrzi_space = token.indexOf(' ') === -1;
            if(sadrzi_space) {
                if(q2.length == 0) q2 = "naziv_tsvector @@ to_tsquery('english', '" + token + "')";
                else q2 += op2 + "naziv_tsvector @@ to_tsquery('english', '" + token + "')";
            }
            else {
                if (q2.length > 0) q2 += op2 + "naziv_tsvector @@ to_tsquery('english', '";
                else q2 += " naziv_tsvector @@ to_tsquery('english', '";

                var elementi = token.split(" ");
                for(j in elementi) {
                    var subtoken = elementi[j].replace('\"','');
                    if (j == 0)  q2 += subtoken;
                    else q2 += " & " + subtoken;
                }
                q2 += "')";
            }
        }
        // sa slajdova
        q = "select serija_id,\n ts_headline(serija_naziv, to_tsquery('english', '" + q1 + "')),\n serija_naziv,\n"
            + "ts_rank(naziv_tsvector, to_tsquery('english', '" + q1 + "')) rank\n from serije\n where " + q2
            + "\n order by rank DESC";
    }
    else if(document.getElementById("identicni").checked) {
        for (i in tokeni) {
            var token = tokeni[i].replace("\"", "");
            if (token.substring(token.length-1) == "\"") {
                token = token.substring(0, token.length-1);
            }
            if(q2.length == 0)  q2 = "serija_naziv LIKE '%" + token + "%'";
            else  q2 += op2 + " serija_naziv LIKE '%" + token + "%'";
        }
        // sa slajdova
        q = "select serija_id,\n ts_headline(serija_naziv, to_tsquery('english', '" + q1 + "')),\n serija_naziv,\n"
            + "ts_rank(naziv_tsvector, to_tsquery('english', '" + q1 + "')) rank\n from serije\n where " + q2
            + "\n order by rank DESC";
    }
    document.getElementById("sql").value = q;
}