class Solution {
  public:
    bool canSplit(vector<int>& arr) 
    {
        int sum=0;
        for(auto x:arr)sum+=x;
        int psum=0;
        for(auto x:arr)
        {
            sum-=x;
            psum+=x;
            if(sum==psum)return 1;
        }
        return 0;
    }
};
