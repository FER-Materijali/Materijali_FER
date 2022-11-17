void f(int a[], int b) {
    a[1] = b;
}

int main(void) {
    int a[10] = {10, 10};
    int b = 7;
    f(a, b);
    return a[1];
}