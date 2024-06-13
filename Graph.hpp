#pragma once
#include <vector>
#include <cstddef>

// id:322522806
// email:oriyaperel18@gmail.com

namespace ariel
{
    class Graph
    {
    private:
        std::vector<std::vector<int>> matrix; // represent the adjacency matrix
        int numVertices;
        bool directed;

    public:
        Graph(); // the default is directed graph
        Graph(bool directed);
        const std::vector<std::vector<int>> &getGraph() const;
        void loadGraph(std::vector<std::vector<int>> g);
        void printGraph();
        bool isdirected() const;
        int getNumEdge() const;
        size_t getNumVertices() const;
    };
}
