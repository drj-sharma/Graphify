#include <iostream>
#include "Graphify.h"
using namespace std;
#include <vector>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g = Graph(7, vector<vector<int>>({{1, 2}, {2, 3}, {4, 5}, {2, 6}, {4}, {1, 2, 3, 4}, {5}}));
    g.displayAdjacencyList();
    vector<int> nodes = g.breadthFirstSearch(0);
    cout << "\n BFS: \n";
    for (int i: nodes) {
        cout << i << " ";
    }
    return 0;
}