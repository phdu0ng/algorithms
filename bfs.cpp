#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

bool bfs_has_path(
    const std::unordered_map<std::string, std::vector<std::string>>& graph,
    const std::string& start,
    const std::string& target
) {
    std::queue<std::string> q;
    std::unordered_set<std::string> visited;
    
    // Start is already discovered once it is enqueued.
    q.push(start);
    visited.insert(start);

    while(!q.empty()) {
        std::string current = q.front();
        q.pop();

        if(current == target) {
            return true;        
        }

        for(const std::string& neighbor : graph.at(current)) {
            if (visited.find(neighbor) == visited.end()) {
                // Mark when enqueuing so the same node is not queued twice.
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    
    return false;
}

std::vector<std::string> bfs_shortest_path(
    const std::unordered_map<std::string, std::vector<std::string>>& graph,
    const std::string& start,
    const std::string& target
) {
    std::queue<std::string> q;
    std::unordered_set<std::string> visited;
    // parent[child] = node that first discovered child.
    // In BFS, first discovery gives the shortest path in an unweighted graph.
    std::unordered_map<std::string, std::string> parent;
    
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        if (target == current) {
            // Reconstruct by walking backward from target to start.
            std::vector<std::string> path;
            path.push_back(current);

            while (current != start) {
                current = parent[current];
                path.push_back(current);
            }

            // The walk above is target -> ... -> start, so reverse it.
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (const std::string& neighbor : graph.at(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    return {};
}

void print_path(const std::vector<std::string>& path) {
    if (path.empty()) {
        std::cout << "(empty)\n";
        return;
    }

    for (const std::string& node : path) {
        std::cout << node << ' ';
    }

    std::cout << '\n';
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    graph["Alice"] = {"Bob", "Claire"};
    graph["Bob"] = {"Dennis"};
    graph["Claire"] = {"Elaine"};
    graph["Dennis"] = {};
    graph["Elaine"] = {};

    std::cout << std::boolalpha;
    std::cout << "Alice -> Elaine = " << bfs_has_path(graph, "Alice", "Elaine") << '\n';
    std::cout << "Bob -> Elaine = " << bfs_has_path(graph, "Bob", "Elaine") << '\n';
    std::cout << "Alice -> Alice = " << bfs_has_path(graph, "Alice", "Alice") << '\n';
    print_path(bfs_shortest_path(graph, "Alice", "Elaine"));
    print_path(bfs_shortest_path(graph, "Bob", "Elaine"));
    print_path(bfs_shortest_path(graph, "Alice", "Alice"));

    return 0;
}
