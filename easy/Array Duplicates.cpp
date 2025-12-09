class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) 
    {
        map<int,int>m;
        vector<int>ans;
        for(auto x:arr)
        {
            m[x]++;
            if(m[x]==2)ans.push_back(x);
        }
        return ans;
        
    }
};
