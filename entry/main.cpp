#include "wikigraph.h"

int main() {
    // WikiGraph graph;
    std::vector<std::string> file_names;
    std::ifstream ifs("../data/file_list.txt");
    std::string file;
    while (ifs.good()) {
        ifs >> file;
        // std::cout << "../data/" + file + ".csv" << std::endl;
        if (!file.empty()) {
            file_names.push_back("../data/" + file + ".csv");
            file.clear();
        }
    }
    // graph.ParseFromFiles(file_names);
    // std::string edge_list = graph.PrintEdgeList();
    // std::cout << edge_list << std::endl;
    // std::cout << "****** https://graphonline.ru/en/create_graph_by_edge_list ******" << std::endl;
    // std::cout << "Use this website to plot the graph" << std::endl;

    WikiGraph dj;
    dj.ParseFromFiles(file_names);
    // std::cout << dj.PrintEdgeList() << std::endl;
    // std::vector<std::string> path = dj.ShortestPath("a", "h");

    // for (std::string s : path) {
    //     std::cout << s << ">";
    // }
    // std::cout << std::endl;
    std::cout << "Finding the Shortest Paths" << std::endl;
    std::vector<std::string> path = dj.ShortestPath("/wiki/Hadendoa", "/wiki/Little_nightjar");
    for (std::string s : path) {
        std::cout << s << ">";
    }
    std::cout << std::endl;
    // std::vector<std::vector<std::string>> components = dj.SCC();
    // std::cout << std::endl;
    // std::cout << "Components:" << std::endl;
    // for (std::vector<std::string>& component: components) {
    //     if (component.size() > 1) {
    //         for (std::string& page : component) {
    //             std::cout << page << ", ";
    //         }
    //         std::cout << std::endl;
    //     }
    // }
    return 0;
}