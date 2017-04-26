#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Number Number;
typedef struct Node Node;

void init_number(int, Number*);
void print_number(Node*);
void multiply(int, Number*);
void myPrint(Node*);

struct Node {
	int value;
	Node *next;
};

struct Number {
	Node *digit;
	int size;
};

int main(){
    Number num;
    int n,i;
    scanf("%d", &n);
    init_number(n, &num);
    
    for(i = n; i > 1; i--){
		printf("Calling Multiply with i=%d\n", i);
		printf("Node is :");
		myPrint(num.digit);
		printf("\n");
    	multiply(i, &num);
    }
    print_number(num.digit);
	printf("\n");
	myPrint(num.digit);
    return 0;
}

void multiply(int n, Number *num){
	Node *node = num->digit, *tempNode;
	int temp, carry;
	carry = 0;
	while(1){
		temp = node->value*n + carry;
		node->value = temp % 10;
		carry = temp/10;
		printf("Mult: temp = %d node-val = %d, carry = %d\n", temp,
		    node->value, carry);
		if(node->next == NULL) break;
		node = node->next;
	}
	
	while(carry){
		tempNode = (Node *)malloc(sizeof(Node));
		tempNode->value = carry % 10;
		tempNode->next = NULL;
		node->next = tempNode;
		carry = carry/10;
		node = node->next;
		printf("Mult:new-Node: node->val=%d carry = %d\n", tempNode->value,
		    carry); 
	}
	printf("\n");
}

void init_number(int n, Number *num){
    num->digit = (Node *)malloc(sizeof(Node));
    num->digit->value = 1;
    num->digit->next = NULL;
    num->size = 1;
	printf("init: digit->value = 1, size = 1\n");
}

void print_number(Node *node){
	if(node == NULL) return;
	print_number(node->next);
	printf("%d", node->value);
}

void myPrint(Node *node) {
	Node *t_node = node;
	while (t_node != NULL) {
		printf("%d ", t_node->value);
		t_node = t_node->next;
	}
}
