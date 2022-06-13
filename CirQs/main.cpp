#include <stdio.h>
#include <stdlib.h>
 struct Queue {
                 int rear;
                 int front;
                 int size;
                 int *Q;
                           };
            void create (struct Queue *q){
                printf("\nEnter the size of the queue\n");
                scanf("%d" , &q->size);
                q->size++;
                q->rear = q->front = 0;
                q->Q = (int*)malloc(sizeof(struct Queue)*q->size);
            }
            void enqueue(struct Queue *q){
                if((q->rear+1)%q->size==q->front){
                    printf("\n Queue is full");
                    return;
                }
                q->rear = (q->rear+1)%q->size;
                printf("Enter the element to enqueued\n");
                scanf("%d" , &q->Q[q->rear]);
            }
            void dequeue(struct Queue *q){
                if(q->rear==q->front){
                    printf("\n Queue is empty");
                    return;
                }
                q->front = (q->front+1)%q->size;
                printf("Element dequeued is %d\n" , q->Q[q->front]);
            }
            
            void display(struct Queue q){
                if(q.rear==q.front){
                    printf("Empty Queue");
                    return;
                }
               int i = q.front+1;
               do{
                   printf("%d " , q.Q[i]);
                   i = (i+1)%q.size;
               }while(i!=(q.rear+1)%q.size);
                  printf("\n");
            }
            
            int main() {
                struct Queue q;
                int chc;
                create(&q);
                while(1>0){
                    printf("\n1 DISPLAY\n");
                    printf("2 Enqueue\n");
                    printf("3 Dequeue\n");
                    printf("PRESS 0 FOR EXIT!!!\n");
                    printf("Enter your chocie :    ");
                    scanf("%d" , &chc);
                    switch(chc){
                        case 0 : free(q.Q);
                                 exit(0);
                                 break;
                        case 1:  display(q);
                                 break;
                        case 2 : enqueue(&q);
                                 break;
                        case 3 : dequeue(&q);
                                 break;
                        default : printf("\nPress 0 for exit !!!! Invalid choice");
                                  break;
                    }
                }
            }
            
            
            

