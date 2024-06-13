/*
As the guys fried the radio station facilities, the school principal（校长） gave them tasks as a punishment.（惩罚）
Dustin's task was to add comments to nginx configuration for school's website. 
The school has n servers. Each server has a name and an ip (names aren't necessarily unique, but ips are). 
Dustin knows the ip and name of each server. 
For simplicity, we'll assume that an nginx command is of form "command ip;" 
where command is a string consisting of English lowercase letter only, （命令是由小写的英文字母的string组成）
and ip is the ip of one of school servers.

Each ip is of form "a.b.c.d" （每个ip的形式为“a.b.c.d”）where a, b, c and d are non-negative integers（非负数） 
less than or equal to 255 (with no leading zeros).（没有前导0）
The nginx configuration file Dustin has to add comments to has m commands. 
Nobody ever memorizes the ips of servers, so to understand the configuration better, 
Dustin has to comment the name of server that the ip belongs to at the end of each line (after each command). 
More formally（more formally）, if a line is "command ip;" 
Dustin has to replace it with "command ip; #name" where name is the name of the server with ip equal to ip.

Dustin doesn't know anything about nginx, so he panicked again and his friends asked you to do his task for him.

Input
The first line of input contains two integers n and m (1 ≤ n, m ≤ 1000).

The next n lines contain the names and ips of the servers. 
Each line contains a string name, name of the server and a string ip, ip of the server, 
separated by space (1 ≤ |name| ≤ 10, name only consists of English lowercase letters). 
It is guaranteed that all ip are distinct.

The next m lines contain the commands in the configuration file. 
Each line is of form "command ip;" (1 ≤ |command| ≤ 10, command only consists of English lowercase letters). 
It is guaranteed that ip belongs to one of the n school servers.

Output
Print m lines, the commands in the configuration file after Dustin did his task.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    unordered_map<string,string> hash;
    string name,ip;
    for (int i = 0;i < n;i++) {
        cin >> name >> ip;
        hash[ip] = name;
    }
    cin.ignore();
    vector<string> commands(m);
    for (int i = 0;i < m;i++) {
        getline(cin,commands[i]);
    }
    for (string& s:commands) {
        int pos = s.find(' '); //字串使用方法起始位置+长度
        name = s.substr(0,pos);
        ip = s.substr(pos + 1,s.size() - 2 - pos);
        cout << s << " #" << hash[ip] << endl;
    }
}
