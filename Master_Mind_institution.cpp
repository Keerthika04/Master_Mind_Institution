#include <iostream>		// to get input and output
#include <fstream> 		// to store inside a file
#include <string> 		// to access string datatype
#include <Windows.h> 	// to access and change the default behaivor of console
#include <stdlib.h>		// to generate random numbers
#include <sstream>		// to convert integer to string
#include <time.h>		// to generate random numbers using the current time
#include <conio.h>		// to use single character for onclick rather than using enter for each input
#include <vector>		// to store the datas from files


// Username : Admin56 , Password : 123456

using namespace std;

//struct to store student's data
struct student{
	string name;
	int phoneNo;
	string email;
	string courseName;
	string feeStatus;
}newStudent;

//struct to store courses details
struct course_detail{
	string courseName;
	int duration[2];
	int fee;
	string entryQualification;
}newCourse;

//functions
void header();
void login();
void home();
void aboutUs();
void courses();
void searchCourse();
void viewAllCourses();
void addNewCourse();
void deletecourse();
void students();
void searchStudent();
void viewAllStudents();
void addNewStudent();
void updateStudentInfo();
void deleteStudent();
void exit();

//will be used inside many functions
string filename, null;

int main(){
	
	//to set fixed size console
	HWND hWnd = GetConsoleWindow();
    RECT rect;
    GetWindowRect(hWnd, &rect);
    MoveWindow(hWnd, rect.left, rect.top, 660, 700, TRUE);
  	LONG style = GetWindowLong(hWnd, GWL_STYLE);
    style = style & ~(WS_THICKFRAME | WS_MAXIMIZEBOX);
	SetWindowLong(hWnd, GWL_STYLE, style);
	
	system("Color F8");

	login();
	return 0;
}

//login function
void login(){
	system("CLS");
	header();
	cout <<"           _________________________________________________________________________________________________________________________________________\n\n\n\n";
	 
	string username, password;
	
	cout<<"\t Enter Your Username : ";
	cin>>username;
	cout<<"\t Enter your Password : ";
	cin>>password;
	
	if (username == "Admin56" && password == "123456"){
		home();
	}else{
		cout<<"\n\t Ops! You have entered wrong password or username!!!\n\t ";
		system("PAUSE");
		login();
		
	}
}

//for ui design
void header(){
	cout<<"\n      __________________________________________________________________________________________________________________________________________________\n\n"
		<<" \t\t\t    Master Mind Institution      \t\t\t\t";
		
	
}

void course_header(){
	header();
	cout<<"\n\t\t\t\t   Courses" <<endl
		 <<"\t       _____________________________________________________________________________________________________________________________________________\n\n";
	
}

//to take back to course menu
void course_back(){
	cout <<"______________________________________________________________________________\n\n"
		 << "  Press spacebar to go back.\n"
		 <<"______________________________________________________________________________\n";
	char spacebar = _getch();
	if(spacebar == ' '){
		courses();
	}
}

void num_error(){
	cout << "\n\n\n You have entered letter instead of number for the one that requires number!!! \n   Try again!!! \n   ";
		cin.clear();
		cin.ignore();
		system("PAUSE");
		system("CLS");
}

//Home switch
void swt(){
	int num;
	cin >> num;
	switch (num){
		case 1 : aboutUs();
			break;
		
		case 2 : courses();
			break;
		
		case 3 : students();
			break;
		
		case 4 : exit();
			break; 
			
		
		default :
			if(cin.fail()){
			  num_error();
			  home();
			}else{
			 cout << "\n\t Ops! You have entered and invalid number! \n\t ";
			 system("PAUSE");
			 home();
		}
	}
}

//course switch
void swt2(){
	int num;
	cin >> num;
	switch (num){
		case 1 : searchCourse();
			break;
		
		case 2 : viewAllCourses();
			break;
		
		case 3 : addNewCourse();
			break;
		
		case 4 : deletecourse();
			break; 

		case 5 : home();
			break; 		
		default : 
			if(cin.fail()){
			  num_error();
			  courses();
			}else{
			  cout << "\n\t Ops! You have entered and invalid number! \n\t ";
			  system("PAUSE");
			  courses();
			}
	}
}

//add new switch
 void swt3(){
	system("CLS");
	system("Color 8F");
	header();
	cout <<"           _________________________________________________________________________________________________________________________________________\n\n\n\n";
	 
		cout << "\t \n Successfully saved to file!" << endl
			 <<"\t \n\n  Do you want to add again? \n  Select Any Option Using Given Numbers  \n\n"
		 	 <<"\t     => [1] Add New " <<endl
		 	 <<"\t     => [2] Back" <<endl 
			 << "\t \n\n  Select Any Option : ";
}

