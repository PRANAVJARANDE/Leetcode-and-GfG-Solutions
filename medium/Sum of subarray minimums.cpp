class Solution {
  public:
    int sumSubMins(vector<int> &a) 
    {
        int n=a.size();
        vector<int>nmin(n,n);
        vector<int>pmin(n,-1);
        
        stack<int>s1,s2;
        for(int i=n-1;i>=0;i--)
        {
            while(!s1.empty() && a[s1.top()]>a[i])s1.pop();
            if(!s1.empty())nmin[i]=s1.top();
            s1.push(i);
        }
        for(int i=0;i<n;i++)
        {
            while(!s2.empty() && a[s2.top()]>=a[i])s2.pop();
            if(!s2.empty())pmin[i]=s2.top();
            s2.push(i);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int l=i-pmin[i];
            int r=nmin[i]-i;
            ans+=l*r*a[i];
        }
        return ans;
    }
};
