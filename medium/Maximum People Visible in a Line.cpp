class Solution {
  public:
    int maxPeople(vector<int> &a) {
        int n=a.size();
        vector<int>nmax(n,n),pmax(n,-1);
        stack<int>s1;
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && a[s1.top()]<a[i])s1.pop();
            if(!s1.empty())pmax[i]=s1.top();
            s1.push(i);
        }
        
        stack<int>s2;
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && a[s2.top()]<a[i])s2.pop();
            if(!s2.empty())nmax[i]=s2.top();
            s2.push(i);
        }
        
        int ans=1;
        for(int i=0;i<n;i++)
        {
            int res=nmax[i]-pmax[i]-1;
            ans=max(ans,res);
        }
        return ans;
    }
};
