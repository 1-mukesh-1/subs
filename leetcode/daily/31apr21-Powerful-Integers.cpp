class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> ans;
        int fst=1;
        while(fst<=bound){
            int sec=1;
            while(sec<=bound){
                int temp=fst+sec;
                if(temp>bound) break;
                ans.insert(temp);
                sec*=y;
                if(y==1){
                    break;
                }
            }
            fst*=x;
            if(x==1){
                break;
            }
        }
        vector<int> ret;
        for(auto x:ans) ret.push_back(x);
        return ret;
    }
};
