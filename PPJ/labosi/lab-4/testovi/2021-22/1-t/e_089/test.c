int main(void) {
    int x = 1, y = 2, z[5] = {1,2,3,4,5};
    x = y = z[0] = z[1] = z[3] = 12;
    return z[3];
}