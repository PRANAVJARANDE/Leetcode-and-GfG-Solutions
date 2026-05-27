class Solution {
  public:
    bool wifiRange(string &s, int x) 
    {
        int n=s.size();
        vector<int>nx(n,-1),pv(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')pv[i]=i;
            else if(i-1>=0)pv[i]=pv[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')nx[i]=i;
            else if(i+1<n)nx[i]=nx[i+1];
        }
        
        for(int i=0;i<n;i++)
        {
            int diff=INT_MAX;
            if(pv[i]!=-1)diff=min(diff,abs(i-pv[i]));
            if(nx[i]!=-1)diff=min(diff,abs(nx[i]-i));
            if(diff>x)return 0;
        }
        return 1;   
        
    }
};