// searching function
void search(string filename){
	string data;
	ifstream openFile(filename.c_str());
	cout <<endl;
		if(openFile.is_open()){
			while (getline(openFile, data)) {
         	cout <<endl << data << endl;
			}
			cout << endl << endl;
	openFile.close();
	}else{
		cout << "\t Ops!!! File isn't available\n\n";
	}
}

//Home function
void home(){
	system("CLS");
	system("Color F8");
	header();
	cout<<"\n\t\t\t\t      Home" <<endl
		 <<"\t       _____________________________________________________________________________________________________________________________________________\n\n\n\n";
	
	cout <<"\t Select Any Option Using Given Numbers  \n\n"
		 <<"\t   => [1] About Us" <<endl
		 <<"\t   => [2] Courses" <<endl
		 <<"\t   => [3] Students" <<endl
	     <<"\t   => [4] Logout" <<endl
	 	 << "\n\n\t Select Your Option : ";
	swt();
}

//aboutUS function
void aboutUs(){
	system("CLS");
	header();
	cout <<"           _________________________________________________________________________________________________________________________________________\n\n\n\n";
	 
	cout << "\t\t\t\t   About Us \n\n" 
		 <<"   Master Mind Institution is an educational organization that offers training \n  programs for both local and international students. The programs are made to \n   give students the knowledge and skills they need to succeed in their chosen \n  fields of study. The institution strives to offer a top-notch education that \n   satisfies the demands of the today's job industry."
		 << "\n\n\n\t\t\t\t  Our Mission \n\n"
		 <<	"  To provide lifelong learning opportunities through flexible education with \n   a commitment to excellence in teaching and research."
		 << "\n\n\n\t\t\t\t  Our Vision\n\n"
		 <<	"  The institution aims to provide high-quality, equitable educational \n   opportunities that can make a positive impact on people's lives."
		 << "\n\n\n\t\t\t\t  Contact Us\n\n"
		 <<	" \t\tADDRESS : 178A, New Kalmunai Road, Batticaloa. \n \t\t  EMAIL : masterMindInstitution@mmicampus.edu.lk \n \t\t  PHONE : 065 5111000 \n \t\t    FAX : 065 5111000" <<endl <<endl;
		
	cout <<"______________________________________________________________________________\n\n"
		 << "  Press spacebar to go back.\n"
		 <<"______________________________________________________________________________\n";
	char spacebar = _getch();
	if(spacebar == ' '){
		home();
	}
}

//courses function
void courses(){
	
	system("CLS");
	system("Color F8");
	course_header();
	cout <<"\t Select Any Option Using Given Numbers  \n\n"
		 <<"\t   => (1) Search course details" <<endl
		 <<"\t   => (2) View all courses" <<endl
		 <<"\t   => (3) Add new course" <<endl
	     <<"\t   => (4) Delete a course" << endl
		 <<"\t   => (5) Back "
		 << "\n\n\t Select Your Option : ";
	swt2();
}

// search a Course record
void searchCourse(){
	system("CLS");
	course_header();
    cout << "\n    Enter the course ID to search: ";
    cin>>filename;
    filename = "Courses/" + filename + ".txt";
    search(filename);
	course_back();
}

//view all course records
void viewAllCourses(){
	system("CLS");
	system("Color F8");
	course_header();
	
	string data;
	ifstream openFile;
	
	//to open all files in course folder and display its data
	for(int i=1;i<99999;i++){
		stringstream ss ;
		ss << i ;
		filename = "Courses/" + ss.str() + ".txt";
		
		openFile.open (filename.c_str());
		if(openFile.is_open()){
			while (getline(openFile, data)) {
         	cout << endl << data << endl;
			}
			cout << endl << endl;
			openFile.close();
	}
  }
  course_back();
  
}

