#pragma once

#include <vector>
#include <string>

class WikiGraph {
    public:
        WikiGraph() = default;
        void parse_from_file();
        std::vector<std::string> shortest_path(std::string page_A, std::string page_B);

    private:
        std::vector<std::vector<unsigned int>> adjacency_matrix; // Definition of a 2D adjacency matrix
};