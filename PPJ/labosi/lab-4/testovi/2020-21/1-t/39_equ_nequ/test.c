int main(void){
    int a = 5 == 4;
    int b = 8 == a;
    int c = 0 != 0;
    int d = 2 != 6;

    return (a == b == c) != d;
}