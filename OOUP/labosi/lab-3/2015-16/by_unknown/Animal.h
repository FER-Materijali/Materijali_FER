#ifndef ANIMAL_H

#define ANIMAL_H

#include <string>

class Animal
{
public:
    virtual std::string const& name() const = 0;
    virtual std::string const& greet() const = 0;
    virtual std::string const& menu() const = 0;

    virtual ~Animal() = default;
};

#endif // !ANIMAL_H