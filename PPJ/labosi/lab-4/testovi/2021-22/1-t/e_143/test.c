int main(void) {
    int x;
    {
        int w = 1;
        int z[5] = {2, 3};
        int u[5] = {w, u[0] + 1, u[1]};
        char c[7] = "ab";
        x = u[0];
    }
    return x;
}