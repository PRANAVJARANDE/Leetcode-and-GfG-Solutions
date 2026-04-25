class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) 
    {
        vector<int>ans;
        for(auto x:arr) 
        {
            while(!ans.empty() && ans.back()*x<0) 
            {
                int top=ans.back();
                if(abs(top)>abs(x)) 
                {
                    x=top;
                    ans.pop_back();
                }
                else if(abs(top)<abs(x)) 
                {
                    ans.pop_back();  
                }
                else 
                {
                    ans.pop_back(); 
                    x=0; 
                    break;
                }
            }
            if(x!= 0)ans.push_back(x);
        }
        return ans;
    }
};
