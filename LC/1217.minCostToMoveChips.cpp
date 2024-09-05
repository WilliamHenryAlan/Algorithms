1.

搞懂 position 的含义

 e.g.position = [2,2,2,3,3] 

表示 position为2的位置上放了3个chip

表示 position为3的位置上放了2个chip

2. 

因为move两格不需要花费 所以奇数到奇数 偶数到偶数都不需要花费

所以 遍历 position  把所有筹码移动到0或者1的位置 最后移动小的那一堆 就是 最小cost 



class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0,odd = 0;
        for (int val:position) {
            if (val % 2 == 0) even++;
            else odd++;
        }
        return min(odd,even);
    }
};


