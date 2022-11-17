int a[5] = {1, 2, 4, 5};

int zbroji(int polje[]) {
    int zb;
    zb = polje[1];
    zb = zb + polje[2];
    return zb;
}

int main(void){
    return zbroji(a);
}