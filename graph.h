#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node {
    public:
        vector<int> outgoing;

        Node():outgoing() {}
};

template <typename TWeight>
class Arc {
    public:
        int start;
        int end;
        TWeight weight;

        Arc(): start(), end(), weight() {}

        Arc(int start_, int end_, TWeight weight_) {
            this->start = start_;
            this->end = end_;
            this->weight = weight_;
        }
};

template <typename TWeight>
class Graph {
    public:
        inline static int id = 100;
        map<int, Arc<TWeight>> arcs;
        vector<Node> nodes;

        Graph():arcs(), nodes() {}

        void AddNode() {    
            Node newNode;
            nodes.push_back(newNode);
        }

        void AddNodes(int count) {
            for (int i = 0; i < count; i++) {
                Node newNode;
                nodes.push_back(newNode);
            }
        }

        void AddArc(int start, int end, TWeight weight) {
            Arc arc(start, end, weight);
            nodes[start].outgoing.push_back(id);
            arcs[id++] = arc;
        }
};



