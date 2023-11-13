/*

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen=s.size();
        int tlen=t.size();
        if (slen != tlen) return false; 
        vector<int> nums(26,0);
        for (int i = 0; i < slen; i++)
        {
            nums[s[i]-'a']++;
        }
        for (int i = 0; i < tlen; i++)
        {
            nums[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (nums[i]!= 0) return false;
        }
        return true;
        
    }
};
int main()
{
    Solution ret;
    string s="rat",t="car";
    cout << "output = " << ret.isAnagram(s,t) << endl;
}