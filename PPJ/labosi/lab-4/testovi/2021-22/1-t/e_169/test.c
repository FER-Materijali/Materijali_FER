void g(int g[]) {
    g[1] = g[1] + 10;
}

void f(int a[], int b) {
    a[1] = b;
    g(a);
}

int main(void) {
    int a[10] = {10, 10};
    int b = 7;
    f(a, b);
    return a[1];
}