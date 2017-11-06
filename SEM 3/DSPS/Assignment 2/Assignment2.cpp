/*
* @Author: ubuntu
* @Date:   2017-11-06 11:23:27
* @Last Modified 2017-11-06
* @Last Modified time: 2017-11-06 11:33:10
*/
#include<iostream> 
using namespace std; 

class node 															//Declaration of Class 
{ 
	public: 

	int data; 
	node *prev; 
	node *next; 

	node()															//Default Constructor 
	{ 
		prev=next=NULL; 
	} 
}; 

class dcll 															//Declaration of Class 
{ 

	public: 
	node *head; 
	void create(); 													//Prototype for create function 
	void display();				 									//Prototype for display function 
	void insert_beg(); 												//Prototype for insert_beg function 
	void insert_end(); 												//Prototype for insert_end function 
	void insert_between(); 											//Prototype for insert_between function 
	void del_beg(); 												//Prototype for del_beg function 
	void del_end(); 												//Prototype for del_end function 
	void del_between(); 											//Prototype for del_between function 
	void search(); 													//Prototype for search function 
	dcll()															//Constructor Defination 
	{ 
		head=NULL; 
	} 
}; 

void dcll::create()													//Creating the node 
{ 
 
	int flag=1; 
	char ans; 
	node *p,*temp; 
	head=new node; 
	do 
	{ 

		p=new node; 
		p->next=NULL; 
		p->prev=NULL; 
		cout<<"\nEnter the data:"; 
		cin>>p->data; 

		if(flag==1)													//Flag for head node 
		{ 
		   head=p; 
		   p->prev=head; 
		   p->next=head; 
		   flag=0;													//Resting flag for other nodes     
		} 
		else 
		{ 
		  temp=head; 
		  while(temp->next!=head)									//Finding last node 
		  temp=temp->next; 

		  p->next=head; 
		  p->prev=temp; 
		  temp->next=p; 
		  head->prev=p; 
		} 
	cout<<"\nYou want to enter more nodes?:"; 
	cin>>ans; 
	} 
	while(ans=='Y'||ans=='y'); 
} 

void dcll::display()												//Function for Displaying node 
{ 
	node *temp; 
	temp=head; 
	if(temp==NULL) 
	cout<<"\n LIST IS EMPTY";										//Check the list is EMPTY or NOT 
	else 
	do 
	{ 
		cout<<temp->data<<"==> "; 
		temp=temp->next; 
	}while(temp!=head); 
} 

void dcll::insert_beg()												//Function for Insert at Start 
{ 
	node *p,*temp; 
	p=new node; 
	p->next=NULL; 
	p->prev=NULL; 
	cout<<"\nEnter data:"; 
	cin>>p->data; 
	if(head==NULL)													//If list is EMPTY,take new node as head 
	{ 
		head=p; 
		p->prev=head; 
		p->next=head; 
	} 
	else 
	{ 
		temp=head; 
		while(temp->next!=head) 
		temp=temp->next; 
		p->next=head; 
		p->prev=temp; 
		head->prev=p; 
		temp->next=p; 
		head=p; 
	} 
	cout<<"\nNode is inserted!"; 
} 

void dcll::insert_end()												//Function for Inserting node at end 
{ 
	node *p,*temp; 
	p=new node; 
	p->prev=NULL; 
	p->next=NULL; 
	cout<<"\nEnter the data:"; 
	cin>>p->data; 

	if(head==NULL)													//If list is EMPTY,take new node as HEAD 
	{ 
		head=p; 
		p->next=head; 
		p->prev=head; 
	} 
	else 
	{ 
		temp=head; 
	while(temp->next!=head) 
		temp=temp->next; 
		p->next=head; 
		p->prev=temp; 
		head->prev=p; 
		temp->next=p; 
		temp->next->prev=temp; 
	} 
 	cout<<"\nNode is inserted!!"; 
} 

void dcll::insert_between()											//Function for Inserting node in Between 
{ 
	int element; 
	node *p,*temp; 
	p=new node; 
	p->next=NULL; 
	p->prev=NULL; 
	cout<<"\nEnter the data:"; 
	cin>>p->data; 
	if(head==NULL) 
	{ 
		head=p; 
	} 
	else 
	{ 
		cout<<"\nEnter the element after which you want to insert node:"; 
		cin>>element; 
		temp=head; 
		do 
		{ 
			if(temp->data==element) 
			{ 
				p->next=temp->next; 
				(temp->next)->prev=p; 
				temp->next=p; 
				p->prev=temp; 
				return; 
			} 
			else 
			{ 
			  	temp=temp->next; 
			} 
		}while(temp!=head); 
	} 
	cout<<"\nNode is inserted!!"; 
} 

