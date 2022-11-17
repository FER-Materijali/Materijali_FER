int main(void) {
    int x = 10;
    int y = 0;
    for (;;x--) {
        y = y + x;
        if (x == 0) break;
    }
    return y;
}