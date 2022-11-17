int main(void) {
    int x = 10;
    int y = 0;
    while (x > 0) {
        x--;
        if (x > 5) continue;
        y = y + x;
    }
    return y;
}