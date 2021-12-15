#include<iostream>
using namespace std;
// class Node to store elements.
class Node{
	public:
		int data;
		Node* next;
		Node(){
			data=-1;
			next=NULL;
		}
		Node(int data){
			this->data=data;
			next=NULL;
		}
};
// class LinkedList.
class LinkedList{
	Node* head;
	public:
		LinkedList(){
			head=NULL;
		}
	// function to insert element at first.
	void InsertFirst(int d){
		Node* n=new Node(d);
		if(head==NULL){
			head=n;
			return;
		}
		n->next=*head;
		head=n;
		return;
	}
		// function to insert element at last.
	void InsertLast(int d){
		Node* n= new Node(d);
		if(head==NULL){
			head=n;
			return;
		}
		Node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=n;
		return;
	}
		// function to delete element from first.
	void DeleteFirst(){
		if(head==NULL){
			cout<<"Empty."<<endl;
			return;
		}
		Node *temp=head;
		head=(head)->next;
	//	delete temp;
	}
		// function to delete element from last.
	void DeleteLast(){
		if(head==NULL){
		cout<<"Empty"<<endl;
		return;
		}
		Node* temp= head;
		while((temp->next)->next!=NULL)
		temp=temp->next;
		Node *d=temp->next;
		temp->next=NULL;
	//	delete d;
	}
	//	// function to delete element from user input.
	void Delete(int n){
		if(head==NULL){
			cout<<"Empty"<<endl;
			return;
		}
		Node* todel=NULL;
		// case 1: If element is first;
		if((head)->data==n){
			todel= *head;
			*head=(head)->next;
			return;
		}
		// case 2: if  not a first element.
		Node *itr=head;
		int flag=0;
		
		while(itr!=NULL && flag==0){
			if((itr->next)->data==n){
				todel=itr->next;
				flag=1;
			}
			itr=itr->next;
		}
		if(flag==0){
			cout<<"Element Not found"<<endl;
			return;
		}
		itr->next=todel->next;
		delete itr;	
	}
		// function to print element.
	void Print(Node *head){
		if(head==NULL){
			cout<<"List Is Empty"<<endl;
			return;
		}
		while(head!=NULL){
			cout<<head->data<<endl;
			head=head->next;
		}
	}
	
};
