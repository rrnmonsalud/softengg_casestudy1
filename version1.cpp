#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <iomanip>

using namespace std;

class Details{
	int idno;
	char name [50];
	int pagesize;
	int priority;
	
	
	public:
		void createDetails(); //function that gets info from user
		void showDetails() const;   //function to show info
		int reacctno() const; //function to return acct number

		 
};


void intro()
{
	system("Color 2E");
	cout << "\t\t\t  ___ ___ _   _   _____ ___ ___ _  _   \n";
	cout << "\t\t\t | __| __| | | | |_   _| __/ __| || | \n";
	cout << "\t\t\t | _|| _|| |_| |   | | | _| (__| __ |  \n";
	cout << "\t\t\t |_| |___|\ ___/    |_| |___\ ___|_||_|  \n";
	cout<<"\t\t\n\n\n\t\t\t\t FAR EASTERN UNIVERSITY";
	cout<<"\t\t\n\n\t\t\t\t INSTITUTE OF TECHNOLOGY";

}


void Details::createDetails(){
	system("cls");

	system("Color F6");	
	cout << "==========PROJECT INFORMATION==========\n\n";
	cout << "\nEnter ID Number: "; 
	cin >> idno;
	cin.ignore();
	cout << "\nProject Title: ";
	cin.getline(name,50);
	cout << "\nEnter Page Size: ";
	cin >> pagesize;
	cout << "\nEnter Page Size: ";
	cin >> priority;
	
	//for loading screen
 	cout<<"\n\n\n\t\t\t\tCreating Project....\n\n";
 	char a=177, b=219;
 	cout<<"\t\t\t\t";
 	for (int i=0;i<=15;i++)
 	cout<<a;
 	cout<<"\r";
 	cout<<"\t\t\t\t";
 	for (int i=0;i<=15;i++)
 	{
  	cout<<b;
  	Sleep(150);
 	}
	cout << "\n\n\n\tProject Created...";
	
}

void Details::showDetails() const{
	system("Color F6");	
	cout << "\nProject No.: " << idno;
	cout << "\nProject Name: ";
	cout << name;
	cout << "\nProject Page Size: " << pagesize;
	cout << "\nProject Priority: " << priority;
}




void writeDetails(); //function to write record in file
void displayInfo(int); //function to display project info given by user



// ========================================================================== START OF MAIN =================================================================


int main(){
	intro();
	int choose;
	int num;
	int viewchoice;
	
	do{
		system("cls");
		system ("Color 0E");
		intro();

	
	cout << "\n";
	cout << "\t\t\t******************************************\n" 
		 << "\t\t\t******           M E N U            ******\n"
		 << "\t\t\t******************************************\n"
		 << "\t\t\t*        [1] Input Project Details       *\n"         
		 << "\t\t\t*        [2] View Projects               *\n" 
		 << "\t\t\t*        [3] Schedule Projects           *\n" 
		 << "\t\t\t*        [4] Get a Project            	 *\n" 
		 << "\t\t\t*        [5] Exit             	         *\n" 
		 << "\t\t\t******************************************" 
		 << "\t\t\t"
		 << std::endl;
	cout<<  "\n\n\tSelect Your Option (1-5): ";
	cin >> choose;
		switch(choose){
			
		case 1 :
			
			writeDetails();
			break;
		
			
			
			
		case 2 :{
		system("cls");
		
		system("Color F6");
		
		cout << "\n=============== VIEW PROJECTS ===============";
		cout<<"\n\n\t1. ONE PROJECT";
		cout<<"\n\n\t2. COMPLETED";
		cout<<"\n\n\t3. ALL PROJECTS";
		
		cout<<"\n\n\tSelect Your Option (1-3): ";
		cin >> viewchoice;
				system("cls");
				
				
		switch(viewchoice)	{
			case 1:
				
			cout<<"\n\nEnter project number: "; 
			cin >> num;
			displayInfo(num);
			break;
			
				
		}
			break;	

			
		}
			
			
		
		 case 5:
		 	system ("Color 0A");
			cout << "\t\t  ___ ___ _   _   _____ ___ ___ _  _   \n";
			cout << "\t\t | __| __| | | | |_   _| __/ __| || | \n";
			cout << "\t\t | _|| _|| |_| |   | | | _| (__| __ |  \n";
			cout << "\t\t |_| |___|\ ___/    |_| |___\ ___|_||_|  \n";
                                                            
			cout<<"\n\tThank You for using the program.";
			break;
		 
		}
		cin.ignore();
		cin.get();
	}while(choose!='5');
	return 0;
}

// ======================================================================= START OF FUNCTIONS =========================================================================


//function to write file
void writeDetails() {
	Details details;
	ofstream f;
	f.open("details.txt",ios::binary|ios::app);
	details.createDetails();
	f.write(reinterpret_cast<char *> (&details), sizeof(Details));
	f.close();
}

//function to read a record from file
void displayInfo (int disp){
	Details details;
	bool flag = 0;
	ifstream f;
	f.open("details.txt", ios::binary);
	if(!f){
		cout << "CANNOT OPEN FILE. Press ENTER to continue..";
		return;
	}
	cout << "\n===============PROJECT DETAILS===============";
	while (f.read(reinterpret_cast <char *> (&details), sizeof (Details))){
		if (details.reacctno() == disp){
			details.showDetails();
			flag = 1;
		}
	}
	f.close();
	if (flag == 0)
		cout << "\n\nSorry but the Account Number that you entered does not exist.";
}
	
int Details::reacctno() const{
	return idno;
}
	
