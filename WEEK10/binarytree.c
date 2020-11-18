//
// Created by rusta on 17-Nov-20.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 250
#define STACK_CAPACITY 2
#define INT_MIN -2147483648;

struct Node{
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int addNodes(struct Node* iter){
    if(iter == NULL)
        return 0;
    return iter->value + addNodes(iter->left) + addNodes(iter->right);
}

int maximumSum(struct Node* head) {
    if (head == NULL) return 0;
    int lres = maximumSum(head->left);
    int rres = maximumSum(head->right);
    if(lres > rres){
        return lres + head->value;
    }else return rres + head->value;
}

int main(){
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("%d", maximumSum(root));

    return 0;
}
