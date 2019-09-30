#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

struct Queue
{
	int info;
	Queue *link;
};
class list
{
	Queue *front, *back;
	int count;
public:
	list()
	{
		front=NULL;
		back=NULL;
		count =0;
	}

	void create_Queue(int data)
	{
		Queue *new_Queue = new Queue;
		new_Queue->info = data;
		new_Queue->link = NULL;

		if(front==NULL)
		{
			front = new_Queue;
			back = new_Queue;
			count++;
		}
		else
		{
			back->link = new_Queue;
			back = new_Queue;
		}

	}
	//===========(Initialize the Queue)===========\\

	void initialize_Queue()
	{
		if (isempty())
		cout<<"Queue is already empty";
		else
		{
			Queue *temp;
			while(front!=NULL)
			{
				temp = front;
				front = front->link;
				delete temp;
			}
			back = NULL;
			cout<<"The Queue is empty now"<<endl;
		}
	}
	//===========(Display the Queue)===========\\
	
	void display()
	{
		if (isempty())
		cout<<"Queue is empty";
		else
		{
			Queue *temp = front;
			cout<<"The Queue : ";
			while(temp !=NULL)
			{
				cout<<temp->info<<" ";
				temp = temp->link;
			}
	
		}
	}
	//===========(Check the Queue is empty or not)===========\\

	bool isempty()
	{
		if(front == NULL && back == NULL)
			return true;
		else
			return false;
	}
	//===========(Print the front of Queue)===========\\
	
	void print_front()
	{
		if(isempty())
			cout<<"Sorry the list is empty"<<endl;
		else
		cout<<"Front of the Queue is : "<<front->info<<endl;
	}
	//===========(Print the back of Queue)===========\\

	void print_back()
	{
		if(isempty())
			cout<<"Sorry the list is empty"<<endl;
		else
		cout<<"Back of the Queue is : "<<back->info<<endl;
	}
	//===========(Delete the front element of Queue)===========\\

	void delete_front_Queue()
	{
		if(isempty())
			cout<<"Sorry the list is empty"<<endl;
		else
		{
			Queue *temp = front;
			front = front->link;
			cout<<"The front element "<<temp->info<<" of the Queue successfuly deleted"<<endl;
			delete temp;
			
			if(front == NULL) // if the element is only one in list 
			back = NULL;
		}
	}

};

int main()
{
	list obj;
	int data;
	char ch;
manu:
	system("CLS");
	cout<<"1) Create Queue"<<endl;
	cout<<"2) print front"<<endl;
	cout<<"3) Print back"<<endl;
	cout<<"4) Check the list is empty or not"<<endl;
	cout<<"5) Delete the front of the Queue"<<endl;
	cout<<"6) Delete the Queue (initialize the Queue)"<<endl;
	cout<<"0) Display List"<<endl;
	int opt;
	cin>>opt;
	switch(opt)
	{
	case 1:
		cout<<"Enter the number of Queues : ";
		int size;
		cin>>size;
	
		for(int i=1; i<=size; i++)
		{
			cout<<"\nEnter the "<< i<<" Queue data : ";
			cin>>data;
			obj.create_Queue(data);
		}
		cout<<"\nPress Y/y to go in previous manu : ";
    	cin>>ch;
    	if(ch=='Y'||ch=='y')
    	{
    		goto manu;
		}
		break;

	case 2:
		obj.print_front();
		cout<<"\nPress Y/y to go in previous manu : ";
    	cin>>ch;
    	if(ch=='Y'||ch=='y')
    	{
    		goto manu;
		}
		break;

	case 3:
		obj.print_back();
		cout<<"\nPress Y/y to go in previous manu : ";
    	cin>>ch;
    	if(ch=='Y'||ch=='y')
    	{
    		goto manu;
		}
		break;
	case 4:
		if(obj.isempty())
			cout<<"The list is empty"<<endl;
		else
			cout<<"The list is not empty"<<endl;
		cout<<"\nPress Y/y to go in previous manu : ";
    	cin>>ch;
    	if(ch=='Y'||ch=='y')
    	{
    		goto manu;
		}
		break;
		
	case 5:
		obj.delete_front_Queue();
		cout<<"\nPress Y/y to go in previous manu : ";
    	cin>>ch;
    	if(ch=='Y'||ch=='y')
    	{
    		goto manu;
		}
		break;

	case 6:
		obj.initialize_Queue();
		cout<<"\nPress Y/y to go in previous manu : ";
    	cin>>ch;
    	if(ch=='Y'||ch=='y')
    	{
    		goto manu;
		}
		break;
	case 0:
		obj.display();
		cout<<"\nPress Y/y to go in previous manu : ";
    	cin>>ch;
    	if(ch=='Y'||ch=='y')
    	{
    		goto manu;
		}
		break;
	default:
		cout<<"Invalid inpput"<<endl;
	}
	getch();
}
