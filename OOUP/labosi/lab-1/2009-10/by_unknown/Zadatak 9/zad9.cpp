#include <iostream>
#include <string>

void otvoriDialog() {
     char s[3];
     std::cout << "Unesi brojeve: ";     
     gets(s);
     std::cout<<"Uneseno je: ";
     for(int i=0;i<3;i++)
     std::cout<<s[i];
}

void otvoriDialog2() {
     char mystring [5];
     std::cout << "Unesi brojeve: ";     
     fgets (mystring , 5 , stdin);
     std::cout<<"Uneseno je: ";
     for(int i=0;i<3;i++)
     std::cout<<mystring[i];
}

void otvoriDialog3() {
     std::string str;
     std::cout << "Unesi brojeve: ";
     getline (std::cin,str);
     std::cout << "Uneseno je: " << str << "\n";
}

int main() {
 
    //otvoriDialog();   
    //otvoriDialog2(); 
    otvoriDialog3();
}
