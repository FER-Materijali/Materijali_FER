#include "Tiger.h"

int Tiger::hreg = Factory<Animal>::instance().register_creator("Tiger", creator);

std::unique_ptr<Animal> Tiger::creator(std::string const& name)
{
    return std::make_unique<Tiger>(name);
}

Tiger::Tiger(std::string const& name)
    : AbstractAnimal(name, "Mijau!", "mlako mlijeko")
{
    ;
}
