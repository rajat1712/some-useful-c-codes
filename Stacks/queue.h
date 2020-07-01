class QueueUsingArray{
	int *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;
	
	public:
		QueueUsingArray(){
			data=new data[5];
			nextIndex=0;
			firstIndex=-1;
			size=0;
			capacity=5;
		}
		
	int size(){
		return size;
	}
	
	bool isEmpty(){
		if(size==0){
			return true;
		}
		else{
			return false;
		}
	}
	
	void enqueue(int element){
		if(size==capacity){
			int *newData=new int[2*capacity];
			int j=0;
			for(int i=firstIndex;i<capacity;i++){
				newData[j]=data[i];
				j++;
			}
			
			for(int i=0;i<firstIndex;i++){
				newData[j]=data[i];
				j++;
			}
			firstIndex=0;
			capacity=2*capacity;
			delete [] data;
			data=newData;
			nextIndex=capacity;
		}
		
		data[nextIndex]=element;
		nextIndex=(nextIndex+1)%capacity;
		
		if(firstIndex==-1){
			firstIndex=0;
		}
		size++;	
	}
	
	
	int front(){
		if(size==0){
			cout<<"Queue is empty!"<<endl;
			return INT_MIN;
		}
	  return data[firstIndex];
	}
	
	
	int dequeue(){
		if(size==0){
			cout<<"Queue is empty!"<<endl;
			return INT_MIN;
		}
		
		int ans=data[firstIndex];
		firstIndex=(firstIndex+1)%capacity;
		size--;
		return ans;
	}
};




















