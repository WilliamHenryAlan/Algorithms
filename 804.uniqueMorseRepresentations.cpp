/*
国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串， 比如:

    'a' 对应 ".-" ，
    'b' 对应 "-..." ，
    'c' 对应 "-.-." ，以此类推。

为了方便，所有 26 个英文字母的摩尔斯密码表如下：

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

给你一个字符串数组 words ，每个单词可以写成每个字母对应摩尔斯密码的组合。

    例如，"cab" 可以写成 "-.-..--..." ，(即 "-.-." + ".-" + "-..." 字符串的结合)。我们将这样一个连接过程称作 单词翻译 。

对 words 中所有单词进行单词翻译，返回不同 单词翻译 的数量。

 

示例 1：

输入: words = ["gin", "zen", "gig", "msg"]
输出: 2
解释: 
各单词翻译如下:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

共有 2 种不同翻译, "--...-." 和 "--...--.".

示例 2：

输入：words = ["a"]
输出：1


提示：

    1 <= words.length <= 100
    1 <= words[i].length <= 12
    words[i] 由小写英文字母组成


*/

/*
创建字符串数组存储每个char对应的morse密码
因为words.lengh在100及以内 所以可以用100大小的数组存储
映射每个单词的密码在unordered_set中去重

prompt:
1.c++静态成员必须完成类外初始化
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
const static std::string morse[] =  {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
        "...-", ".--", "-..-", "-.--", "--.."
};
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        std::unordered_set<std::string> unset;
        int len = words.size();
        for (std::string &word:words) {
            std::string str;
            for (char& c:word) {
                str += morse[c - 'a'];
            }
            unset.emplace(str);
        }
        return unset.size();
    }
};

// //version A
// class Solution {
// public:
//     int uniqueMorseRepresentations(vector<string>& words) {
//         std::vector<std::string> morse{".-", "-...", "-.-.", "-..", ".", "..-.", "--.",     //类外声明了std::string[]静态数组
//          "....", "..", ".---", "-.-", ".-..", "--", "-.",
//          "---", ".--.", "--.-", ".-.", "...", "-", "..-",
//          "...-", ".--", "-..-", "-.--", "--.."};
//         std::unordered_set<std::string> unset;
//         int len = words.size();
//         for (int i = 0;i < len;i++) {
//             std::string str;
//             for (char& c:words[i]) {
//                 str += morse[c - 'a'];
//             }
//             unset.insert(str);      //用了emplace方法 在类型特别大的时候 能高效插入
//         }
//         return unset.size();
//     }
// };