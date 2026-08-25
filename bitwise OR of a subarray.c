#include <stdlib.h>

// Simple hash set implementation for tracking globally unique results
#define HASH_SIZE 1000003
typedef struct Node {
    int val;
    struct Node* next;
} Node;

void insert(Node** hashTable, int val, int* uniqueCount) {
    int key = abs(val) % HASH_SIZE;
    Node* curr = hashTable[key];
    while (curr != NULL) {
        if (curr->val == val) return;
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = hashTable[key];
    hashTable[key] = newNode;
    (*uniqueCount)++;
}

int subarrayBitwiseORs(int* arr, int arrSize) {
    Node** hashTable = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    int uniqueCount = 0;

    int* currentOrs = (int*)malloc(32 * sizeof(int));
    int currentSize = 0;

    for (int i = 0; i < arrSize; i++) {
        int* nextOrs = (int*)malloc(32 * sizeof(int));
        int nextSize = 0;

        // Insert the current element alone
        nextOrs[nextSize++] = arr[i];
        insert(hashTable, arr[i], &uniqueCount);

        for (int j = 0; j < currentSize; j++) {
            int newOr = currentOrs[j] | arr[i];
            // Avoid adding duplicate values inside the small active array
            if (nextOrs[nextSize - 1] != newOr) { 
                nextOrs[nextSize++] = newOr;
                insert(hashTable, newOr, &uniqueCount);
            }
        }

        free(currentOrs);
        currentOrs = nextOrs;
        currentSize = nextSize;
    }

    // Free allocated memory
    free(currentOrs);
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(hashTable);

    return uniqueCount;
}
