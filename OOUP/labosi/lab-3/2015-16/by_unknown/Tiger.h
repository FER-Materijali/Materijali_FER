#ifndef CAT_H

#define CAT_H

#include <memory>

#include "AbstractAnimal.h"
#include "Factory.h"

class Tiger : public AbstractAnimal
{
public:
    static std::unique_ptr<Animal> creator(std::string const& name);

    Tiger(std::string const& name);

    virtual ~Tiger() = default;
private:
    static int hreg;
};
#endif // !CAT_H