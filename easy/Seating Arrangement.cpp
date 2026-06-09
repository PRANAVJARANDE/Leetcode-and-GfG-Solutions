class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) 
    {
        int n=seats.size();
        for(int i=0;i<n;i++)
        {
            bool f1=0,f2=0;
            if(i-1>=0 && seats[i-1]==1)f1=1;
            if(i+1<n && seats[i+1]==1)f2=1;
            if(seats[i]==0 && !f1 && !f2)
            {
                seats[i]=1;
                k--;
            }
            if(seats[i]==1 && (f1 || f2))return 0;
        }
        if(k<=0)return 1;
        return 0;
        
    }
};
