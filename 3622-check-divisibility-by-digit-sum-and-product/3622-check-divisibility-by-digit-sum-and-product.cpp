class Solution {
public:
    bool checkDivisibility(int n) {
        // Initialize sum and product of digits
        int digitSum = 0;
        int digitProduct = 1;
      
        // Create a copy of n to extract digits
        int number = n;
      
        // Extract each digit from right to left
        while (number != 0) {
            // Get the rightmost digit
            int currentDigit = number % 10;
          
            // Remove the rightmost digit from number
            number /= 10;
          
            // Update sum and product
            digitSum += currentDigit;
            digitProduct *= currentDigit;
        }
      
        // Check if n is divisible by (sum + product) of its digits
        return n % (digitSum + digitProduct) == 0;
    }
};
