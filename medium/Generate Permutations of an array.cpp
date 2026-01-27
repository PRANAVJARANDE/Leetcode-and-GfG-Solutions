class Solution {
  public:
    vector<vector<int>> permuteDist(vector<int>& a) 
    {
        sort(a.begin(),a.end());
        vector<vector<int>>ans;
        ans.push_back(a);
        while(next_permutation(a.begin(),a.end()))
        {
            ans.push_back(a);
        }
        return ans;
    }
};
