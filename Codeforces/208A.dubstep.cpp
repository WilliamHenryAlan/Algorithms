/*
Vasya works as a DJ in the best Berland nightclub, and he often uses dubstep(达布舞) music in his performance. 
Recently, he has decided to take a couple of old songs and make dubstep remixes from them.

Let's assume that a song consists of some number of words. （让我们假设 一首歌由一定数量的单词组成）
To make the dubstep remix of this song, （为了制作达布舞混合这首歌）
Vasya inserts a certain number of words "WUB" before the first word of the song (the number may be zero),
（插入一定数量的“WUB”在歌曲的第一个单词之前）（数量可能是0）
after the last word (the number may be zero), 
（在最后一个单词之后）（数字可能是0）
and between words (at least one between any pair of neighbouring words), 
两个单词之间（至少有一个在任意两个相邻单词之间）
and then the boy glues together all the words, including "WUB", in one string and plays the song at the club.

For example, a song with words "I AM X" can transform into a dubstep remix as "WUBWUBIWUBAMWUBWUBX" 
and cannot transform into "WUBWUBIAMWUBX".

Recently, Petya has heard Vasya's new dubstep track, but since he isn't into modern music, 
he decided to find out what was the initial song that Vasya remixed. Help Petya restore the original song.

Input
The input consists of a single non-empty string, consisting only of uppercase English letters, 
the string's length doesn't exceed 200 characters. 
It is guaranteed that before Vasya remixed the song, no word contained substring "WUB" in it; 
Vasya didn't change the word order. It is also guaranteed that initially the song had at least one word.

Output
Print the words of the initial song that Vasya used to make a dubsteb remix. Separate the words with a space.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string song;
    getline(cin,song); //读取song
    int pos = 0;
    string pattern = "WUB";
    vector<string> ans; //存储original string
    while ((pos = song.find(pattern))!= string::npos) { //找substr 记录pos
        //如果开头是pattern token为empty 
        //如果不是pattern token为我们需要的word
        string token = song.substr(0,pos); 
        if (!token.empty()) ans.push_back(token);
        song = song.substr(pos + 3);
    }
    if (!song.empty()) ans.push_back(song);
    for (string& w:ans) {
        cout << w << " ";
    }
    cout << endl;
    return 0;
}
