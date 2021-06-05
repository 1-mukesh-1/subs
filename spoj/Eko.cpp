#include<bits/stdc++.h>
#define int long long
using namespace std;

bool ok(vector<int> &arr,int mid,int k){
    int summ=0;
    for(int i=0;i<arr.size();i++){
        summ+=max(arr[i]-mid,(int)0);
    }
    return summ>=k;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    int l=0;
    int h=INT_MIN;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
        h=max(h,temp);
    }
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(ok(arr,mid,k)){
            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
