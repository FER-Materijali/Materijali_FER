#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <vector>

struct Edge {
    Edge(char f, char t, int w) : from{f}, to{t}, weight{w} {
        ;
    }

    char from;
    char to;
    int weight;
};

using edges_t = std::vector<Edge>;
using vertices_t = std::set<char>;
using graph_t = std::pair<vertices_t, edges_t>;

using path_data_t = std::map<char, std::pair<int, char>>;

graph_t read_graph(std::istream& in);

path_data_t bellman_ford(graph_t const& graph, char source);

std::map<char, std::pair<int, std::vector<char>>> recounstruct_path(path_data_t const& data, char source);

int main(int argc, char* argv[]) {
    std::fstream file(argv[1]);
    auto graph = read_graph(file);
    
    std::cout << "Enter starting node (";
    for (auto v : graph.first) {
        std::cout << v << ' ';
    }
    std::cout << "): ";
    char source;
    std::cin >> source;
    
    try {
        auto data = bellman_ford(graph, source);
        auto paths = recounstruct_path(data, source);

        for (auto& mp : paths) {
            std::cout << source << '-' << mp.first << " (" << mp.second.first << "): ";
            for (auto& v : mp.second.second) {
                std::cout << v << ' ';
            }
            std::cout << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    system("pause");
}

graph_t read_graph(std::istream& in) {
    auto vertices = vertices_t();
    auto edges = edges_t();

    std::string line;
    while (std::getline(in, line)) {
        std::istringstream stream(line);
        char from; char to; int weight;
        stream >> from >> to >> weight;

        vertices.insert(from);
        vertices.insert(to);
        edges.emplace_back(from, to, weight);
    }
    return{vertices, edges};
}

path_data_t bellman_ford(graph_t const& graph, char source) {
    auto const& vertices = graph.first;
    auto const& edges = graph.second;

    auto data = path_data_t();
    for (auto const& v : vertices) {
        data[v].first = std::numeric_limits<int>::max() / 2 ;
        data[v].second = '0';
    }
    data[source].first = 0;

    for (auto i = 0; i < vertices.size() - 1; ++i) {
        for (auto const& e : edges) {
            auto temp = data[e.from].first + e.weight;
            if (temp < data[e.to].first) {
                data[e.to].first = temp;
                data[e.to].second = e.from;
            }
        }
    }

    for (auto const& e : edges) {
        if (data[e.from].first + e.weight < data[e.to].first) {
            throw std::exception("Graph contains a negative weight cycle.");
        }
    }
    return data;
}

std::map<char, std::pair<int, std::vector<char>>> recounstruct_path(path_data_t const& data, char source) {
    auto rv = std::map<char, std::pair<int, std::vector<char>>>();
    for (auto const& p : data) {
        if (p.first != source) {
            auto v = p.first;
            auto path = std::vector<char>();
            while (true) {
                path.push_back(v);
                if (v == source) {
                    rv[p.first] = {p.second.first, { path.rbegin(), path.rend() }};
                    break;
                }
                else {
                    v = data.at(v).second;
                    if (v == '0') {
                        break;
                    }
                }
            }
        }
    }

    return rv;
}
