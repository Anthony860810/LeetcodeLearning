#define LENGTH  32
#define SHIFT   1

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < LENGTH; i++) {
            int bit = n & 1;
            result = result << SHIFT;
            result |= bit;
            n = n >> SHIFT;
        }

        return result;
    }
};