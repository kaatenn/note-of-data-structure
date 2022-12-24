//
// Created by 86137 on 2022/12/24.
//
#include "public/Graph.h"

int main() {
    Eigen::Matrix<int, 5, 5> collar;
    int data[5]{3, 5, 2, 4, 1};
    collar << 0, 3, 1, 0, 1,
            3, 0, 4, 2, 0,
            1, 4, 0, 5, 3,
            0, 2, 5, 0, 0,
            1, 0, 3, 0, 0;
    Graph graph(collar, data);
    cout << "Kruskal" << endl;
    graph.Kruskal();
    cout << "Prim" << endl;
    graph.Prim();
    return 0;
}