int main(void) {
    int f(int a, int b);
    int x = f(10, 20);
    return x;
}

int f(int z, int w) {
    return z + w;
}