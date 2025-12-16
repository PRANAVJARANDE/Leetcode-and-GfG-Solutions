class Solution {
  public:
    
    vector<int> helper(string&s)
    {
        int n=s.size();
        vector<int>lps(n,-1);
        int in=-1;
        for(int i=1;i<n;i++)
        {
            while(in!=-1 && s[i]!=s[in+1])
            {
                in=lps[in];
            }
            if(s[in+1]==s[i])in++;
            lps[i]=in;
        }
        return lps;
    }
  
    bool areRotations(string &s, string &t) 
    {
        s=s+s;
        int n=s.size();
        vector<int>lps=helper(t);
        int m=t.size();
        
        int in=-1;
        for(int i=0;i<n;i++)
        {
            while(in!=-1 && s[i]!=t[in+1])
            {
                in=lps[in];
            }
            if(s[i]==t[in+1])in++;
            if(in==m-1)return 1;
        }
        return 0;
    }
};
