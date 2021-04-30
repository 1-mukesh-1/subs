#include<bits/stdc++.h>
using namespace std;

#define MAX 20010
#define log 15

class G{
public:
    int level[MAX];
    int lca[MAX][log];
    int dist[MAX][log];
    vector<pair<int,int>> graph[MAX];
    void addEdge(int u, int v, int cost)
    {
    	graph[u].push_back({ v, cost });
    	graph[v].push_back({ u, cost });
    }

    void dfs(int node, int parent,int h, int cost)
    {
    	lca[node][0] = parent;
    	level[node] = h;
    	if (parent != -1) {
    		dist[node][0] = cost;
    	}
    	for (int i = 1; i < log; i++) {
    		if (lca[node][i - 1] != -1) {
    			lca[node][i]= lca[lca[node][i - 1]][i - 1];
    			dist[node][i]= dist[node][i - 1]+ dist[lca[node][i - 1]][i - 1];
    		}
    	}
    	for (auto i : graph[node]) {
    		if (i.first == parent)
    			continue;
    		dfs(i.first, node,h + 1, i.second);
    	}
    }

    int distance(int u, int v)
    {
    	int ans = 0;
    	if (level[u] > level[v])
    		swap(u, v);
    	for (int i = log - 1; i >= 0; i--) {
    		if (lca[v][i] != -1
    			&& level[lca[v][i]]>= level[u]) {
    			ans += dist[v][i];
    			v = lca[v][i];
    		}
    	}
    	if (v == u) {
    		return ans;
    	}
    	else {
    		for (int i = log - 1; i >= 0; i--) {
    			if (lca[v][i] != lca[u][i]) {
    				ans += dist[u][i] + dist[v][i];
    				v = lca[v][i];
    				u = lca[u][i];
    			}
    		}
    		ans += dist[u][0] + dist[v][0];
    		return ans;
    	}
    }
};

void solve(){
    int n,k,a;
    cin>>n>>k>>a;
    int spl[k];
    for(int i=0;i<k;i++) cin>>spl[i];
    sort(spl,spl+k);
    G x;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        x.addEdge(a,b,1);
    }
	for(int i=1;i<=n;i++) {
		for (int j = 0; j < log; j++) {
			x.lca[i][j] = -1;
			x.dist[i][j] = 0;
		}
	}
	x.dfs(1, -1, 0, 0);
	vector<int> ans(n+1,INT_MIN);
	vector<int> ind(n+1,INT_MIN);
	for(int u=0;u<k;u++){
    	for(int i=1;i<=n;i++){
    	    int temp=x.distance(a,spl[u])-x.distance(i,spl[u]);
    	    if(ans[i]<temp){
    	        ans[i]=temp;
    	        ind[i]=spl[u];
    	    }
	    }
	}
	for(int i=1;i<n+1;i++){
	    cout<<ans[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<n+1;i++){
	    cout<<ind[i]<<" ";
	}
	cout<<endl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
