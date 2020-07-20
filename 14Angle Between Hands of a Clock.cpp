class Solution {
public:
    double angleClock(int h, int m) {
        float hour=(h%12+(float)m/60)*30;
        float min=m*6;
        float angle=abs(min-hour);
        if(angle>180)angle=360-angle;
        return angle;
        
    }
};
