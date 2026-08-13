class Solution {
public:
    int f(int i,int jump,int can,map<vector<int>,int>&m,int k,vector<int>&pow){
        if(i>k+1)
        return 0;
        if(m.count({i,jump,can})!=0){
            return m[{i,jump,can}];
        }
        int total=0;
        if(i==k)
        total++;
        if(can){
            total+=f(i-1,jump,0,m,k,pow);
            int cal=pow[jump];
            total+=f(i+cal,jump+1,1,m,k,pow);
        }
        else{
            int cal=pow[jump];
            total+=f(i+cal,jump+1,1,m,k,pow);
        }
        return m[{i,jump,can}]=total;
    }
    int waysToReachStair(int k) {
       map<vector<int>,int>m; 
        vector<int>pow;
        int p=1;
        pow.push_back(p);
        for(int i=1;i<=30;i++){
            p=p*2;
            pow.push_back(p);
        }
        return f(1,0,1,m,k,pow);
    }
};