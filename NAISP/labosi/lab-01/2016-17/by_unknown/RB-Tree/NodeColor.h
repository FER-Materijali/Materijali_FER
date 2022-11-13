#ifndef NODE_COLOR_H
#define NODE_COLOR_H

#include <string>

enum class NodeColor : bool {
    Red, Black
};

namespace std {
    std::string to_string(NodeColor const& color) {
        switch (color) {
            case NodeColor::Black:
                return "B";
            case NodeColor::Red:
                return "R";
            default:
                return "Err";
        }
    }
}

#endif // !NODE_COLOR_H
