class Solution {
public:
    int fib(int n) {
        int prev = 1;
        int next = 1;
        if(n == 0)return 0;
        if(n == 1 || n == 2)return 1;
        for(int i = 3;i<=n;i++){
            int temp = next;
            next += prev;
            prev = temp;
        }
        return next;
    }
};