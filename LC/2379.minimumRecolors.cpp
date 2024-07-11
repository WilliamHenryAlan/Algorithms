class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(),ans = 0,ret = n;
        for (int i = 0;i < n;i++) {
            if (blocks[i] == 'W')ans++;//进入窗口
            if (i < k - 1) continue;//累计使滑动窗口长度达到k
            ret = min(ret,ans);//更新答案
            if (blocks[i - k + 1] == 'W') ans--;//退出窗口
        }
        return ret;
    }
};
