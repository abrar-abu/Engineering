/*
* @Author: ubuntu
* @Date:   2017-11-06 12:45:40
* @Last Modified 2017-11-06our Name>
* @Last Modified time: 2017-11-06 12:45:47
*/
#include<iostream>
#include<string.h>
#define MAX 30					//Macro to assign 30 to MAX. 
using namespace std;

class mall						//Node for single item.
{
  public:
  	int  Purchase;
  	char Name[MAX];
};

class Priority_Queue				//Declaration of class
{
  private:
	char P_Queue[MAX][MAX];	//2-D Array of Character
	int PC[MAX];				//1-D Array of Integer
	int Rear,Front,count,n1,n2,NEW1,NEW2;
  public:
	void Input();				//Prototype for Input function
	void Initialize();				//Prototype for Initialize function
	void Display();				//Prototype for Display function
	void Insert_By_Priority(char [MAX],int );//Prototype Insert_B_P function
};

void Priority_Queue::Initialize()		//Function Definition for Initialize
{
	NEW1 = 0;
	NEW2 = 0;
	n1 = 0;	
	n2 = 0;
	count = 0;
	Rear = -1;
	Front = -1;
}

void Priority_Queue::Input()		//Function Definition for Input
{
	int i,n;
	mall m;
	do
	{
	cout<<"\n\n\n\n\nWHAT DO U WANT TO PURCHASE FROM THE MALL"<<endl;
	cout<<"\t\t\t1.Vegetables"<<endl;
	cout<<"\t\t\t2.Fruits"<<endl;
	cout<<"\t\t\t3.EXIT"<<endl;
	cout<<"Enter A Choice from above \t\t\t:";
	cin>>n;
	switch (n)
	{
		case 1:
			cout<<"Enter the Number of vegetables\t\t\t:";
			cin>>n1;
			for(i=1;i<=n1;i++)
			{		
				cout<<"Enter the name of vegetable \t\t\t:";
				cin>>m.Name;
				cout<<"Enter the priority of "<<m.Name<<"\t\t\t:";
				cin>>m.Purchase;
				Insert_By_Priority(m.Name,m.Purchase);
			}
			NEW1=n1+NEW1;
			break;
		case 2:
			cout<<"Enter the Number of Fruits\t\t\t:";
			cin>>n2;
			for(i=1;i<=n2;i++)
			{		
				cout<<"Enter the name of Fruits \t\t\t:";
				cin>>m.Name;
				cout<<"Enter the priority of "<<m.Name<<"\t\t\t:";
				cin>>m.Purchase;
				Insert_By_Priority(m.Name,m.Purchase);
			}
			NEW2=n2+NEW2;
			break;
		case 3:
			cout<<"-----------------THANK YOU FOR PUCHASING DO VISIT US AGAIN------------------"<<endl;
			break;
		default:
			cout<<"----------------------------Entered Wrong Choice----------------------------"<<endl;
	}
	}while(n==1||n==2||n!=3);
}

void Priority_Queue ::Insert_By_Priority(char Name[],int Purchase)
{
	int i,j,temp;
	char ch[MAX];
	if(Rear>=MAX-1)
	{
		cout<<"Priority Queue IS FULL"<<endl;
	}
	else
	{ 
		if((Front==-1)&&(Rear==-1)) 	//QUEUE IS EMPTY
		{
			Front++;
			Rear++;
			strcpy(P_Queue[Rear],Name);
			PC[Rear]=Purchase;
		}	
		else 
		{	
			Rear++;
			strcpy(P_Queue[Rear],Name);
			PC[Rear]=Purchase;			
			for(i=0;i<Rear;i++)
			{
				for(j=i;j<=Rear;j++)
				{
					if(PC[i]<PC[j])
					{
						temp=PC[j];
						PC[j]=PC[i];
						PC[i]=temp;
						strcpy(ch,P_Queue[i]);
						strcpy(P_Queue[i],P_Queue[j]);
						strcpy(P_Queue[j],ch);
					}	
				}
			}
			
		}
	}
}
void Priority_Queue ::Display()			//Function Definition for Display
{
	int i,n;
	n=NEW1+NEW2;
	cout<<"-------------------MODERN EDUCATION SOCIETY MALL-------------------"<<endl;
	cout<<"Sr. No."<<"\t\t\t NAME\t\t\t FREQUENCY COUNT"<<endl;
	for(i=0;i<n;i++)
	{	
		cout<<i+1<<"\t\t\t";
		cout<<P_Queue[i]<<"\t\t\t\t"<<PC[i]<<endl;
	}
}
int main()
{
	Priority_Queue P;
	P.Initialize();			//Calling of Initialize function
	P.Input();				//Calling of Input function
	P.Display();			//Calling of Display function
}