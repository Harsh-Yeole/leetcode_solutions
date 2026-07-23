#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>a,b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    int sum=0,eo=0,ez=0;
    bool flag=true;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            sum+=a[i];
            flag=false;
        }
        else{
            if(a[i]==1)
            eo++;
            else
            ez++;
        }
    }
    if(flag){
        cout<<0<<endl;
        return;
    }
    if(sum>0){
        if(sum%2){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
        return;
    }
    else{
        if(eo && ez){
            cout<<2<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        return;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}