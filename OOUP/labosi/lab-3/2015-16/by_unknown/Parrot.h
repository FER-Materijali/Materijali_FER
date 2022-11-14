#ifndef PARROT_H

#define PARROT_H

#include <memory>

#include "AbstractAnimal.h"
#include "Factory.h"

class Parrot : public AbstractAnimal
{
public:
    static std::unique_ptr<Animal> creator(std::string const& name);

    Parrot(std::string const& name);

    virtual ~Parrot() = default;
private:
    static int hreg;
};
#endif // !PARROT_H