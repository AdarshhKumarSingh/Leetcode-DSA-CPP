class Solution {
public:
    int mySqrt(int x) {
        //// method 1(overflow safe krne ke liye)
        // long long n = x;
        // for(long long i=0;i<=x;i++){
        //     if(i*i==x){
        //         return i;
        //     }
        //     if(i*i>x){
        //         return i-1;
        //     }
        // }
        //return 23423;



        // method 2
        // without long long

        for(int i = 1; i <= x; i++){

    if(i == x / i){
        return i;
    }

    if(i > x / i){
        return i - 1;
    }
    }

    return 0;

        
    }
};