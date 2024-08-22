class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertexNum = isConnected.size();         //获取邻接矩阵顶点数量
        vector<bool> visited(vertexNum,false);      //记录是否有未访问的vertex
        int ans = 0;
        auto bfs = [&](int start) {
            queue<int> q;                           //用队列辅助
            q.push(start);                          //push进起始顶点
            visited[start] = true;
            while (!q.empty()) {                    //队列不为空
                int v = q.front();                  //暂存队头元素
                q.pop();
                for (int w = 0;w < vertexNum;w++) { //遍历v的row
                    if (isConnected[v][w] == 1 && !visited[w]) { //如果有边连通且未被访问
                        visited[w] = true;                       //标记访问过
                        q.push(w);                               //push进queue中 待后续处理w的连通顶点
                    }
                }
            }
        };
        for (int i = 0;i < vertexNum;i++) {
            if (visited[i]) continue;
            ans++;
            bfs(i);
        }
        return ans;
    }
};