//add new course record
void addNewCourse(){
	system("CLS");
	system("Color F8");
	course_header();
	
	//to generate random number using the current time for file's name
	int num;
	srand(time(0));
	num = rand();
	
	cout << "\n   Course ID   : " << num <<endl;
	cout << "\n   Enter the Course Name : ";
	getline(cin, null);
	getline(cin, newCourse.courseName);
	cout << "   Enter the Course Duration -> \n"
		 << "\t   Full-Time : ";
	cin	>> newCourse.duration[0];
	cout << "\t   Part-Time : ";
	cin	>> newCourse.duration[1];
		cout << "   Enter the Course Fees : ";
	cin	>> newCourse.fee;
	cout << "   Enter the Course Entry Qualification : ";
	getline(cin, null);
	getline(cin, newCourse.entryQualification);
	
	if(cin.fail()){
		num_error();
		system("CLS");
		addNewCourse();
	}else{
	
	//to convert integer to string	
	stringstream ss;
	ss<<num;
	filename = "Courses/"+ ss.str() + ".txt";
	
	ofstream openFile (filename.c_str());
	if(openFile.is_open()){
		openFile << "\t Course ID   : " << num <<endl
				 << "\t Course Name : " <<newCourse.courseName<<endl
				 << "\t Course Duration (Full-Time) : " <<newCourse.duration[0] << " months"<<endl
				 << "\t Course Duration (Part-Time) : " <<newCourse.duration[1] << " months"<<endl
				 << "\t Course Fee : " << newCourse.fee <<"rs"<< endl
				 << "\t Course Entry Qualification  : " <<newCourse.entryQualification << endl ;
		
		cout << "\n\n   ";
		system("PAUSE");	 
		openFile.close();
		
		
		// want to add new function 
		swt3();
		int num;
		cin>>num;
		switch(num){
		case 1 : 
			addNewCourse();
			break;
		break;
		case 2 :
			courses();
		break;
		default : 
			cout << "\n\t Ops! You have entered and invalid number! \n\t ";
			system("PAUSE");
			swt3();
	}
	}else{
		cout << "\n\t Unable to save";
	}
 }
} 

//delete a course record
void deletecourse(){
	system("CLS");
	system("Color F8");
	course_header();
	cout << "\n    Enter the course ID to delete: ";
    cin >> filename;
	filename = "Courses/" + filename + ".txt"; 

	//deleting the file
    int status = remove(filename.c_str()); 

    if (status == 0) {
        cout << "\n\t File deleted successfully." << endl;
        course_back();
    } else { 
        cout << "\n\t Ops!!! File isn't available.\n\n\n" << endl;
        course_back();
    }
}

//Student switch
void swt4(){
	int num;
	cin >> num;
	switch (num){
		case 1 : searchStudent();
			break;
		
		case 2 : viewAllStudents();
			break;
		
		case 3 : addNewStudent();
			break;
		
		case 4 : updateStudentInfo();
			break;
		
		case 5 : deleteStudent();
			break; 

		case 6 : home();
			break; 		
		default : 
			if(cin.fail()){
			  num_error();
			  students();
			}else{
			  cout<<"\n\t Ops! You have entered wrong password or username!!!\n\t ";
			  system("PAUSE");
			  students();
			}
	}
}

//ui design
void student_header(){
	header();
	cout<<"\n\t\t\t\t   Student" <<endl
		 <<"\t       _____________________________________________________________________________________________________________________________________________\n\n";
	
}

//back to student menu
void student_back(){
	cout <<"______________________________________________________________________________\n\n";
	cout << "  Press spacebar to go back.\n";
	cout <<"______________________________________________________________________________\n";
	char spacebar = _getch();
	if(spacebar == ' '){
		students();
	}
}

//student menu
void students(){
	system("CLS");
	system("Color F8");
	student_header();
	cout <<"\t  Select Any Option Using Given Numbers  \n\n"
	  	 <<"\t   => (1) Search student details" <<endl
	  	 <<"\t   => (2) View all students detail" <<endl
		 <<"\t   => (3) Add new student" <<endl
		 <<"\t   => (4) Update student's information" <<endl
		 <<"\t   => (5) Delete student's information" <<endl
	     <<"\t   => (6) Back";
		
	cout << "\n\n\t  Select Your Option : ";
	swt4();
	
}

//search student record
void searchStudent(){
	system("CLS");
	student_header();
    cout << "\n   Enter the student ID to search: ";
    cin>>filename;
    filename = "Students/" + filename + ".txt";
   search(filename);
    
	student_back();
}

//view all student records
void viewAllStudents(){
	system("CLS");
	system("Color F8");
	student_header();
	
	string data;
	ifstream openFile;
	
	//to open all files in students folder and display its data
	for(int i=1;i<99999;i++){
		stringstream ss ;
		ss << i ;
		filename = "Students/" + ss.str() + ".txt";
		
		openFile.open (filename.c_str());
		if(openFile.is_open()){
			while (getline(openFile, data)) {
         	cout << endl << data << endl;
			}
			cout << endl << endl;
			openFile.close();
	}
  }
  student_back();
	
}

