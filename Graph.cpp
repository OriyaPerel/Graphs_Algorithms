#include "Graph.hpp"
#include <iostream>

// id:322522806
// email:oriyaperel18@gmail.com

namespace ariel
{
    Graph::Graph()
    { // default constructor
        this->directed = true;
    }

    Graph::Graph(bool directed)
    {
        this->directed = directed;
    }

    const std::vector<std::vector<int>> &Graph::getGraph() const 
    {
        return this->g;
    }

    bool Graph::isdirected()const 
    {
        return this->directed;
    }

    int Graph::getNumEdge()const
    {
        int count = 0;
        int V = this->col;
        for (size_t i = 0; i < V; i++)
        {
            for (size_t j = 0; j < V; j++)
            {
                if (g[i][j] != 0)
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

    size_t Graph::getNumVertices()const 
    {
        return this->g.size();
    }

    void Graph::loadGraph(std::vector<std::vector<int>> ingraph)
    {
        if (ingraph.empty())
        {
            throw std::invalid_argument("Invalid graph: The graph is empty");
            return;
        }
        size_t r = ingraph.size();
        size_t c = ingraph[0].size();

        for (size_t i = 0; i < r; ++i)
        {
            if (ingraph[i].size() != r)
            {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
                return;
            }
        }
        this->g = ingraph;
        this->row = r;
        this->col = c;
    }

    void Graph::printGraph()
    {
        int count = 0;
        int V = this->col;
        for (size_t i = 0; i < V; i++)
        {
            for (size_t j = 0; j < V; j++)
            {
                std::cout << g[i][j] << " ";
                if (g[i][j] != 0)
                {
                    count++;
                }
            }
            std::cout << std::endl;
        }
        if (this->directed == true)
        {
            std::cout << "Graph with " << row << " vertices and " << count << " edges" << std::endl;
        }
        else
        {
            std::cout << "Graph with " << row << " vertices and " << count / 2 << " edges" << std::endl;
        }
    }

}
