#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
// id:322522806
// email:oriyaperel18@gmail.com

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("empty graph")
{
    ariel::Graph g;
    CHECK_THROWS_WITH(Algorithms::isBipartite(g), "Invalid graph: The graph is empty");
    CHECK_THROWS_WITH(Algorithms::isConnected(g), "Invalid graph: The graph is empty");
    CHECK_THROWS_WITH(Algorithms::shortestPath(g, 1, 2) ,"Invalid graph: The graph is empty");
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "No path found");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == "No cycle found");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isContainsCycle(g) == "Cycle: 0 1 2 0 ");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isBipartite(g) == "not Bipartite");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, -1, 4, 0, 0},
        {0, 0, 3, 2, 2},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {-3, 0, 0, 1, 0},
    };
    g.loadGraph(graph);
    CHECK(Algorithms::negativeCycle(g) == "Negative cycle found! Cycle: 1 4 0 1 ");
}

TEST_CASE("Test for checking if graph has one vertex")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {{2}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isConnected(g) == 1);
    CHECK(Algorithms::isContainsCycle(g) == "No cycle found");
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={}");
}

TEST_CASE("infinity shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, -1},
        {-1, 0}};
    g.loadGraph(graph1);

    CHECK(Algorithms::negativeCycle(g) == "Negative cycle found! Cycle: 1 0 1 ");
    CHECK(Algorithms::shortestPath(g, 0, 1) == "No path found");
}

TEST_CASE("shortestPath from vertex to itself")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 5},
        {5, 0}};
    g.loadGraph(graph1);

    CHECK(Algorithms::shortestPath(g, 0, 0) == "this is the same vertex");
}
TEST_CASE("graph without edges")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 0},
        {0, 0}};
    g.loadGraph(graph1);

    CHECK(Algorithms::shortestPath(g, 0, 1) == "No path found");
    CHECK(Algorithms::isConnected(g) == 0);
}

TEST_CASE("shortest path between vertes that not existent")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 0},
        {0, 0}};
    g.loadGraph(graph1);
    CHECK_THROWS_WITH(Algorithms::shortestPath(g, 0, 3), "Invalid vertex: The vertex does not exist");
}
TEST_CASE("empty graph")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {};

    CHECK_THROWS(g.loadGraph(graph1));
    CHECK_THROWS(Algorithms::isConnected(g));
    CHECK_THROWS(Algorithms::negativeCycle(g));
    CHECK_THROWS(Algorithms::shortestPath(g, 0, 1));
    CHECK_THROWS(Algorithms::isContainsCycle(g));
}
TEST_CASE("contains a negative circle with a positive graph")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g.loadGraph(graph1);

    CHECK(Algorithms::negativeCycle(g) == "No negative cycle found.");
}

TEST_CASE("cycle from vertex to itself")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {1, 0},
        {0, 0}};
    g.loadGraph(graph1);

    CHECK(Algorithms::isContainsCycle(g) == "No cycle found");
}

TEST_CASE("have a cycle but not negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 4, 0, 0},
        {0, 0, 3, 2, 2},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {-3, 0, 0, 1, 0},
    };
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == "Cycle: 0 1 2 0 ");
    CHECK(Algorithms::negativeCycle(g) == "No negative cycle found.");
}

TEST_CASE("undirected Connected")
{
    ariel::Graph g1(false);
    vector<vector<int>> graph6 = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph6);
    CHECK(Algorithms::isConnected(g1) == true);
}

TEST_CASE("undirected ContainsCycle")
{
    ariel::Graph g1(false);
    vector<vector<int>> graph6 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph6);

    CHECK(Algorithms::isContainsCycle(g1) == "Cycle: 0 1 2 0 ");
}

TEST_CASE("graph that all the vertice are not connected")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph1);

    CHECK(Algorithms::isConnected(g) == 0);
    CHECK(Algorithms::isContainsCycle(g) == "No cycle found");
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2}, B={}");
}
