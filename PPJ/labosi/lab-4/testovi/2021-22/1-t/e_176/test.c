int main(void) {
    int x = 10;
    int y = 0;
    while (x >= 0) {
        if (x <= 5) break;
        y = y + x;
        x--;
    }
    return y;
}