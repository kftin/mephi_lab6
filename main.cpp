#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>
#include "graph.h"
#include "algosHoroshiy.h"
#include <algorithm>

using namespace std;

int main() {
    //////////////////////////////////tests for find ways
    Graph<int> graph;
    graph.AddNodes(5);
    graph.AddArc(0, 1, 9);//1
    graph.AddArc(1, 3, 5);//2
    graph.AddArc(0, 2, 2);//3
    graph.AddArc(0, 4, 1);//4
    graph.AddArc(1, 2, 3);//5
    graph.AddArc(2, 1, 3);//6
    graph.AddArc(2, 4, 6);//7
    graph.AddArc(2, 3, 9);//8
    graph.AddArc(4, 2, 6);//9
    graph.AddArc(4, 3, 7);//10

    vector<int> res = Dijkstra(graph, 0, 1);
    reverse(res.begin(), res.end());
    cout << "arc id: ";
    for (int i = 1; i < (int)res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << endl << "shortest distance to node: " << res[0] << endl;

    /////////////////////////////////tests for topsort
    Graph<int> graph1;
    graph1.AddNodes(7);
    graph1.AddArc(0, 3, 1);//11
    graph1.AddArc(1, 3, 1);//12
    graph1.AddArc(2, 3, 1);//13
    graph1.AddArc(4, 3, 1);//14
    graph1.AddArc(4, 1, 1);//15
    graph1.AddArc(5, 2, 1);//16
    graph1.AddArc(5, 4, 1);//17
    graph1.AddArc(5, 3, 1);//18
    graph1.AddArc(6, 4, 1);//19
    graph1.AddArc(6, 2, 1);//20
                          
    vector<int> res1 = TopSort(graph1);
    cout << "size of res1 " << res1.size() << endl;
    cout << "topsort of nodes: ";
    for (int i = 0; i < (int)res1.size(); i++) {
        cout << res1[i] << ' ';
    }
    cout << endl;
    
    /////////////////////////////////tests for spanning tree in graph
    
    Graph<int> graph2;
    graph2.AddNodes(7);
    graph2.AddArc(0, 1, 1);//21
    graph2.AddArc(1, 0, 1);//22
    graph2.AddArc(1, 3, 1);//23
    graph2.AddArc(3, 1, 1);//24
    graph2.AddArc(1, 2, 1);//25
    graph2.AddArc(2, 1, 1);//26
    graph2.AddArc(2, 3, 1);//27
    graph2.AddArc(3, 2, 1);//28
    graph2.AddArc(3, 4, 1);//29
    graph2.AddArc(4, 3, 1);//30
    graph2.AddArc(2, 4, 1);//31
    graph2.AddArc(4, 2, 1);//32
    
    Graph<int> graph3 = SpanningTree(graph2);
    cout << "new Graph-spanningTree: id startNode endNode" << endl;
    for (const auto &[arc_id, arc] : graph3.arcs) {
        cout << arc_id << ' ' << arc.start << ' ' << arc.end << endl;
    }
}
