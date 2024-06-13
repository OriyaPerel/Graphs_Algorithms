#include "Graph.hpp"
#include <iostream>

// id:322522806
// email:oriyaperel18@gmail.com

namespace ariel
{
    Graph::Graph() // the default is directed graph
    {
        this->directed = true;
    }

    Graph::Graph(bool directed)
    {
        this->directed = directed;
    }

    const std::vector<std::vector<int>> &Graph::getGraph() const // return the adjacency matrix
    {
        return this->matrix;
    }

    bool Graph::isdirected() const // return if the graph is directed or not
    {
        return this->directed;
    }

    int Graph::getNumEdge() const
    // return the number of edges in the graph,
    // if the graph is directed return the number of edges,
    // if is undirected return the number of edges divided by 2
    {
        int count = 0;
        int V = this->numVertices;
        for (size_t i = 0; i < V; i++)
        {
            for (size_t j = 0; j < V; j++)
            {
                if (matrix[i][j] != 0)
                {
                    count++;
                }
            }
        }
        if (this->directed)
        {
            return count;
        }
        return (count / 2);
    }

    size_t Graph::getNumVertices() const
    {
        return (size_t)this->numVertices;
    }

    void Graph::loadGraph(std::vector<std::vector<int>> ingraph)
    {
        if (ingraph.empty()) // check if the graph is empty
        {
            throw std::invalid_argument("Invalid graph: The graph is empty");
            return;
        }
        size_t r = ingraph.size();

        for (size_t i = 0; i < r; ++i) // check if the graph is a square matrix
        {
            if (ingraph[i].size() != r)
            {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
                return;
            }
        }
        this->matrix = ingraph;
        this->numVertices = r;
    }

    void Graph::printGraph()
    {
        int count = 0;
        int V = this->numVertices;
        for (size_t i = 0; i < V; i++)
        {
            for (size_t j = 0; j < V; j++)
            {
                std::cout << matrix[i][j] << " ";
                if (matrix[i][j] != 0)
                {
                    count++;
                }
            }
            std::cout << std::endl;
        }
        if (this->directed == true) // print the number of edges in the graph for directed graph
        {
            std::cout << "Graph with " << this->numVertices << " vertices and " << count << " edges" << std::endl;
        }
        else // print the number of edges in the graph for undirected graph
        {
            std::cout << "Graph with " << this->numVertices << " vertices and " << count / 2 << " edges" << std::endl;
        }
    }

}
