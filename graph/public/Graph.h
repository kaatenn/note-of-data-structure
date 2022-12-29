//
// Created by 86137 on 2022/12/22.
//

#ifndef NOTE_OF_DATA_STRUCTURE_GRAPH_H
#define NOTE_OF_DATA_STRUCTURE_GRAPH_H
#define MAX_VERTEX_NUM 6
#define MAX_DIS 65535

#include "bits/stdc++.h"
#include "eigen3/Eigen/Eigen"

using namespace std;

enum class Kind {
    UNDIRECTED,
    DIRECTED
};

//边结点
class ArcNode {
    int adjVex, info;
    ArcNode *nextArc;
public:
    ArcNode(int adjVex, int info, ArcNode *nextArc = nullptr);

    ArcNode *addArc(ArcNode *nextArc);

    int getAdjVex() {
        return adjVex;
    }

    ArcNode *getNextArc() {
        return nextArc;
    }

    int getInfo() { return info; }
};

//头结点
typedef class VNode {
    int data;
    ArcNode *firstArc;
public:
    VNode() = default;

    VNode(int data, ArcNode *firstArc = nullptr);

    bool isSingle() { return firstArc == nullptr; }

    ArcNode *addArc(ArcNode *arcNode) {
        this->firstArc = arcNode;
        return this->firstArc;
    }

    ArcNode *getFirstArc() {
        return firstArc;
    }
} VNode, AdjList[MAX_VERTEX_NUM];

class Graph {
    AdjList vertices;
    int vexNum, arcNum = 0;
    Kind kind;
public:
    Graph(Eigen::Matrix<int, 5, 5> collar, int data[5], int vexNum = 5, Kind kind = Kind::UNDIRECTED);

    Graph(Eigen::Matrix<int, 6, 6> collar, int vexNum = 6, Kind kind = Kind::DIRECTED);

    void topology();

    void Kruskal();

    void Prim();

    void Dijkstra();
};

#endif //NOTE_OF_DATA_STRUCTURE_GRAPH_H
