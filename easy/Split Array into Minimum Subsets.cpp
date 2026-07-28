class Solution {
  public:
    int minSubsets(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        multiset<int>s1;
        for(auto x:arr)
        {
            int pv=x-1;
            if(s1.find(pv)!=s1.end())
            {
                s1.erase(s1.find(pv));
                s1.insert(x);
            }
            else 
            {
                s1.insert(x);
            }
        }
        return (int)s1.size();
    }
};
