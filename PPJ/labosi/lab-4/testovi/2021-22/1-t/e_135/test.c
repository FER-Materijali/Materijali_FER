int main(void) {
    int a = 3, x[5] = {1, x[0] + 3, x[1] * 7, x[2] - a, x[3]};
    return x[4];
}