/*

Name: Connor Robison

NetID: w10045714

Program Description: This program will test the Graph Class by finding the shortest path between two differents pair of nodes.

*/

#include"connor_robison_graph.h"
#include<iostream>

using namespace std;

int main() {
    // Number of Edges and Vertices for Graph G
    int num_vertices = 10;
    int num_edges = 12;
    Graph G(num_vertices, num_edges);

    // Add all edges to graph
    G.AddEdge(1, 2);
    G.AddEdge(1, 4);
    G.AddEdge(1, 5);
    G.AddEdge(1, 9);
    G.AddEdge(2, 4);
    G.AddEdge(2, 6);
    G.AddEdge(2, 10);
    G.AddEdge(3, 5);
    G.AddEdge(3, 6);
    G.AddEdge(4, 8);
    G.AddEdge(6, 10);
    G.AddEdge(7, 10);


    /* Part 2 – Implementation of Graph Data Structure and Chosen Algorithm */
    
    //Part A: Find the Shortest Path between 1 -> 7 
    int source = 1; int target = 7;
    G.DijkstraShortestPath(source, target);
    cout << endl << endl;

    //Part B: Find the Shortest Path between 10 -> 8
    source = 10; target = 8;
    G.DijkstraShortestPath(source, target);
    cout << endl;
}