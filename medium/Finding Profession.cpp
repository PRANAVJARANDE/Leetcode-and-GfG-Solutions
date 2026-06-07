class Solution {
  public:
    
    string profession(int level, int pos) 
    {
        pos--;
        int cnt=0;
        while(pos)
        {
            if(pos%2)cnt++;
            pos/=2;
        }
        if(cnt%2==0)return "Engineer";
        else return "Doctor";
    }
};
