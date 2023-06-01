#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

void Dijkstra(vector<vector<int>> &graph, int start, vector<int> &time)
{
    int numVertices = graph.size();
    time.resize(numVertices, INT_MAX); // Initialize time as infinity
    time[start] = 0;                   // Distance from source to itself

    // Create a min-heap priority queue to store vertices and their time
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start)); // Push source vertex into the priority queue

    while (!pq.empty())
    {
        int currVertex = pq.top().second; // Get the vertex with the minimum distance
        pq.pop();

        // Visit all neighbors of the current vertex
        for (int neighbor = 0; neighbor < numVertices; neighbor++)
        {
            // If there is an edge between the current vertex and the neighbor
            if (graph[currVertex][neighbor] > 0)
            {
                int weight = graph[currVertex][neighbor]; // Weight of the edge (current vertex, neighbor)

                // If the distance to the neighbor through the current vertex is shorter, update the distance
                if (time[currVertex] + weight < time[neighbor])
                {
                    time[neighbor] = time[currVertex] + weight;
                    pq.push(make_pair(time[neighbor], neighbor)); // Push updated distance and neighbor into the priority queue
                }
            }
        }
    }
}

int main()
{
    // Define the adjacency matrix for the graph
    vector<vector<int>> adjacencyMatrix = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}};

    int numVertices = adjacencyMatrix.size(); // Number of verticesshortestTime

    int startVertex; // Source vertex
    cout << "\nEnter the starting city: ";
    cin >> startVertex;
    while (startVertex != -1)
    {

        vector<int> shortestTime; // Vector to store the shortest time
        Dijkstra(adjacencyMatrix, startVertex, shortestTime);

        // Print the shortest time from the source
        for (int i = 0; i < numVertices; i++)
        {
            if (i == startVertex)
            {
                continue;
            }
            else
            {
                cout << "Shortest Time from city " << startVertex << " to city " << i << " is " << shortestTime[i] << endl;
            }
        }

        cout << "\nEnter the starting city: ";
        cin >> startVertex;
    }

    return 0;
}
