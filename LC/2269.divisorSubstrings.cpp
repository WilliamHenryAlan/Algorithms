class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);//预处理为string
        int ans = 0;
        int i = k;//左闭右开滑动窗口
        while (i <= str.size()) {//左闭右开
            int r = stoi(str.substr(i - k,k));
            if (r > 0 && num % r == 0) {//要注意除数不能为0
                ans++;
            }
            i++;
        }
        return ans;
    }
};