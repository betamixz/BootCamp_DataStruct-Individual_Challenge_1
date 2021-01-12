// 6. Given a sorted (ascending) linked list, manipulate it to become a sorted (descending) linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
        int num;
        struct node *next;
};
 
struct node *create(struct node *start);
struct node *insert_s(struct node *start,int num);
struct node* SortedMerge(struct node *a, struct node *b);
void display(struct node *start );
void MergeSort (struct node** headRef);
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef); 
  
/* sorts the linked list by changing next pointers (not num) */

int main()
{
        struct node *start1=NULL;
        start1=create(start1);
 
        printf("List Before Sort : ");
        display(start1);

        MergeSort(&start1);

        printf("List After Sort : ");
        display(start1);
        
 
        return 0;
 
}/*End of main()*/

void MergeSort(struct node** headRef) 
{ 
    struct node* head = *headRef; 
    struct node* a; 
    struct node* b; 
  
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b); 
  
    /* Recursively sort the sublists */
    MergeSort(&a); 
    MergeSort(&b); 
  
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b); 
} 

struct node* SortedMerge(struct node* a, struct node* b) 
{ 
    struct node* result = NULL; 
  
    /* Base cases */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Pick either a or b, and recur */
    if (a->num >= b->num) // >= for descending || <= for Ascending
    { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else 
    { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 
  
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves, 
    and return the two lists using the reference parameters. 
    If the length is odd, the extra node should go in the front list. 
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef) 
{ 
    struct node* fast; 
    struct node* slow; 
    slow = source; 
    fast = source->next; 
  
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    /* 'slow' is before the midpoint in the list, so split it in two 
    at that point. */
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 

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
