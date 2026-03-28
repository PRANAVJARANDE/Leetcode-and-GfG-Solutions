class Solution {
public:

    int n;
    int helper(int i,int j,string&s,vector<vector<int>>&dp)
    {
        if(i>=n || j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return dp[i][j]=1+helper(i+1,j+1,s,dp);
        else
        {
            return dp[i][j]=0;
        }
    }

    string findTheString(vector<vector<int>>& a) 
    {
        n=a.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    if(a[i][i]!=(n-i))return "";
                }
                else if(a[i][j]!=a[j][i])return "";
                else
                {
                    int mini=min(n-i,n-j);
                    if(a[i][j]>mini)return "";
                }
            }
        }
        
        string s(n,'0');
        char ch='a';
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(ch>'z')return "";
                for(int j=i;j<n;j++)
                {
                    if(a[i][j]>0)s[j]=ch;
                }
                ch++;
            }
        }

        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(helper(i,j,s,dp)!=a[i][j])return "";
            }
        }
        return s;
    }
};
