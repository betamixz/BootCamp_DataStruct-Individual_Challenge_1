// 4. Given a sorted linked list, remove all the duplicates.

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

int main()
{
        struct node *start1=NULL;
        start1=create(start1);
 
        printf("List Before Cleanup: ");
        display(start1);

        removeDuplicates(start1);

        printf("List After Cleanup: ");
        display(start1);
 
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

void removeDuplicates(struct node* head) 
{ 
    /* Pointer to traverse the linked list */
    struct node* current = head; 
  
    /* Pointer to store the next pointer of a node to be deleted*/
    struct node* next_next;  
    
    /* do nothing if the list is empty */
    if (current == NULL)  
       return;  
  
    /* Traverse the list till last node */
    while (current->next != NULL)  
    { 
       /* Compare current node with next node */
       if (current->num == current->next->num)  
       { 
           /* The sequence of steps is important*/               
           next_next = current->next->next; 
           free(current->next); 
           current->next = next_next;   
       } 
       else /* This is tricky: only advance if no deletion */
       { 
          current = current->next;  
       } 
    } 
} 