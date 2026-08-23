class Solution {
public:
    int findComplement(int num) {
        int bit_length = 32 - __builtin_clz(num);
        unsigned int mask = (1ULL << bit_length) - 1;
        return num ^ mask;
    }
};
