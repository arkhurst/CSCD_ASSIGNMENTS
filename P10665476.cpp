#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>

using namespace std;

  class student
  {
      int numStudents;  //the number of students in the class
      char name[50];
      int programming, numerical,arch,info_system,calculus, aca_writing;
      float average; //gives you the average mark for all the courses
      char grade;
      void calculate();


  public:
    void showdata();
    void getdata();
    int getrollno();

  };

  void student:: calculate()
  {
      average = (programming + numerical + arch + info_system + calculus + aca_writing)/6.0;
      if (average >= 80)
        grade = 'A';
      else if (average >= 70 && average < 80)
        grade = 'B';
      else if (average >=60 && average < 70)
        grade = 'C';
      else if (average >= 50 && average < 60)
        grade = 'D';
      else if (average >= 40 && average < 50)
        grade = 'E';
      else
        grade = 'F';
  }

  void student:: getdata()
  {
      cout<<"Enter the student number"<< endl;
      cin>>numStudents;
      cout<<"Enter the name of student"<<endl;
      cin>>name;
      cout<<"Enter the mark for CSCD 205 (Programming with C++)"<<endl;
      cin>>programming;
      cout<<"Enter the mark for CSCD 207 (Numerical Methods)"<<endl;
      cin>>numerical;
      cout<<"Enter the mark for CSCD 201 (Computer Architecture)"<<endl;
      cin>>arch;
      cout<<"Enter the mark for CSCD 203 (Information System)"<<endl;
      cin>>info_system;
      cout<<"Enter the mark for Math 223 (Calculus)"<<endl;
      cin>>calculus;
      cout<<"Enter the mark for UGRC 211 (Academic Writing)"<<endl;
      cin>>aca_writing;
      calculate();
  }



  void student::showdata()
{

	cout<<"\t---------------------------";
	cout<<"\n\t      STUDENT DETAIL\n";
	cout<<"\t---------------------------";
	cout<<"\n\n\tRoll number of student : "<<numStudents;
	cout<<"\n\n\tName of student : "<<name;
	cout<<"\n\n\tCSCD 205 (Programming with C++) : "<<programming;
	cout<<"\n\n\tCSCD 207 (Numerical Methods) : "<<numerical;
	cout<<"\n\n\tCSCD 201 (Computer Architecture) "<<arch;
	cout<<"\n\n\tCSCD 203 (Information System) : "<<info_system;
	cout<<"\n\n\tMath 223 (Calculus) :"<<calculus;
	cout<<"\n\n\tUGRC 211 (Academic Writing) :"<<aca_writing;
	cout<<"\n\n\tPercentage of student is  :"<<average;
	cout<<"\n\n\tGrade of student is :"<<grade;
}

int  student::getrollno()
{
	return numStudents;
}

void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.txt",ios::binary|ios::app);
	st.getdata();
	outFile.write((char *) &st, sizeof(student));
	outFile.close();
    cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	getch();
}

void display_sp(int n)
{

	student st;
	ifstream inFile;
	inFile.open("student.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}

/*	int temp=0;
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.getrollno()==n)
		{
			 st.showdata();
			 temp=1;
		}
	}
	inFile.close();
	if(temp==0)
		cout<<"\n\n\tRECORD DOES NOT EXIST...!!!";
	getch();*/
}

void modify_student(int n)
{

	int found=0;
	student st;
	fstream File;
	File.open("student.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\n\tFile could not be open !!";
		getch();
		return;
	}
	while(File.read((char *) &st, sizeof(student)) && found==0)
	{
		if(st.getrollno()==n)
		{
			st.showdata();

			cout<<"\n\n\tPlease Enter The New Details of student"<<endl;
			st.getdata();
		    	int pos=(-1)*sizeof(st);
		    	File.seekp(pos,ios::cur);
		    	File.write((char *) &st, sizeof(student));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n\tRecord Not Found ";
	getch();
}

void delete_student(int n)
{

	student st;
	ifstream inFile;
	inFile.open("student.txt",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		getch();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.txt",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.getrollno()!=n)
		{
			outFile.write((char *) &st, sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.txt");
	rename("Temp.txt","student.txt");
	cout<<"\n\n\tRecord Deleted ..";
	getch();
}

void result()
{
	char ch;
	int numStudents;

	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\t1. Student Report Card";
	cout<<"\n\n\t2. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (1/2)? ";
	cin>>ch;
	switch(ch)
	{
	case '1' :
		  cout<<"\n\n\tEnter the student number : ";
		  cin>>numStudents;
		  display_sp(numStudents); break;
	case '2' :
			break;
	default :
			cout<<"\a";
	}
}

void entry_menu()
{
	char ch;
	int num;

	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t3.MODIFY STUDENT RECORD";
	cout<<"\n\n\t4.DELETE STUDENT RECORD";
	cout<<"\n\n\t5.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-5) ";
	cin>>ch;
	switch(ch)
	{
	case '1':
			write_student(); break;
	case '2':
			cout<<"\n\n\tPlease enter the student number ";
            cin>>num;
			display_sp(num); break;
	case '3':
			cout<<"\n\n\tPlease enter the student number ";
			cin>>num;
			modify_student(num);break;
	case '4':
			cout<<"\n\n\tPlease enter the student number ";
			cin>>num;
			delete_student(num);break;
	case '5':
			break;
	default:
			cout<<"\a"; entry_menu();
	}
}


int main()
{
	int password();
	password();
	char ch;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2);

	do
	{
	    cout<<"\t-------------------------------";
        cout<<"\n\n\t\tREPORT CARD";
		cout<<"\n\t   STUDENT DETAIL MANAGEMENT\n";
		cout<<"\t-------------------------------";
		cout<<"\n\n\t\t**MAIN MENU**";
		cout<<"\n\n\t01. RESULT MENU";
		cout<<"\n\n\t02. ENTRY/EDIT RECORD MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option : ";
		cin>>ch;
		switch(ch)
		{
			case '1': result();
				break;
			case '2': entry_menu();
				break;
			case '3':


                        return 0;
				break;
			default :
			    cout<<"\n\n\tError...!!!...Wrong Choice Entered...!!!";
		}
    	}
		while(ch!='3');
}

int password(){

   string pass ="";
   char ch;
   	cout<<"\n\n\n\n\n\n\t\t\t\t\t-------------------------------";
	cout<<"\n\t\t\t\t\tSTUDENT DETAIL MANAGEMENT LOGIN\n";
	cout<<"\t\t\t\t\t-------------------------------\n";
   cout << "\n\n\t\t\t\t\tEnter Password: ";
   ch = getch();
   while(ch != 13)
   {//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = getch();
   }
   if(pass == "pass")
   {

      cout << "\n\n\n\t\t\t\t\tAccess Granted \n\n\n";

   }
   else
   {
      cout << "\n\n\n\t\t\t\t\tAccess Denied...Please Try Again!\n";

      password();
   }
}
