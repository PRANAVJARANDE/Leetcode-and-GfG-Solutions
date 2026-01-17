class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& a) 
    {
        map<int,int>freq;
        for(auto x:a)freq[x]++;
        stack<int>s1;
        int n=a.size();
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!s1.empty() && freq[a[i]]>=freq[s1.top()])s1.pop();
            if(!s1.empty())ans[i]=s1.top();
            s1.push(a[i]);
        }
        return ans;
    }
};
