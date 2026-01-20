class Solution {
  public:
    
    string s;
    stack<char>s1;
  
    void append(char x) 
    {
        s.push_back(x);
    }

    void undo() 
    {
        if(!s.empty())
        {
            s1.push(s.back());
            s.pop_back();
        }
    }

    void redo() 
    {
        if(!s1.empty())
        {
            s.push_back(s1.top());
            s1.pop();
        }
    }

    string read() {
        return s;
    }
};
