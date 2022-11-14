#include <iostream>

#include "Animal.h"
#include "Factory.h"

void print_greeting(Animal const& animal);
void print_menu(Animal const& animal);

int main()
{
    auto& factory = Factory<Animal>::instance();
    for (auto const& id : factory.ids()) {
        auto animal = factory.create(id, "Ljubimac " + id);
        print_greeting(*animal);
        print_menu(*animal);
    }

    system("pause");
}

void print_greeting(Animal const& animal)
{
    std::cout << animal.name() << " pozdravlja: " << animal.greet() << "\n";
}

void print_menu(Animal const& animal)
{
    std::cout << animal.name() << " voli: " << animal.menu() << "\n";
}
