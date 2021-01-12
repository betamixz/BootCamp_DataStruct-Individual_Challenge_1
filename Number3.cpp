// 3. Find the middle element of a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
        int num;
        struct node *next;
};
 
struct node *create(struct node *start);
struct node *insert_s(struct node *start,int data);
void printMiddle(struct node *head);
void display(struct node *start );

int main()
{
        struct node *start1=NULL;
        start1=create(start1);
 
        printf("List : ");
        display(start1);

        printMiddle(start1);
 
        return 0;
 
}/*End of main()*/

void printMiddle(struct node *head)  
{  
    struct node *slow_ptr = head;  
    struct node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        printf("The middle element is [%d]\n", slow_ptr->num);  
    }  
}  
 
struct node *create(struct node *start )
{
        int i,n,data;
        printf("Enter the number of nodes : ");
        scanf("%d",&n);
        start=NULL;
        for(i=1;i<=n;i++)
        {
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                start=insert_s(start, data);
        }
        return start;
}/*End of create_slist()*/
 
struct node *insert_s(struct node *start,int data)
{
        struct node *p, *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->num=data;
        /*list empty or data to be added in beginning */
        if(!start || data < start->num)
        {
                tmp->next =start;
                start=tmp;
                return start;
        }
        else
        {
                p=start;
                while(p->next && p->next->num < data)
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