#include "wikigraph.h"

int main() {
    WikiGraph graph;
    // std::vector<std::string> file_names = {"../data/Conservation_status.csv", 
    //                                     "../data/Gaiwan.csv", 
    //                                     "../data/Green_tea.csv", 
    //                                     "../data/Hydrocera.csv", 
    //                                     "../data/Longjing_tea.csv", 
    //                                     "../data/Roman_Republic.csv", 
    //                                     "../data/Tea.csv"};
    std::vector<std::string> file_names = {"../data/Hydrocera.csv",
                                        "../data/Gaiwan.csv",};
    graph.parse_from_files(file_names);
    std::string edge_list = graph.print_edge_list();
    std::cout << edge_list << std::endl;
    std::cout << "****** https://graphonline.ru/en/create_graph_by_edge_list ******" << std::endl;
    std::cout << "Use this website to plot the graph" << std::endl;
    return 0;
}