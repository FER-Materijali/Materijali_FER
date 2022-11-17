int f(int a) {
    if (a <= 0) return 0;
    return 1 + f(a - 1);
}

int main(void) {
    return f(10);
}