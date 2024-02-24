/*
            weight      value
item 0      1           15
item 1      3           20
item 2      4           30
...
item i

dp[i][j]表示 0～i之间的item任取 放到容量为j的背包
不放item i dp[i-1][j]
放物品 item i dp[i][j+weight[i]]
*/
#include <iostream>

int main() {

}