using namespace std;
class Fraction{
	private:
		int numerator;
		int denominator;
	public:
		Fraction(int numerator,int denominator)
		{
			this->numerator=numerator;
			this->denominator=denominator;
		}
		
		void print()
		{
			cout<<this->numerator<<"/"<<this->denominator<<endl;;
		}
		
	  void simplify()
	  {
	  	int hcf=1;
	    int j=min(this->numerator,this->denominator);
	    for(int i=1;i<=j;i++)
	    {
	    	if(this->numerator%i ==0 && this->denominator%i==0)
	    	{
	    		hcf=i;
			}
		}
		
		this->numerator=this->numerator/hcf;
		this->denominator=this->denominator/hcf;
	  }	
		
	  
	  void add(Fraction f2)
	  {
	  	int den=this->numerator*f2.denominator;
	  	 int x=den/this->denominator;
	  	 int y=den/f2.denominator;
	  	 int num=(x*this->numerator)+(y*f2.numerator);
	  	 
	  	 numerator=num;
	  	 denominator=den;
	  	 
	  	 simplify();
	  }
};
