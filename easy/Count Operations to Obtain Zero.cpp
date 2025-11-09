class Solution {
public:
    int countOperations(int num1, int num2) {
        int op=0;
        while(num1 && num2)
        {
            op++;
            if(num1>num2)num1-=num2;
            else num2-=num1;
        }
        return op;
    }
};
