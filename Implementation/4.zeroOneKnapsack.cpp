/*
            weight      value
item 0      0           0
item 1      2           3
item 2      3           4
item 3      4           5
item 4      5           8
...
item i

- 确定dp含义：
    
    dp[i][j]
    
    j为容量为j的背包
    
    i为编号为0 - i之间的物品任意取
    
    dp[i][j]的意义为：
    
    容量为j的背包 从编号 0 - i 之间的物品任取使得背包中价值最大


不放item i dp[i-1][j]
放物品 item i dp[i - 1][j - weight[i]] + value[i]
*/
#include <iostream>
#include <vector>
using namespace std;

#define itemNum 5
#define capacity 9

int dp[itemNum][capacity] = {0}; //实际上是求解4个物品 背包容量为8的最优解
vector<int> weight = {0,2,3,4,5};
vector<int> value = {0,3,4,5,8};


int main() {
    memset(dp,0,sizeof(dp));//初始化 不是所有情况都是0
    for (int i = 1;i < itemNum;i++) {   //从[1][1]开始推导
        for (int j = 1;j < capacity;j++) {
            if (weight[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    cout << "在0 - 4号物品 背包容量为8时 任取 最大价值为：" << dp[4][8] << endl;
}

