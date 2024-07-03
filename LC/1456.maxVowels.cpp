//O(n * k)会超时
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int i = 0,j = k - 1; //fixed sliding window
        for (;j < s.length();j++,i++) {
            int temp = 0;
            for (int m = i;m <= j;m++) {
                if (isVowel(s[m])) temp++;
            }
            ans = max(ans,temp);
        }
        return ans;
    }
    bool isVowel(char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
};
/*
1.第一个for预处理窗口大小为[0,i)左闭右开 方便处理边界条件
2.for循环遍历剩余string 第一个if窗口加入元素 第二个if窗口弹出元素
3.update ans && return ret
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0,ret = 0;
        for (int i = 0;i < k;i++) if (isVowel(s[i])) ret++;//预处理 固定窗口大小
        ans = ret;//不能少 不然会使得ans进入时为0 那么预处理就白做了
        for (int i = k;i < s.size();i++) {
            if (isVowel(s[i])) ans++;
            if (isVowel(s[i - k])) ans--;
            ret = max(ret,ans);
        }
        return ret;
    }
    bool isVowel(char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
};

/*
窗口为[0,i]左闭右闭
1.循环进入后 先循环执行第一个if和第二个if 直到固定窗口 使得0-i为k大小的窗口
2.固定窗口大小后 更新答案 执行第三个if 离开窗口
3.执行第1个if 进入窗口 此后 第二个if将不会进入
s = "aaaa" k = 3
模拟走一遍code即可
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0,ret = 0;
        for (int i = 0;i < s.size();i++) {
            if (isVowel(s[i])) ans++;
            if (i < k - 1) continue;//固定窗口 使得0-i为k大小的窗口
            ret = max(ans,ret);
            if (isVowel(s[i - k + 1])) ans--;
        }
        return ret;
    }
    bool isVowel(char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
};