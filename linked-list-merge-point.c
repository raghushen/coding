/*
 * Given linked list A and B, they merge at some point from which subsequent members are same.
 * [List #1] a--->b--->c
 *                      \
 *                       x--->y--->z--->NULL
 *                      /
 *     [List #2] p--->q
 *
 * TAsk is to print x without modifying the list and in O(n).
 */
 
 /*
  * Solution: Let L1 and L2 be the lenth of list 1 and list 2 respectively.
  * Let p1 and p2 points to List 1 and List 2 and start walking thru' till they reach the end.
  * p2 reaches the end of the list first(since it small). When p2 reaches the end, let it start
  * walking thru' List 1. When p1 reaches the end, let p1 start to walk thru' List 2.
  * NB: P1 and P2 will meet at the merging point of the two list since they would have walked
  * equal distance when both reach the merge point.
  * Let   L1 = a + c where a is the lengh before merge and c is after merging point.
  * |||ly L2 = b + c
  * When p1 and p2 meet, both would've walked, a + c + b and b + c + a.
  * Hence they meet at the merge point.
  */
  /*
    Inserte code to create the two merge list
   */
   
/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    Node *n1, *n2;
    n1 = headA; n2 = headB;
    
    while (n1 != n2) {
        n1 = n1->next;
        n2 = n2->next;
        if (n1 == NULL) n1 = headB;
        if (n2 == NULL) n2 = headA;
    }
    return (n1->data);
}
