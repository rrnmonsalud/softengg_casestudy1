#include<algorithm>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
bool is_empty(ifstream& pFile) //is file empty or not
{
    return pFile.peek() == ifstream::traits_type::eof();
}

struct addr  //per project
{
	int ID;
	string title;
	int size;
	int prio;
	
};

	bool acompare(addr lhs, addr rhs) {  //schedule parameters  
		if (lhs.prio != rhs.prio)
		return lhs.prio < rhs.prio;
		else
		return lhs.size < rhs.size; }

int main()
{
	char ch1;
	int x=1;
	addr proj[1000];
	string tmptitle;
	int tmpsize;
	int tmpprio;
	int tmpID = 0;
do{
	
cout << "1. Input Project Details" << endl;
cout << "2. View Projects" << endl;
cout << "3. Schedule Projects" << endl;
cout << "4. Get a Project" << endl;
cout << "5. Exit" << endl << endl;


cout << "Enter your choice: ";

ch1 = getch();

cout << ch1;

switch(ch1){
	
	case '1' : 	{
				ifstream file("schedule.txt");
				if (is_empty(file)){
			    ifstream f( "example.txt");
				int i = 0;
				int xx=1;
 			    while( i < 1000 && f >> proj[i].ID >> proj[i].title >> proj[i].size >> proj[i].prio ){	//get existing projects
 			   i++;
				}
				f.close(); 
				do{
				tmpID = 0;
				xx = 1;
				cout << endl << endl << "ID Number: " ;
				cin >> tmpID;
				
				for(int ct=0;ct<i;ct++){
					if(tmpID==proj[ct].ID){
					cout << "ID already exists! Please enter another ID" << endl;	
					xx = 0;
					}
					}
					}while(xx==0);
			
				cout << "Title: " ;
				cin >> proj[i].title;  //dapat walang space kasi magerror
				cout << "Size: " ;
				cin >> proj[i].size;
				cout << "Priority: " ;
				cin >> proj[i].prio;
				ofstream myfile;
				proj[i].ID = tmpID;
 				myfile.open ("example.txt", ofstream::app);
 				myfile << proj[i].ID << "\t" << proj[i].title << "\t" << proj[i].size << "\t" << proj[i].prio << endl;
 				myfile.close();
				break;
								}
				else{
					cout << "Schedule is not yet empty! Please finish current schedule first." << endl;
					system("pause");
					break;
					}					
				}
				
	case '2' : 	{
				system("cls");
				cout << "a. One Project" << endl;
				cout << "b. Completed Projects" << endl;
				cout << "c. All Projects" << endl;
				ch1 = getch();
						switch(ch1){
							
							case 'a' : {
									    ifstream f( "example.txt");
										int i = 0;
										int vd=0;
 									    while( i < 1000 && f >> proj[i].ID >> proj[i].title >> proj[i].size >> proj[i].prio ){	//get all existing projects
 									    i++;
										}
										f.close(); 
										cout << "Enter ID : ";
										cin >> tmpID;
										for(int ct=0;ct<i;ct++){
											if(proj[ct].ID==tmpID){
											
											cout << "FOUND MATCH" << endl;
											cout << "Project title : " << proj[ct].title << endl;
											cout << "Number of pages: " << proj[ct].size << endl;
											cout << "Priority Level: " << proj[ct].prio << endl;
											vd++;
										}
										}
										if (vd==0){
											cout <<"No match found." << endl;
										}
										system("pause");
										break;
									   	}
							case 'b' : {	
										cout << "ID" << "\t" << "Title" << "\t" << "Size" <<  "\t" <<  "Priority" << endl; 
										string line;
 										ifstream myfile ("Completed Projects.txt");
  										if (myfile.is_open())
 										{
 									    while ( getline (myfile,line) )
 				 					    {
 	   								    cout << line << '\n';
 	 									}
 									    myfile.close();
 										}
 										system("pause");
										break;
										}
							case 'c' : {
										cout << "ID" << "\t" << "Title" << "\t" << "Size" <<  "\t" <<  "Priority" << endl; 
										string line;
 										ifstream myfile ("example.txt");
  										if (myfile.is_open())
 	 {
 	   while ( getline (myfile,line) )
 	   {
 	     cout << line << '\n';
 	   }
 	   myfile.close();
 	 }	
 	 system("pause");
										break;
										}
							default : {
										cout << "Invalid Input please try again" << endl;
										system("pause");
										break;
										}
							
						}
				break;
				}
	case '3' :	{
				system("cls");
				cout << "a. Create Schedule" << endl;
				cout << "b. View Schedule" << endl;
				ch1 = getch();
						switch(ch1){
							case 'a' : {
										ifstream f( "example.txt");
										int i = 0;
 									    while( i < 1000 && f >> proj[i].ID >> proj[i].title >> proj[i].size >> proj[i].prio ){	
 									    i++;
										}
										f.close(); //counts how many projects received in total
										sort(proj, proj+i, acompare);  //schedule maker
										ofstream myf;
										myf.open("schedule.txt");
										for(int ct=0;ct<i;ct++){
										myf << proj[ct].ID << "\t" << proj[ct].title << "\t" << proj[ct].size << "\t" << proj[ct].prio << endl;
										}
										cout << "Schedule created!"  << endl;
										system("pause");
										myf.close();
										break;
										}
							case 'b' : {
										string line;
										ifstream file("schedule.txt");
										if (is_empty(file)){
   										cout << "No schedule created! Please create a schedule first." << endl;
										}
										else{
										cout << "ID" << "\t" << "Title" << "\t" << "Size" << "\t" <<  "Priority" << endl; 	
  										if (file.is_open())
 										{
 								   	    while ( getline (file,line) )
 									   {
 	  								   cout << line << '\n';
 	  									 }
 	 									  file.close();
 										 }	
											}
										system("pause");								
										break;
										}
							default : {
										cout << "Invalid Input please try again" << endl;
										system("pause");
										break;
									   }
						}
				break;
				}
		
	case '4' :	{
				ifstream f("schedule.txt");
				if (is_empty(f)){
			    cout << "No schedule created! Please create a schedule first." << endl;
 			    system("pause");
			   f.close();
			   break;
				}
				int ctt = 0;
				while( ctt < 1000 && f >> proj[ctt].ID >> proj[ctt].title >> proj[ctt].size >> proj[ctt].prio ){	
 				ctt++;
				}	
				f.close();
				cout << "OLD SCHEDULE" << endl;
				for (int ct=0;ct<ctt;ct++){
				cout << proj[ct].ID << "\t" << proj[ct].title << "\t" << proj[ct].size << "\t" << proj[ct].prio << endl;
				}
				ofstream myf;
				myf.open("Completed Projects.txt", ofstream::app );
				myf << proj[0].ID << "\t" << proj[0].title << "\t" << proj[0].size << "\t" << proj[0].prio << endl;
				myf.close();
				for(int ct=0;ct<ctt-1;ct++){
				proj[ct].ID = proj[ct+1].ID;
				proj[ct].title = proj[ct+1].title;
				proj[ct].size = proj[ct+1].size;
				proj[ct].prio = proj[ct+1].prio;
				}
				cout << endl;
				myf.open("schedule.txt");
				cout << "NEW SCHEDULE" << endl;
				for(int ct=0;ct<ctt-1;ct++){
				cout << proj[ct].ID << "\t" << proj[ct].title << "\t" << proj[ct].size << "\t" << proj[ct].prio << endl;
				myf << proj[ct].ID << "\t" << proj[ct].title << "\t" << proj[ct].size << "\t" << proj[ct].prio << endl;
				}
				myf.close();
				system("pause");
				break;
				}
				
	case '5' :	{
				x=0;
				break;
				}
	default : 	{
				cout << "Invalid Input, please try again" << endl;
				system("pause");
				break;
				}
}  
system("cls");
}while(x==1);
cout << "Program Closing....." ; 
}
