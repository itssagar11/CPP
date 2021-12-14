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
class Collection{
    public:
    // function to find middle element
    Node* getMid(Node *h){
        Node* p1=h;
        Node* p2=h;
        while(p2->next!=NULL && (p2->next)->next!=NULL){
            p2=(p2->next)->next;
            p1=p1->next;
        }
        return p1;
    }
    // function to merge two list
    Node* Merge(Node *left,Node *right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        if(left->data<right->data){
            left->next=Merge(left->next,right);
            return left;
        }
            right->next=Merge(left,right->next);
            return right;
    }
    // function to get last node
   Node* last(Node* head){
        Node* lastnode=head;
            while(lastnode->next!=NULL){
                lastnode=lastnode->next;
            }

        return lastnode;
    }
    // function to swap two node value.
    void Swap(Node **curr,Node **start){
        int temp=(*curr)->data;
        (*curr)->data=(*start)->data;
        (*start)->data=temp;
    }
    Node* Partition(Node *head,Node *last){
        if(head==NULL || head==last || last==NULL){
            return head;
        }

        int pivot=last->data;
        Node* curr=head;
        Node* start=head;
        Node* prev=head;
        while(start!=last){
            if(start->data<pivot){
                prev=curr;
                Swap(&curr,&start);
                curr=curr->next;
            }
            start=start->next;
        }
        Swap(&curr,&start);
        return prev;

    }
};
class Sorting:public Collection{
public:
    // function of merge sort in linkedList.
    Node* mergeSort(Node *head)
    {
       if(head==NULL || head->next==NULL){
            return head;
        }
        Node* mid=getMid(head);
        Node* midNext=mid->next;
        mid->next=NULL;
        Node* left=mergeSort(head);
        Node* right=mergeSort(midNext);
        return Merge(left,right);

    }
    // QuickSort
    void QuickSort(Node **start,Node **last){
        if(*start==*last || *start==NULL || *start==(*last)->next){
            return;
        }
        Node* pivot= Partition(*start,*last);
       // System.out.println("pivot is :-"+pivot.data);
        QuickSort(start,&pivot);
             if(pivot!=NULL && pivot==*start){ // pivot =start means pivot is first element
                 QuickSort(&(pivot->next),last);
             }
             else if(pivot->next!=NULL && pivot->next->next!=NULL)
                QuickSort(&(pivot->next->next),last);
    }


} ;
// class LinkedList.
class LinkedList: public Sorting{
    protected:
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
		n->next=head;
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
			todel= head;
			head=(head)->next;
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
	void Print(){
		if(head==NULL){
			cout<<"List Is Empty"<<endl;
			return;
		}
		while(head!=NULL){
			cout<<head->data<<endl;
			head=head->next;
		}
	}
	private:
	void Sort(){
       head= mergeSort(head);
	}

};
// Stack using Linked ist (Dynamic stack);
// Stack class inherit linkedList class;
class Stack: public LinkedList{
    public:
      Stack(){
      }
      void PUSH(int n){
          InsertFirst(n);
      }
      void POP(){
        DeleteFirst();
      }
      void PEEK(){
        if(head==NULL){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        int d=head->data;
        cout<<d<<endl;
      }
};
class Queue{
    protected:
    Node * fro_nt;
    Node* rear;
    public:
    Queue(){
        fro_nt=NULL;
        rear=NULL;
    }
    void enqueue(int n){
        Node* temp= new Node(n);
        if(fro_nt==NULL){
            fro_nt=rear=temp;
            return;
        }
        rear->next=temp;
        rear=rear->next;
        return;
    }
    void dequeue(){
        if(fro_nt==NULL){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        Node* todel= fro_nt;
        if(fro_nt==rear){
            fro_nt=rear=NULL;
        }else
            fro_nt=fro_nt->next;
        delete todel;
    }
    void print(){
    Node *itr= fro_nt;
        while(itr!=NULL){
            cout<<itr->data<<endl;
            itr=itr->next;
        }

    }


};
class CircularQueue: public Queue{
    public:
       void enqueue(int v)
        {
            Node* temp = new Node(v);
            if (fro_nt == NULL)
                fro_nt =rear = temp;
            else
                rear->next = temp;
            rear = temp;
            temp=fro_nt;
        }

        void deQueue()
        {
            if (fro_nt == NULL) {
                cout<<"Queue is empty"<<endl;
                return;
            }
            Node* todel;
            // If the last node to be deleted
            if (fro_nt == rear) {
                todel=fro_nt;
                fro_nt = NULL;
                rear = NULL;
            }
            else // There are more than one nodes
            {
                todel= fro_nt;
                fro_nt = fro_nt->next;
                rear->next = fro_nt;

            }
            delete todel;
        }

        // to display a queue
        void print(){
            if(fro_nt==NULL){
                cout<<"Queue is Empty"<<endl;
                return;
            }
            Node* temp = fro_nt;
            while (fro_nt->next != fro_nt) {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
               cout<<temp->data<<endl;

        }
};
