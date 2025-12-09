class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n=nums.size();
        map<int,vector<int>>m;
        for(int i=0;i<n;i++)m[nums[i]].push_back(i);

        set<int>s1;
        s1.insert(n);
        int ans=0;
        for(auto x:m)
        {
            if(x.first!=0)
            {
                int pv=-1;
                for(auto z:x.second)
                {
                    int nx=*s1.lower_bound(z);
                    if(nx!=pv)ans++;
                    pv=nx;
                }
            }
            for(auto z:x.second)s1.insert(z);
        }
        return ans;
    }
};
