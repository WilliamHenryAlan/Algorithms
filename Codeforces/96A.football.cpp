/*
Petya loves football very much. One day, as he was watching a football match, 
he was writing the players' current positions on a piece of paper. 
To simplify the situation he depicted（描述） it as a string consisting of zeroes and ones. 
A zero corresponds to players of one team; a one corresponds to players of another team. 
（0代表了一个队的队员，1代表另一个队的队员）
If there are at least 7 players of some team standing one after another, then the situation is considered dangerous. 
For example, the situation 00100110111111101 is dangerous and 11110111011101 is not. 
You are given the current situation. Determine whether it is dangerous or not.

Input
The first input line contains a non-empty string consisting of characters "0" and "1", 
which represents players. The length of the string does not exceed 100 characters. 
There's at least one player from each team present on the field.

Output
Print "YES" if the situation is dangerous. Otherwise, print "NO".

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string team;
    getline(cin,team);
    int count = 1;
    for (int i = 1;i < team.size();i++) {
        if (team[i] == team[i - 1]) {
            count++;
            if (count >= 7) {
                cout << "YES" << endl;
                return 0;
            }
        }else {
            count = 1;
        }
    }
    cout << "NO" << endl;
}

// int main() {
//     string team;
//     getline(cin,team);
//     if (team.size() < 7) cout << "NO" << endl;
//     else {
//         int slow = 0,fast = 0;
//         while (fast < team.size()) {
//             while (team[++fast] == team[slow]);
//             if (fast - slow >= 7) {
//                 cout << "YES" << endl;
//                 return 0;
//             }
//             slow = fast;
//         }
//         cout << "NO" << endl;
//     }
// }