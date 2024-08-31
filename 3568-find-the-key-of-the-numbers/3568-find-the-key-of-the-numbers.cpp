class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
     int key = 0;
        int multiplier = 1;
        
        // Iterate through each digit position from least significant to most significant
        for (int i = 0; i < 4; i++) {
            // Get the ith digit from the right for each number
            int digit1 = num1 % 10;
            int digit2 = num2 % 10;
            int digit3 = num3 % 10;
            
            // Find the minimum digit
            int minDigit = min({digit1, digit2, digit3});
            
            // Build the key by placing the minDigit at the correct position
            key += minDigit * multiplier;
            
            // Move to the next digit position
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
            multiplier *= 10;
        }
        
        return key;   
    }
};