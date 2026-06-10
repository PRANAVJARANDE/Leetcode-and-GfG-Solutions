#define ll long long
class Solution {
public:

    int n;
    int next_ind(int a,vector<vector<int>>&v1)
    {
        int l=0,r=n-1;
        int ans=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(v1[mid][0]<=a)
            {
                l=mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }

    map<pair<ll,ll>,pair<ll,vector<int>>>dp;
    
    pair<ll,vector<int>> helper(ll in,ll k,vector<vector<int>>&v1)
    {
        if(in>=n || k==0)return {0,{}};
        if(dp.find({in,k})!=dp.end())return dp[{in,k}];
        //ntake
        auto op1=helper(in+1,k,v1);

        //take
        pair<ll,vector<int>>op2={0,{}};
        if(k>=1)op2=helper(next_ind(v1[in][1],v1),k-1,v1);
        op2.first+=v1[in][2];
        op2.second.push_back(v1[in][3]);
        sort(op2.second.begin(),op2.second.end());

        pair<ll,vector<int>>res;
        if(op1.first>op2.first)res=op1;
        else if(op2.first>op1.first)res=op2;
        else 
        {
            res.first=op1.first;
            res.second=min(op1.second,op2.second);
        }
        return dp[{in,k}]=res;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) 
    {
        n=intervals.size();
        for(int i=0;i<n;i++)intervals[i].push_back(i);
        sort(intervals.begin(),intervals.end());
        auto ans=helper(0,4,intervals);
        return ans.second;
    }
};
