#include<bits/stdc++.h>
#define int long long
using namespace std;

int movex[4]={0,0,1,-1};
int movey[4]={1,-1,0,0};

void bfs(stack<pair<int,int>> &st,vector<string> &arr,int i,int j,int n,int m){
    arr[i][j]='#';
    st.push(make_pair(i,j));
    while(st.size()!=0){
        pair<int,int> curr=st.top();
        st.pop();
        for(int k=0;k<4;k++){
            int xx=curr.first+movex[k];
            int yy=curr.second+movey[k];
            if(xx>=0 && xx<n && yy<m && yy>=0 && arr[xx][yy]=='.'){
                st.push(make_pair(xx,yy));
                arr[xx][yy]='#';
            }
        }
    }
}

signed main(){
    int n,m;
    cin>>n>>m;
    vector<string> arr;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int c=0;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.'){
                bfs(st,arr,i,j,n,m);
                c++;
            }
        }
    }
    cout<<c<<endl;
    return 0;
}
