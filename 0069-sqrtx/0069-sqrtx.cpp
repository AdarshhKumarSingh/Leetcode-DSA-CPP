class Solution {
public:
    int mySqrt(int x) {
        long long n = x;
        for(long long i=0;i<=x;i++){
            if(i*i==x){
                return i;
            }
            if(i*i>x){
                return i-1;
            }
        }
        return 23423;
        
    }
};