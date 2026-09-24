class Solution {
public:
    bool check(string a,string b){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])
            cnt++;
        }
        return cnt==1;
    }
    int f(int i,int num,string &endGene,vector<string>&bank,vector<vector<int>>&dp){
        if(bank[i]==endGene)
        return 0;
        if(dp[i][num]!=-1)
        return dp[i][num];
        int cnt=11;
        for(int j=0;j<bank.size();j++){
            if((((num>>j)&1)==0) && check(bank[i],bank[j])){
                int cal=1+f(j,(num|(1<<j)),endGene,bank,dp);
                cnt=min(cnt,cal);
            }
        }
        return dp[i][num]=cnt;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<string>newbank;
        newbank.push_back(startGene);
        for(auto &it:bank){
            newbank.push_back(it);
        }
        int n=bank.size()+1;
        int num=(1<<n)-1;
        vector<vector<int>>dp(n,vector<int>(num+1,-1));
        int ans=f(0,1,endGene,newbank,dp);
        if(ans>=11)
        return -1;
        return ans;
    }
};