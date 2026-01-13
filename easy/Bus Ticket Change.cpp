class Solution {
  public:
    bool canServe(vector<int> &a) 
    {
        int n5=0,n10=0;
        for(auto x:a)
        {
            if(x==5)n5++;
            else if(x==10)
            {
                if(n5>0)n5--;
                else return 0;
                n10++;
            }
            else
            {
                if(n5>0 && n10>0)
                {
                    n5--;
                    n10--;
                }
                else if(n5>=3)n5-=3;
                else return 0;
            }
        }
        return 1;
    }
};
