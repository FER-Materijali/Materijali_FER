int main(void) {
    int x = 10;
    int y;
    for (y = 0; x > 0;) {
        x--;
        if (x > 5) continue;
        y = y + x;
    }
    return y;
}