//add new student record
void addNewStudent(){
	system("CLS");
	system("Color F8");
	student_header();
	
	//to generate random number using the current time for file's name
	int num;
	srand(time(0));
	num = rand();
	
	cout << "\n   Student ID   : " << num <<endl;
	cout << "\n   Enter the Student Name : ";
	getline(cin, null);
	getline(cin, newStudent.name);
	cout << "   Enter the selected Course Name  : ";
	getline(cin, newStudent.courseName);
	cout << "   Enter their Phone Number : ";
	cin >> newStudent.phoneNo;
	cout << "   Enter their Email Address : ";
	cin >> newStudent.email;
	cout << "   Payment : ";
	getline(cin, null);
	getline(cin, newStudent.feeStatus);
	
	if(cin.fail()){
		num_error();
		addNewStudent();
	}else{
	
	//to convert integer to string
	stringstream ss;
	ss<<num;
	filename = "Students/"+ ss.str() + ".txt";
		
	ofstream openFile (filename.c_str());
	if(openFile.is_open()){
		openFile << "\t Student ID   : " << num <<endl
				 << "\t Student Name : " << newStudent.name <<endl
				 << "\t Course Selected : " << newStudent.courseName <<endl
				 << "\t Student's Phone No : " << newStudent.phoneNo <<endl
				 << "\t Student's Email : " << newStudent.email << endl
				 << "\t Payment  : " << newStudent.feeStatus << endl ; 
		
			cout << "\n\n   ";
			system("PAUSE");		 
			openFile.close();
				 
		// to add again
		swt3();
		int num;
		cin>>num;
		switch(num){
		case 1 : 
			addNewStudent();
			break;
		break;
		case 2 :
			students();
		break;
		default : 
			cout << "\n\t Ops! You have entered and invalid number! \n\t ";
			system("PAUSE");
			swt3();
		}
	}else{
		cout << "\n\t Unable to save";
	}
  }
}

//update sudent record
void updateStudentInfo(){
	system("CLS");
	system("Color F8");
	student_header();
	
  string text;
  int line_number;
  
  cout << "   Enter the Student ID to update: ";
  cin>> filename;
  
  filename = "Students/"+ filename +".txt";
  
  fstream read_file;
  
  read_file.open(filename.c_str());
  
  if (read_file.fail())
  {
    cout << "\n\t Ops! That file doesn't exist." << endl << "\n\n ";
    student_back();

  }
  
  cout <<"\n\t Select Any Option Using Given Numbers  \n\n"
	  	 <<"\t   => [1] Re-enter the student name " <<endl
	  	 <<"\t   => [3] Re-enter the student's phone no " <<endl
		 <<"\t   => [4] Re-enter the student's email " <<endl
		 <<"\t   => [5] Re-enter the student's Payment detail \n";
		 
  cout << "\n\t Your Option : ";
  cin >> line_number;
  	if(cin.fail()){
		num_error();
		addNewStudent();
	}else{
  
  vector<string> lines;
  string line;
  
  //getting the lines from file and storing it vector's "lines" 
  while (getline(read_file, line))
    lines.push_back(line);
  
  read_file.close();
  
  if (line_number > 5)
  {
    cout << "\n\t Invalid input!!!" << endl << "\t ";
    system("PAUSE");
	updateStudentInfo();

  }
  
  //Inputing the replacing text
  cout << "\t Enter the input : ";
  cin.get();
  getline(cin, text);
  
  ofstream write;
  
  write.open(filename.c_str());
  
  if (write.is_open()){
  
    //can't change the student id and the selected course
  	if(line_number == 0 || line_number ==2){
		cout<< "\t Ops You have entered an invalid number. Try again \n \t ";
		for(int i = 0; i<lines.size();i++){
				write << lines[i] <<endl;
		}
		system("PAUSE");
		updateStudentInfo();
	}else{
		//looping through lines to get the line which was requested by users to update
		for(int i = 0; i<lines.size();i++){
			if(i!=line_number){
				write << lines[i] <<endl;
			}else if(i == 1){
				write << "\t Student Name : " << text <<endl;
			}else if(i == 3){
				write << "\t Student's Phone No : " << text <<endl;
			}else if(i == 4){
				write << "\t Student's Email : " << text <<endl;
			}else{
				write << "\t Payment : " << text <<endl;
			}
		  }
		  cout << "\n\t Successfully Saved!!! \n";
		}
		  	write.close();
}else{
    cout << "\t Error opening file." << endl;
    system("PAUSE");
	updateStudentInfo();
  }
  
	student_back();
	}
}

//delete a student record
void deleteStudent(){
	system("CLS");
	system("Color F8");
	student_header();
	
	cout << "\n   Enter the Student ID to delete: ";
    cin >> filename;
	filename = "Students/" + filename + ".txt"; 
	//deleting the file
    int status = remove(filename.c_str());

    if (status == 0) {
        cout << "\n\t File deleted successfully.\n" << endl;
        student_back();
    } else { 
        cout << "\n\t Ops!!! File isn't available.\n" << endl;
        student_back();
    }
}
  

//closing console function
void exit(){
	HWND hWnd = GetConsoleWindow();
    PostMessage(hWnd, WM_CLOSE, 0, 0); 
}




