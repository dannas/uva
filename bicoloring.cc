#include <vector>
#include <iostream>
#include <list>

using namespace std;

struct Graph
{
    int V;
    vector<list<int> > adj;

    Graph(int n)
        : V(n), adj(n, list<int>()) {}
    
    void add_edge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
};

struct TwoColor
{
    vector<bool> marked;
    vector<bool> color;
    bool isTwoColorable;

    TwoColor(Graph &G)
        : marked(G.V, false), color(G.V, false), isTwoColorable(true)
    {
        for (int s = 0; s < G.V; s++)
            if (!marked[s])
                dfs(G, s);
    }

    void dfs(Graph &G, int v)
    {
        marked[v] = true;
        list<int>::iterator i;
        for (i = G.adj[v].begin(); i != G.adj[v].end(); ++i) {
            if (!marked[*i]) {
                color[*i] = !color[v];
                dfs(G, *i);
            } else if (color[v] == color[*i])
                isTwoColorable = false;
        }
    }
};

int main(int argc, const char *argv[])
{
    int ncases;
    cin >> ncases;

    while (ncases--) {
        int N, v, w;
        cin >> N;

        if (N == 0)
            break;

        Graph G(N);

        for (int i = 0; i < N; i++) {
            cin >> v >> w;
            G.add_edge(v, w);
        }
        TwoColor C(G);

        if (C.isTwoColorable)
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}
