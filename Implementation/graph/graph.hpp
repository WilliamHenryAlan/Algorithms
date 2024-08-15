#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define MaxVertexNum 100//顶点最大数目
#define station string//顶点数据类型
class Mgraph {
private:
    station vertex[MaxVertexNum];//顶点表
    int edge[MaxVertexNum][MaxVertexNum];//边表
    int vertexNum,arcNum;//顶点数量，边数量
public:
    Mgraph() {}
};

class ALGraph {
private:
    //边表
    struct arcNode {
        int weight;//权值
        arcNode* next;//指向下一条arc的指针
        int index;//指向node的index
    };
    //顶点表
    struct vertexNode {
        station vertex;//顶点类型
        arcNode* first;//第一个指向下一个顶点的指针
    };
    //邻接链表
    vertexNode adjList[MaxVertexNum];
    int arcNum,vertexNum;
};
void BFS(int start, vector<vector<int>>& adj, vector<bool>& visited);
#endif
