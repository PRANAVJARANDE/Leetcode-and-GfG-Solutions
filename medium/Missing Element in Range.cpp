class Solution {
  public:
    vector<int> missinRange(vector<int>& a, int low, int high) {
        sort(a.begin(),a.end());
        vector<int>ans;
        for(int i=low;i<=high;i++)
        {
            auto in=lower_bound(a.begin(),a.end(),i)-a.begin();
            if(in==a.size() || a[in]!=i)ans.push_back(i);
        }
        return ans;
    }
};
