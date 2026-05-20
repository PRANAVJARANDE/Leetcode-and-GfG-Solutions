class Solution {
  public:
    int findSmallest(vector<int> &arr) 
    {
        sort(arr.begin(),arr.end());
        int ans=1;
        for(auto x:arr)
        {
            if(x>ans)return ans;
            ans+=x;
        }
        return ans;
    }
};
