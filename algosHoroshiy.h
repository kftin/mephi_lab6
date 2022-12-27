#include <vector>
#include <queue>
#include "graph.h"


template <typename TWeight>
vector<int> Dijkstra(Graph<TWeight> &graph, int start_, int end_) {
    queue<Node> q;
    q.push(graph.nodes[start_]);
    vector<TWeight> d(graph.nodes.size(), INT_MAX);
    d[start_] = 0;
    vector<int> p(graph.nodes.size(), -2);
    p[start_] = -1;
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
    vector<int> res;
    auto id = p[end_];
    res.push_back(p[end_]);
    while(graph.arcs[id].start != start_) {
        res.push_back(p[graph.arcs[id].start]);
        id = p[graph.arcs[id].start];
    }
    res.push_back(d[end_]);
    return res;
}

template <typename TWeight>
void Dfs(int *pos, int i, vector<int> &ans, vector<bool> &used, Graph<TWeight> &graph) {
    used[i] = true;
    for (auto arc_id: graph.nodes[i].outgoing) {
        if (used[graph.arcs[arc_id].end]) {
            continue;
        }
        Dfs(pos, graph.arcs[arc_id].end, ans, used, graph);
    }
    // ans.push_back(i);
    ans[*(pos)] = i;
    *(pos) -= 1;
}

template <typename TWeight>
vector<int> TopSort(Graph<TWeight> &graph) {
    vector<int> ans(graph.nodes.size(), -1);
    vector<bool> used(graph.nodes.size(), false);
    int *pos = new int[1];
    *(pos) = graph.nodes.size() - 1;
    for (int i = 0; i < (int)graph.nodes.size(); i++) {
        if (!used[i]) {
            Dfs(pos, i, ans, used, graph);
        }
    }
    delete[] pos;
    // reverse(ans.begin(), ans.end());
    return ans;
}

template <typename TWeight>
Graph<TWeight> SpanningTree(Graph<TWeight> &graph) {
    Graph<TWeight> res;
    res.AddNodes(graph.nodes.size());
    vector<bool> used(graph.nodes.size(), false);
    DfsST(3, used, graph, res);
    return res;
}


template <typename TWeight>
void DfsST(int v, vector<bool> &used, Graph<TWeight> &graph, Graph<TWeight> &res) {
    used[v] = true;
    for (auto arc_id: graph.nodes[v].outgoing) {
        auto edge = graph.arcs[arc_id];
        if (used[edge.end]) {
            continue;
        }
        res.AddArc(edge.start, edge.end, edge.weight);
        DfsST(edge.end, used, graph, res);
    }
    
}

