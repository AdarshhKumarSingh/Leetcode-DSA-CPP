class Solution {
public:
    int reverse(int num) {
        int rev = 0;

        while(num != 0) {
            int digit = num % 10;

            if(rev > INT_MAX / 10 ||
               (rev == INT_MAX / 10 && digit > 7))
                return 0;

            if(rev < INT_MIN / 10 ||
               (rev == INT_MIN / 10 && digit < -8))
                return 0;

            rev = rev * 10 + digit;
            num /= 10;
        }

        return rev;
    }
};



// Formula:
// rev > INT_MAX/10 → positive overflow
// rev == INT_MAX/10 && digit > 7 → positive overflow
// rev < INT_MIN/10 → negative overflow
// rev == INT_MIN/10 && digit < -8 → negative overflow