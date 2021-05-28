#include<bits/stdc++.h>
#define int long long
using namespace std;
 
void solve(){
    int n;
    cin>>n;
    int arr[n];
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int summ=0;
    int c=0;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        summ+=arr[i];
        while(summ<0){
            int x=pq.top();
            pq.pop();
            summ+=abs(x);
            c-=1;
        }
        c+=1;
    }
    cout<<c<<endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
