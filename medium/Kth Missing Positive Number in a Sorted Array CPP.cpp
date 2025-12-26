// O(n) ----------------------------------------------------

// class Solution {
//   public:
//     int kthMissing(vector<int> &a, int k) 
//     {
//         // int in=1;
//         // for(auto x:a)
//         // {
//         //     int missing=(x-in);
//         //     if(k>missing)
//         //     {
//         //         k-=missing;
//         //         in=x+1;
//         //     }
//         //     else
//         //     {
//         //         return in+k-1;
//         //     }
//         // }
//         // return in+k-1;
//     }
// };

class Solution {
  public:
    int kthMissing(vector<int>&a, int k) 
    {
        int n=a.size();
        int ans=n+k;
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(a[mid]>mid+k)
            {
                ans=mid+k;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
