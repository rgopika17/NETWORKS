#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    
    // The maximum possible length of the result is max(lenA, lenB) + 1 (for potential carry)
    int maxLen = (lenA > lenB ? lenA : lenB) + 1;
    
    // Allocate memory for the result string plus the null terminator
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    result[maxLen] = '\0'; // Set null terminator at the end
    
    int i = lenA - 1;
    int j = lenB - 1;
    int k = maxLen - 1;
    int carry = 0;
    
    // Loop until both strings are exhausted and there is no carry left
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        
        if (i >= 0) {
            sum += a[i] - '0'; // Convert char to integer
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0'; // Convert char to integer
            j--;
        }
        
        result[k] = (sum % 2) + '0'; // Current binary digit ('0' or '1')
        carry = sum / 2;             // New carry (0 or 1)
        k--;
    }
    
    // If the loop finished early without using the leftmost space, shift the string
    if (k >= 0) {
        // Move the string forward to skip the unused pre-allocated space
        char* actualResult = strdup(&result[k + 1]);
        free(result);
        return actualResult;
    }
    
    return result;
}
