class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        if(n==1)return 0;
        if((n & (n-1))==0)return 0;
        return 1;
    }
};
