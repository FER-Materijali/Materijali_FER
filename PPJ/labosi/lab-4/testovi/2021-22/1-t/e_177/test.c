int main(void) {
    int x = 10;
    int y = 0;
    for (;x >= 0;x--) {
        if (x < 5) break;
        y = y + x;
    }
    return y;
}