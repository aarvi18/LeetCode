class Solution {
public:
    bool isPalindrome(int x) {
        int ld, rev = 0;
        int num = x;
        while(x > 0) {
            ld = x % 10;
            if(rev > INT_MAX/10 || rev < INT_MIN/10){
                return false;
            }
            rev = (rev*10) + ld;
            x = x / 10;
        }
        return (rev == num);
    }
};