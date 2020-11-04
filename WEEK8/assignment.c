//
// Created by rusta on 04-Nov-20.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    char data[256];
    struct Node *next;
};

void luckyCustomer(struct Node** head, char *key){
    struct Node *temp = (*head), *prev;

    if(temp != NULL && strcmp(temp->data, key) == 0){
        *head = temp->next;
    }else {
        while (temp != NULL && strcmp(temp->data, key) != 0) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("There is no such customer.\n");
            return;
        }
        prev->next = temp->next;
    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node*));
    struct Node *last = *head;
    strcpy(new_node->data, temp->data);
    new_node->next = NULL;

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    free(temp);
}

void admit(struct Node **head){
    if (*head == NULL){
        printf("The queue is empty.\n");
        return;
    }
    struct Node* next_node = (*head)->next;
//    head = NULL;
    free(*head);

    *head = next_node;
}

void append(struct Node **head, char *key){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head;
    strcpy(new_node->data, key);
    new_node->next = NULL;

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}

void printList(struct Node *node){
    printf("Queue: ");
    while(node != NULL){
        printf("%s ", node->data);
        node = node->next;
        if(node != NULL) printf(", ");
    }
    printf("\n");
}


void deleteList(struct Node** head){
      struct Node* curr = *head, *next;
      while (curr != NULL){
          next = curr -> next;
          free(curr);
          curr = next;
      }

      *head = NULL;
  }

int main(){

    struct Node *head = (struct Node*)malloc(sizeof(struct Node));

    strcpy(head->data, "Elnur");
    head->next = NULL;
    append(&head, "Karim");
    append(&head, "Elmar");
    append(&head, "Ramil");
    append(&head, "Mikayil");
    printList(head);
    char input[256];
    bool quit = 0;
    while(!quit){
        printf("\n");
        printf("Enter a command:");
        scanf("%s", input);
        if(strcmp(input, "quit") == 0) quit = 1;
        else if(strcmp(input, "admit") == 0){
            admit(&head);
        }else{
            luckyCustomer(&head, input);
        }
        printList(head);
    }
    free(head);
    head = NULL;

    deleteList(&head);

    return 0;
}
