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

    std::vector<int> distances(adjacency_list.size(), INT32_MAX);
    std::map<std::string, std::string> previous;
    std::priority_queue<std::pair<std::string, int>> pq;
    std::vector<std::string> visited;

    pq.push(std::pair<std::string, int>(page_A, 0));
    distances[0] = 0;

    while (pq.top().first != page_B) {
        std::pair<std::string, int> current = pq.top();
        pq.pop();  
        
        std::cout << current.first << std::endl;

        for (std::string neighbor : adjacency_list[current.first]) {
            // std::cout << neighbor << std::endl;
            if (std::find(visited.begin(), visited.end(), neighbor) == visited.end()) {
                
                previous[neighbor] = current.first;
                pq.push(std::pair<std::string, int>(neighbor, current.second + 1));
            }


        }
        visited.push_back(current.first); 
    }



    // PROBLEM WITH THIS BTW
    // std::string curr = page_B;
    // std::string prev = page_B;
    // while (prev != page_A) {
    //     std::string prev = previous[curr];
    //     ret.push_back(prev)
    //     curr = prev; 
    // }
    return ret;

}