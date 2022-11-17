void h(int z[]) {
    z[1] = z[1] % 6;
}

void g(int b[]) {
    b[1] = b[1] + 10;
    h(b);
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