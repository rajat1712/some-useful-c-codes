class student{
	public:
		int age;
		int rollNumber;
	    static int totalStudents;
	
	student()
	{
		totalStudents++;
	}
	
	static int gettotalStudents()
	{
		return totalStudents;
	}
};

int student::totalStudents=0;
