class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) 
    {
        vector<int>ans;
        for(auto &q:queries)
        {
            int l=q[0],r=q[1],x=q[2];
            auto it1=lower_bound(arr.begin()+l,arr.begin()+r+1,x);
            auto it2=upper_bound(arr.begin()+l,arr.begin()+r+1,x);
            ans.push_back(it2-it1);
        }
        return ans;
    }
};
