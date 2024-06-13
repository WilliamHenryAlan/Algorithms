/*
思路
首先明白字典序和题意
字典序（lexicographical order），也称为字母序或词典顺序，是一种字符串排列方式，其排序规则类似于字典中的单词排列。
按照字典序，字符串是按字母顺序从左到右逐字符比较的。
字典序排序规则
1. **逐字符比较**：从左到右逐个字符进行比较，直到找到第一个不同的字符。
2. **字符顺序**：比较字符时，按照字符的编码值（通常是ASCII或Unicode编码值）进行比较。
3. **长度**：如果所有字符都相同，则较短的字符串排在前面。

"apple" < "banana"  // 因为 'a' < 'b'
"apple" < "apricot" // 因为 'p' < 'r'
"apple" < "applepie" // 因为 "apple" 比 "applepie" 短
"123" < "45"        // 因为 '1' < '4'
"A" < "a"           // 因为 'A' 的ASCII值是65，'a' 的ASCII值是97
*/

/*
回到题目中 e.g. str = "aaabaa"
删除左边的a会比删除右边的a得到的字典序更大
也就是 aabaa > aaaba
根据题意 我们应该删除最右边的
*/

/*
str = aaabaa
删除左边的a会比删除右边的a得到的字典序更大
也就是 aabaa > aaaba
根据题意 我们应该删除最右边的

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        vector<int> vec[26];//可以用stack<vector<int>> st
        //这里vec含义为 = [[],[],[],[],[]···26个[] 每一个[]都是vector<int>]
        //e.g. s = "aabc*"
        for (int i = 0;i < s.size();++i) {
            char c = s[i];
            if (c != '*') {
                /*
                第一个'a'映射到vector的index为0 并且记录'a'在string中的index
                结果为vec = [[0],[],[],[],[]···26个[] 每一个[]都是vector<int>]
                */
                /*
                第二个'a'映射到vector的index为0 并且记录'a'在string中的index
                结果为vec = [[0,1],[],[],[],[]···26个[] 每一个[]都是vector<int>]
                以此类推
                */
                /*
                字母映射完应该是
                vec = [[0,1],[2],[3],[],[]···26个[] 每一个[]都是vector<int>]
                */
                vec[c - 'a'].push_back(i);
                continue;
            }
            for (vector<int>& vi:vec) {
                /*
                到最后一个'*'从前往后遍历 这样可以找到字典序最小的字母 
                再pop_back()可以保证弹出最右边的字母达到字典序最小
                */
                if (!vi.empty()) {
                    s[vi.back()] = '*';//把需要删除的标记为'*' 方便后面操作一键erase-remove
                    vi.pop_back();
                    break;
                }
            }
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        /*
        stl遵循左闭右开区间
        remove只把所有'*'移动到末尾
        erase真正删除
        */
        return s;
    }
};


