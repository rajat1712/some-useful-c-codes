using namespace std;
class shop{
	public:
		int quantity;
	private:
		int price;
		
		
	public:
		void setPrice(int a,int password)
		{
			if(password!=123)
			{
				cout<<"password wrong! Updation cannot be done";
			}
			else{
			   price=a;
			}
			
		}
		
		int getPrice()
		{
			return price;
		}
};
