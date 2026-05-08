#define ll long long
class Solution {
  public:
    
    ll n;
    ll helper(ll in,ll cnt,string&s,vector<vector<ll>>&dp)
    {
        if(cnt<0)return INT_MIN;
        if(in>=n)
        {
            if(cnt==0)return 0;
            return INT_MIN;
        }
        if(dp[in][cnt]!=-1)return dp[in][cnt];
        if(!(s[in]==')' || s[in]=='('))
        {
            return dp[in][cnt]=1+helper(in+1,cnt,s,dp);
        }
        //ntake 
        ll op1=helper(in+1,cnt,s,dp);
        
        //take
        ll op2=1+helper(in+1,cnt+((s[in]==')') ? -1:1),s,dp);
        return dp[in][cnt]=max(op1,op2);
    }
    
    void generate(ll in,ll cnt,string &s,vector<vector<ll>>&dp,string curr,set<string>&ans)
    {
        if(cnt<0)return;
        if(in>=n)
        {
            if(cnt==0)ans.insert(curr);
            return;
        }
        
        if(!(s[in]==')' || s[in]=='('))
        {
            generate(in+1,cnt,s,dp,curr+s[in],ans);
            return;
        }
        
        ll best=dp[in][cnt];
        
        if(best==helper(in+1,cnt,s,dp))
        {
            generate(in+1,cnt,s,dp,curr,ans);
        }
        ll ncnt=cnt+((s[in]==')') ? -1:1);
        if(best==1+helper(in+1,ncnt,s,dp))
        {
            generate(in+1,ncnt,s,dp,curr+s[in],ans);
        }
    }
  
    vector<string> validParenthesis(string &s) 
    {
        n=s.size();
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
        helper(0,0,s,dp);        
        set<string>ans;
        generate(0,0,s,dp,"",ans);
        return vector<string>(ans.begin(),ans.end());
    }
};
