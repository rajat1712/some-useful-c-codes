----Length Of LL-------
int length(Node *head){
	Node *temp=head;
	int length=0;
	while(temp!=NULL){
		length++;
		temp=temp->next;
	}
	return length;
}


---- Print Ith Node -----
void printIthNode(Node *head, int i){
	Node *temp=head;
	int index=0;
	while(temp!=NULL){
		if(i==index){
			cout<<temp->data;
			break;
		}
		else{
			index++;
			temp=temp->next;
		}
	}
}




-----Length Of LL Recursively-----
int length(Node *head) {
	Node *temp=head;
	if(temp==NULL){
		return 0;
	}
    return length(temp->next)+1;
   
}


-----Insert At Ith Position--------

Node *insert(Node *head,int data,int pos){
	Node *temp=head;
	Node *newNode=new Node(data);
	int count=0;
	if(pos==0){
		newNode->next=head;
		head=newNode;
		return head;
	}
	while(count<pos-1 && temp!=NULL){
		count++;
		temp=temp->next;
	}
	
	Node *a=temp->next;
	Node *b=a->next;
	a->next=newNode;
	newNode->next=b;
	
	
	return head;
}



-------Delete At Ith Node-------

Node *deleteNode(Node *head, int pos)
{
    Node *temp=head;
    Node *temp2=head;
    int count=0;
    if(pos==0){
    	head=temp2->next;
    	delete(temp2);
    	return head;
	}
    while(count<pos-1 && temp!=NULL){
    	count++;
    	temp=temp->next;
	}
	
	Node *a=temp->next;
	Node *b=a->next;
	temp->next=b;
	delete(a);
	
	
	return head;
}


--------Delete Ith Node --------
int lengthLL(Node *head){
    Node *temp=head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}
Node *deleteNode(Node *head, int pos)
{
   
    Node *temp=head;
    Node *temp2=head;
    int count=0;
    int length=lengthLL(head);
    if(pos > length)
    {
        return head;
    }
    if(pos==0){
    	head=temp2->next;
    	delete(temp2);
    	return head;
	}
    while(count<pos-1 && temp!=NULL){
    	count++;
    	temp=temp->next;
	}
	
	if(temp->next!=NULL)
    {
    Node *a=temp->next;
	Node *b=a->next;
	temp->next=b;
	delete(a);
    }
	
	
	return head;
}



------Inserting Node Recursively----------
Node* insertNodeRec(Node *head, int i, int data){
	Node *temp=head;
	Node *newNode=new Node(data);
	if(head==NULL){
		return head;
	}
	
	if(i==0){
		newNode->next=head;
		head=newNode;
		return head;
	}
	
	Node *x=insertNodeRec(head->next,i-1,data);
	
	temp->next=x;
	return temp;
	
}

-------Delete Node Recursively-------
Node* deleteNodeRec(Node *head, int i){
	Node *temp=head;
	Node *temp2=head;
	if(head==NULL){
		return head;
	}
	if(i==0){
		head=temp2->next;
		delete(temp2);
		return head;
	}
	
	Node *x=deleteNodeRec(head->next,i-1);
	temp->next=x;
	return temp;
}

------Let Last be the First-------
int lengthLL(Node<int> *head){
	Node<int> *temp=head;
	int length=0;
	while(temp!=NULL){
		length++;
		temp=temp->next;
	}
	return length;
}
Node<int>* moveToFront(Node<int> *head_ref){
	Node<int> *head=head_ref;
	Node<int> *temp=head_ref;
	int length=lengthLL(head);
	int count=1;
	while(count<length-1){
		count++;
		temp=temp->next;
	}
	Node<int> *a=temp->next;
	temp->next=NULL;
	a->next=head;
	head=a;
	
	return a;
	
}



