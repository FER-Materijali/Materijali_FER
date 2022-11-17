int main(void) {
    int x;
    int y = 0;
    for (x = 0; x <= 10;) {
        int a = 10;
        {
            x++;
            if (x > 4) continue;
            y = y + x;
        }
    }
    return y;
}