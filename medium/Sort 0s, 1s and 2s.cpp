class Solution {
  public:
    void sort012(vector<int>& a) 
    {
        int n=a.size();
        int l=0,r=n-1;
        int in=0;
        while(in<=r)
        {
            if(a[in]==0)
            {
                swap(a[l],a[in]);
                l++;
                in++;
            }
            else if(a[in]==1)
            {
                in++;
            }
            else
            {
                swap(a[r],a[in]);
                r--;
            }
        }
    }
};
