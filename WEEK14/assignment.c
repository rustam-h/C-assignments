//
// Created by rusta on 25-Nov-20.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    bool swapped;
    struct Node* next;
};

void printList(struct Node* head){
    printf("result: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void append(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;  /* used in step 5*/

    /* 2. put in the data  */
    new_node->data  = new_data;
    new_node->swapped = false;

    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void swapNodes(struct Node* head_ref, int x){
    struct Node* temp = head_ref;
    if (head_ref == NULL || head_ref->next == NULL)
        return;


    while(temp->next != NULL){
        if(temp->data == x && !(temp->swapped) && !(temp->next->swapped)){

//            struct Node* new = temp->next;
//            temp->next = temp;
//            printf("%d ", temp->next->data);
//            temp = new;
//            temp->next = temp->next->next;
//
//            printf("%d %d %d", temp->data, new->data, temp->next->data);
//            temp->next->swapped = true;
            printf("\n");
            printList(head_ref);
            return;
        }
        temp = temp->next;
    }
    printf("No swap candidates found. Try again:\n");
}


int main(){
    struct Node* head = NULL;
    char *num1 = malloc(100);
    char *num2 = malloc(100);

    int flag = 0;
    long n = 0;
    printf("Enter numbers to add to your list:\n");
    do{
        scanf("%s", num1);
        for (int i = 0; i < 100; i++){
            if(num1[i] == 'D'){
                flag = 1;
                break;
            }
        }
        char *ptr = NULL;
        n = strtol(num1, (char **) ptr, 10);
        if(flag) break;
        else{
            append(&head, n);
            continue;
        }
    }while(!flag);

    printList(head);

    flag = 0;
    n = 0;
    do{
        printf("Type two numbers to swap them around:\n");
        scanf("%s", num2);
        for (int i = 0; i < 100; i++){
            if(num2[i] == 'D'){
                flag = 1;
                break;
            }
        }
        char *ptr = NULL;
        n = strtol(num2, (char **) ptr, 10);
        if(flag) break;
        else{
            swapNodes(head, n);
            printList(head);
            continue;
        }
    }while(!flag);

    return 0;
}
