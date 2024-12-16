#include <iostream>
#include <climits>  // For INT_MAX

// stores adjacency list items
struct adjNode {
    int val, cost;
    adjNode* next;
};

// structure to store edges
struct graphEdge {
    int start_ver, end_ver, weight;
};

class DiaGraph {
    adjNode* getAdjListNode(int value, int weight, adjNode* head) {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->cost = weight;
        newNode->next = head;  // point new node to current head
        return newNode;
    }

    int N;  // number of nodes in the graph
public:
    adjNode **head;  // adjacency list as array of pointers

    // Constructor
    DiaGraph(graphEdge edges[], int n, int N) {
        head = new adjNode*[N]();
        this->N = N;
        // initialize head pointer for all vertices
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;
        // construct directed graph by adding edges to it
        for (unsigned i = 0; i < n; i++) {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;
            // insert in the beginning
            adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);
            head[start_ver] = newNode;
        }
    }

    // Destructor
    ~DiaGraph() {
        for (int i = 0; i < N; i++) {
            adjNode* temp = head[i];
            while (temp != nullptr) {
                adjNode* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
        }
        delete[] head;
    }

    // Function to create the adjacency matrix from the adjacency list
    void createAdjMatrix() {
        // Create the adjacency matrix initialized to 0 (no edge)
        int **adjMatrix = new int*[N];
        for (int i = 0; i < N; i++) {
            adjMatrix[i] = new int[N]();
            for (int j = 0; j < N; j++) {
                adjMatrix[i][j] = 0;  // No edge, initialized to 0
            }
        }

        // Populate the adjacency matrix from the adjacency list
        for (int i = 0; i < N; i++) {
            adjNode* temp = head[i];
            while (temp != nullptr) {
                adjMatrix[i][temp->val] = temp->cost;  // Set weight
                temp = temp->next;
            }
        }

        // Display the adjacency matrix
        std::cout << "\nAdjacency Matrix Representation (Weight):\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }

        // Clean up the memory used by the adjacency matrix
        for (int i = 0; i < N; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    // Add a vertex to the graph
    void addVertex() {
        // Allocate a new array of pointers to represent the adjacency list
        adjNode **newHead = new adjNode*[N + 1];
        
        // Copy existing vertices' adjacency lists to the new array
        for (int i = 0; i < N; i++) {
            newHead[i] = head[i];
        }

        // Initialize the new vertex with no edges (null pointer)
        newHead[N] = nullptr;

        // Delete the old adjacency list array and update head to the new one
        delete[] head;
        head = newHead;
        N++;  // Increase the number of vertices
        std::cout << "Vertex " << N - 1 << " added.\n";
    }

    // Add an edge between two vertices
    void addEdge(int start, int end, int weight) {
        // Ensure the edge is added to the adjacency list of the start vertex
        adjNode* newNode = getAdjListNode(end, weight, head[start]);
        head[start] = newNode;
        std::cout << "Edge added from vertex " << start << " to vertex " << end << " with weight " << weight << ".\n";
    }

    // Display the graph vertices
    void displayVertices() {
        std::cout << "Graph vertices: ";
        for (int i = 0; i < N; i++) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

// print all adjacent vertices of given vertex
void display_AdjList(adjNode* ptr, int i) {
    while (ptr != nullptr) {
        std::cout << "(" << i << ", " << ptr->val
                  << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

// graph implementation
int main() {
    // graph edges array.
    graphEdge edges[] = {
        // (x, y, w) -> edge from x to y with weight w
        {0, 1, 2}, {0, 2, 4}, {1, 4, 3}, {2, 3, 2}, {3, 1, 4}, {4, 3, 3}
    };
    int N = 6;  // Number of vertices in the graph
    // calculate number of edges
    int n = sizeof(edges) / sizeof(edges[0]);
    // construct graph
    DiaGraph diagraph(edges, n, N);
    
    // Display the graph vertices
    diagraph.displayVertices();
    
    // Display adjacency list representation of the graph
    std::cout << "Graph adjacency list:\n(start_vertex, end_vertex, weight):\n";
    for (int i = 0; i < N; i++) {
        display_AdjList(diagraph.head[i], i);
    }

    // Create and display adjacency matrix representation
    diagraph.createAdjMatrix();
    
    // Add a vertex to the graph
    diagraph.addVertex();

    // Display the graph vertices after adding a new vertex
    diagraph.displayVertices();

    // Add an edge from vertex 5 to vertex 0 with weight 1
    diagraph.addEdge(5, 0, 1);

    // Display adjacency list representation of the graph
    std::cout << "Graph adjacency list:\n(start_vertex, end_vertex, weight):\n";
    for (int i = 0; i < N; i++) {
        display_AdjList(diagraph.head[i], i);
    }

    // Create and display adjacency matrix representation
    diagraph.createAdjMatrix();

    return 0;
}

