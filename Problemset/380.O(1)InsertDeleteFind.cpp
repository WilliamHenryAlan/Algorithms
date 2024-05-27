#include <iostream>
#include <unordered_map>
#include <vector>
class RandomizedSet {
public:
    std::vector<int> data;
    std::unordered_map<int,int> hash;
    RandomizedSet() {}
    
    bool insert(int val) {
        if (hash.find(val) != hash.end()) return false;
        data.push_back(val);
        hash.insert({val,data.size() - 1});
        return true;
    }
    
    bool remove(int val) {
        std::unordered_map<int,int>::iterator iter = hash.find(val);
        if (iter == hash.end()) return false;   //没找到
        //找到了 idx为要删除的元素index
        int idx = iter->second;
        int lastVal = data[data.size() - 1];//记录最后一个元素的value
        data[idx] = lastVal; //覆盖要删除的元素
        hash[lastVal] = idx;
        data.pop_back();
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        int size = data.size();
        int pos = rand() % size;
        return data[pos];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */