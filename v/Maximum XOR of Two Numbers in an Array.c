#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 31

typedef struct TrieNode
{
    struct TrieNode *child[2];
} TrieNode;


/* Create a new trie node */
TrieNode* createNode()
{
    TrieNode *node =
        (TrieNode *)malloc(sizeof(TrieNode));

    node->child[0] = NULL;
    node->child[1] = NULL;

    return node;
}


/* Insert number into binary trie */
void insert(TrieNode *root, int num)
{
    TrieNode *node = root;

    int i;
    int bit;

    for (i = 30; i >= 0; i--)
    {
        bit = (num >> i) & 1;

        if (node->child[bit] == NULL)
        {
            node->child[bit] = createNode();
        }

        node = node->child[bit];
    }
}


/* Find maximum XOR with num */
int getMaxXOR(TrieNode *root, int num)
{
    TrieNode *node = root;

    int result = 0;

    int i;
    int bit;
    int opposite;

    for (i = 30; i >= 0; i--)
    {
        bit = (num >> i) & 1;

        /*
         * To maximize XOR,
         * choose the opposite bit if possible.
         */
        opposite = 1 - bit;

        if (node->child[opposite] != NULL)
        {
            result |= (1 << i);
            node = node->child[opposite];
        }
        else
        {
            node = node->child[bit];
        }
    }

    return result;
}


/* Main function required by the problem */
int findMaximumXOR(int* nums, int numsSize)
{
    TrieNode *root = createNode();

    int i;
    int answer = 0;
    int current;


    /* Insert all numbers */
    for (i = 0; i < numsSize; i++)
    {
        insert(root, nums[i]);
    }


    /* Find maximum XOR */
    for (i = 0; i < numsSize; i++)
    {
        current =
            getMaxXOR(root, nums[i]);

        if (current > answer)
        {
            answer = current;
        }
    }


    return answer;
}
