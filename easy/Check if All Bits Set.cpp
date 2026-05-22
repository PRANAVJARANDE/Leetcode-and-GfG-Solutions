class Solution {
  public:
    bool isBitSet(int n) {
        if(n==0)return 0;
        if((n & (n+1)))return 0;
        return 1;
    }
};
