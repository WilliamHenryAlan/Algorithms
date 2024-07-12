class SmallestInfiniteSet {
    set<int> s;//维护 < boundary的正整数
    int boundary = 1;//表示 >= boundary的所有正整数
public:
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        if (s.empty()) {
            int ret = boundary++;
            return ret;
        }
        int ans = *s.begin();
        s.erase(ans);
        return ans;
    }
    
    void addBack(int num) {
        if (num >= boundary) return ;
        if (!s.contains(num)) s.insert(num);
    }
};

