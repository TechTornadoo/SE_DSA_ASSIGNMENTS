#include <iostream>
#include <vector>
#include <string>
#include <limits>

const int MAX_CITIES = 10; // Maximum number of cities

using namespace std;

class FlightGraph {
private:
    int numCities;
    vector<vector<int>> adjacencyMatrix;
    vector<string> cityNames;

public:
    FlightGraph(int cities) {
        numCities = cities;
        adjacencyMatrix.resize(numCities, vector<int>(numCities, -1));
        cityNames.resize(numCities);
    }

    void addFlight(int source, int destination, int cost) {
        adjacencyMatrix[source][destination] = cost;
        adjacencyMatrix[destination][source] = cost; // Assuming undirected flights
    }

    void setCityName(int index, const string& name) {
        if (index >= 0 && index < numCities) {
            cityNames[index] = name;
        }
    }

    void printMinimumSpanningTree() {
        vector<int> parent(numCities, -1);
        vector<int> key(numCities, numeric_limits<int>::max());
        vector<bool> inMST(numCities, false);

        key[0] = 0; // Start with the first city

        for (int count = 0; count < numCities - 1; ++count) {
            int minKey = numeric_limits<int>::max();
            int minIndex = -1;

            for (int i = 0; i < numCities; ++i) {
                if (!inMST[i] && key[i] < minKey) {
                    minKey = key[i];
                    minIndex = i;
                }
            }

            inMST[minIndex] = true;

            for (int i = 0; i < numCities; ++i) {
                if (adjacencyMatrix[minIndex][i] != -1 && !inMST[i] && adjacencyMatrix[minIndex][i] < key[i]) {
                    parent[i] = minIndex;
                    key[i] = adjacencyMatrix[minIndex][i];
                }
            }
        }

        cout << "Minimum Spanning Tree:\n";
        for (int i = 1; i < numCities; ++i) {
            cout << cityNames[parent[i]] << " - " << cityNames[i] << ": " << adjacencyMatrix[parent[i]][i] << " units\n";
        }
    }
};

int main() {
    int numCities;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    FlightGraph flightGraph(numCities);

    // Add city names
    cin.ignore(); // Ignore the newline character in the buffer
    cout << "Enter city names:\n";
    for (int i = 0; i < numCities; ++i) {
        cout << "City " << i << ": ";
        string cityName;
        getline(cin, cityName);
        flightGraph.setCityName(i, cityName);
    }

    // Add flight paths
    int source, destination, cost;
    cout << "Enter flight paths (-1 to stop):\n";
    while (true) {
        cout << "From: ";
        cin >> source;
        if (source == -1) {
            break;
        }
        cout << "To: ";
        cin >> destination;
        cout << "Cost: ";
        cin >> cost;
        flightGraph.addFlight(source, destination, cost);
    }

    // Print minimum spanning tree
    flightGraph.printMinimumSpanningTree();

    return 0;
}
