#ifndef FACTORY_H

#define FACTORY_H

#include <functional>
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>

template<typename T>
class Factory
{
public:
    using creator_t = std::function<std::unique_ptr<T>(std::string const&)>;

    static Factory& instance();
    int register_creator(std::string const& id, creator_t creator);
    std::unique_ptr<T> create(std::string const& id, std::string const& arg) const;
    std::vector<std::string> ids() const;

private:
    Factory() = default;
    std::unordered_map<std::string, creator_t> creators_;
};

template<typename T>
inline Factory<T>& Factory<T>::instance()
{
    static auto factory = Factory<T>();

    return factory;
}

template<typename T>
inline int Factory<T>::register_creator(std::string const& id, creator_t creator)
{
    creators_[id] = creator;
    return creators_.size();
}

template<typename T>
inline std::unique_ptr<T> Factory<T>::create(std::string const& id, std::string const& arg) const
{
    return creators_.at(id)(arg);
}

template<typename T>
inline std::vector<std::string> Factory<T>::ids() const
{
    auto ids = std::vector<std::string>();
    for (auto const& id : creators_) {
        ids.push_back(id.first);
    }
    return ids;
}

#endif // !FACTORY_H
