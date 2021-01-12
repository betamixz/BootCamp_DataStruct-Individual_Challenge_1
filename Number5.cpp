// 5. Find the Nth node from the end of the linked list. 

// Simple C++ program to 
// find n'th node from end 
#include <stdio.h>
#include <stdlib.h>

struct node
{
        int num;
        struct node *next;
};
 
struct node *create(struct node *start);
struct node *insert_s(struct node *start,int num);
void removeDuplicates(struct node* head);
void display(struct node *start );
void printNthFromLast(struct node* head, int n); 

int main()
{
        struct node *start1=NULL;
        start1=create(start1);
 
        printf("List : ");
        display(start1);

        int N; printf("Input Nth number: ");
        scanf("%d", &N);
        printNthFromLast(start1, N);
 
        return 0;
 
}/*End of main()*/
 
struct node *create(struct node *start )
{
        int i,n,num;
        printf("Enter the number of nodes : ");
        scanf("%d",&n);
        start=NULL;
        for(i=1;i<=n;i++)
        {
                printf("Enter the element to be inserted : ");
                scanf("%d",&num);
                start=insert_s(start, num);
        }
        return start;
}/*End of create_slist()*/
 
struct node *insert_s(struct node *start,int num)
{
        struct node *p, *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->num=num;
        /*list empty or num to be added in beginning */
        if(!start || num < start->num)
        {
                tmp->next =start;
                start=tmp;
                return start;
        }
        else
        {
                p=start;
                while(p->next && p->next->num < num)
                {
                    p=p->next;                    
                }
                tmp->next=p->next;
                p->next=tmp;
        }
        return start;
}/*End of insert_s()*/
 
void display(struct node *start)
{
        struct node *p;
        if(start==NULL)
        {
                printf("List is empty\n");
                return;
        }
        p=start;
        while(p!=NULL)
        {
                printf("%d ",p->num);
                p=p->next;
        }
        printf("\n");
}/*End of display()*/

void printNthFromLast(struct node* head, int n)
{ 
    static int i = 0; 
    if (head == NULL) 
        return; 
    printNthFromLast(head->next, n); 
    if (++i == n) 
        printf("%d", head->num); 
} 