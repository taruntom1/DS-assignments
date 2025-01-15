#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <functional>

class Node;

struct edge_to_cost
{
    Node *to;
    int cost;
};

class Node
{
public:
    int data;
    std::vector<edge_to_cost> edges;

    Node(int val)
    {
        data = val;
    }

    void newNeighbour(int data, int cost)
    {
        edges.push_back(edge_to_cost{new Node(data), cost});
    }

    void linkNeighbours(const std::vector<Node *> &newNeighbours, const std::vector<int> &newCosts)
    {
        if (newNeighbours.size() != newCosts.size())
        {
            std::cerr << "Error: Neighbours and costs must have the same size!" << std::endl;
            return;
        }
        for (size_t i = 0; i < newNeighbours.size(); ++i)
        {
            edges.push_back(edge_to_cost{newNeighbours[i], newCosts[i]});
            newNeighbours[i]->edges.push_back({this, newCosts[i]});
        }
    }
};

template <typename Func, typename... Args>
void bfs(Node *start, Func func, Args &&...args)
{
    std::unordered_set<Node *> visited;
    std::queue<Node *> q;

    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        func(curr, std::forward<Args>(args)...);

        for (auto edge : curr->edges)
        {
            if (visited.find(edge.to) == visited.end())
            {
                q.push(edge.to);
                visited.insert(edge.to);
            }
        }
    }
}

std::vector<int> dfs(Node *start)
{
    std::set<Node *> visited;
    std::stack<Node *> s;
    std::vector<int> result;

    s.push(start);
    visited.insert(start);

    while (!s.empty())
    {
        auto curr = s.top();
        s.pop();
        result.push_back(curr->data);
        for (auto edge : curr->edges)
        {
            if (visited.find(edge.to) == visited.end())
            {
                s.push(edge.to);
                visited.insert(edge.to);
            }
        }
    }
    return result;
}

struct Edge
{
    Node *from;
    Node *to;
    int cost;
};

struct compare
{
    bool operator()(const Edge &a, const Edge &b)
    {
        return a.cost > b.cost;
    }
};

std::vector<Edge> prims(Node *start)
{
    std::priority_queue<Edge, std::vector<Edge>, compare> pq;
    std::set<Node *> visited;
    std::vector<Edge> result;

    for (const auto &edge : start->edges)
    {
        pq.push(Edge{start, edge.to, edge.cost});
    }
    visited.insert(start);

    while (!pq.empty())
    {

        auto curr = pq.top();
        pq.pop();
        if (visited.find(curr.to) != visited.end())
            continue;
        visited.insert(curr.to);
        result.push_back(curr);

        for (auto edge : curr.to->edges)
        {

            pq.push(Edge{curr.to, edge.to, edge.cost});
        }
    }

    return result;
}

void getEdges(Node *node, std::priority_queue<Edge, std::vector<Edge>, compare> &pq)
{
    if (node == nullptr)
        return;
    for (auto edge : node->edges)
        pq.push(Edge{node, edge.to, edge.cost});
}

void getNodes(Node *node, std::vector<Node *> &nodes)
{
    if (node != nullptr)
    {
        nodes.push_back(node);
    }
}

class DSU
{
    std::unordered_map<Node *, Node *> parent;
    std::unordered_map<Node *, int> rank;

public:
    void makeSet(Node *node)
    {
        parent[node] = node;
        rank[node] = 0;
    }

