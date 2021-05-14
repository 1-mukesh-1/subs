#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int summ=0;
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>temp;
            summ+=temp*(((n-i)*(m-j))*((i+1)*(j+1)));
        }
    }
    cout<<summ<<endl;
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
