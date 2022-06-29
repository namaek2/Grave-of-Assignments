#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#define DUMMY 0
#define INF 1e9 // use this to represent the infinity

using namespace std;

int temp = 0;

class DisjointSet {
private:
    vector<int> p;
    vector<int> rank;
public:
    DisjointSet(int n) {
        p = vector<int>(n + 1);
        rank = vector<int>(n + 1);
    }

    void make(int u) { p[u] = u; rank[u] = 0; }

    int find_us(int u) {
        if (p[u] != u) p[u] = find_us(p[u]);
        return p[u];
    }

    bool merge(int u, int v) {
        int ur = find_us(u);
        int vr = find_us(v);
        if (ur == vr) return false;

        if (rank[ur] > rank[vr]) 
            p[vr] = ur;
        else 
        {
            p[ur] = vr;
            if (rank[ur] == rank[vr]) rank[vr] = rank[vr] + 1;
        }
        return true;
    }
};

class Graph {
private:
    struct Edge {
        int u; int v; int w;
        Edge(int u, int v, int w) : u(u), v(v), w(w) { }
        bool operator < (const Edge& edge) const { return this->w < edge.w; }
    };

    vector<Edge> edges;            //edge list used for Kruskal's algorithm
    int n;                         //number of edges
public:
    Graph(int n) : n(n) {
        edges = vector<Edge>();
    }

    void insert_edge(int u, int v, int w) {
        edges.push_back(Edge(u, v, w));
    }

    vector<int> kruskal() {
        vector<int> kruskal_sequence(1, DUMMY); // store the weight of an edge
        DisjointSet set(n);

        sort(edges.begin(), edges.end());

        for (int i = 1; i <= temp; i++)
        {
            set.make(i);
        }

        for (Edge edge : edges)
        {
            int w = edge.w;
            int x = edge.u;
            int y = edge.v;

            if (set.find_us(x) != set.find_us(y))
            {
                set.merge(x, y);
                kruskal_sequence.push_back(w);
            }

            set.merge(x, y);
        }

        

        // fill in here
        //  - you can use std::sort() to sort edges
        //  - you can sequentially iterate each edge as follows:
        //     - for(Edge edge : edges)
        //  - push back the weight of an edge selected by Kruskal into kruskal_sequence
        //    (use kruskal_sequence.push_back(int weight))

        return kruskal_sequence;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // # of nodes
    int m; // # of edges
    int i; // index of a sequence to be printed
    cin >> n >> m >> i;

    temp = n;

    Graph graph(n);

    for (int j = 0; j < m; j++) {
        int s, t, w;
        cin >> s >> t >> w;
        graph.insert_edge(s, t, w);
    }

    vector<int> kruskal_sequence = graph.kruskal();

    // sum all entries of kruskal_sequence
    long long cost = std::accumulate(kruskal_sequence.begin(), kruskal_sequence.end(), 0L);

    cout << cost << endl;
    cout << kruskal_sequence[i] << endl;

    return 0;
}
