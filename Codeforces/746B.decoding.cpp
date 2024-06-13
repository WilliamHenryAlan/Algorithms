/*
Polycarp is mad about coding, that is why he writes Sveta encoded messages. 
He calls the median letter in a word the letter which is in the middle of the word.
If the word's length is even（偶数）, the median letter is the left of the two middle letters. 
In the following examples, the median letter is highlighted: conBest, iNfo. (B和N为高亮)
If the word consists of single letter,(如果这个单词只有一个字母)
then according to above definition this letter is the median letter.(那么根据上面的定义 这个字母就是中间的字母)

Polycarp encodes each word in the following way: 
he writes down the median letter of the word,（他写下中间的字母） 
then deletes it（然后删除原来单词中的中间的字母） and repeats the process until there are no letters left.
For example, he encodes the word volga as logva.

You are given an encoding s of some word, your task is to decode it.

Input
The first line contains a positive integer n (1 ≤ n ≤ 2000) — the length of the encoded word.

The second line contains the string s of length n consisting of lowercase English letters — the encoding.

Output
Print the word that Polycarp encoded.
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;
string encoding(int n,const string& str) { //n为string长度
    deque<char> q;  //借助deq实现
    for (int i = 0;i < n;i++) { 
        if ((n - i) % 2 == 0) {
            q.push_front(str[i]);   //如果是even 插入左侧
        }else {
            q.push_back(str[i]);    //如果是odd 插入右侧
        }
    }
    return string(q.begin(),q.end()); //deq => string
}
int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    cout << encoding(n,str) << endl;
}
