#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Graph representation as an adjacency list
vector<vector<pair<int, int>>> adjacencyList;

// Function to add an edge to the graph
void addEdgeToGraph(int node1, int node2, int weight) {
    adjacencyList[node1].push_back(make_pair(node2, weight));
    adjacencyList[node2].push_back(make_pair(node1, weight));
}

// Function to find the minimum spanning tree (MST) using Prim's algorithm
vector<pair<pair<int, int>, int>> findMinimumSpanningTree(int numNodes) {
    // Initialize data structures
    vector<int> key(numNodes, INT_MAX);
    vector<int> parent(numNodes, -1);
    vector<bool> inMST(numNodes, false);

    // Priority queue to store nodes and their key values
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with Node 0
    int startNode = 0;
    pq.push(make_pair(0, startNode));
    key[startNode] = 0;

    while (!pq.empty()) {
        int currentNode = pq.top().second;
        pq.pop();

        inMST[currentNode] = true;

        // Iterate through adjacent nodes of the current node
        for (auto& neighbor : adjacencyList[currentNode]) {
            int neighborNode = neighbor.first;
            int neighborWeight = neighbor.second;

            // If neighborNode is not yet included in MST and weight of (currentNode, neighborNode) is smaller than key[neighborNode]
            if (!inMST[neighborNode] && neighborWeight < key[neighborNode]) {
                // Update key value and parent of neighborNode
                key[neighborNode] = neighborWeight;
                parent[neighborNode] = currentNode;
                pq.push(make_pair(key[neighborNode], neighborNode));
            }
        }
    }

    // Create a vector to store MST edges and their weights
    vector<pair<pair<int, int>, int>> mstEdges;
    for (int i = 1; i < numNodes; ++i) {
        int parentNode = parent[i];
        int currentNode = i;
        int weight = key[i];
        mstEdges.push_back(make_pair(make_pair(parentNode, currentNode), weight));
    }

    return mstEdges;
}

int main() {
    int numNodes = 6;
    adjacencyList.resize(numNodes);

    // Add edges to the graph
    addEdgeToGraph(0, 1, 3);
    addEdgeToGraph(0, 5, 1);
    addEdgeToGraph(1, 2, 2);
    addEdgeToGraph(1, 3, 1);
    addEdgeToGraph(1, 4, 10);
    addEdgeToGraph(2, 3, 3);
    addEdgeToGraph(2, 5, 5);
    addEdgeToGraph(3, 4, 5);
    addEdgeToGraph(4, 5, 4);

    // Find the MST
    vector<pair<pair<int, int>, int>> mstEdges = findMinimumSpanningTree(numNodes);

    // Display the MST edges and their weights
    cout << " Edge   : Weight:" << endl;
    for (const auto& edge : mstEdges) {
        cout << edge.first.first << " - " << edge.first.second << "\t:  " << edge.second << endl;
    }

    return 0;
}
