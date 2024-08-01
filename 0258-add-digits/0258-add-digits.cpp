class Solution {
public:
    int addDigits(int num) {
        while(num>9) {
            int ld = 0;
            int sum = 0;
            while(num!=0){
                ld = num % 10;
                sum += ld;
                num /= 10;
            }
            num = sum;
        }

        return num;
        
    }
};