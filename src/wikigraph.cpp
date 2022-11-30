#include "wikigraph.h"

std::string WikiGraph::PrintEdgeList() {
    std::string edge_list;
    for (auto const& pair : adjacency_list) {
        std::string from = pair.first;
        for (auto const& to : pair.second) {
            edge_list += from + ">" + to + "\n";
        }
    }
    return edge_list;
}

void WikiGraph::ParseFromFiles(std::vector<std::string> file_names) {
    for (std::string& name : file_names) {
        ParseFromFile(name);
    }
    // for (auto const& vertice : vertice_set) {
    //     std::cout << vertice << ", ";
    // }
    // std::cout << std::endl;
    std::cout << "Number of Pages: " << vertice_set.size() << std::endl;
}

void WikiGraph::ParseFromFile(std::string filename) {
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

std::vector<std::string> WikiGraph::ShortestPath(std::string page_A, std::string page_B) {
    std::vector<std::string> ret;

    std::map<std::string, int> distance;
    std::map<std::string, std::string> previous;
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> pq;
    std::vector<std::string> visited;

    for (std::string v : vertice_set) {
        distance.insert({v, INT32_MAX});
    }

    pq.push({0, page_A});
    distance[page_A] = 0;

    while (pq.top().second != page_B) {
        std::pair<int, std::string> current = pq.top();
        pq.pop();  
        if (!visited.empty() && std::find(visited.begin(), visited.end(), current.second) != visited.end()) {
            continue;
        }

        for (std::string neighbor : adjacency_list[current.second]) {
            if ((!visited.empty() && std::find(visited.begin(), visited.end(), neighbor) != visited.end()) || current.first + 1 < distance[neighbor]) {
                pq.push({current.first + 1, neighbor});
                previous[neighbor] = current.second;  
                distance[neighbor] = current.first + 1;
            } 


        }
        visited.push_back(current.second);
    }



    // PROBLEM WITH THIS BTW
    std::string curr = page_B;
    while (curr != page_A) {
        ret.insert(ret.begin(), curr);
        curr = previous[curr];
    }
    ret.insert(ret.begin(), page_A);
    return ret;

}