#include <iostream>
#include "Graphify.h"
using namespace std;
#include <vector>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g = Graph(7, vector<vector<int>>({{1, 2}, {2, 3}, {4, 5}, {2, 6}, {4}, {1, 2, 3, 4}, {5}}));
    g.displayAdjacencyList();
    vector<int> nodesBFS = g.breadthFirstSearch(0);
    cout << "\n BFS: \n";
    for (int i: nodesBFS) {
        cout << i << " ";
    }
    vector<int> nodesDFS = g.depthFirstSearch(0);
    cout << "\n DFS: \n";
    for (int i: nodesDFS) {
        cout << i << " ";
    }
    return 0;
}