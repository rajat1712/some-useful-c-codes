-----Merge Two Sorted LL-----
Node* mergeTwoLLs(Node *head1, Node *head2) {
     if(head1==NULL){
     	return head2;
	 }
	 
	 if(head2==NULL){
	 	return head1;
	 }
	 Node *temp=NULL;
	 if(head1->data > head2->data){
	 	temp=head2;
	 	temp->next=mergeTwoLLs(head1,head2->next);
	 }
	 else{
	 	temp=head1;
	 	temp->next=mergeTwoLLs(head1->next,head2);
	 }
	 
	return temp;
}


------Decimal Equivalent------
Node<int> *reverse(Node<int> *head){
	Node<int> *temp=head;
	Node<int> *current=temp;
	Node<int> *prev=NULL;
	while(current!=NULL){
		Node<int> *next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	return prev;
}
int decimal(Node<int> *head){
	Node<int> *temp=reverse(head);
	int count=0;
	int sum=0;
	while(temp!=NULL){
		int n=temp->data;
		int result=pow(2,count)*n;
		sum=sum+result;
		
		temp=temp->next;
		count++;
	}
	return sum;
}

















