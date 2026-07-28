class Solution {
public:
    int N=1e9+7;
    int pow(long long a,long long b){
        long long p=1LL;
        while(b>0){
            if(b%2)
            p=(p*a)%N;
            a=(a*a)%N;
            b=b/2LL;
        }
        return p;
    }
    int combinatorics(int n,int r,vector<long long>&prod){
        if(r>n)
        return 0;
        long long num=prod[n];
        long long den=pow(prod[r],N-2)%N;
        den=(den*pow(prod[n-r],N-2))%N;
        long long ans=(num*den)%N;
        return ans;
    }
    int countValidSequences(int n, int k) {
        vector<long long>prod;
        long long p=1LL;
        for(int i=0;i<=n+k;i++){
            if(i==0)
            prod.push_back(p);
            else{
            p=(p*i)%N;
            prod.push_back(p);
            }
        }
        long long total=combinatorics(n-1,k-1,prod);
        long long odd=0LL;
        if((n+k)%2==0){
            int num=(n-k)/2;
            num+=k-1;
            odd=combinatorics(num,k-1,prod);
        }
        long long ret=(total-odd+N)%N;
        return (int)ret;
    }
};