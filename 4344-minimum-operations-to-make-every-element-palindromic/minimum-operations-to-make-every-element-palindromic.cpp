class Solution {
public:
    void generate(string& s,int l,int r,vector<long long>&odd,vector<long long>&even){
        if(r<l){
            long long num=0LL;
            int ri=s.size()-1;
            while(ri>=0){
                if(s[ri]=='0'){
                    ri--;
                }
                else
                break;
            }
            for(int i=0;i<=ri;i++){
                num=10*num+(s[i]-'0');
            }
            if(num%2)
            odd.push_back(num);
            else
            even.push_back(num);
            return;
        }
        for(int i=0;i<=9;i++){
            s[l]=(i+'0');
            s[r]=(i+'0');
            generate(s,l+1,r-1,odd,even);
        }
    }
    long long minOperations(vector<int>& nums) {
        static bool generated=false;
        static vector<long long>odd,even;
        if(!generated){
            static string s="";
            for(int i=0;i<10;i++){
                s+='0';
            }
            generate(s,0,9,odd,even);
            s.pop_back();
            for(int i=0;i<9;i++){
                s[i]='0';
            }
            generate(s,0,8,odd,even);
            sort(odd.begin(),odd.end());
            sort(even.begin(),even.end());
            generated=true;
        }
        long long ans=0LL;
        /*for(auto &it:odd){
            cout<<it<<" ";
        }
        for(auto &it:even){
            cout<<it<<" ";
        }*/
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2){
                int indx=upper_bound(odd.begin(),odd.end(),nums[i])-odd.begin();
                long long cal=LLONG_MAX;
                if(indx<odd.size())
                cal=min(cal,abs(nums[i]-odd[indx]));
                if(indx>0)
                cal=min(cal,abs(nums[i]-odd[indx-1]));
                ans+=cal;
            }
            else{
                int indx=upper_bound(even.begin(),even.end(),nums[i])-even.begin();
                long long cal=LLONG_MAX;
                if(indx<even.size())
                cal=min(cal,abs(nums[i]-even[indx]));
                if(indx>0)
                cal=min(cal,abs(nums[i]-even[indx-1]));
                ans+=cal;
            }
        }
        return ans/2;
    }
};