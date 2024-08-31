class Solution {
public:
    string stringHash(string s, int k) {
       int n = s.length();
        string result = "";
        
        // Iterate through the string in chunks of size k
        for (int i = 0; i < n; i += k) {
            int sum = 0;
            
            // Calculate the sum of hash values for the current substring
            for (int j = i; j < i + k; j++) {
                sum += (s[j] - 'a');
            }
            
            // Calculate the hashed character and append it to the result
            char hashedChar = (sum % 26) + 'a';
            result += hashedChar;
        }
        
        return result; 
    }
};