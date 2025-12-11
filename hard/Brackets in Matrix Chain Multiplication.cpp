#define ll long long
class Solution {
  public:
  
    pair<ll,string> helper(int i,int j,vector<int>&a,vector<vector<pair<ll,string>>>&dp)
    {
        if(i>j)return {INT_MAX,""};
        if(dp[i][j].first!=-1)return dp[i][j];
        if(j-i==1)
        {
            char ch=i+'A';
            string temp="";
            return dp[i][j]={0,temp+ch};
        }
        ll ans=INT_MAX;
        string temp="";
        for(int mid=i+1;mid<j;mid++)
        {
            ll res=a[i]*a[mid]*a[j];
            auto left=helper(i,mid,a,dp);
            auto right=helper(mid,j,a,dp);
            res+=left.first+right.first;
            if(res<ans)
            {
                ans=res;
                temp="("+left.second+right.second+")";
            }
        }
        return dp[i][j]={ans,temp};
    }
    
    string matrixChainOrder(vector<int> &a) 
    {
        int n=a.size();
        vector<vector<pair<ll,string>>>dp(n,vector<pair<ll,string>>(n,{-1,""}));
        auto ans=helper(0,n-1,a,dp);
        //cout<<ans.second<<endl;
        return ans.second;
    }
};
