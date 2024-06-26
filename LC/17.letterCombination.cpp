#include <iostream>
#include <vector>
using namespace std;
/*
review 2024.2.15

1.枚举 digits[i] - '0'、枚举 digits[i+1] - '0' 、枚举 digits[i+2] - '0' 
i = [0,digits.size()]
需要枚举digits.size()个
*/

class Solution {
public:
    vector<string> MAPPING={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string path;
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {}; //如果不加 当size = 0时 执行递归第一个if 会把空str加入ans 再返回
        dfs(0,digits);
        return ans;
    }
    void dfs(int index,string& digits) {
        if (path.size() == digits.size()) {
            ans.push_back(path);
            return ;
        }
        int digit = digits[index] - '0';    //给我们的是string 需要stoi
        string str = MAPPING[digit];
        for (int i = 0;i < str.size();i++) {
            path.push_back(str[i]); //path += str[i];
            dfs(index+1,digits);
            path.pop_back();    //path.resize(path.size()-1);
        }
    }
};
/*
review 2024.3.4
*/
class Solution {
public:
    vector<string> letter = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string path;
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        dfs(digits,0);
        return ans;
    }
    void dfs(string digits,int index) {
        if (path.size() == digits.size()) {
            ans.push_back(path);
            return ;
        }
        int number = digits[index] - '0';
        string str = letter[number];
        for (int i = 0;i < str.size();i++) {
            path.push_back(str[i]);
            dfs(digits,index + 1);
            path.pop_back();
        }
    }
};

/*
review 2024.6.26
*/
class Solution {
    vector<string> letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string path;
    vector<string> ans;
public:
    void dfs(int index,string& digits) {
        if (index == digits.size()) {
            ans.push_back(path);
            return ;
        }
        int num = digits[index] - '0';
        string str = letters[num];
        for (int i = 0;i < str.size();i++) {
            path.push_back(str[i]);
            dfs(index + 1,digits);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        dfs(0,digits);
        return ans;
    }
};


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
    void backtracking(int index,
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
