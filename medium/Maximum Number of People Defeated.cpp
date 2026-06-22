class Solution {
  public:
    int maxPeopleDefeated(int p) {
        long long in=1;
        while(p>=in*in)
        {
            p-=in*in;
            in++;
        }
        return in-1;
    }
};
