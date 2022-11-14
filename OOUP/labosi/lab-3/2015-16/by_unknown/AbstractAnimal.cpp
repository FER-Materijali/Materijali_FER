#include "AbstractAnimal.h"

std::string const& AbstractAnimal::name() const
{
    return name_;
}

std::string const& AbstractAnimal::greet() const
{
    return greet_;
}

std::string const& AbstractAnimal::menu() const
{
    return menu_;
}

AbstractAnimal::AbstractAnimal(std::string const& name, std::string const& greet, std::string const& menu)
    : Animal(),
    name_{name},
    greet_{greet},
    menu_{menu}
{
    ;
}
