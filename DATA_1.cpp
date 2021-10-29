// Basic Linked List App.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class node{
	public:
		int data;
		class node *next;
		class node *prev;	
};
class node *head, *tail;

void add(int x){
	class node *temp;
	temp = (node *)malloc(1*sizeof(node));
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	
	if(!head){
		head = tail = temp;
		return;		
	}
	
	tail->next = temp;
	temp->prev = tail;
	
	tail = temp;

	return;
}

void Insert(int data, int n){
    class node* temp1 = new node();
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1){
        temp1->next = head;
        head = temp1;
        return;
    }
    class node* temp2 = head;
    for(int i = 0;i < n-2;i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;

}

void show(){
	class node *temp=head;
	
	do{
		cout << temp->data << " ";
		temp = temp->next;	
	}while(temp != NULL);
	cout << "" << endl;
	return;
}

void showReverse(){
	class node *temp=tail;
	
	do{
		cout << temp->data << " ";
		temp = temp->prev;	
	}while(temp != NULL);
	cout << "" << endl;
	return;
}


void remove(int x){
	class node *temp=head;
	
	// if the removed node is HEAD
	if (head->data == x){
		head = head->next;
		temp->next = NULL;
		free(temp);	
		return;
	}
}

int main(int argc, char** argv) {
	add(22);
	add(31);
	add(62);
	show();
	showReverse();
	remove(22);
	show();
    Insert(3,2);
	return 0;
}