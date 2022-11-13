package napredbebaze4
import groovy.sparql.*
class MyController {

    def index() {

        // SPARQL 1.0 or 1.1 endpoint
        def sparql = new Sparql(endpoint: "http://localhost:3030/ds/sparql")

        def query = "SELECT (COUNT(*) AS ?ukupnoTrojki)\n" +
                "WHERE {\n" +
                "?s ?p ?o\n" +
                "}"

        // sparql result variables projected into the closure delegate
        String ukTrojki = ""
        sparql.each query, {
            ukTrojki = "${ukupnoTrojki}"
        }

        query = "PREFIX movie: <http://data.linkedmdb.org/resource/movie/>\n" +
                "SELECT (COUNT(*) AS ?brFilmova1) WHERE {\n" +
                "?movie a movie:film\n" +
                "}"

        String brFilmova = ""
        sparql.each query, {
            brFilmova = "${brFilmova1}"
        }

        query = "PREFIX movie: <http://data.linkedmdb.org/resource/movie/>\n" +
                "SELECT (COUNT(*) AS ?brojFilmova)\n" +
                "WHERE {\n" +
                "?movie movie:genre ?genre .\n" +
                "?genre movie:film_genre_name ?gname .\n" +
                "VALUES ?gname {\"Action\"}\n" +
                "}"

        String brojAkcijskih = ""
        sparql.each query, {
            brojAkcijskih = "${brojFilmova}"
        }

        query = "PREFIX movie: <http://data.linkedmdb.org/resource/movie/>\n" +
                "PREFIX dc: <http://purl.org/dc/terms/>\n" +
                "SELECT (COUNT(*) AS ?brojFilmova)\n" +
                "WHERE {\n" +
                "?movie movie:actor ?actor .\n" +
                "?movie dc:date ?date .\n" +
                "\n" +
                "FILTER(?date>\"2000-01-01\" && ?date<\"2001-12-31\")\n" +
                "}"

        String brojFilmovaOveGodine = ""
        sparql.each query, {
            brojFilmovaOveGodine = "${brojFilmova}"
        }


        query = "PREFIX movie: <http://data.linkedmdb.org/resource/movie/>\n" +
                "PREFIX dc: <http://purl.org/dc/terms/>\n" +
                "SELECT distinct ?title \n" +
                "WHERE {\n" +
                "?movie dc:title ?title .\n" +
                "}\n" +
                "ORDER BY RAND() LIMIT 3"

        def randFilmovi = []
        sparql.each query, {
            randFilmovi.add("${title}")
        }

        [ukTrojkiInView: ukTrojki, brFilmovaInVIew: brFilmova, brojAkcijskihInView: brojAkcijskih, brojFilmovaOveGodineInView: brojFilmovaOveGodine, randFilmoviInView: randFilmovi]
    }

    def showMovie() {
        def movieTitle = params.id
        def myListOfLists = []
        def sparql = new Sparql(endpoint: "http://localhost:3030/ds/sparql")
        def query = "PREFIX movie: <http://data.linkedmdb.org/resource/movie/>\n" +
                "PREFIX dc: <http://purl.org/dc/terms/>\n" +
                "SELECT distinct ?title ?genreName ?dirName ?editorName ?date \n" +
                "WHERE {\n" +
                "?movie dc:title ?title .\n" +
                "?movie movie:genre ?genre.\n" +
                "?genre movie:film_genre_name ?genreName.\n" +
                "?movie movie:director ?director.\n" +
                "?director movie:director_name ?dirName.\n" +
                "?movie movie:editor ?editor.\n" +
                "?editor movie:editor_name ?editorName.\n" +
                "?movie dc:date ?date \n" +
                "FILTER REGEX (?title, \"" +
                movieTitle +
                "\", \"i\")\n." +
                "}\n" +
                "ORDER BY ASC(?title)"
        sparql.each query, {
            def myList = []
            myList.add("${title}")
            myList.add("${genreName}")
            myList.add("${dirName}")
            myList.add("${editorName}")
            myList.add("${date}")

            myListOfLists.add(myList)
        }

        [myListOfListsInView: myListOfLists]
    }

    def showActor(){
        def actorName = params.id
        def myListOfLists = []
        def sparql = new Sparql(endpoint: "http://localhost:3030/ds/sparql")
        def query = "PREFIX lmdb: <http://data.linkedmdb.org/resource/movie/>\n" +
                "PREFIX dcterms: <http://purl.org/dc/terms/>\n" +
                "PREFIX dbpo: <http://dbpedia.org/ontology/>\n" +
                "PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema#>\n" +
                "PREFIX owl: <http://www.w3.org/2002/07/owl#>\n" +
                "PREFIX foaf: <http://xmlns.com/foaf/0.1/>\n" +
                "SELECT ?dbpediaUrl ?title ?date ?abstractE ?runtime ?wikiPage \n" +
                "WHERE {\n" +
                "?actor lmdb:actor_name \"" +
                actorName +
                "\".\n" +
                "?movie lmdb:actor ?actor .\n" +
                "?movie dcterms:title ?title .\n" +
                "?movie dcterms:date ?date .\n" +
                "?movie owl:sameAs ?dbpediaUrl .\n" +
                "FILTER( REGEX( STR(?dbpediaUrl), \"dbpedia\")) .\n" +
                "SERVICE <http://dbpedia.org/sparql>\n" +
                "{\n" +
                "?dbpediaUrl a dbpo:Film .\n" +
                "?dbpediaUrl foaf:isPrimaryTopicOf ?wikiPage .\n" +
                "?dbpediaUrl dbpo:abstract ?abstractE .\n" +
                "?dbpediaUrl dbpo:runtime ?runtime .\n" +
                "FILTER(lang(?abstractE) = \"en\")\n" +
                "}\n" +
                "}"
        sparql.each query, {
            def myList = []
            myList.add("${title}")
            myList.add("${date}")
            myList.add("${abstractE}")
            myList.add("${runtime}")
            myList.add("${wikiPage}")

            myListOfLists.add(myList)
        }

        [myListOfListsInView: myListOfLists]
    }

    def listMovies(){
        def searchTerm = params.query
        def myList = []
        def sparql = new Sparql(endpoint: "http://localhost:3030/ds/sparql")
        def query = "PREFIX movie: <http://data.linkedmdb.org/resource/movie/>\n" +
                "PREFIX dc: <http://purl.org/dc/terms/>\n" +
                "SELECT DISTINCT ?title \n" +
                "WHERE {\n" +
                "?movie dc:title ?title .\n" +
                "FILTER regex(?title, \"" +
                searchTerm +
                "\", \"i\")\n" +
                "}\n" +
                "ORDER BY ASC(?title)"
        sparql.each query, {
            myList.add("${title}")
        }
        [taskInstanceList: myList]
    }

    def listActors(){
        def searchTerm = params.query
        def myList = []
        def sparql = new Sparql(endpoint: "http://localhost:3030/ds/sparql")
        def query = "PREFIX lmdb: <http://data.linkedmdb.org/resource/movie/>\n" +
                "SELECT DISTINCT  ?actorName\n" +
                "WHERE {\n" +
                "?movie lmdb:actor ?personURI .\n" +
                "?personURI lmdb:actor_name ?actorName\n" +
                "FILTER regex(?actorName, \"" +
                searchTerm +
                "\", \"i\")\n" +
                "}\n" +
                "ORDER BY ASC(?actorName)"
        sparql.each query, {
            myList.add("${actorName}")
        }
        [taskInstanceList: myList]
    }
}
