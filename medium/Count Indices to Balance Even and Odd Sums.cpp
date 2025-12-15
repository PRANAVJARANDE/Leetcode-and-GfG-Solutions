class Solution {
  public:
    int cntWays(vector<int>& a) 
    {
        int n=a.size();
        vector<int>od(n,0);
        vector<int>ev(n,0);
        for(int i=0;i<n;i++)
        {
            if(i%2==0)ev[i]+=a[i];
            else od[i]+=a[i];
            if(i-1>=0)
            {
                ev[i]+=ev[i-1];
                od[i]+=od[i-1];
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int sum_ev=ev[i];
            int sum_od=od[i];
            
            if(i%2==0)sum_ev-=a[i];
            else sum_od-=a[i];
            
            sum_ev+=(od[n-1]-od[i]);
            sum_od+=(ev[n-1]-ev[i]);
            
            if(sum_ev==sum_od)ans++;
        }
        return ans;
    }
};
