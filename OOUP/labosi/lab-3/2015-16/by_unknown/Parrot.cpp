#include "Parrot.h"

int Parrot::hreg = Factory<Animal>::instance().register_creator("Parrot", creator);

std::unique_ptr<Animal> Parrot::creator(std::string const& name)
{
    return std::make_unique<Parrot>(name);
}

Parrot::Parrot(std::string const& name)
    : AbstractAnimal(name, "Sto mu gromova!", "brazilske orahe")
{
    ;
}