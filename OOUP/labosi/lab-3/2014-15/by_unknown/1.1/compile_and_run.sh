gcc main.c myfactory.c -ldl
gcc -shared parrot.c -o parrot.so -fPIC
gcc -shared tiger.c -o tiger.so -fPIC
./a.out
