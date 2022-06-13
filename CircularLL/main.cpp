#include <stdio.h>
#include <stdlib.h>
       struct node {
           int data ;
           struct node * link;
       };
       struct node *last = NULL;
       int node = 0;
       void insert_beg(){
           struct node *newnode;
           newnode = (struct node *)malloc(sizeof(struct node));
           printf("\nEnter the data to be inserted\n");
           scanf("%d" , &newnode->data);
           if(last==NULL){
               last = newnode;
               newnode->link = newnode;
               node++;
           }
           else {
               newnode->link = last->link;
               last->link = newnode;
               node++;
           }
       }
       void insert_end(){
           struct node *newnode;
           newnode = (struct node *)malloc(sizeof(struct node));
           printf("\nEnter the data to be inserted\n");
           scanf("%d" , &newnode->data);
                      if(last==NULL){
               last = newnode;
               newnode->link = newnode;
               node++;
           } else {
               newnode->link = last->link;
               last->link = newnode;
               last = newnode;
               node++;
           }
       }
        void insert_pos(){
            struct node *newnode , *head;
            newnode = (struct node*)malloc(sizeof(struct node));
            int pos , i = 1;
            printf("Enter the position to be inserted\n");
            scanf("%d" , &pos);
            if(pos==1)
                insert_beg();
           else  if(pos==node)
                insert_end();
           else if(pos>1 && pos<node){
                head = last->link;
                printf("Enter the data to be inserted\n");
                scanf("%d" , &newnode->data);
                while(i<pos-1){
                    head = head->link;
                    i++;
                }
                newnode->link = head->link;
                head->link = newnode;
                node++;
            }
            else 
                printf("Invalid position entered\n");
            
        }
        
        void delete_beg(){
            struct node*temp;
            if(last==NULL){
                printf("Nothing to delete\n");
            }
            else {
                temp = last->link;
                last->link = temp->link;
                free(temp);
                node--;
            }
        }
        void delete_end(){
            struct node *temp , *head  ;
             if(last==NULL){
                printf("Nothing to delete\n");
            }
            else {
                head = last->link;
                while(head->link!=last){
                    head = head->link;
                }
                head->link = last->link;
                temp = last;
                last = head;
                free(temp);
                node--;
            }
        }
        
        void delete_pos(){
            struct node *head;
            struct node *temp;
            int pos , i =1;
            printf("Enter the position to be deleted\n");
            scanf("%d" , &pos);
            if(pos==1)
            delete_beg();
            else if(pos==node)
                delete_end();
            else if(pos>0 && pos<node){
                head = last->link;
                while(i<pos-1){
                    head = head->link;
                    i++;
                }
                temp = head->link;
                head->link = temp->link;
                free(temp);
                node--;
            }
            else {
                printf("\nPosition Invalid\n");
            }
        }
        
        void traversal (){
            struct node *head;
            if(last==NULL)
                printf("\nNothing to display here\n");
            else {
            head = last->link;
            while(head->link != last->link){
                printf("%d " , head->data);
                head = head->link;
            }
            printf("%d" , head->data);
            printf("\n");
        }
        }
            int main(void){
                int chc ;
                while(1>0){
                printf("\n0 EXIT\n");
                printf("1 DISPLAY\n");
                printf("2 INSERT BEG\n");
                printf("3 INSERT END\n");
                printf("4 INSERT AT ANY POS\n");
                printf("5 DELETE BEG\n");
                printf("6 DELETE END\n");
                printf("7 DELETE AT ANY POS\n");
                printf("\nEnter your choice   ");
                scanf("%d" , &chc);
                switch (chc) {
                    case 0 : exit(0);
                             break;
                    case 1 : traversal();
                             break;
                    case 2 : insert_beg();
                             break;
                    case 3:  insert_end();
                             break;
                    case 4 : insert_pos();
                             break;
                    case 5:  delete_beg();
                             break;
                    case 6 : delete_end();
                             break;
                    case 7 : delete_pos();
                             break;
                   default : printf("INVALID ENTRY , PRESS 0 FOR EXIT!!!");
                             break;
                }
            }
            }