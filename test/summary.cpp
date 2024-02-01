#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
//c
#include <stdio.h>
#include <stdlib.h>//c++中是<cstdlib>
#include <string.h>//c++中<cstring>

const int INF = 0x3f3f3f3f;
bool compare(int a,int b) {
    return a > b;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.in","w",stdout);
    int startTime = clock();
    #endif

    #ifndef ONLINE_JUDGE
    printf("Time = %dms",clock() - startTime);
    #endif


    //io
    std::string str = "";
    std::getline(std::cin,str);    //std::cin.getline(str,10);   //这里的str必须为C-style的string
    std::cout << str << std::endl;
    /*
    还是用scanf 因为scanf快 容易TLE(time limit exceeded)
    小数输出用printf即可好控制
    */
    double number = 3.149;
    printf("%.2f",number);

    int file = 0;//当file到文件尾 也就是EOF时 会结束
    // while (std::cin >> file) {

    // }
    int temp;
    std::cin >> temp;
    int arr[temp];
    std::cout << sizeof(arr)/sizeof(int) << std::endl;

    //c
    int arr[] = {1,2,3,4};
    memset(arr,INF,sizeof(arr)/sizeof(int));


    //vector
    std::vector<int> nums {4,3,3,4,6,5,};
    vector<int> nums;
    nums.size();//O(1)
    nums.clear();//O(n)
    std::unique(nums.begin(),nums.end());//去重 把出现过一次的排在前面
    std::swap(nums[0],nums[1]);
    std::sort(nums.begin(),nums.end(),compare);
    std::nth_element(nums.begin(),nums.begin()+3,nums.end());   
    std::reverse(nums.begin(),nums.end());
    int first = std::lower_bound(nums.begin(),nums.end(),2) - nums.end();

    //string
    string str,str1,str2;
    str.insert(1,"a");//O(n)
    str.insert(str.begin(),'c');//O(n)
    str.size();//O(n)
    str1.append(str2);//把str2拼接到str1上
    const char *c_style = str.c_str();//c++string转化为c语言的
    int arr[5] = {1,2,3,4,5};
    for (int i = 0;i < sizeof(arr)/sizeof(int);++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    memset(arr,0,sizeof(arr));  //暴力清空
    for (int i = 0;i < sizeof(arr)/sizeof(int);++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    /*
    willian@William-Alan test % gcc test_c.c -o exec
    willian@William-Alan test % ./exec 
    1 2 3 4 5 
    0 0 0 0 0 
    */

    //set
    set<int> hash;
    hash.insert(1);
    hash.insert(1); //只会有一个1 去重
    hash.erase(1);

    multiset<int> mhash;
    mhash.insert(1);
    mhash.insert(1);
    mhash.insert(1);
    mhash.count(1); //计数1出现的次数


    //map
    //pair<int,int> pr  //自带比较函数 先比较第一个int
    pair<string,int> pr{"alan",1};
    map<string,int> mymap;
    mymap.insert(pr);
    mymap["hello"] = 5;
    pair<string,int> id = make_pair("world",5);
    mymap.insert(id);
    mymap.erase("world");

    multimap<string,int> mhash;
    mhash.insert(pr);
    mhash.insert(pr);
    mhash.count("alan"); //计数1出现的次数
}