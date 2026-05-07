class Solution {
  public:
    vector<int> kthLargest(vector<int>& a, int k) 
    {
        
        
        // q1 - Small to big (Small at top) ---->> main 
        
        int n=a.size();
        vector<int>ans(n,-1);
        
        priority_queue<int,vector<int>,greater<int>>q1;
        
        
        for(int i=0;i<n;i++)
        {
            q1.push(a[i]);
            if(q1.size()>k)q1.pop();
            if(q1.size()==k)
            {
                ans[i]=q1.top();
            }
        }
        return ans;
    }
};
