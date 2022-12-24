//
// Created by 86137 on 2022/12/22.
//

#include "Graph.h"

Graph::Graph(Eigen::Matrix<int, 5, 5> collar, int data[5], int vexNum, Kind kind) {
    this->vexNum = vexNum;
    this->kind = kind;
    for (int i = 0; i < 5; ++i) {
        vertices[i] = VNode(data[i]);
        ArcNode *pArc;
        for (int j = 0; j < 5; ++j) {
            if (collar(i, j) != 0) {
                if (vertices[i].isSingle()) {
                    pArc = vertices[i].addArc(new ArcNode(j, collar(i, j)));
                } else {
                    pArc = pArc->addArc(new ArcNode(j, collar(i, j)));
                }
                if (i <= j || kind == Kind::DIRECTED) {
                    this->arcNum++;
                }
            }
        }
    }
}

void Graph::Kruskal() {
    int count, head, end;
    int assign[5]; // 连通分量标记
    vector<pair<int, ArcNode *> > minTree;
    vector<pair<int, ArcNode *> > vecArc; // 边集
    //初始化所有连通分量标记为不一样的值
    for (int i = 0; i < 5; ++i) {
        assign[i] = i;
    }
    for (int i = 0; i < vexNum; ++i) {
        ArcNode *pArc = vertices[i].getFirstArc();
        if (pArc && i <= pArc->getAdjVex())
            vecArc.emplace_back(i, pArc);
        while (pArc->getNextArc() && i <= pArc->getNextArc()->getAdjVex()) {
            pArc = pArc->getNextArc();
            vecArc.emplace_back(i, pArc);
        }
    }
    sort(vecArc.begin(), vecArc.end(),
         [](pair<int, ArcNode *> node1, pair<int, ArcNode *> node2) -> bool {
             return node1.second->getInfo() < node2.second->getInfo();
         });
    for (auto edge: vecArc) {
        head = edge.first;
        end = edge.second->getAdjVex();
        if (assign[head] != assign[end]) {
            minTree.emplace_back(edge);
            count++;
            for (int & i : assign) {
                if (i == assign[end]) {
                    i = assign[head];
                }
            }
        }
        if (count == 4)
            break;
    }
    for (auto edge: minTree) {
        cout << '<' << edge.first << ", " << edge.second->getAdjVex() << '>' << endl;
    }
}

void Graph::Prim() {
    bool visited[5]{false, false, false, false, false};
    int dis[5]{MAX_DIS, MAX_DIS, MAX_DIS, MAX_DIS, MAX_DIS};
    int parents[5]{-1, -1, -1, -1, -1};
    dis[0] = 0;
    parents[0] = -1;
    for (int i = 0; i < 4; ++i) {
        int min = MAX_DIS, minIndex;
        for (int v = 0; v < 5; ++v) {
            if (!visited[v] && dis[v] < min) {
                min = dis[v];
                minIndex = v;
            }
        }
        visited[minIndex] = true;
        ArcNode *pArc = vertices[minIndex].getFirstArc();
        if (pArc->getInfo() < dis[pArc->getAdjVex()] && !visited[pArc->getAdjVex()]) {
            parents[pArc->getAdjVex()] = minIndex;
            dis[pArc->getAdjVex()] = pArc->getInfo();
        }
        while (pArc->getNextArc()) {
            pArc = pArc->getNextArc();
            if (pArc->getInfo() < dis[pArc->getAdjVex()] && !visited[pArc->getAdjVex()]) {
                parents[pArc->getAdjVex()] = minIndex;
                dis[pArc->getAdjVex()] = pArc->getInfo();
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        cout << '<' << parents[i] << ", " << i << '>' << endl;
    }
}

ArcNode::ArcNode(int adjVex, int info, ArcNode *nextArc) {
    this->adjVex = adjVex;
    this->nextArc = nextArc;
    this->info = info;
}

ArcNode *ArcNode::addArc(ArcNode *nextArc) {
    this->nextArc = nextArc;
    return this->nextArc;
}

VNode::VNode(int data, ArcNode *firstArc) {
    this->data = data;
    this->firstArc = firstArc;
}
