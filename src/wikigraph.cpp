#include "wikigraph.h"

std::string WikiGraph::print_edge_list() {
    std::string edge_list;
    for (auto const& pair : adjacency_list) {
        std::string from = pair.first;
        for (auto const& to : pair.second) {
            edge_list += from + ">" + to + "\n";
        }
    }
    return edge_list;
}

void WikiGraph::parse_from_files(std::vector<std::string> file_names) {
    for (std::string& name : file_names) {
        parse_from_file(name);
    }
    // for (auto const& vertice : vertice_set) {
    //     std::cout << vertice << ", ";
    // }
    // std::cout << std::endl;
    std::cout << "Number of Pages: " << vertice_set.size() << std::endl;
}

void WikiGraph::parse_from_file(std::string filename) {
    std::ifstream ifs(filename);
    std::string line;
    if (ifs.fail()) {
        throw std::invalid_argument("File failed to open!");
    }
    while (ifs.good()) {
        ifs >> line;
        if (line == "") {
            continue;
        }
        std::string from = line.substr(0, line.find(","));
        if (from == "src") {
            continue;
        }
        std::string to = line.substr(from.size() + 1, line.size() - from.size());
        if (adjacency_list.find(from) != adjacency_list.end()) {
            adjacency_list.at(from).push_back(to);
            vertice_set.insert(to);
        } else {
            std::vector<std::string> temp_vec;
            temp_vec.push_back(to);
            adjacency_list.insert({from, temp_vec});
            vertice_set.insert(from);
            vertice_set.insert(to);
        }
        line = "";
    }
}

std::vector<std::string> WikiGraph::shortest_path(std::string page_A, std::string page_B) {
    std::vector<std::string> ret;

    return ret;
}