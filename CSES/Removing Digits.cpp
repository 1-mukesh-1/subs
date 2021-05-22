#include<bits/stdc++.h>
using namespace std;

// int util(int n,int step,vector<int> &memo){
//     if(n==0) return step;
//     int mini=INT_MAX;
//     int len=1+floor(log10(n));
//     for(int i=0;i<len;i++){
//         int rem=((int)(n/pow(10,i)))%10;
//         if(rem!=0)
//         {
//             if(memo[n-rem]==-1){
//                 int temp=util(n-rem,step+1,memo);
//                 memo[n-rem]=temp;
//                 mini=min(mini,temp);
//             }
//             else{
//                 int temp=memo[n-rem];
//                 mini=min(mini,temp);
//             }
//         }
//     }
//     return mini;
// }

int main() {
    int n;
    cin >> n;
    vector<int> dp;
    dp.push_back(0);
    for (int i = 1; i < n + 1; i++) {
        int temp = i;
        dp.push_back(1000009);
        while (temp != 0) {
            dp[i] = min(dp[i], dp[i - temp % 10] + 1);
            temp /= 10;
        }
    }
    cout << dp[n] << endl;
}
