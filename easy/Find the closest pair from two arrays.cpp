class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) 
    {
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        
        int p1=-1,p2=-1,diff=INT_MAX;
        for(auto a:arr1)
        {
            int req=x-a;
            auto in=lower_bound(arr2.begin(),arr2.end(),req)-arr2.begin();
            if(in!=arr2.size())
            {
                int b=arr2[in];
                int d=abs(x-(a+b));
                if(d<diff)
                {
                    diff=d;
                    p1=a;
                    p2=b;
                }
            }
            in--;
            if(in>=0)
            {
                int b=arr2[in];
                int d=abs(x-(a+b));
                if(d<diff)
                {
                    diff=d;
                    p1=a;
                    p2=b;
                }
            }
        }
        return {p1,p2};
       
    }
};
