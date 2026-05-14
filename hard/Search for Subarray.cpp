class Solution {
  public:
    
    vector<int> getLPS(vector<int>&b)
    {
        int n=b.size();
        vector<int>lps(n,-1);
        int in=-1;
        
        for(int i=1;i<n;i++)
        {
            while(in!=-1 && b[in+1]!=b[i])
            {
                in=lps[in];
            }
            if(b[in+1]==b[i])in++;
            lps[i]=in;
        }
        return lps;
    }
    
    vector<int> search(vector<int> &a, vector<int> &b) 
    {
        int n=a.size();
        int m=b.size();
        vector<int>lps=getLPS(b);
        vector<int>ans;
        int in=-1;
        for(int i=0;i<n;i++)
        {
            while(in!=-1 && b[in+1]!=a[i])
            {
                in=lps[in];
            }
            if(b[in+1]==a[i])in++;
            if(in==m-1)
            {
                ans.push_back(i-m+1);
                in=lps[in];
            }
        }
        return ans;
    }
};
