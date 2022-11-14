#include <cstdio>

namespace
{
    class Base
    {
        public:
            Base() 
            {
                metoda();
            }

            virtual void virtualnaMetoda() 
            {
                printf("ja sam bazna implementacija!\n");
            }

            void metoda() 
            {
                printf("Metoda kaze: ");
                virtualnaMetoda();
            }
    };

    class Derived : public Base
    {
        public:
            Derived() : Base() 
            {
                metoda();
            }

            virtual void virtualnaMetoda() 
            {
                printf("ja sam izvedena implementacija!\n");
            }
    };
}

int main()
{
    Derived* pd = new Derived();
    pd->metoda();

    return 0;
}