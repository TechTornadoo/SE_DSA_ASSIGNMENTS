//DSA_ASSIGNMENT6_DFS&BFS
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
private:
    unordered_map<char, vector<char>> adjacencyList;

public:
    void addEdge(char source, char destination) {
        adjacencyList[source].push_back(destination);
        adjacencyList[destination].push_back(source); // Assuming an undirected graph
    }

    void DFS(char startNode) {
        unordered_set<char> visited;
        stack<char> nodeStack;

        nodeStack.push(startNode);

        while (!nodeStack.empty()) {
            char currentNode = nodeStack.top();
            nodeStack.pop();

            if (visited.find(currentNode) == visited.end()) {
                visited.insert(currentNode);
                cout << currentNode << " ";

                for (char neighbor : adjacencyList[currentNode]) {
                    if (visited.find(neighbor) == visited.end()) {
                        nodeStack.push(neighbor);
                    }
                }
            }
        }
    }

    void BFS(char startNode) {
        unordered_set<char> visited;
        queue<char> nodeQueue;

        nodeQueue.push(startNode);

        while (!nodeQueue.empty()) {
            char currentNode = nodeQueue.front();
            nodeQueue.pop();

            if (visited.find(currentNode) == visited.end()) {
                visited.insert(currentNode);
                cout << currentNode << " ";

                for (char neighbor : adjacencyList[currentNode]) {
                    if (visited.find(neighbor) == visited.end()) {
                        nodeQueue.push(neighbor);
                    }
                }
            }
        }
    }
};

int main() {
    Graph graph;

    // Adding edges to the graph
    graph.addEdge('A', 'B');
    graph.addEdge('A', 'C');
    graph.addEdge('B', 'C');
    graph.addEdge('B', 'D');
    graph.addEdge('B', 'E');
    graph.addEdge('C', 'F');
    graph.addEdge('D', 'E');
    graph.addEdge('E', 'F');

    cout << "DFS Traversal: ";
    graph.DFS('A');
    cout << endl;

    cout << "BFS Traversal: ";
    graph.BFS('A');
    cout << endl;

    return 0;
}
