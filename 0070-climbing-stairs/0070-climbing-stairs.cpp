class Solution {
public:
    int arr[1001];
    int climbStairs(int n) {

        if(n<=2) return n;
        if(arr[n])return arr[n];
        
        arr[n]=climbStairs(n-1)+climbStairs(n-2);

        return arr[n];

        
    }
};


// using DP
