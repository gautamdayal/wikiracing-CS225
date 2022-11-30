#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

/**
 * @brief Class to store the connections between wikipedia pages as a graph data structure
 * 
 * Given a collection of csv files storing the source and destination wikipedia pages for a single page, 
 * the class encapsulates functionality to parse this data, store it as an adjacency list, and compute the shortest
 * path between any two pages that are in the stored subgraph. Functionality to compute strongly connected components is also 
 * included. 
*/
class WikiGraph {
    public:
        /**
         * @brief Default constructor for the WikiGraph class
        */
        WikiGraph() = default;

        /**
         * @brief Function that calls parse_from_file on each filename in the argument vector
         * @param file_names A vector of filenames that make up the subgraph to be analyzed
        */
        void ParseFromFiles(std::vector<std::string> file_names);

        /** 
         * @brief Function that parses a CSV formatted as src/dest into an adjacency list
         * @param filename A string that stores the text filename to be parsed
         * 
         * The adacency list is stored as a STL map as a private member variable
        */
        void ParseFromFile(std::string filename);

        /**
         * @brief Function that computes the shortest path between two pages in the parsed subgraph using Dijkstra's algorithm
         * @param page_A Source page for path to be calculated 
         * @param page_b Destination page for path to be calculated
         * @returns A vector of wikipedia page names representing each vertex in the computed path
         * 
        */
        std::vector<std::string> ShortestPath(std::string page_A, std::string page_B);

        /**
         * @brief Prints each edge in the subgraph. Useful for debugging and general representation
         * @returns String showing an arrow between a source and a destination page
        */
        std::string PrintEdgeList();

    private:
        std::map<std::string, std::vector<std::string>> adjacency_list; // Definition of a 2D adjacency matrix
        std::set<std::string> vertice_set;
};