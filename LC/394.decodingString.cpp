
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        function<string(int&)> dfs = [&](int& i) {
            string res;
            while (i < n) {
                if (isdigit(s[i])) {
                    int k = 0;
                    while (i < n && isdigit(s[i])) {//如果不是个位数字 需要转化成数字
                        k = k * 10 + (s[i] - '0');
                        i++;
                    }
                    i++;
                    string temp = dfs(i);
                    while (k--) {
                        res += temp;
                    }
                }else if (isalpha(s[i])) res += s[i++];
                else if (s[i] == ']') {
                    i++;
                    return res;
                }
            }
            return res;
        };
        int i = 0;
        return dfs(i);
    }
};
class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<int> nums;
        stack<string> strs;
        int num = 0, len = s.size();
        for(int i = 0; i < len; ++ i)
        {
            if(isdigit(s[i])) num = num * 10 + s[i] - '0';
            else if(isalpha(s[i])) res = res + s[i];
            else if(s[i] == '[') //将‘[’前的数字压入nums栈内， 字母字符串压入strs栈内
            {
                nums.push(num);
                num = 0;
                strs.push(res); 
                res = "";
            }
            else //遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
            {
                int times = nums.top();
                nums.pop();
                for(int j = 0; j < times; ++ j)
                    strs.top() += res;
                res = strs.top(); //之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
                                  //若是左括号，res会被压入strs栈，作为上一层的运算
                strs.pop();
            }
        }
        return res;
    }
};
