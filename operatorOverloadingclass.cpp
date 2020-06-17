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
		
	  
	Fraction operator+(Fraction const f2) const
	  {
	  	int den=this->denominator*f2.denominator;
	  	 int x=den/this->denominator;
	  	 int y=den/f2.denominator;
	  	 int num=(x*this->numerator)+(y*f2.numerator);
	  	 
	  	 Fraction fNew(num,den);
	  	 
	  	 fNew.simplify();
	  	 return fNew;
	  }
	  
	  Fraction operator*(Fraction const f2) const{
	  	int x=this->numerator*(f2.numerator);
	  	int y=this->denominator*(f2.denominator);
	  	
	  	Fraction fNew(x,y);
	  	fNew.simplify();
	  	return fNew;
	  }
	  
	  bool operator==(Fraction const f2) const{
	  	return(numerator==f2.numerator && denominator==f2.denominator);
	  }  
	  
	  
	  Fraction& operator++()
	  {
	    numerator=this->numerator+this->denominator;
	    simplify();
	    return *this;
	  }
	  
	  
	  Fraction operator++(int){
	  	Fraction fNew(this->numerator,this->denominator);
	  	numerator=this->numerator+this->denominator;
	  	simplify();
	  	fNew.simplify();
	  	return fNew;
	  }
	  
	  
	  Fraction& operator+=(Fraction const f2 ){
	  	int den=this->denominator*f2.denominator;
	  	 int x=den/this->denominator;
	  	 int y=den/f2.denominator;
	  	 int num=(x*this->numerator)+(y*f2.numerator);
	  	 
	  	 this->numerator=num;
	  	 this->denominator=den;
	  	 simplify();
	  	 return *this;
	  }
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
};
