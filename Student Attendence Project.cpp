#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Student{
	string name;
	int RollNO;
	bool present; 
};
Student student;
vector<Student> st;

save(const vector<Student>& st, const string& stFile)
{
	ofstream out ("E:/University Task/Student Attendence Management/student_data.txt");
	if(!out)
	{
		cerr<<"File not Found : "<<stFile<<endl;
	}
	for(int i=0 ; i<st.size() ; i++)
	{
		out<<"Name : "<<st[i].name<<endl;
		out<<"Roll NO : "<<st[i].RollNO<<endl;
		out<<"Status : "<<st[i].present<<endl;
	}
	out.close();
	cout<<"Saved The File "<<stFile<<endl;
 } 

int main(){
	int value;
	while(true)
	{
		cout<<"1. Add Student "<<endl;
		cout<<"2. Add Attendence "<<endl;
		cout<<"3. Show Detail "<<endl;
		cout<<"4. To save the File "<<endl;
		cout<<"0. To Exit "<<endl;
		cout<<" Enter Choice : ";cin>>value;
		
		if(value==1)
		{
		   system("cls");
		   char choice;
		   do{
		   	   cout<<"Name : "; cin>>student.name;
		   	   cout<<"Roll NO : ";cin>>student.RollNO;
		   	   st.push_back(student);
		   	   cout<<"Student Saved"<<endl;
		   	   cout<<"Enter X for Exit and C for Continue : ";cin>>choice;
		   }
		   while((choice!='x' || choice!='X') && (  choice=='c' || choice=='C'));	
		  	
		} 
		
		else if(value==2)
		{
			system("cls");
			char choice;
			for (int i=0; i<st.size(); i++)
			{
				cout<<"Name : "<<st[i].name<<endl;
				cout<<"RollNO : "<<st[i].RollNO<<endl;
				cout<<"'P' for Present and 'A' for Absent : "; cin>>choice;
				if(choice=='p')
				{
					st[i].present=true;
				}
				else if(choice=='a')
				{
					st[i].present=false;
				}
				else
				{
					cout<<"invalid Character";
				}
			}
		} 
		
		else if(value==3)
		{
			system("cls");
			for (int i=0 ; i<st.size() ; i++)
			{
				if(st[i].present==true)
				{
					cout<<"Name : "<<st[i].name<<endl;
		   	        cout<<"Roll NO : "<<st[i].RollNO<<endl;
		   	        cout<<"Status : Present"<<endl;
				}
				else if(st[i].present==false)
				{
					cout<<"Name : "<<st[i].name<<endl;
		   	        cout<<"Roll NO : "<<st[i].RollNO<<endl;
		   	        cout<<"Status : Absent"<<endl;
				}
				else
				{
					cout<<"invalid Character";
				}
			}
			
		} 
		
		else if(value==4)
		{
			save(st, "E:/University Task/Student Attendence Management/student_data.txt");
			
		} 
		
		else if(value==0)
		{
		    
			break;	
		}
		else
		{
			system("cls");
			cout<<"invalid Input"<<endl;
		}
	} 
} 
