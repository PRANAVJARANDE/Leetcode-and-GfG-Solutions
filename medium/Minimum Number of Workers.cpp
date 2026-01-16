class Solution {
  public:
    
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
  
    int minMen(vector<int>& a) 
    {
        int n=a.size();
        vector<vector<int>>v1;
        for(int i=0;i<n;i++)if(a[i]!=-1)v1.push_back({max(0,i-a[i]),min(n-1,i+a[i])});
        sort(v1.begin(),v1.end(),cmp);
        int sz=v1.size();
        if(sz==0)return -1;
        
        int ans=0;
        int in=0;
        int emax=-1;
        while(emax<n-1)
        {
            if(in>=sz)return -1;
            if(v1[in][0]>emax+1)return -1;
            ans++;
            int nmax=emax;
            while(in<sz && v1[in][0]<=emax+1)
            {
                nmax=max(nmax,v1[in][1]);
                in++;
            }
            if(nmax==emax)return -1;
            emax=nmax;
        }
        return ans;
    }
};
