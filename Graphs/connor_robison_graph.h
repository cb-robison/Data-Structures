#pragma once
/*

Name: Connor Robison

NetID: w10045714

Program Description: This graph class will store the vertices and edges of a graph, create an adjacency list, and can find the shortest path between two nodes on an unweighted, undirected graph.

*/

// This code was inspired by the solution from https://www.codingninjas.com/studio/library/shortest-path-in-an-unweighted-graph
// The original author of that code was Aniket Verma.

#include<vector>
#include<iostream>

using namespace std;


class Graph {

public:
    int V;                                                                  // Number of Vertices
    int E;                                                                  // Number of Edges
    vector<int>* adj_list;                                                  // The adjacency list
    Graph(int num_vertices, int num_edges) {
        this->V = num_vertices;
        this->E = num_edges;
        this->adj_list = new vector<int>[num_vertices];
    }

    // This function will add edges
    void AddEdge(int u, int v) {
        adj_list[u - 1].push_back(v - 1);
        adj_list[v - 1].push_back(u - 1);
    }

    // This function will compute all paths
    void ComputeAllPaths(int source, int target, vector<int>& path, vector<bool>& visited, vector<vector<int>>& possible_paths) {
        // Return is the node has already been visited
        if (visited[source]) {
            return;
        }

        // If source == target, then the shortest path has been found
        if (source == target) {
            path.push_back(source);
            possible_paths.push_back(path);
            path.pop_back();
            return;
        }

        // Mark that the current node has been visited
        visited[source] = 1;
        path.push_back(source);

        // Use the adjacency list to traverse to neighboring nodes
        for (int node : this->adj_list[source]) {
            // If adjacent node is not visited
            if (!visited[node]) {
                // Use compute AllPaths to recursively traverse path
                ComputeAllPaths(node, target, path, visited, possible_paths);
            }
        }

        visited[source] = 0;                                                // Mark current node as unvisited
        path.pop_back();                                                    // Pop the current source node
    }

    // This function will print out the shortest path     
    void DijkstraShortestPath(int source, int target) {
        source--; target--;                                                 // Adjust for 0-based indexing
        vector<int> path;                                                   // This is a possible path
        vector<bool> visited(V, 0);                                         // List of visited vertices
        vector<vector<int>> possible_paths;                                 // List of all possible paths from source to target
        ComputeAllPaths(source, target, path, visited, possible_paths);     // A function to find all paths
        vector<int> shortest_path;                                          // A vector to store the shortest_path

        // Find the shortest_path
        for (vector<int> v : possible_paths) {
            if (shortest_path.size() == 0 or (shortest_path.size() > v.size())) {
                shortest_path = v;
            }
        }
        cout << "The Shortest Path of the Unweighted Graph is: ";

        // Print the shortest path
        for (int i = 0; i < shortest_path.size(); ++i) {
            if (i != shortest_path.size() - 1) {
                cout << shortest_path[i] + 1 << " -> ";
            }
            else {
                cout << shortest_path[i] + 1 << '\n';
            }
        }
        cout << "The length is " << shortest_path.size();
    }
};