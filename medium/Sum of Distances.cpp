#define ll long long
class Solution {
public:
    vector<long long> distance(vector<int>& nums) 
    {
        int n=nums.size();
        map<int,vector<ll>>m;
        for(int i=0;i<nums.size();i++)m[nums[i]].push_back(i);
        vector<ll>ans(n,0);

        for(auto &x:m)
        {
            int sz=x.second.size();
            vector<ll>psum(sz,0);
            psum[0]=x.second[0];
            for(int i=1;i<sz;i++)psum[i]=psum[i-1]+x.second[i];

            for(int i=0;i<sz;i++)
            {
                ll val=x.second[i];
                ll pv=psum[i];
                ll nx=psum[sz-1]-psum[i];

                ll res1=(val*(i+1))-pv;
                ll res2=nx-(val*(sz-i-1));
                ans[val]=res1+res2;
            }
        }
        return ans;
    }
};
