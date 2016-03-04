			/* Basic Stack Operations Using Linked List.*/

/*Created By Murtaza S Vhora
	at 18:28 04/03/2016 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


		
class Stack
{
	private:
		int arr[100],max,count;
		struct LList
		{
			int data;
			struct LList *next;
		}*start;
	public:


	/*Empty Constructor */
	Stack(){}

	/*Constructor to create stack */
	Stack(int size)
	{
		count = 0;
		max = size;
		start = NULL;
	}


	/*Function for push element to the stack. */
	void push(int value)
	{
		if(count < max)
		{
			count++;
			struct LList *temp = new struct LList;
			temp->data=value;
			if(start == NULL)
			{
				temp->next = NULL;
				start = temp;
			}
			else
			{
				temp->next = start;
				start = temp;
			}
			cout<<endl<<"   Element "<<value<<" pushed succesfully."<<endl<<endl;
		}
		else
			cout<<endl<<"   Stack Overflow."<<endl<<endl;
	}


	/*Function to pop element from stack. */
	int pop()
	{
		int temp = 0;
		if(count > 0)
		{
			temp = start->data;
			struct LList *t = start;
			start = start->next;
			count--;
			delete t;
		}
		return temp;
	}


	/*Function to print Stack */
	void printStack()
	{
		if(count > 0)
		{
			cout<<"\n\n\t\t|\t\t|\n\t\t|\t\t|\n\t\t|\t\t|\n\t\t|\t\t|\n";
			struct LList *tempStart = start;
			cout<<"\ttop---->|\t"<<tempStart->data<<"\t|\n";
			tempStart=tempStart->next;
			while(tempStart != NULL)
			{
				cout<<"\t\t|\t"<<tempStart->data<<"\t|\n";
				tempStart=tempStart->next;
			}
			cout<<"\t\t`````````````````\n\n";
		}
		else
			cout<<endl<<"   Stack is empty."<<endl<<endl;
	}

	/*Function to empty stack. */
	void emptyStack()
	{
		while(start != NULL)
		{
			struct LList *t = start->next;
			delete start;
			start = t;
			count--;
		}
		cout<<endl<<"   Stack emptied."<<endl<<endl;
	}
};

/*Main Function */
int main()
{
	system("clear");
	cout<<"\t\t*******STACK IMPLEMENTATION USING ARRAY*******"<<endl<<endl;
	cout<<"Enter the size of stack : ";
	int size;
	cin>>size;
	Stack s(size);
	
	while(true)
	{
	
		/*Description to be printed on screen. */
		system("clear");
		cout<<"\t\t*******STACK IMPLEMENTATION USING ARRAY*******"<<endl<<endl;
		cout<<"   1. Push Value"<<endl;
		cout<<"   2. Pop Value"<<endl;
		cout<<"   3. Print Stack"<<endl;
		cout<<"   4. Empty Stack"<<endl;
		cout<<"   5. Exit"<<endl<<endl;
		cout<<"Enter your choice : ";
		int choice;
		cin>>choice;
		
		/*Switch Cases*/
		switch(choice)
		{
		
			/*Push Value Case*/
			case 1:
			{
				cout<<"Enter the value of element : ";
				int element;
				cin>>element;
				s.push(element);
				break;
			}
			
			/*Pop  Value Case*/
			case 2:
			{
				int element=s.pop();
				if(element == 0)
					cout<<endl<<"   Stack Underflow."<<endl<<endl;
				else
					cout<<endl<<"   Element "<<element<<" popped successfully."<<endl<<endl;
				break;
			}
			
			/*Print Stack Case*/
			case 3:
			{
				s.printStack();
				break;
			}
			
			/*Empty Stack Case*/
			case 4:
			{
				s.emptyStack();
				break;
			}
			
			/*Exit Case*/
			case 5:
			{
				return 0;
			}
			
			default:
			{
				cout<<"You have entered an invalid choice. Please try again.";
				break;
			}
		}
		
		cout<<"Do you wanna continue(1-YES else No) : ";
		int con;
		cin>>con;
		if(con != 1)
			return 0;
	}
	return 0;
}
