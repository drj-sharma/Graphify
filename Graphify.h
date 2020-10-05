#ifndef test2_h
#define test2_h
#include <vector>
#include <queue>
using namespace std;
class Graph {
    int numOfNodes;
    vector<vector<int>> adjList;
public:
    Graph(int numOfNodes, vector<vector<int>> adjList) {
        this->numOfNodes = numOfNodes;
        this->adjList = adjList;
    }
    void displayAdjacencyList();
    vector<int> breadthFirstSearch(int);
    vector<int> depthFirstSearch(int);
    void dfsHelper(int, vector<int>&, vector<bool>&);
};
void Graph::displayAdjacencyList() {
    for (int i = 0; i < numOfNodes; i++) {
        cout << i << " -> ";
        for (int j : adjList[i])
            cout << j << " -> ";
        cout << "null" << "\n";
    }
}
vector<int> Graph:: breadthFirstSearch(int src) {
    vector<int> nodes;
    vector<bool> visited(numOfNodes + 1, false);
    queue<int> queue;
    queue.push(src);
    visited[src] = true;
    while (!queue.empty()) {
        int explorer = queue.front();
        queue.pop();
        nodes.push_back(explorer);
        for (auto neighbour: adjList[explorer]) {
            if (!visited[neighbour]) {
                queue.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
    return nodes;
}
void Graph:: dfsHelper(int src, vector<int>& nodes, vector<bool>& visited) {
    visited[src] = true;
    nodes.push_back(src);
    for (auto neighbour: adjList[src]) {
        if (!visited[neighbour]) {
            dfsHelper(neighbour, nodes, visited);
        }
    }
}
vector<int> Graph:: depthFirstSearch(int src) {
    vector<bool> visited(numOfNodes + 1, 0);
    vector<int> nodes;
    dfsHelper(src, nodes, visited);
    return nodes;
}
#endif //  TEST.H