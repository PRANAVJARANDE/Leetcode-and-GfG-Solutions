#define ll long long
class Solution {
  public:
    vector<int> constructArr(vector<int>& a) 
    {
        ll n=a.size();
        if(n==1)return {a[0]-1,1};
        ll asum=0;
        for(auto x:a)asum+=x;
        
        ll org=1;
        while(((org*(org-1))/2)!=n)org++;
        
        ll sum=asum/(org-1);
        map<ll,ll>m;
        
        ll in=0;
        for(int i=0;i<org;i++)
        {
            for(int j=i+1;j<org;j++)
            {
                m[i]+=a[in];
                m[j]+=a[in];
                in++;
            }
        }
        
        vector<int>ans(org);
        for(int i=0;i<org;i++)
        {
            ans[i]=(m[i]-sum)/(org-2);
        }
        return ans;
    }
};
