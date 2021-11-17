//Hasan ARIKAN  210303851  HOMEWORK
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
ifstream readFile("table_in.txt");
ofstream writeFile("table_out.txt");

class node {
public:
	int data; // We will hold info of data/number inside this
	int person; // We will hold info of person's chair number inside this
	node* next; 
	node* prev;
};
class node *head, *tail; 
int counter = 1; // Count the people
int N = 1000000; // Number of people 

// ADD integer variable to Node
void add(int x) { // Add another node to our last node, create if doesn't exist
	if(counter >= N){
		return; // You can't add beyond 999.999 people to table. because "N < 1.000.000" is given 
	}
	node* temp = (node*)malloc(1 * sizeof(node)); // Create the pointer 'temp' for node
	
	temp->data = x; // Take the number and store it inside node.data
	temp->person = counter; // Store person's chair number inside node.person
	counter++; // increase the chair number
	temp->next = temp->prev = NULL; // create but do not assign anytihng to '.next' or '.prev'

	if (!head) { // If  there is no head, create it 
		head = tail = temp;
		head->next = head;
		head->prev = head;
		return;
	}
	/* add new node to the last node */
	tail->next = temp; 
	temp->prev = tail;
	temp->next = head;
	head->prev = temp;
	tail = temp;
	return;
}




int removeNode(class node* temp){
	if (temp == temp->next) { // If we ended every one of the codes, just delete it then return 'NULL' to end our application
		writeFile << temp->person << endl; // Write the person's chair number
		free(temp); // free(temp) at the END of our doubly linked list
		return 0; // End the function and return 0, the while loop on main() will be end
	}
	int x = temp->data; // x'll hold the number 
	if (temp == tail) { 
		writeFile << temp->person << endl; // Write the person's chair number
		/* Delete the node, make others continue without it*/
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		
		tail = tail->prev; // Move the tail one backwards
	}
	else if(temp == head) {
		writeFile << temp->person << endl; // Write the person's chair number
		/* Delete the node, make others continue without it*/
		temp->next->prev = temp->prev; 
		temp->prev->next = temp->next;
		
		head = head->next; // Move the head one forwards
	}else{
		writeFile << temp->person << endl; // Write the person's chair number
		/* Delete the node, make others continue without it*/
		temp->next->prev = temp->prev; 
		temp->prev->next = temp->next;
	}
	return x; // Return the number to move on table / forwards or backwards
}

void filetoNode() {
	int tableNumber; // an integer to hold the number given on the line inside '.txt'
	readFile >> tableNumber; // First get rid of Number Of People which is on the first Line
	while (readFile.eof() != 1) {
		readFile >> tableNumber; //hold the number on the tableNumber. (to paste on Node)
		add(tableNumber); // Add number (from file) to the node
	} // Finish if all lines are finished
	return; // End the function;
}



int main() {
	filetoNode(); // Call this function to read 'table_in.txt' and then paste the number on out doubly linked list
	class node* temp = head; // Create a temp file, it starts from the first person/chair
	
	int x = temp->data;// We'll use this 'x' to determine how many times we need to move.
	while (x !=0) // run the program until temp becomes 'EMPTY' and returns 0
	{
		x = removeNode(temp); // Take the number of person
		
		if( x%2  == 1){ // ODD number
			for(int i = 0; i < x ; i++){
			temp = temp->next; //move to next point according to, deleted person's number
			}
		}else{ // EVEN number
			for(int i = 0; i < x ; i++){
			temp = temp->prev; //move to previous point according to, deleted person's number
			}
		}
	}
	cout << "Code has been terminated." << endl; // Remind if the code is executed successfully
	readFile.close(); //Close the 'table_in.txt' file
	writeFile.close(); //Close the 'table_out.txt' file
	return 0; // End of our Code
}
