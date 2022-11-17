void f(int a[], int b) {
    void g(int z[]);
    a[1] = b;
    g(a);
}

void g(int g[]) {
    g[1] = g[1] + 10;
}

int main(void) {
    int a[10] = {10, 10};
    int b = 7;
    f(a, b);
    return a[1];
}