class Solution {
public:

    int tsum;
    set<int>ops;
    int build(int in,int par,vector<vector<int>>&adj,vector<int>&nums)
    {
        int sum=nums[in];
        for(auto x:adj[in])if(x!=par)sum+=build(x,in,adj,nums);
        if(tsum%sum==0)ops.insert(sum);
        return sum;
    }
    
    int helper(int in,int par,vector<int>&nums,vector<vector<int>>&adj,int val,int &tres)
    {
        int sum=nums[in];
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                int res=helper(x,in,nums,adj,val,tres);
                if(res==-1)return -1;
                sum+=res;
            }
        }
        if(sum==val)
        {
            tres++;
            return 0;
        }
        if(sum>val)return -1;
        return sum;
    }

    int componentValue(vector<int>& nums, vector<vector<int>>& edg) 
    {
        int n=nums.size();
        vector<vector<int>>adj(n);
        for(auto x:edg)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        tsum=0;
        for(auto x:nums)tsum+=x;
        build(0,-1,adj,nums);
    
        int ans=1;
        for(auto x:ops)
        {
            int tres=0;
            int tp=helper(0,-1,nums,adj,x,tres);
            if(tp!=-1)ans=max(ans,tres);
        }
        return ans-1;
    }
};
