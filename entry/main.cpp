#include "wikigraph.h"

int main() {
    WikiGraph graph;
    graph.parse_from_file("../data/Green_tea.csv");
    return 0;
}