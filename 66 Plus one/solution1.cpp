class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Iterate from the last digit to the first
        for (int i = n - 1; i >= 0; --i) {
            // If the current digit is less than 9, just increment and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // If the current digit is 9, set it to 0 and carry over
            digits[i] = 0;
        }

        // If we reach here, it means all digits were 9s (e.g., [9,9,9])
        // We need to add a leading 1 and append 0s for the rest
        digits.insert(digits.begin(), 1); // Insert 1 at the beginning
        return digits;
    }
};