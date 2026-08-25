int hammingDistance(int x, int y) {
    // XOR finds all positions where bits are different
    unsigned int xor_result = x ^ y;
    int distance = 0;
    
    // Brian Kernighan's Algorithm to count set bits
    while (xor_result > 0) {
        xor_result &= (xor_result - 1); // Clears the lowest set bit
        distance++;
    }
    
    return distance;
}
