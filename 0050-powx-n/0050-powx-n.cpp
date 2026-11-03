// class Solution {
// public:
//     double power(double a ,long long b){
//         if(b==0)return  1;
        
//         double p=power(a,b/2);

//         if(b%2==0){
//             return p*p;
//         }else{
//             return p*p*a;
//         }
//     }

//     double myPow(double a, int b) {
//         bool flag = (b>=0);
//         long long b2 = b;
//         double ans = power(a,abs(b2));

//         if(!flag){
//             ans=1/ans;
//         }
//         return ans;
//     }
// };





class Solution {
public:
    double power(double a ,long long b){
        if(b==0)return 1;
        double half = power(a,b/2);

        if(b%2==0){
            return half*half;
        }else{
            return half*half*a;
        }
        
        }
    

    double myPow(double a, int b) {
        // bool flag = (b>=0);
        long long b2= b ;
        
        double ans = power(a,abs(b2));

        if(b<0){
            ans=1/ans;
        }
        return ans;
    }
};