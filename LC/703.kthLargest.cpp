#include <map>
#include <iostream>
using namespace std;

class KthLargest {
public:
    int k;
    multimap<int,int> data;
    KthLargest(int _k, vector<int>& _nums) :k(_k) {
        for (int i = 0;i < _nums.size();i++) {
            data.insert({_nums[i],i});
        }
    }
    
    int add(int val) {
        data.push_back(val);
        sort(data.begin(),data.end());
        return data[data.size() - k];
    }
};
