class Solution {
  public:
    
    vector<int>ans;
    int n;
    void helper(int in,int pv,string&res)
    {
        if(in>=n)
        {
            ans.push_back(stoi(res));
            return;
        }
        for(int i=pv+1;i<=9;i++)
        {
            res.push_back(i+'0');
            helper(in+1,i,res);
            res.pop_back();
        }
    }
    
 
    vector<int> increasingNumbers(int n) 
    {
        if(n>=10)return ans;
        this->n=n;
        if(n==1)ans.push_back(0);
        string res;
        helper(0,0,res);
        
        return ans;
    }
};
