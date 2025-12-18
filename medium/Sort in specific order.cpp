class Solution {
  public:
    
    static bool cmp(int&a,int&b)
    {
        if(a%2==1 && b%2==0)return 1;
        else if(a%2==0 && b%2==1)return 0;
        else if(a%2==0 && b%2==0)return a<b;
        else return a>b;
    }

    void sortIt(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end(),cmp);
    }
};
