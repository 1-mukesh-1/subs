class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int n) {
        vector<int> left;
        vector<int> right;
        int mini=arr[0];
        for(int i=0;i<n;i++){
            mini=min(mini,arr[i]);
            left.push_back(mini);
        }
        int maxi=arr[n-1];
        for(int i=n-1;i>-1;i--){
            maxi=max(maxi,arr[i]);
            right.push_back(maxi);
        }
        vector<int> ans;
        reverse(right.begin(),right.end());
        for(int i=0;i<n;i++){
            if(left[i]<arr[i] && right[i]>arr[i]){
                ans.push_back(left[i]);
                ans.push_back(arr[i]);
                ans.push_back(right[i]);
                return ans;
            }
        }
        return ans;
    }
};
