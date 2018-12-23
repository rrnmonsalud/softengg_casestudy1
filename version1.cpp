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




void writeDetails(); //function to write record in file


// ========================================================================== START OF MAIN =================================================================


int main(){
	intro();
	char choose;
	int num;
	
	do{
		system("cls");
		system ("Color 0E");
		intro();;

	
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
		switch(choose)
		{
		case '1':
			system("cls");
			
			writeDetails();
			
			break;
		
		 case '9':
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
	}while(choose!='9');
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

	

	

