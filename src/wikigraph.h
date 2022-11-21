#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <set>

class WikiGraph {
    public:
        WikiGraph() = default;
        void parse_from_files(std::vector<std::string> file_names);
        void parse_from_file(std::string filename);
        std::vector<std::string> shortest_path(std::string page_A, std::string page_B);
        std::string print_edge_list();

    private:
        std::map<std::string, std::vector<std::string>> adjacency_list; // Definition of a 2D adjacency matrix
        std::set<std::string> vertice_set;
};