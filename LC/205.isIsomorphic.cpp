/*
solution:

*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> s_map,t_map;
        for (int i = 0;i < s.size();i++) {
            char s_char = s[i],t_char = t[i];
            if (s_map.find(s_char) != s_map.end() && s_map[s_char] != t_char || 
                t_map.find(t_char) != t_map.end() && t_map[t_char] != s_char) {
                    return false;
                } 
            s_map[s_char] = t_char;
            t_map[t_char] = s_char;
        }
        return true;
    }
};