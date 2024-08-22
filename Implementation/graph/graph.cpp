#include "graph.hpp"
void BFS(vertexType& v,vector<bool>& visited) {
    queue<int> q;
    q.push(vertexIndex[v]);//从起始顶点开始访问
    visited[v] = true;//对start做标记

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

bool Mgraph::adjacent(const vertexType& x,const vertexType& y)const                    //判断是否存在边<x,y> or (x,y)
{
    if (vertexIndex.contains(x) || vertexIndex.contains(y)) {
        int ix = vertexIndex[x];
        int iy = vertexIndex[y];
        return edge[ix][iy] != NO_EDGE;
    }
    return false;
}
vector<vertexType> Mgraph::neighbor(const vertexType& x)const                                        //列出与x的邻接边
{
	vector<vertexType> neighbor;
	if (vertexIndex.find(x) == vertexIndex.end()) return neighbor;	//错误处理：方法中加入了对非法顶点和边的检查，比如顶点不存在时的返回值，避免操作非法数据。
	int ix = vertexIndex[x];
	for (int i = 0;i < vertexNum;i++) {
		if (edge[ix][i] == NO_EDGE) continue;
		neighbor.push_back(vertex[i]);
	}
	return neighbor;
}
vertexType Mgraph::firstNeighbor(const vertexType& x)const                             //return节点x的第一个邻接点
{
	
}
vertexType Mgraph::nextNeighbor(const vertexType& x,const vertexType& y)const;          //假设y是x的一个邻接点 return节点x除y外的第一个邻接点
void Mgraph::insertVertex(const vertexType& x);                                         //插入节点x
void Mgraph::deleteVertex(const vertexType& x);                                         //删除节点x
bool Mgraph::addEdge(const vertexType& x,const vertexType& y);                          //添加连接节点x和节点y的边
bool Mgraph::removeEdge(const vertexType& x,const vertexType& y);                       //移除连接节点x和节点y的边
void Mgraph::getEdgeValue(const vertexType& x,const vertexType& y)const;
void Mgraph::setEdgeValue(const vertexType& x,const vertexType& y);







vertexType firstNeighbor(const vertexType& x) const {
        if (vertexIndex.find(x) == vertexIndex.end()) return "";
        int ix = vertexIndex.at(x);
        for (int i = 0; i < vertexNum; i++) {
            if (edge[ix][i] != NO_EDGE) {
                return vertex[i];
            }
        }
        return "";
    }

    vertexType nextNeighbor(const vertexType& x, const vertexType& y) const {
        if (vertexIndex.find(x) == vertexIndex.end() || vertexIndex.find(y) == vertexIndex.end()) return "";
        int ix = vertexIndex.at(x);
        int iy = vertexIndex.at(y);
        for (int i = iy + 1; i < vertexNum; i++) {
            if (edge[ix][i] != NO_EDGE) {
                return vertex[i];
            }
        }
        return "";
    }

    void insertVertex(const vertexType& x) {
        if (vertexIndex.find(x) != vertexIndex.end()) return; // 已存在该顶点
        if (vertexNum >= MaxVertexNum) return; // 顶点数目超限
        vertex[vertexNum] = x;
        vertexIndex[x] = vertexNum;
        vertexNum++;
    }

    void deleteVertex(const vertexType& x) {
        if (vertexIndex.find(x) == vertexIndex.end()) return; // 顶点不存在
        int ix = vertexIndex[x];
        for (int i = 0; i < vertexNum; i++) {
            edge[ix][i] = NO_EDGE; // 删除与该顶点相连的所有边
            edge[i][ix] = NO_EDGE;
        }
        vertexIndex.erase(x);
        for (int i = ix; i < vertexNum - 1; i++) {
            vertex[i] = vertex[i + 1];
            vertexIndex[vertex[i]] = i;
            for (int j = 0; j < vertexNum; j++) {
                edge[i][j] = edge[i + 1][j];
                edge[j][i] = edge[j][i + 1];
            }
        }
        vertexNum--;
    }

    bool addEdge(const vertexType& x, const vertexType& y, int weight = 1) {
        if (vertexIndex.find(x) == vertexIndex.end() || vertexIndex.find(y) == vertexIndex.end()) return false;
        int ix = vertexIndex[x];
        int iy = vertexIndex[y];
        if (edge[ix][iy] != NO_EDGE) return false; // 边已存在
        edge[ix][iy] = weight;
        arcNum++;
        return true;
    }

    bool removeEdge(const vertexType& x, const vertexType& y) {
        if (vertexIndex.find(x) == vertexIndex.end() || vertexIndex.find(y) == vertexIndex.end()) return false;
        int ix = vertexIndex[x];
        int iy = vertexIndex[y];
        if (edge[ix][iy] == NO_EDGE) return false; // 边不存在
        edge[ix][iy] = NO_EDGE;
        arcNum--;
        return true;
    }

    int getEdgeValue(const vertexType& x, const vertexType& y) const {
        if (vertexIndex.find(x) == vertexIndex.end() || vertexIndex.find(y) == vertexIndex.end()) return NO_EDGE;
        int ix = vertexIndex.at(x);
        int iy = vertexIndex.at(y);
        return edge[ix][iy];
    }

    void setEdgeValue(const vertexType& x, const vertexType& y, int weight) {
        if (vertexIndex.find(x) == vertexIndex.end() || vertexIndex.find(y) == vertexIndex.end()) return;
        int ix = vertexIndex[x];
        int iy = vertexIndex[y];
        edge[ix][iy] = weight;
    }

