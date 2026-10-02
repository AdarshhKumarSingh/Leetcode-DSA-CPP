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

    //     for(int i = 1; i <= x; i++){

    // if(i == x / i){
    //     return i;
    // }

    // if(i > x / i){
    //     return i - 1;
    // }
    // }

    // return 0;

        



        // method 3(using binary search)
        if(x==0){
            return 0;
        }
        
        int low = 1 , high = x;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(mid>x/mid){
                high = mid-1;
            }
            else if(mid<x/mid){
                low=mid+1;
            }
            else{
                return mid;
            }
            
        }
        return high;
    }
};