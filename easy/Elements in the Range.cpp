class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) 
    {
        sort(arr.begin(),arr.end());
        auto in=lower_bound(arr.begin(),arr.end(),start)-arr.begin();
        
        int cr=start;
        while(in<arr.size())
        {
            bool flag=0;
            while(in<arr.size() && arr[in]==cr)
            {
                flag=1;
                in++;
            }
            if(flag==0)return 0;
            cr++;
            if(cr>end)return 1;
        }
        return 0;
    }
};
