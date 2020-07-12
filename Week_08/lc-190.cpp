//190. 颠倒二进制位
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t temp = 0;
        for(int i = 0;i < 32;i++)
        {
            temp <<= 1;
            temp += (n & 1);
            n >>= 1;
        }
        return temp;
    }
};