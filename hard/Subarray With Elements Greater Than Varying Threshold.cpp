class Solution {
public:
    int validSubarraySize(vector<int>& nums, int th) 
    {
        int n=nums.size();
        vector<int>req(n,0);
        for(int i=0;i<n;i++)
        {
            req[i]=th/nums[i];
            req[i]++;
        }
        vector<int>pmax(n,-1),nmax(n,n);
        stack<int>s1,s2;
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && req[s1.top()]<=req[i])s1.pop();
            if(!s1.empty())pmax[i]=s1.top();
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && req[s2.top()]<=req[i])s2.pop();
            if(!s2.empty())nmax[i]=s2.top();
            s2.push(i);
        }

        // for(auto x:req)cout<<x<<" ";
        // cout<<endl;

        // for(auto x:pmax)cout<<x<<" ";
        // cout<<endl;

        // for(auto x:nmax)cout<<x<<" ";
        // cout<<endl;

        for(int i=0;i<n;i++)
        {
            int sz=nmax[i]-pmax[i]-1;
            // cout<<sz<<" ";
            if(sz>=req[i])
            {
                return req[i];
            }
        }
        return -1;
    }
};
