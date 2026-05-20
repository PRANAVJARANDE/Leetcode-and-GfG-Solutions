class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) 
    {
        vector<int>res;
        for(auto x:arr)
        {
            if(res.empty())res.push_back(x);
            else
            {
                if(x==0)
                {
                    if(res.back()<0)res.pop_back();
                    else res.push_back(x);
                }
                else if(res.back()==0)
                {
                    if(x<0)res.pop_back();
                    else res.push_back(x);
                }
                else
                {
                    if(!res.empty() && res.back()*x<0)res.pop_back();
                    else res.push_back(x);
                }
            }
        }
        return res;
    }
};
