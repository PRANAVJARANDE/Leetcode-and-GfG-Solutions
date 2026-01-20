class Solution {
  public:
    vector<int> calculateSpan(vector<int>& a) 
    {
        int n=a.size();
        vector<int>ans(n,0);
        stack<int>s1;
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && a[s1.top()]<=a[i])s1.pop();
            int pv=-1;
            if(!s1.empty())pv=s1.top();
            ans[i]=i-pv;
            s1.push(i);
        }
        return ans;
    }
};
