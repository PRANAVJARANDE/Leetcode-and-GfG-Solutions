class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) 
    {
        int n=nums.size();
        vector<int>ans(n,-1);
        map<int,vector<int>>m;
        for(int i=0;i<n;i++)m[nums[i]].push_back(i);
        
        for(auto x:m)
        {
            int sz=x.second.size();
            if(sz==1)continue;
            for(int i=0;i<sz;i++)
            {
                int op1,op2;
                if(i==0)op1=n-x.second.back()+x.second[0];
                else op1=x.second[i]-x.second[i-1];
                if(i==sz-1)op2=n-x.second.back()+x.second[0];
                else op2=x.second[i+1]-x.second[i];
                int dis=min(op1,op2);
                ans[x.second[i]]=dis;
            }
        }
        vector<int>res;
        for(auto x:queries)res.push_back(ans[x]);
        return res;
    }
};
