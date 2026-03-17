class Solution {
  public:
    int countSubarrays(vector<int> &a) 
    {
        int n=a.size();
        int ans=0;
        stack<int>s1;
        for(int i=n-1;i>=0;i--)
        {
            while(!s1.empty() && a[s1.top()]>=a[i])s1.pop();
            int ls=n;
            if(!s1.empty())ls=s1.top();
            ans+=ls-i;
            s1.push(i);
        }
        return ans;
    }
};