    Node *find(Node *node)
    {
        if (parent[node] != node)
        {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void unionSets(Node *x, Node *y)
    {
        Node *rootX = find(x);
        Node *rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootY] > rank[rootX])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

std::vector<Edge> kruskalsDSU(Node *start)
{
    std::priority_queue<Edge, std::vector<Edge>, compare> edges;
    DSU dsu;
    std::vector<Node *> nodes;
    bfs(start, getNodes, nodes);

    for (auto node : nodes)
    {
        dsu.makeSet(node);
    }

    bfs(start, getEdges, edges);

    std::vector<Edge> mst_edges;
    while (!edges.empty() && mst_edges.size() < (nodes.size() - 1))
    {
        Edge curr = edges.top();
        edges.pop();

        if (dsu.find(curr.from) != dsu.find(curr.to))
        {
            mst_edges.push_back(curr);
            dsu.unionSets(curr.from, curr.to);
        }
    }
    return mst_edges;
}

std::vector<Edge> kruskals(Node *start)
{
    std::priority_queue<Edge, std::vector<Edge>, compare> edges;
    std::vector<std::unordered_set<Node *>> visited_groups;
    std::vector<Edge> result;

    bfs(start, getEdges, edges);

    while (!edges.empty())
    {
        Edge curr = edges.top();
        edges.pop();

        int i = 0;
        int edge_from_group = -1;
        int edge_to_group = -1;

        for (auto group : visited_groups)
        {
            if (group.find(curr.from) != group.end())
            {
                edge_from_group = i;
            }
            if (group.find(curr.to) != group.end())
            {
                edge_to_group = i;
            }
            if (edge_from_group != -1 && edge_to_group != -1)
                break;
            i++;
        }

        if (edge_from_group == -1 && edge_to_group == -1)
        {
            visited_groups.push_back(std::unordered_set<Node *>{curr.from, curr.to});
            result.push_back(curr);
        }
        else if (edge_from_group == -1)
        {
            visited_groups[edge_to_group].insert(curr.from);
            result.push_back(curr);
        }
        else if (edge_to_group == -1)
        {
            visited_groups[edge_from_group].insert(curr.to);
            result.push_back(curr);
        }
        else if (edge_from_group != edge_to_group)
        {
            visited_groups[edge_from_group].insert(visited_groups[edge_to_group].begin(), visited_groups[edge_to_group].end());

            visited_groups.erase(visited_groups.begin() + edge_to_group);
            result.push_back(curr);
        }
    }

    return result;
}

struct dijkstras_pq_element
{
    Node *curr;
    Node *prev;
    int dist;

    bool operator>(const dijkstras_pq_element &other) const
    {
        return dist > other.dist;
    }
};

std::unordered_map<Node *, std::pair<std::vector<Node *>, int>> dijkstras(Node *start)
{
    std::unordered_map<Node *, std::pair<int, Node *>> table;
    std::unordered_map<Node *, std::pair<std::vector<Node *>, int>> paths;

    std::priority_queue<dijkstras_pq_element, std::vector<dijkstras_pq_element>, std::greater<>> pq;
    pq.push({start, nullptr, 0});

    while (!pq.empty())
    {
        dijkstras_pq_element curr = pq.top();
        pq.pop();

        // Skip if node has already been visited
        if (table.find(curr.curr) != table.end())
            continue;

        table[curr.curr] = {curr.dist, curr.prev};

        for (auto edge : curr.curr->edges)
        {
            int new_dist = curr.dist + edge.cost;
            if (table.find(edge.to) == table.end() || new_dist < table[edge.to].first)
            {
                pq.push({edge.to, curr.curr, new_dist});
            }
        }
    }

    // Reconstruct paths
    for (const auto &[node, info] : table)
    {
        int dist = info.first;
        Node *prev = info.second;

        std::vector<Node *> path;
        Node *current = node;
        while (prev)
        {
            path.push_back(prev);
            prev = table[prev].second;
        }
        std::reverse(path.begin(), path.end());

        paths[node] = {path, dist};
    }

    return paths;
}

int main()
{
    // Create a vector to hold pointers to Node objects
    std::vector<Node *> nodes;

    // Initialize nodes with values from 0 to 10
    for (int i = 0; i < 11; i++)
    {
        nodes.push_back(new Node(i));
    }

    // Establish links between nodes with corresponding edge weights
    nodes[0]->linkNeighbours({nodes[1], nodes[2], nodes[4]}, {5, 3, 7});
    nodes[1]->linkNeighbours({}, {}); // No outgoing edges
    nodes[2]->linkNeighbours({nodes[1], nodes[3], nodes[5], nodes[6]}, {4, 6, 2, 8});
    nodes[3]->linkNeighbours({}, {}); // No outgoing edges
    nodes[4]->linkNeighbours({nodes[7]}, {4});
    nodes[5]->linkNeighbours({nodes[6]}, {2});
    nodes[6]->linkNeighbours({nodes[8], nodes[10]}, {5, 7});
    nodes[7]->linkNeighbours({nodes[9]}, {4});
    nodes[8]->linkNeighbours({nodes[10]}, {3});
    nodes[9]->linkNeighbours({nodes[10]}, {1});
    nodes[10]->linkNeighbours({}, {}); // No outgoing edges

    // Perform Breadth-First Search (BFS) and store result in bfsresult vector
    std::vector<Node *> bfsresult;
    bfs(nodes[0], getNodes, bfsresult);
    std::cout << "BFS Traversal Order:" << std::endl;

    // Print BFS traversal order
    for (auto i : bfsresult)
    {
        std::cout << i->data << " ";
    }
    std::cout << std::endl
              << std::endl;

    // Perform Depth-First Search (DFS) and store result in dfsresult vector
    std::vector<int> dfsresult = dfs(nodes[0]);
    std::cout << "DFS Traversal Order:" << std::endl;

    // Print DFS traversal order
    for (auto i : dfsresult)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl
              << std::endl;

    // Print the edges of the graph
    std::cout << "Edges" << std::endl;

    std::priority_queue<Edge, std::vector<Edge>, compare> pq;

    bfs(nodes[0], getEdges, pq);

    while (!pq.empty())
    {
        std::cout << pq.top().from->data << "-->" << pq.top().to->data << " "
                  << pq.top().cost << std::endl;
        pq.pop();
    }

    // Perform Prim's algorithm to find the Minimum Spanning Tree (MST)
    std::cout << "Prim's:" << std::endl;
    std::vector<Edge> primsResult = prims(nodes[0]);

    int total_edge_weight = 0;

    for (auto e : primsResult)
    {
        if (e.from)
        {
            std::cout << e.from->data << "-->" << e.to->data << " "
                      << e.cost << std::endl;
            total_edge_weight += e.cost;
        }
    }

    std::cout << "total edge weight: " << total_edge_weight << std::endl
              << std::endl;

    std::cout << "Kruskal's:" << std::endl;
    std::vector<Edge> kruskalsResult = kruskals(nodes[0]);

    total_edge_weight = 0;

    for (auto e : kruskalsResult)
    {
        if (e.from)
        {
            std::cout << e.from->data << "-->" << e.to->data << " "
                      << e.cost << std::endl;
            total_edge_weight += e.cost;
        }
    }

    std::cout << "total edge weight: " << total_edge_weight << std::endl
              << std::endl;

    std::cout << "Kruskal's DSU:" << std::endl;
    std::vector<Edge> kruskalsResultDSU = kruskalsDSU(nodes[0]);

    total_edge_weight = 0;

    for (auto e : kruskalsResultDSU)
    {
        if (e.from)
        {
            std::cout << e.from->data << "-->" << e.to->data << " " << e.cost
                      << std::endl;
            total_edge_weight += e.cost;
        }
    }

    std::cout << "total edge weight: " << total_edge_weight << std::endl
              << std::endl;

    std::cout << "Dijkstra's Algorithm:" << std::endl;

    std::unordered_map<Node *, std::pair<std::vector<Node *>, int>> dijkstra_result = dijkstras(nodes[0]);

    for (auto element : dijkstra_result)
    {
        std::cout << element.first->data << " -> ";
        for (auto node : element.second.first)
        {
            std::cout << node->data << " -> ";
        }
        std::cout << "cost: " << element.second.second << std::endl;
    }
}
