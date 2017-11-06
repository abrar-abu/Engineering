/*
* @Author: ubuntu
* @Date:   2017-11-06 11:10:43
* @Last Modified 2017-11-06
* @Last Modified time: 2017-11-06 11:19:52
*/
#include<iostream> 
using namespace std; 
class sort					      									//Declaration of Class 
{ 
    private: 
        int array[100],c[100]; 
    public: 
        void input(int n);				 							//Prototype for input function 
        void old(int);				 								//Prototype for last Input data 
        void display(int n);			 							//Prototype for Display function 
         
        int qsort(int,int);											//Prototype for Quick Sort function 
        void Partition(int,int);									//Prototype for Partition function 

       	void sort1(int low,int mid,int high);  						//Prototype for Merging array function 
       	void divide(int low,int high);		   						//Prototype for Dividing array function 

        void shellsort(int);										//Prototype for Shell Sort function 
  
        void radixsort(int);										//Prototype for radix sorting function 
}; 
 
void sort::input(int n)			  									//Function Definition for Input 
{ 	
    int i; 
    cout<<"Enter the Elements in array \t"<<endl; 
    for (i=0;i<n;i++) 
    { 
        cout<<"\t"; 
        cin>>array[i]; 
        
        c[i]=array[i]; 
    } 
} 

void sort::old(int n)												//Function Definition for previous Input 
 { 
   for(int i=0;i<n;i++) 
     array[i]=c[i]; 
 } 

int sort :: qsort(int o,int n)	  	   								//Function Definition for Quick Sort 
{ 
    int up,down, pivot,temp,i; 
    pivot=array[o]; up=o; down=n; 
    while(down>up) 
    { 
        while(array[up]<=pivot) 
        { 
            up++; 
        } 
        while(array[down]>pivot) 
        { 
            down--; 
        } 
        if(up<down)				      								//Swapping of elements in array 
        { 
            temp= array[up]; 
            array[up]=array[down]; 
            array[down]=temp; 
        } 
    }                 				    							//Swapping of pivot Element 
    array[o]=array[down]; 
    array[down]=pivot; 
    return down; 
} 

void sort :: Partition(int up,int down)  							//Function Definition for Partition of array                                                                                                                                                                                                                                                      
{                                                                 
    int pivot; 
    if(down>up) 
    { 
        pivot=qsort(up,down); 
        Partition(up,pivot-1); 
        Partition(pivot+1,down); 
	} 
} 

void sort::divide(int low,int high)									//Function Definition for Dividing array
{                                                                 
    if(low<high) 
    { 
        int mid; 
        mid=(low+high)/2; 
        divide(low,mid); 
        divide(mid+1,high); 
        sort1(low,mid,high);                       					//Calling of Sort and Merge function 
    } 
} 

void sort::sort1(int low,int mid,int high) 							//Function Definition for Sorting merge                                                                                                                                                                                                                                                               { 
{   
	int i,j,k; 
    i=low; 
    j=mid+1; 
    k=low; 
   
    while(i<=mid && j<=high) 
    { 
        if(array[i]<array[j]) 
        { 
            c[k]=array[i]; 
            k++; 
            i++; 
        } 
        else 
        { 
            c[k]=array[j]; 
            k++; 
            j++; 
        } 
    } 
    while(i<=mid) 
    { 
        c[k]=array[i]; 
        k++; 
        i++; 
    } 
    while(j<=high) 
    { 
        c[k]=array[j]; 
        k++; 
        j++; 
    } 
    for(i=0;i<k;i++) 
    { 
        array[i]=c[i]; 
    } 
} 

void sort::shellsort(int n)			   								//Function Definition for Shell Sort 
{ 
    int temp,gap,i; 
    int swapped; 
    gap=n/2; 
    do 
    { 
        do 
        { 
            swapped=0; 
            for(i=0;i<n-gap;i++) 
            { 
               if(array[i]>array[i+gap])   							//Checking of condition whether Element is smaller or greater 
                { 
                    temp=array[i]; 
                    array[i]=array[i+gap]; 
                    array[i+gap]=temp; 
                    swapped=1; 
                } 
            } 
        }while(swapped==1);											//To Swap the elements 
    }while(gap=(gap/2)>=1);											//To increase the gap 
} 

