class Solution {
  public:
    int minDeletions(vector<int>& arr) 
    {
        vector<int>res;
        for(auto x:arr)
        {
            auto in=lower_bound(res.begin(),res.end(),x)-res.begin();
            if(in==res.size())res.push_back(x);
            else res[in]=x;
        }
        return arr.size()-res.size();
    }
};
