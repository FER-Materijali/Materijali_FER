int main(void) {
    int x = 11;
    int y = 1;
    while (x > 0) {
        int z = 0;
        {
            x--;
            if (x <= 8) continue;
            y = y * x;
        }
    }
    return y;
}