void sort::radixsort(int n)		         							//Function Definition for Radix Sort 
{ 
    int largest,divisor=1,r=0; 
    int bucket[10][15],counter[10]; 
  	largest=array[0]; 
 	for(int i=1;i<n;i++)		       								//For Checking Largest Number in array 
 	{ 
           if(array[i]>largest) 
           { 
            largest=array[i]; 
           } 
        } 
	cout<<"Largest number in a is"<<largest<<endl; 
        int p=0; 
	while(largest>0)												// Printing the number of passes in array 
	{ 
        p++; 
        largest=largest/10; 
	} 
	cout<<"Total number of pass are "<<p<<endl; 
        for(int k=0;k<p;k++) 
    	{ 
        	for(int q=0;q<10;q++) 
       	 	{ 
            		counter[q]=0; 
        	} 
        	for(int j=0;j<n;j++) 
        	{ 
        	    r=(array[j]/divisor)%10; 
        	    bucket[r][counter[r]]=array[j]; 
        	    counter[r]++; 
        	} 
        	int z=0; 
        	for(int w=0;w<10;w++) 
        	{ 
        	    for(int b=0;b<counter[w];b++) 
        	    { 
        	        array[z++]=bucket[w][b]; 
        	    } 
        	} divisor=divisor*10; 
       } 
} 

void sort::display(int n)											//Function Definition for Display 
{ 
    int i; 
    cout<<"Sorted array is "<<endl; 
    for (i=0;i<n;i++) 
	{ 
	cout<<"\t"<<array[i]<<endl; 
	} 
} 

int main() 
{ 
    sort s; 
    int n,num; 
    char c,c1; 
    cout<<"\nEnter the number of Elements of the array \t"; 
    cin>>n; 
    cout<<"Total number of Elements are "<<n<<endl; 
    if(n==0) 
    { 
     	cout<<"Entered  number is 0 alreadry sorted"<<endl; 
    } 
    else 
    { 
    if(n==1) 
    { 
     	s.input(n); 
     	cout<<"Entered  number is 1 already sorted"<<endl; 
     	s.display(n); 
    } 
    else 
    { 
     	s.input(n); 
    } 
    do 
    { 
    cout<<"**********Differnt type of sort**********"<<endl;  
    cout<<"\t1 Quick Sort"<<endl; 
    cout<<"\t2 Merge Sort"<<endl; 
    cout<<"\t3 Shell Sort"<<endl; 
    cout<<"\t4 Radix Sort"<<endl; 
    cout<<"Enter type of sort u want to perform \t"; 
    cin>>num; 
    cout<<"Enter Choice is "<<num<<endl; 
 	switch(num) 
    { 
        case 1:cout<<"**************QuickSort**************"<<endl<<endl; 
                 s.Partition(0,n-1);								//Calling of Partition(in which Quick sort function is called ) Function 
                s.display(n); 
        break; 
        case 2:cout<<"**************Merge Sort**************"<<endl<<endl; 
                s.divide(0,n-1);									//Calling of Dividing (in which sort and merge function is called) Function 
                s.display(n); 
        break; 
        case 3:cout<<"**************Shell Sort**************"<<endl<<endl; 
                s.shellsort(n);										//Calling of Shell Sort Function 
                s.display(n); 
       break; 
        case 4:cout<<"**************Radix Sort**************"<<endl<<endl; 
                s.radixsort(n); 									//Calling of Radix Sort Function 
                s.display(n); 
        break; 
        default:cout<<"Entered Choice is Wrong"<<endl<<endl; 
        break; 
    } 
    cout<<"Do u want to continue Yes or No \t"<<endl; 
    cin>>c; 
          if(c=='y' || c=='Y') 
          { 
          cout<<"Do u want to continue With same numbers yes or no \t"<<endl; 
          cin>>c1; 
                  if(c1=='y' || c1=='Y') 
                  { 
                  s.old(n); 
                  } 
                  else 
                  { 
                  cout<<"Enter the number of Elements of the array \t"; 
                  cin>>n; 
                  cout<<"Total number of Elements are "<<n<<endl; 
                  s.input(n); 
                  } 
          } 
       }while(c=='y' || c=='Y'); 
     
    } 
    return 0; 
} 