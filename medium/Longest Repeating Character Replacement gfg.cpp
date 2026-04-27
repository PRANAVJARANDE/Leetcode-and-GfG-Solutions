class Solution {
  public:
    int longestSubstr(string& s, int k) 
    {
        int n=s.size();
        int ans=1;
        for(char c='A';c<='Z';c++)
        {
            int l=0;
            int sum=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]!=c)sum++;
                while(sum>k)
                {
                    if(s[l]!=c)sum--;
                    l++;
                }
                ans=max(ans,i-l+1);
            }
        }
        return ans;
    }
};
