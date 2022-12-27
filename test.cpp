#include <gtest/gtest.h>
#include "graph.h"
#include <exception>

TEST(BFS, bfs) {
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
    ASSERT_EQ(res[0], 5);
    ASSERT_EQ(res[1], 3);
    ASSERT_EQ(res[2], 6);
}

TEST(TopSort, ts) {
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
                          
    vector<int> res1 = TopSort(graph1);//6 5 4 2 1 0 3
    ASSERT_EQ(res1[0], 6);
    ASSERT_EQ(res1[1], 5);
    ASSERT_EQ(res1[2], 4);
    ASSERT_EQ(res1[3], 2);
    ASSERT_EQ(res1[4], 1);
    ASSERT_EQ(res1[5], 0);
    ASSERT_EQ(res1[6], 3);
}

TEST(SpanningTree, st) {
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
//33 3 1
//34 1 0
//35 1 2
//36 2 4
    Graph<int> graph3 = SpanningTree(graph2);
    int i = 33;
    for (const auto &[arc_id, arc] : graph3.arcs) {
        ASSERT_EQ(arc_id, i);
        i++;
    }
}


