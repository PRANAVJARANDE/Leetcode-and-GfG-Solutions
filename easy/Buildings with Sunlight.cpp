class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int ans=0;
        int maxi=INT_MIN;
        for(auto x:arr)
        {
            if(x>=maxi)ans++;
            maxi=max(maxi,x);
        }
        return ans;
    }
};
