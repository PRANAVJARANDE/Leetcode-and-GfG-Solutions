// Time Complexity : O(n) 
// Space Complexity : O(1)

class Solution {
  public:
    int maxCircularSum(vector<int> &a) 
    {
        int n=a.size();
        bool ps=0;
        for(auto x:a)
        {
            if(x>=0)
            {
                ps=1;
                break;
            }
        }
        if(ps==0)
        {
            int mini=INT_MIN;
            for(int i=0;i<n;i++)mini=max(mini,a[i]);
            return mini;
        }
        
        int ans=0;
        int cs=0;
        int sum=0;
        for(auto x:a)
        {
            sum+=x;
            cs+=x;
            if(cs<0)cs=0;
            ans=max(ans,cs);
        }
        
        int mini=0;
        cs=0;
        for(auto x:a)
        {
            cs+=x;
            if(cs>0)cs=0;
            mini=min(mini,cs);
        }
        sum-=mini;
        return max(ans,sum);
    }
};

// Time Complexity : O(nlogn) 
// Space Complexity : O(2*n + n)

class Solution {
  public:
    int maxCircularSum(vector<int> &a) 
    {
        int n=a.size();
        for(int i=0;i<n;i++)a.push_back(a[i]);
        vector<int>psum(2*n+1,0);
        for(int i=0;i<2*n;i++)psum[i+1]=a[i]+psum[i];
        int ans=INT_MIN;
        multiset<int>s1;
        s1.insert(0);
        for(int i=1;i<=2*n;i++)
        {
            if(i-n-1>=0)s1.erase(s1.find(psum[i-n-1]));
            int res=psum[i]-*s1.begin();
            ans=max(ans,res);
            s1.insert(psum[i]);
        }
        return ans;
    }
};
