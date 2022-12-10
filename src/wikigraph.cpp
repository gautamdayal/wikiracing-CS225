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
            if (current.first + 1 < distance[neighbor]) {
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

std::vector<std::vector<std::string>> WikiGraph::SCC() {
    std::stack<std::string> s;
    std::vector<std::string> visited;


    std::set<std::string>::iterator set_iter;

    for (set_iter = vertice_set.begin(); set_iter != vertice_set.end(); ++set_iter) {

        if (std::find(visited.begin(), visited.end(), *set_iter) == visited.end()) {
            fillOrder(*set_iter, visited, s);
        }
    }

    WikiGraph gr = transpose();

    visited.clear();

    while (!s.empty()) {
        std::string temp = s.top();
        s.pop();


        if (std::find(visited.begin(), visited.end(), temp) == visited.end()) {
            gr.DFS(temp, visited);
            std::cout << std::endl;
        }
    }
    return {{"Nothing"}};

}

void WikiGraph::DFS(std::string i, std::vector<std::string> &visited) {

    visited.push_back(i);

    std::cout << i << " ";

    std::vector<std::string>::iterator iter;
    for (iter = adjacency_list[i].begin(); iter != adjacency_list[i].end(); ++iter) {
        if (std::find(visited.begin(), visited.end(), *iter) == visited.end()) {
            DFS(*iter, visited);
        }
    }
}


void WikiGraph::fillOrder(std::string i, std::vector<std::string> &visited, std::stack<std::string> &s) {
    visited.push_back(i);

    std::vector<std::string>::iterator iter;

    for (iter = adjacency_list[i].begin(); iter != adjacency_list[i].end(); ++iter) {
        if (std::find(visited.begin(), visited.end(), *iter) == visited.end()) {
            fillOrder(*iter, visited, s);
        }
    }
    

    s.push(i);

}



WikiGraph WikiGraph::transpose() {
    WikiGraph g;

    std::set<std::string>::iterator set_iter;
    for (set_iter = vertice_set.begin(); set_iter != vertice_set.end(); set_iter++) {
        std::vector<std::string>::iterator iter;
        for (iter = adjacency_list[*set_iter].begin(); iter != adjacency_list[*set_iter].end(); ++iter) {
            g.adjacency_list[*iter].push_back(*set_iter);
        }

    }


    return g;


}