#include<bits/stdc++.h>
#define int long long
using namespace std;

int inf=LLONG_MAX;

void floyd_warshall(vector<vector<int>> &graph,int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][k]!=inf && graph[k][j]!=inf)
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
}

signed main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> graph(n,vector<int>(n,inf));
    for(int i=0;i<n;i++) graph[i][i]=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a-1][b-1]=min(c,graph[a-1][b-1]);
        graph[b-1][a-1]=min(c,graph[b-1][a-1]);
    }
    floyd_warshall(graph,n);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(graph[a-1][b-1]>=inf){
            cout<<-1<<endl;
        }
        else{
            cout<<graph[a-1][b-1]<<endl;
        }
    }
    return 0;
}
