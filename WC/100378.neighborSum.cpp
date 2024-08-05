class neighborSum {
    vector<vector<int>> grid;//存储grid数据
    unordered_map<int,pair<int,int>> valueToPosition;//映射grid每一个value的x y
    int direction[8][2] = {//偏移量
        {0,1},//上
        {0,-1},//下
        {-1,0},//左
        {1,0},//右
        {-1,-1},//左上
        {1,-1},//右上
        {-1,1},//左下
        {1,1}//右下
    };
public:
    neighborSum(vector<vector<int>>& grid) :grid(grid) {
        int m = grid.size(),n = grid[0].size();
        for (int i = 0;i < m;i++) { //映射grid每一个value的x y
            for (int j = 0;j < n;j++) {
                valueToPosition[grid[i][j]] = {i,j};
            }
        }
    }
    
    int adjacentSum(int value) {
        int sum = 0,x,y;
        for (int i = 0;i < 4;i++) {//遍历value的上下左右
            x = valueToPosition[value].first + direction[i][0];//加上偏移量
            y = valueToPosition[value].second + direction[i][1];
            if (check(x,y)) sum += grid[x][y];
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        int sum = 0,x,y;
        for (int i = 0;i < 4;i++) {//遍历value的四个斜对角
            x = valueToPosition[value].first + direction[i + 4][0];
            y = valueToPosition[value].second + direction[i + 4][1];
            if (check(x,y)) sum += grid[x][y];
        }
        return sum;
    }
    bool check(int x,int y) { //判断边界
        return x >= 0 && x < grid.size() && y >= 0 && y < grid.size();
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
