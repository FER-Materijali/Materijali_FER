int zbroji(int polje[]) {
    int zb;
    zb = polje[1];
    zb = zb + polje[2];
    return zb + polje[3];
}

int main(void){
    int a[5] = {1, 2, 3, 4, 5};

    return zbroji(a);
}