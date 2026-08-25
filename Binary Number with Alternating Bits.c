#include <stdbool.h>

bool hasAlternatingBits(int n) {
    // Shift n right by 1 and XOR with original n
    // If bits are alternating, this creates a number with all 1s (e.g., 1111)
    unsigned int x = n ^ (n >> 1);
    
    // Check if x + 1 clears all bits (e.g., 1111 + 1 = 10000)
    // 1111 & 10000 == 0
    return (x & (x + 1)) == 0;
}
