#define u uint64_t
vector<u> v(1e5 + 2);
const u MOD = 1e9 + 7;

const bool iife = []{
    v[0] = 0;
    v[1] = 1;
    for(u i = 2; i <= 1e5; ++i){
        int len = log2(i) + 1;
        v[i] = (v[i-1] * (u)(pow(2, len)) + i) % MOD;
    }
    return true;
}();


class Solution {
public:
    int concatenatedBinary(int n) {
        return (int)(v[n]);
    }
};