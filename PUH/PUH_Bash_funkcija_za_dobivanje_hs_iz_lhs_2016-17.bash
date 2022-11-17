function hsFromLhs() {
    cat $1 | sed 's/^[[:space:]]*>[[:space:]]/~/' | sed 's/^[^~]/-- &/' | sed 's/^~//' > output.hs
}