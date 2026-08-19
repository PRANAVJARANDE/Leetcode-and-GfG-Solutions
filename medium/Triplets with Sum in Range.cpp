class Solution {
public:

    long long solve(vector<int>& a, int x)
    {
        int n=a.size();
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;

            while(j<k)
            {
                if(a[i]+a[j]+a[k]<=x)
                {
                    ans+=k-j;
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }

    int countTriplets(vector<int> &a, int l, int r)
    {
        sort(a.begin(),a.end());
        return solve(a,r)-solve(a,l-1);
    }
};
