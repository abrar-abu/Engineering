/*
* @Author: ubuntu
* @Date:   2017-11-06 11:50:04
* @Last Modified 2017-11-06
* @Last Modified time: 2017-11-06 11:59:22
*/
#include<iostream> 
#include<string.h> 
using namespace std; 
class Element 														//Declaration of Class 
{ 
	public: 
	char key[10]; 
	char meaning[30]; 
	void read() 
	{ 
		cin>>key; 
	} 
	void readkey() 
	{ 
		cin>>meaning; 
	} 
	void display() 
	{ 
		cout<<"Word:-\t"<<key<<"\n  "; 
		cout<<"Meaning:-\t"<<meaning<<"\n"; 
	} 
}; 

class Dictionary 													//Declaration of Class 
{ 
	private:
		int size; 
		Element keys[50]; 
	public: 
		Dictionary() 
		{ 
			size=0; 
		} 
		void create();												//Prototype for create function
		void delete_element();										//Prototype for delete_element function
		void insert();												//Prototype for insert function                
		void modify();												//Prototype for modify function
		void search();												//Prototype for search function
		void display_list();										//Prototype for display_list function
}; 

void Dictionary :: create()											//Function Definition for create                                    
{ 
	int n; 
	cout<<"Enter the number of words:-\t"; 
	cin>>n; 
	for(int i=0;i<n;i++) 
	{ 
		cout<<"Enter the word:-\t"; 
		keys[i].read(); 
		cout<<"Enter the meaning:-\t"; 
		keys[i].readkey(); 
		cout<<endl; 
		++size; 
	} 
} 

void Dictionary :: delete_element()									//Function Definition for delete_element               
{ 
	int n; 
	cout<<"Enter the position of the word u wish to delete:-\t"; 
	cin>>n; 
	if(n>size) 
	{ 
		cout<<"Invalid number...No word at this position\n"; 
	} 
	for(int i=n-1;i<size;i++) 
	{ 
		keys[i]=keys[i+1]; 
	} 
	--size; 
} 

void Dictionary :: insert()											//Function Definition for insert                                              
{ 
	int n; 
	cout<<"Enter the position of the word u wish to insert:-\t"; 
	cin>>n; 
	if(n>(size+2)) 
	{ 
		cout<<"Invalid number...Cannot leave empty spaces in the list\n"; 
	} 
	n--; 
	for(int i=size;i>=n;i--) 
	{ 
		keys[i+1]=keys[i]; 
	} 
	cout<<"Enter the word:-\t"; 
	keys[n].read(); 
	cout<<"Enter the meaning:-\t"; 
	keys[n].readkey(); 
	cout<<endl; 
	size++; 
} 

void Dictionary :: display_list()									//Function Definition for display_list               
{ 
    for(int i=0;i<size;i++) 
    { 
		cout<<i+1<<"."; 
		keys[i].display(); 
		cout<<endl; 
    } 
} 

void Dictionary :: modify()											//Function Definition for modify                                               
{ 
	char ch[20]; 
	int i=0; 
	cout<<"Enter the word you wish to modify:-\t"; 
	cin>>ch; 
	while(i<size) 
	{ 
		if(!strcmp(ch,keys[i].key)) 
		{ 
			cout<<"Enter the meaning for the word:-\t"; 
			keys[i].readkey(); 
			break; 
		} 
		i++; 
	} 
} 

void Dictionary :: search()           								//Function Definition for search
{ 
	char ch[20]; 
	int i=0; 
	int flag=0; 
	cout<<"Enter the word you wish to search:-\t"; 
	cin>>ch; 
	while(i<size) 
	{ 
		if(!strcmp(ch,keys[i].key)) 
		{ 
			cout<<"Word found at position:-\t"; 
			cout<<i+1<<endl; 
			cout<<"Meaning:-\t"<<keys[i].meaning<<endl; 
			flag=1; 
			break; 
		} 
		i++; 
	} 
	if(flag==0) 
	{ 
		cout<<"Word not fund in the list.\n\n"; 
	} 
} 

int main() 
{ 
	Dictionary d; 
	int choice=0; 
	int op=0; 
	cout<<"******************DICTIONARY*********************\n"; 
	do 
	{ 
		cout<<"\n------------------------------------------------------------------\n\n"; 
		cout<<"Enter your choice "<<endl; 
		cout<<"1.Create word."<<endl; 
		cout<<"2.Delete word."<<endl; 
		cout<<"3.Display entire list"<<endl; 
		cout<<"4.Insert"<<endl; 
		cout<<"5.Modify"<<endl; 
		cout<<"6.Search"<<endl; 
		cout<<"7.Exit"<<endl;; 
		cin>>choice; 
		switch(choice)
		{ 
			case 1:     
				d.create(); 
			break; 
			case 2:     
				d.delete_element(); 
			break; 
			case 3:     
				d.display_list(); 
			break; 
			case 4:     
				d.insert(); 
			break; 
			case 5:     
				d.modify(); 
			break; 
			case 6:     
				d.search(); 
			break; 
			case 7:    
				cout<<"********************THANKYOU*******************\n\n";            
			break; 
			default:    
				cout<<"Wrong input\n\n"; 
		} 
	}while(choice!=7); 
	return 0; 
} 