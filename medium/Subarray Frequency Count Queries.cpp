class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) 
    {
        int mx=1e5+2;
        unordered_map<int, vector<int>> ele;
        for(int i=0;i<arr.size();i++)ele[arr[i]].push_back(i);
        vector<int>ans;
        for(auto x:queries)
        {
            int l=x[0],r=x[1],v=x[2];
            auto itr1=upper_bound(ele[v].begin(),ele[v].end(),r);
            auto itr2=lower_bound(ele[v].begin(),ele[v].end(),l);
            ans.push_back(itr1-itr2);
        }
        return ans;
    }
};
