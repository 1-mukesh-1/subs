typedef pair<int,pair<int,int>> pi;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<points.size();i++){
            int dist=pow(points[i][0],2)+pow(points[i][1],2);
            pq.push(make_pair(dist,make_pair(points[i][0],points[i][1])));
        }
        vector<vector<int>> ans;
        while(k--){
            pi temp=pq.top();
            pq.pop();
            pair<int,int> tempo=temp.second;
            vector<int> sample;
            sample.push_back(tempo.first);
            sample.push_back(tempo.second);
            ans.push_back(sample);
        }
        return ans;
    }
};
