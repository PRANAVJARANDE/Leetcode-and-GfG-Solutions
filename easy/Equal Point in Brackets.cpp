class Solution {
  public:
    int findIndex(string &s) {
        int cls=0;
        for(auto x:s)if(x==')')cls++;
        int opn=0,ans=0;
        int in=0;
        for(auto x:s)
        {
            if(x=='(')opn++;
            else cls--;
            if(opn==cls)return in+1;
            in++;
        }
        return ans;
    }
};
