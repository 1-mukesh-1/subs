#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> memo(2000000,-100);

int ways(vector<int> arr,int k,int n){
    if(k==0) return 1;
    if(k<0) return 0;
    int summ=0;
    for(int i=0;i<n;i++){
        int req=k-arr[i];
        int temp=0;
        if(req<=0 || memo[req]==-100)
        {
            temp=ways(arr,req,n);
            if(req>0) memo[req]=temp;
        }
        else{
            temp=memo[req];
        }
        summ+=temp;
    }
    // cout<<endl;
    return summ;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<ways(arr,k,n);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    return 0;
}
