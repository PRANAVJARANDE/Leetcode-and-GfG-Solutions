// Greeedy -------------------------------------------------------------
// O(n + m)
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>>&a) 
    {
        int n=a.size();
        int m=a[0].size();
        int j=m-1;
        int i=0;
        int ans=-1;
        while(i<n && j>=0)
        {
            if(a[i][j]==1)
            {
                j--;
                ans=i;
            }
            else i++;
        }
        return ans;
    }
};

// Binary search ------------------------------------------------------
// O(n * log(m))
// class Solution {
//   public:
//     int rowWithMax1s(vector<vector<int>>&a) 
//     {
//         int ans=-1;
//         int mini=0;
//         for(int i=0;i<a.size();i++)
//         {
//             int cnt=a[i].end()-lower_bound(a[i].begin(),a[i].end(),1);
//             if(cnt>mini)
//             {
//                 mini=cnt;
//                 ans=i;
//             }
//         }
//         return ans;
//     }
// };


// Brute Force -------------------------------------------------------
// O(n*m)
// class Solution {
//   public:
//     int rowWithMax1s(vector<vector<int>>&a) 
//     {
//         int ans=-1;
//         int mini=0;
//         for(int i=0;i<a.size();i++)
//         {
//             int cnt=0;
//             for(auto x:a[i])cnt+=x;
//             if(cnt>mini)
//             {
//                 mini=cnt;
//                 ans=i;
//             }
//         }
//         return ans;
//     }
// };
