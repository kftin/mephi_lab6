#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>
#include "graph.h"

using namespace std;

template <typename TWeight>
vector<Arc<Tweigth>> Dijkstra(Graph<TWeight> &graph, int start, int end) {
    queue<Node> q;
    q.push(graph.nodes[start]);
    vector<TWeight> d(graph.nodes.size(), INT_MAX);
    d[start] = 0;
    vector<int> p(graph.nodes.size());
    p[start] = -1;
    while (!q.empty()) {
        Node v = q.front();
        q.pop();
        for (auto arc_id: v.outgoing) {
            auto arc = graph.arcs[arc_id];
            if (d[arc.start] + arc.weight < d[arc.end]) {
                d[arc.end] = d[arc.start] + arc.weight;
                p[arc.end] = arc_id;
                q.push(graph.nodes[arc.end]);
            }
        }
    }
}

int main() {
    Graph<int> graph;
    graph.AddNodes(5);
    graph.AddArc(1, 2, 9);
    graph.AddArc(2, 4, 5);
    graph.AddArc(1, 3, 2);
    graph.AddArc(1, 5, 1);
    graph.AddArc(2, 3, 3);
    graph.AddArc(3, 2, 3);
    graph.AddArc(3, 5, 6);
    graph.AddArc(3, 4, 9);
    graph.AddArc(5, 3, 6);
    graph.AddArc(5, 4, 7);

    

}
