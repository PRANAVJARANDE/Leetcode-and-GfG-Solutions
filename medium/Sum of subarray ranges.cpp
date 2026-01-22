class Solution {
  public:
    int subarrayRanges(vector<int>& a) 
    {
        int n=a.size();
        
        stack<int>s1;
        vector<int>pmax(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && a[s1.top()]<a[i])s1.pop();
            if(!s1.empty())pmax[i]=s1.top();
            s1.push(i);
        }
        
        stack<int>s2;
        vector<int>nmax(n,n);
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && a[s2.top()]<=a[i])s2.pop();
            if(!s2.empty())nmax[i]=s2.top();
            s2.push(i);
        }
        
        stack<int>s3;
        vector<int>pmin(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!s3.empty() && a[s3.top()]>a[i])s3.pop();
            if(!s3.empty())pmin[i]=s3.top();
            s3.push(i);
        }
        
        stack<int>s4;
        vector<int>nmin(n,n);
        for(int i=n-1;i>=0;i--)
        {
            while(!s4.empty() && a[s4.top()]>=a[i])s4.pop();
            if(!s4.empty())nmin[i]=s4.top();
            s4.push(i);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt1=(nmax[i]-i)*(i-pmax[i]);
            ans+=a[i]*cnt1;
            
            int cnt2=(nmin[i]-i)*(i-pmin[i]);
            ans-=a[i]*cnt2;
        }
        return ans;
 
    }
};
