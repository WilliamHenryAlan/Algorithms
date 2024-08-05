//1.根据/分割path
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> deq;
        int n = path.size();
        for (int i = 0;i < n;i++) {
            string s;
            if (path[i] == '/') {
                for (int j = i + 1;path[j] != '/' && j < n;j++) {
                    s += path[j];
                }
                if (s == "..")  {
                    if (!deq.empty())deq.pop_back();
                }
                else if (s != "." && s != "") deq.push_back(s);
            }
        }
        string ans;
        while (!deq.empty()) {
            ans += "/" + deq.front();
            deq.pop_front();
        }
        return ans == ""?"/":ans;
    }
};
