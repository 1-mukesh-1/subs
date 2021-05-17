#include<bits/stdc++.h>
using namespace std;

void bfs(map<int,vector<int>> &adj,int s,vector<bool> &visited){
    queue<int> st;
    st.push(s);
    visited[s]=true;
    while(st.size()!=0){
        int curr=st.front();
        st.pop();
        for(auto x:adj[curr]){
            if(!visited[x]){
                st.push(x);
                visited[x]=true;
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    map<int,vector<int>> adj;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n+1,false);
    vector<int> build;
    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            bfs(adj,i,visited);
            build.push_back(i);
        }
    }
    cout<<build.size()-1<<endl;
    for(int i=1;i<build.size();i++){
        cout<<build[i-1]<<" "<<build[i]<<endl;
    }
    return 0;
}
