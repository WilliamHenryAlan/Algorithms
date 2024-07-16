class StockSpanner {
public:
    //pair含义：first为实际股票价值 second表示 <= price 的股票数量
    stack<pair<int,int>> st;
    StockSpanner() {}
    
    int next(int price) {
        int res = 1;
        while(!st.empty() && st.top().first <= price) {
            res += st.top().second;
            st.pop();
        }
        st.push(make_pair(price, res));
        return res;
    }
};
