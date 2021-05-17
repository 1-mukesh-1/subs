#include<bits/stdc++.h>
#define int long long
using namespace std;

int movex[4]={0,0,1,-1};
int movey[4]={1,-1,0,0};

pair<int,int> bfs(queue<pair<int,int>> &st,vector<string> &arr,int i,int j,int n,int m,vector<vector<char>> &dist){
    arr[i][j]='#';
    dist[i][j]='0';
    st.push(make_pair(i,j));
    while(st.size()!=0){
        pair<int,int> curr=st.front();
        st.pop();
        for(int k=0;k<4;k++){
            int xx=curr.first+movex[k];
            int yy=curr.second+movey[k];
            if(xx>=0 && xx<n && yy<m && yy>=0 && arr[xx][yy]!='#'){
                if(xx-curr.first==0){
                    if(yy-curr.second>0){
                        dist[xx][yy]='R';
                    }
                    else{
                        dist[xx][yy]='L';
                    }
                }
                else{
                    if(xx-curr.first>0){
                        dist[xx][yy]='D';
                    }
                    else{
                        dist[xx][yy]='U';
                    }
                }
                st.push(make_pair(xx,yy));
                if(arr[xx][yy]=='B'){
                    return make_pair(xx,yy);
                }
                arr[xx][yy]='#';
            }
        }
    }
    return make_pair(-1,-1);
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
    vector<vector<char>> dist(n,vector<char>(m,0));
    int c=0;
    queue<pair<int,int>> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A'){
                pair<int,int> ind=bfs(st,arr,i,j,n,m,dist);
                if(ind.first!=-1 && ind.second!=-1){
                    cout<<"YES"<<endl;
                    int indx=ind.first;
                    int indy=ind.second;
                    string ans="";
                    char curr=dist[indx][indy];
                    while(curr!='0'){
                        ans.push_back(curr);
                        if(curr=='U') indx+=1;
                        else if(curr=='D') indx-=1;
                        else if(curr=='R') indy-=1;
                        else indy+=1;
                        curr=dist[indx][indy];
                    }
                    cout<<ans.length()<<endl;
                    for(int i=ans.length()-1;i>=0;i--){
                        cout<<ans[i];
                    }
                    cout<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    // for(auto x:dist){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
