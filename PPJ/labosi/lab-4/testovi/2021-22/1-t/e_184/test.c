int main(void) {
    int x;
    int y = 0;
    for (x = 0; x <= 10; x++) {
        int a = 10;
        {
            if (x > 5) break;
            y = y + x;
        }
    }
    return y;
}