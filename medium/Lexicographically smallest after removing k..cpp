class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) 
    {
        int n=s.size();
        if((n & (n-1))==0)k/=2;
        else k*=2;
        
        if(k>=n)return "-1";
        vector<vector<int>>nx(n+1,vector<int>(26,n));
        for(int i=n-1;i>=0;i--)
        {
            if(i+1<n)nx[i]=nx[i+1];
            nx[i][s[i]-'a']=i;
        }
        
        int tk=n-k;
        int cnt=0;
        int in=-1;
        string ans;
        while(cnt<tk)
        {
            for(int j=0;j<26;j++)
            {
                int np=nx[in+1][j];
                int tc=np-in-1;
                if(tc<=k)
                {
                    ans.push_back(j+'a');
                    k-=tc;
                    cnt++;
                    in=np;
                    break;
                }
            }
        }
        return ans;
    }
};
