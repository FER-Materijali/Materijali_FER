int main(void) {
    int x;
    {
        int s;
        int w = 1;
        int z[5] = {2, 3};
        int u[5] = {w, u[0] + 1, u[1]};
        char c[7] = "ab";
        s = z[1];
        x = s;
    }
    return x;
}