void dcll::del_beg()												//Function for deleting the node at Start 
{ 
	node *temp,*temp1; 
	temp=head; 
	temp1=temp->next; 
	while(temp->next!=head) 
	{ 
		temp=temp->next; 
	} 
	temp->next=temp1; 
	temp1->prev=temp; 

	delete head; 
	head=temp1; 

	cout<<"\nDeleted the node at the beginning!!"; 
} 

void dcll::del_end()												//Function for Deleting the node at End 
{ 
	node *temp,*temp1; 
	temp=head; 
	 
	while(temp->next!=head) 
	{ 
		temp=temp->next; 
	}	 
	temp1=temp->prev; 
	temp1->next=head; 
	head->prev=temp1; 
	delete temp; 
	temp=temp1; 

	cout<<"\n node in the last is deleted"; 
			 
} 
void dcll::del_between()											//Function for Deleting the in Between node 
{ 
	node *temp,*temp1; 
	int element; 
	cout<<"\nEnter the data you want to delete:"; 
	cin>>element; 
	temp=head; 
	if(temp->data==element) 
	{ 
		temp=temp->next; 
		if(temp==temp1) 
		{ 
			temp=temp1=NULL; 
			delete head; 
			cout<<"\n Node is deleted,linked list is empty"; 
		} 
		else 
		{ 
			while(temp->next!=head) 
			temp=temp->next; 
			temp->next=temp1; 
			temp1->prev=temp; 
			head=temp1; 
			cout<<"\nNode is deleted "; 
		} 
	} 
	else 
	{ 
		while(temp->next!=head) 
		{ 
			if((temp->next)->data==element) 
			{ 
				temp1=temp->next; 
				temp->next=temp1->next; 
				(temp1->next)->prev=temp; 
				delete temp1; 
				cout<<"\nNode is deleted"; 
			} 
			else 
			temp=temp->next; 
		} 
	} 
} 

void dcll::search()													//Search Function 
{ 
	int element; 
	cout<<"\nEnter the element you want to search:"; 
	cin>>element; 

	node *temp; 
	int flag; 
	temp=head; 
	if(temp==NULL)	 												//Checking for EMPTY list condition 
	{ 
		cout<<"\nThe list is empty"; 
	} 
 	flag=0; 
	while(temp->next!=head && flag==0) 
	{ 

		if(temp->data==element) 
		{ 
			flag=1; 
		} 
		else 
		{ 
			temp=temp->next; 
		} 
	} 
	if(flag==1) 
	{ 
		cout<<"\nThe node is present"; 
	} 
	else
	{ 
		cout<<"The node is not present"; 
	}
} 

int main() 
{ 
	node n; 
	dcll d;															//Object is Created 
	int c; 
	do 
	{ 
		cout<<"\n Enter the option you want to perform with nodes: "<<endl; 
		cout<<"1.CREATE "<<endl; 
		cout<<"2.DISPLAY "<<endl; 
		cout<<"3.INSERT AT BEGINNING "<<endl; 
		cout<<"4.INSERT AT END "<<endl; 
		cout<<"5.INSERT IN BETWEEN "<<endl; 
		cout<<"6.DELETE NODE AT BEGINNING "<<endl; 
		cout<<"7.DELETE THE NODE AT THE END "<<endl; 
		cout<<"8.DELETE IN BETWEEN "<<endl; 
		cout<<"9.SEARCH THE NODE "<<endl; 
		cout<<"10.EXIT "<<endl; 
		cin>>c;														//function calling 
		switch(c) 
		{ 
			case 1:d.create(); 
			break; 

			case 2:d.display(); 
			break; 

			case 3:d.insert_beg(); 
			break; 

			case 4:d.insert_end(); 
			break; 

			case 5:d.insert_between(); 
			break; 

			case 6:d.del_beg(); 
			break; 

			case 7:d.del_end(); 
			break; 

			case 8:d.del_between(); 
			break; 

			case 9:d.search(); 
			break; 

			case 10:break; 
			} 
	}while(c!=10); 
	return 0; 
} 