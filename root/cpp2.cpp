#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int ways(vector<int> arr, int k, int n) {
	if (k == 0) return 1;
	if (k < 0) return 0;
	int summ = 0;
	for (int i = 0; i < n; i++) {
		int temp = ways(arr, k - arr[i], n);
		summ += temp;
		// cout<<arr[i]<<endl;
	}
	return summ;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	// for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	// cout<<endl;
	cout << ways(arr, k, n);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	// cin>>t;
	while (t--) {
		solve();
	}
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
