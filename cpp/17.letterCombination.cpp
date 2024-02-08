#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> board={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        string path;
        vector<string> ans;
        int len = digits.size();
        if (len == 0) return ans;
        backtracking(0,digits,path,ans);
        return ans;
    }
    void backtracking(int index,//和之前的startIndex不一样 之前的用于去重 现在是用于len个集合的组合
                        const string& digits,    
                        string& path,
                        vector<string>& ans) {
        if (path.size() == digits.size()) {
            ans.push_back(path);
            return;
        }
        int num = digits[index] - '0';    //取九宫格对应的数字 stoi()
        string letter = board[num]; //对应数字的string
        for (int i = 0;i < letter.size();i++) {
            path.push_back(letter[i]);
            backtracking(index+1,digits,path,ans);  //index+1 下一个数字 进行新一轮的forLoop int i = 0;i < letter.size()
            path.pop_back();
        }
    }
};