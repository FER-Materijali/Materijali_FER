int x=32;

int prva(int b){
    return b+1;
}

int druga(int a, int b){
    return b-a;
}

int main(void){
    return prva(7) + ((druga(1,3))) -5;
}