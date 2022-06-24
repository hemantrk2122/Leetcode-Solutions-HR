class Solution {
public:
    bool isPossible(vector<int>& target) {
        int long long sum=0;// initilize the sum and max to 0
            int max=0;
            for(int i=0;i<target.size();i++){ //by using loop find the sum and target max
                    sum+=target[i];
                    if(target[max]<target[i]){
                            max=i;
                    }
            } 
                    int long long diff=sum-target[max];//find diff
                     if(target[max]==1 || diff==1)return true;//base condition to return true 
                    
                    if(diff>target[max]==1 || diff==0 || target[max]%diff==0)return false;
                    //condition to return false
            target[max] %=diff;
            //to find the updated value of target max with minimum steps 
            return isPossible(target);//call the function untill it hit the base conditions
    }
};