/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false
*/

/*
Solution
1.Hash table
    array set map
2.元素比较少 用array
3.创建一个vector包含26个元素 分别映射 26个字母
4.分别遍历string s和string t
    遍历s时 对应的下标值++ 比如
                            ‘a' nums[0]++
                            ’b‘ nums[1]++
    遍历t时 对应下标值--
5。遍历数组vector 如果nums[i] != 0 return false else return true;
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