--------Union of LL-----------
bool checkPresence(int data,vector<int> first){
	for(int i=0;i<first.size();i++){
		if(first[i]==data){
			return true;
			break;
		}
	}
	return false;
}
ListNode<int> *unionOf2LL(ListNode<int> *head1,ListNode<int> *head2)
{
	int length=lengthHead1(head1); 
	vector<int> first;
	ListNode<int> *temp=head1;
	ListNode<int> *prev=NULL
	while(temp!=NULL){
		first.push_back(temp->data);
		prev=temp;
		temp=temp->next;
	}
	
	ListNode *temp2=head2;
	while(temp2!=NULL){
		bool check=checkPresence(temp2->data,first);
		if(check){
			continue;
		}
		else{
		  prev->next=temp2;
		}
	 temp2=temp2->next;
	 prev=prev->next;
	}
  prev->next=NULL;
  return head1;
}



------Alternating Split--------
Node<int> *reverse(Node<int> *head){
	Node<int> *current=head;
	Node<int> *prev=NULL;
	while(current!=NULL){
		Node<int> *next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	return prev;
}
void print(Node<int> *head){
	Node<int> *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void AlternatingSplit(Node<int>* head) {
	Node<int> *head1=NULL;
	Node<int> *tail1=NULL;
	Node<int> *head2=NULL;
	Node<int> *tail2=NULL;
	Node<int> *temp=head;
	int count=0;
	
	while(temp!=NULL){
		if(count%2==0){
		 
		   if(head1==NULL && tail1==NULL){
		   	 head1=temp;
		   	 tail1=temp;
		   }	
		   
		   else{
		   	 tail1->next=temp;
		   	 tail1=tail1->next;
		   }
		  
		}
		
		
		else{
			
			if(head2==NULL && tail2==NULL){
				head2=temp;
				tail2=temp;
			}
			
			else{
				tail2->next=temp;
				tail2=tail2->next;
			}
		}
		
	   temp=temp->next;
	   count++;
	}
	
	
   Node<int> *first=reverse(head1);
   Node<int> *second=reverse(head2);
   
   print(first);
   print(second);
  
}


-----Is Palindrome--------
int lengthLL(Node *head){
	Node *temp=head;
	int length=0;
	while(temp!=NULL){
		length++;
		temp=temp->next;
	}
	return length;
}
Node *deletePos(Node *head,int pos){
	Node *temp=head;
	int count=0;
	while(count<pos-1 && temp!=NULL){
		count++;
		temp=temp->next;
	}
	Node *a=temp->next;
	Node *b=a->next;
	temp->next=b;
	delete(a);
	return head;
}
Node *reverseLL(Node *head){
	Node *current=head;
	Node *prev=NULL;
	while(current!=NULL){
		Node *next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
   return prev;
}
bool isPalindrome(Node *head)
{
    int length=lengthLL(head);
    if(length==1){
    	return true;
	}
	if(head==NULL){
		return true;
	}
	Node *head2=head;
	if(length%2!=0){
	   head2=deletePos(head,length/2);
	}
	
	Node *temp=head2;
	int count=0;
	int length2=lengthLL(head2);
	int pos=length2/2;
	while(count<pos-1 && temp!=NULL){
		count++;
		temp=temp->next;
	}
	
	Node *x=temp->next;
	temp->next=NULL;
	Node *y=reverse(x);
	
	Node *first=head2;
	bool flag=true;
	while(first!=NULL && second!=NULL){
		if(first->data != y->data){
			flag=false;
			break;
		}
	  first=first->next;
	  y=y->next;
	}
	if(flag==false){
		return false;
	}
	else{
		return true;
	}
}


------Reverse K elements------
node* kReverse(node*head,int n)
{
   node *temp=head;
   int count=0;
   node *current=head;
   node *prev=NULL;
   node *next=NULL;
   while(current!=NULL && count<n){
   	next=current->next;
   	current->next=prev;
   	prev=current;
   	current=next;
   }
   Node *x=NULL;
   if(next!=NULL){
   	x=kReverse(next,n);
   }
   
   temp->next=x;
   return prev;
}








































