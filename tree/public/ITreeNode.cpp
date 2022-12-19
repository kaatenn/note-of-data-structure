//
// Created by 86137 on 2022/12/19.
//

#include "ITreeNode.h"

void ITreeNode::huffmanTree() {
    int src;
    vector<ITreeNode> nodes;
    cout << "���뼸�����������ڼ�����������ĳ�Ա���У����� -1 ��������" << endl;
    cin >> src;
    while (src != -1) {
        nodes.push_back(ITreeNode(src));
        cin >> src;
    }
    sort(nodes.begin(), nodes.end(), [&](const ITreeNode &a, const ITreeNode &b) { return a.data < b.data; });
    int count = 0;
    cout << "���ɹ��������Ĺ���Ϊ��" << endl;
    while (count < nodes.size() - 1) {
        ITreeNode node(nodes[count].data + nodes[count + 1].data);
        node.lChild = &nodes[count];
        node.rChild = &nodes[count + 1];
        nodes.push_back(node);
        cout << nodes[count].data << ' ' << nodes[count + 1].data << ' ' << node.data << endl;
        count += 2;
        sort(nodes.begin(), nodes.end(), [&](const ITreeNode &a, const ITreeNode &b) { return a.data < b.data; });
    }
}

ITreeNode::ITreeNode(int data) : data(data) {
    lChild = nullptr;
    rChild = nullptr;
}