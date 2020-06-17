using namespace std;
class dynamicArray{
	public:
		int *data;
		int nextIndex;
		int capacity;
	 
	 dynamicArray(){
	 	data=new int[5];
	 	nextIndex=0;
	 	capacity=5;
	 }
	 
	 
	 dynamicArray(dynamicArray &d){
	 	this->data=new int[d.capacity];
	 	for(int i=0;i<d.nextIndex;i++){
	 		this->data[i]=d.data[i];
		 }
		 
		 this->nextIndex=d.nextIndex;
		 this->capacity=d.capacity;
	 }
	 
	 
	 
	 void operator=(dynamicArray &d){
	 	this->data=new int[d.capacity];
	 	for(int i=0;i<d.nextIndex;i++){
	 		this->data[i]=d.data[i];
		 }
		 
		 this->nextIndex=d.nextIndex;
		 this->capacity=d.capacity;
	 }
	 
	 
	 void add(int element){
	 	if(nextIndex > capacity){
	 		int *newArray=new int[2*capacity];
	 		for(int i=0;i<nextIndex;i++){
	 			newArray[i]=data[i];
			 }
			 delete [] data;
			 newArray=data;
			 capacity=capacity*2;
		 }
		data[nextIndex]=element;
		nextIndex++;
	 }
	 
	 
	int getElement(int index){
		if(index < nextIndex){
			return data[index];
		}
		else{
			return -1;
		}
	}
	
	
	void addElement(int index,int element){
		if(index<nextIndex){
			data[index]=element;
		}
		
		if(index==nextIndex){
			add(element);
		}
		
		else{
			return;
		}
	}
	
	
	void print(){
		for(int i=0;i<nextIndex;i++){
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
		
};
