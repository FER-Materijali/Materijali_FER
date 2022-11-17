int main(void) {
    int x = 10;
    int y = 1;
    while (1) {
        int z = 0;
        {
            y = y * x;
            x--;
            if (x == 8) break;
        }
    }
    return y;
}