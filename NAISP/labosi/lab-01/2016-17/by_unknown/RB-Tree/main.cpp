#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "RBTree.h"

std::vector<int> read_from_file(char const* filename) {
    std::ifstream file(filename);
    auto rv = std::vector<int>();
    int val;
    while (file >> val) {
        rv.push_back(val);
    }
    return rv;
}

int main(int argc, char* argv[]) {
    RBTree<int> a;
    for (auto& i : read_from_file(argv[1])) {
        a.insert(i);
    }
    std::cout << std::to_string(a) << '\n';
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        if (line == "exit") {
            break;
        }
        std::istringstream stream{line};
        char command;
        int value;
        stream >> command >> value;
        if (command == 'i') {
            a.insert(value);
        }
        else if (command == 'd') {
            a.remove(value);
        }

        std::cout << std::to_string(a) << '\n';
    }
}