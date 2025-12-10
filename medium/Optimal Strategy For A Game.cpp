class Solution {
  public:
    
    int dp[1001][1001][2];
    int helper(int i,int j,bool ch,vector<int>&a)
    {
        if(i>j)return 0;
        int &res = dp[i][j][ch];
        if (res != -1) return res;
        if(ch==0)
        {
            int op1=a[i]+helper(i+1,j,!ch,a);
            int op2=a[j]+helper(i,j-1,!ch,a);
            return res=max(op1,op2);
        }
        else
        {
            int op1=-a[i]+helper(i+1,j,!ch,a);
            int op2=-a[j]+helper(i,j-1,!ch,a);
            return res=min(op1,op2);
        }
    }
  
    int maximumAmount(vector<int> &a) 
    {
        int n=a.size();
        memset(dp, -1, sizeof(dp));
        int diff=helper(0,n-1,0,a);
        int sum=0;
        for(auto x:a)sum+=x;
        int res=(sum+diff)/2;
        return res;
    }
};


