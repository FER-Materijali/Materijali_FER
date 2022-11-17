int main(void) {
    int i = 10;
    int x = 0;
    while (i > 0) {
        x = x + i--;
    }
    return x;
}