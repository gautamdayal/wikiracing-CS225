#include "wikigraph.h"

void WikiGraph::parse_from_file(std::string filename) {
    std::map<std::string, std::vector<std::string>> node_vector;
    std::ifstream ifs(filename);
    std::string line;
    if (ifs.fail()) {
        throw std::invalid_argument("File failed to open!");
    }
    while (ifs.good()) {
        ifs >> line;
        std::string from = line.substr(0, line.find(","));
        if (from == "src") {
            continue;
        }
        std::string to = line.substr(from.size() + 1, line.size() - from.size());
        if (node_vector.find(from) != node_vector.end()) {
            node_vector.at(from).push_back(to);
        } else {
            std::vector<std::string> temp_vec;
            temp_vec.push_back(to);
            node_vector.insert({from, temp_vec});
        }
        line = "";
    }
    for (auto const& pair : node_vector) {
        vertice_set.insert(pair.first);
        for (auto const& to : pair.second) {
            vertice_set.insert(to);
            std::cout << pair.first << "=>" << to << std::endl;
        }
    }
    for (auto const& vertice : vertice_set) {
        std::cout << vertice << ", ";
    }
    std::cout << std::endl;
}

std::vector<std::string> WikiGraph::shortest_path(std::string page_A, std::string page_B) {
    std::vector<std::string> ret;

    return ret;
}