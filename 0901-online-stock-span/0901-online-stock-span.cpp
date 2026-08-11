class StockSpanner {
public:
    stack<pair<int,int>>st;
    int cnt;
    StockSpanner() {
        st=stack<pair<int,int>>();
        cnt=1;
    }
    
    int next(int price) {
        int ret=cnt;
        while(!st.empty()){
            int indx=st.top().first;
            int val=st.top().second;
            if(val<=price)
            st.pop();
            else{
                ret=(cnt-indx);
                break;
            }
        }
        if(st.size()==0){
            ret=cnt;
        }
        st.push({cnt,price});
        cnt++;
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */