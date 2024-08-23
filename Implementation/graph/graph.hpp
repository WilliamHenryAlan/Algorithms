#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

#define vertexType string   //顶点数据类型
#define NO_EDGE 0           //表示无边

class Mgraph {
private:
    vector<vertexType> vertex;				    //顶点表
	vector<vector<int>> edge;			        //边表
    int vertexNum,arcNum;                       //顶点数量，边数量
    unordered_map<vertexType,int> vertexIndex;  //顶点索引映射：使用 unordered_map 来管理顶点名称与其在数组中的索引映射。这可以使操作顶点更方便，并提高查找效率。
public:
    Mgraph() 
    :vertexNum(0),arcNum(0) //邻接矩阵初始化：在构造函数中，所有边的初始值设为 NO_EDGE（即 0），表示这些边不存在。
    {
        for (vector<int>& vi:edge) {
            for (int& val:vi) {
                val = 0;
            }
        }
    }
    bool adjacent(const vertexType& x,const vertexType& y)const;                    //判断是否存在边<x,y> or (x,y)
    vector<vertexType> neighbor(const vertexType& x)const;                           //列出与x的邻接边
    vertexType firstNeighbor(const vertexType& x)const;                             //return节点x的第一个邻接点
    vertexType nextNeighbor(const vertexType& x,const vertexType& y)const;          //假设y是x的一个邻接点 return节点x除y外的第一个邻接点
    void insertVertex(const vertexType& x);                                         //插入节点x
    void deleteVertex(const vertexType& x);                                         //删除节点x
    bool addEdge(const vertexType& x,const vertexType& y,int weight = 1);           //添加连接节点x和节点y的边
    bool removeEdge(const vertexType& x,const vertexType& y);                       //移除连接节点x和节点y的边
    int getEdgeValue(const vertexType& x,const vertexType& y)const;
    void setEdgeValue(const vertexType& x,const vertexType& y,int weight = 1);
	void BFS(vertexType& v,vector<bool>& visited)const;
	void DFS(vertexType& start,vector<bool>& visited)const;
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
        vertexType vertex;//顶点类型
        arcNode* first;//第一个指向下一个顶点的指针
    };
    //邻接链表
    vector<vertexNode> adjList;
    int arcNum,vertexNum;
};
#endif
