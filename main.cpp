#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    int is_intersecting(bool *s_visited, bool *t_visited);
    void add_edge(int u, int v);
    void print_path(int *s_parent, int *t_parent, int s,
                    int t, int intersect_node);
    void bfs(list<int> *queue, bool *visited, int *parent);
    int bidir_search(int s, int t);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::add_edge(int u, int v)
{
    this->adj[u].push_back(v);
    this->adj[v].push_back(u);
}

void Graph::bfs(list<int> *queue, bool *visited, int *parent)
{
    int current = queue->front();
    queue->pop_front();

    list<int>::iterator i;

    for (i = adj[current].begin(); i != adj[current].end(); ++i)
    {
        if (!visited[*i])
        {
            parent[*i] = current;
            visited[*i] = true;
            queue->push_back(*i);
        }
    }
}

int Graph::is_intersecting(bool *s_visited, bool *t_visited)
{
    for (int i = 0; i < V; ++i)
    {
        if (s_visited[i] && t_visited[i]) return i;
    }

    return -1;
}

void Graph::print_path(int *s_parent, int *t_parent, int s, int t, int intersect_node)
{
    vector<int> path;
    path.push_back(intersect_node);
    int i = intersect_node;

    while (i != s)
    {
        path.push_back(s_parent[i]);
        i = s_parent[i];
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
