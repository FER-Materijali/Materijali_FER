int main(void){
    int a = 7;
    int b = 9;
    int fja(int c);
    b = a+b;
    b++;
    fja(a);
    return fja(a) + fja(b);
}

int fja(int c){
    return c-1;
}