#ifndef ABSTRACT_ANIMAL_H

#define ABSTRACT_ANIMAL_H

#include "Animal.h"

class AbstractAnimal : public Animal
{
public:
    virtual std::string const& name() const override;
    virtual std::string const& greet() const override;
    virtual std::string const& menu() const override;

    virtual ~AbstractAnimal() = default;

protected:
    AbstractAnimal(std::string const& name, std::string const& greet, std::string const& menu);

private:
    std::string name_;
    std::string greet_;
    std::string menu_;
};
#endif // !ABSTRACT_ANIMAL_H