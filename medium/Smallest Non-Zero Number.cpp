class Solution {
public:
    bool check(int mid, vector<int>& a)
    {
        long long cr=mid;
        for(int x:a)
        {
            if(cr>10000)return 1;
            cr=2*cr-x;
            if(cr<0)return 0;
        }
        return 1;
    }

    int find(vector<int>& arr)
    {
        int ans=10000;
        int l=0,r=10000;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,arr))
            {
                ans=mid;
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
