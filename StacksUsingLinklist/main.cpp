#include <stdio.h>
#include <stdlib.h>
     
     struct stack_node {
         int data;
         struct stack_node *link;
     };
     struct stack_node *start = NULL;
        void pop() {
            struct stack_node * temp;
            if(start==NULL){
                printf("Stack is empty , Underflow condition\n");
            }
            else {
                temp = start;
                start = start->link;
            }
            printf("\n");
        }
        void push() {
            struct stack_node *newnode ;
            newnode = (struct stack_node*)malloc(sizeof(struct stack_node));
            printf("Enter data to be pushed\n");
            scanf("%d" , &newnode->data);
            printf("\n");
           if(start==NULL){
               start = newnode;
               newnode->link = NULL;
           }
           else {
                newnode->link = start;
                start = newnode;
           }
        }
        void display(){
            struct stack_node *head;
            if(start==NULL){
                printf("Nothing to display");
            }
            else {
                while(head!=NULL){
                    printf("%d" , &head->data);
                    head = head->link;
                }
            }
            printf("\n");
        }
        
        
        int main() {
            int chc;
            while(1>0){
                printf("\n0 EXIT\n");
                printf("1 PUSH\n");
                printf("2 POP\n");
                printf("3 DISPLAY");
                printf("Enter choice :");
                scanf("%d" , &chc);
                switch(chc){
                    case 0 : exit(0);
                             break;
                    case 1 : push();
                             break;
                    case 2:  pop();
                             break;
                    case 3:  display();
                             break;
                    default : printf("\nINVALID ENTRY PLEASE PRESS 0 FOR EXIT!!!!!!!!");
                              break;
                }
                
            }
            return 0;
        }
        
        