#include "graph.hpp"

void Mgraph::DFS(vertexType& start,vector<bool>& visited)const {

}

void Mgraph::BFS(vertexType& start,vector<bool>& visited)const {
	queue<int> q;
	q.push(vertexIndex[start]);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int w = 0;w < vertexNum;w++) {
			if (edge[v][w] != NO_EDGE && visited[w] == false) {
				cout << vertex[w] << " ";
				visited.at(w) = true;
				q.push(w);
			}
		}
	}
}

bool Mgraph::adjacent(const vertexType& x,const vertexType& y)const                    //判断是否存在边<x,y> or (x,y)
{
    if (vertexIndex.contains(x) || vertexIndex.contains(y)) {
        int ix = vertexIndex.at(x);
        int iy = vertexIndex.at(y);
        return edge[ix][iy] != NO_EDGE;
    }
    return false;
}
vector<vertexType> Mgraph::neighbor(const vertexType& x)const                                        //列出与x的邻接边
{
	vector<vertexType> neighbor;
	if (vertexIndex.find(x) == vertexIndex.end()) return neighbor;	//错误处理：方法中加入了对非法顶点和边的检查，比如顶点不存在时的返回值，避免操作非法数据。
	int ix = vertexIndex.at(x);
	for (int i = 0;i < vertexNum;i++) {
		if (edge[ix][i] == NO_EDGE) continue;
		neighbor.push_back(vertex[i]);
	}
	return neighbor;
}
vertexType Mgraph::firstNeighbor(const vertexType& x)const                             //return节点x的第一个邻接点
{
	vertexType v = "null";
	int ix = vertexIndex.at(x);
	for (int i = 0;i < vertexNum;i++) {
		if (edge[ix][i] != NO_EDGE) return vertex[i];
	}
	return v;
}
vertexType Mgraph::nextNeighbor(const vertexType& x,const vertexType& y)const          //假设y是x的一个邻接点 return节点x除y外的第一个邻接点
{
	vertexType v = "null";
	int ix = vertexIndex.at(x);
    int iy = vertexIndex.at(y);
	for (int i = iy + 1;i < vertexNum;i++) {
		if (edge[ix][i] != NO_EDGE) return vertex[i];
	}
	return v;
}
void Mgraph::insertVertex(const vertexType& x)                                         //插入节点x 
{
	vertex.push_back(x);
	vertexIndex[x] = vertexNum++;
}
void Mgraph::deleteVertex(const vertexType& x)                                         //删除节点x
{
	int ix = vertexIndex[x];
	for (int i = 0; i < vertexNum; i++) {
		edge[ix][i] = NO_EDGE; // 删除与该顶点相连的所有边
		edge[i][ix] = NO_EDGE;
	}
	vertexIndex.erase(x);
	vertex[ix] = "null";
	vertexNum--;
}
bool Mgraph::addEdge(const vertexType& x,const vertexType& y,int weight)                //添加连接节点x和节点y的边
{
	int ix = vertexIndex[x];
    int iy = vertexIndex[y];
	if (edge[ix][iy] != NO_EDGE) return false; // 边已存在
	edge[ix][iy] = weight;
	arcNum++;
	return true;
}
bool Mgraph::removeEdge(const vertexType& x,const vertexType& y)                       //移除连接节点x和节点y的边
{
	if (vertexIndex.find(x) == vertexIndex.end() || vertexIndex.find(y) == vertexIndex.end()) return false;
        int ix = vertexIndex[x];
        int iy = vertexIndex[y];
        if (edge[ix][iy] == NO_EDGE) return false; // 边不存在
        edge[ix][iy] = NO_EDGE;
        arcNum--;
        return true;
}
int Mgraph::getEdgeValue(const vertexType& x,const vertexType& y)const {
	if (vertexIndex.find(x) == vertexIndex.end() || vertexIndex.find(y) == vertexIndex.end()) return NO_EDGE;
        int ix = vertexIndex.at(x);
        int iy = vertexIndex.at(y);
        return edge[ix][iy];
}
void Mgraph::setEdgeValue(const vertexType& x,const vertexType& y,int weight) {
	if (vertexIndex.find(x) == vertexIndex.end() || vertexIndex.find(y) == vertexIndex.end()) return;
        int ix = vertexIndex[x];
        int iy = vertexIndex[y];
        edge[ix][iy] = weight;
}
