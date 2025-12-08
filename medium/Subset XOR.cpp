#define ll long long
class Solution {
  public:
 
    vector<int> subsetXOR(int n) 
    {
        int xs=0;
        for(int i=1;i<=n;i++)xs^=i;
        vector<int>ans;
        if(xs==n) 
        {
            for(int i=1;i<=n;i++)ans.push_back(i);
        } 
        else 
        {
            int removeVal=xs^n;
            for(int i=1;i<=n;i++) 
            {
                if(i!=removeVal)ans.push_back(i);
            }
        }
        return ans;
    }
};
