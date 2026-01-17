class Solution {
  public:
    bool checkRedundancy(string &s)
    {
        stack<char>s1;
        for(auto x:s)
        {
            if(x=='(')s1.push(x);
            else if(x=='+' || x=='-' || x=='*' || x=='/')
            {
                if(!s1.empty() && s1.top()=='(')s1.push(x);
            }
            else if(x==')')
            {
                if(s1.top()=='(')return 1;
                while(!s1.empty() && s1.top()!='(')s1.pop();
                s1.pop();
            }
        }
        return 0;
    }
};
