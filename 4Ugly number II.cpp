class Solution {
public:
    int hammingDistance(int x, int y) {
        int n= x ^y;
    int setBits = 0; 
  
    while (n> 0) { 
        setBits += n & 1;
        n>>= 1; 
    } 
  
    return setBits; 
        
    }
};