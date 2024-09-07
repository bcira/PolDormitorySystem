#include<iostream>

#include <string>

#include<fstream>

 

using namespace std;

fstream file;


class PolDorm {
	
	int room_no;
    string book_stu_name;
    string book_stu_surname;
    string book_stu_sex;
    
    
             public:
            
            
             void delete_rec(int);
             
             
             string stu_name;
             string stu_surname;
             string stu_sex;
             string stu_username;
             string stu_password;
             
             string sec_name;
             string sec_surname;
             string sec_username;
             string sec_password;
             
            
             //int room_no;
             
             int edit_room_no;
             int edit_number;
             int edit_available;
             
             

             	
             int choice;//register or login?
             int choi;//manager or student?
             int gbchoi;//add to girl or boy room
             int dchoi;//display girl or boy room

             
             string username,password,un,pw;

             //menu

             void menu(){
             cout<<"\n\n\n\n\t\t\t\t*************";
    		 cout<<"* POL DORMITORY SYSTEM *";
			 cout<<"*************\n";

            

             cout<<"\n\t\t\t\t\t\t1. Register"<<endl;
             cout<<"\n\t\t\t\t\t\t2. Login"<<endl;
             cout<<"\n\t\t\t\t\t\t3. Exit"<<endl;
             cout<<"\n\t\t\t\t\t\t Choose an option: "<<endl;
             cin>>choice;
             switch(choice){
             	
       				case 1: reg();
               				 break;

        			case 2: log();
               				 break;
                    
                    case 3: break;
        			default: cout<<"\n Wrong Choice!!";

    }
    }//menu end

    //log start

   void log(){
   	
             cout<<"\n\t\t\t\t\t\t1. Manager"<<endl;
             cout<<"\n\t\t\t\t\t\t2. Student"<<endl;
             cout<<"\n\t\t\t\t\t\t Choose an option: "<<endl;

             cin>>choi;

            

             switch(choi){

        		case 1: manager_log();

             			break;

				case 2: student_log();
						
						 break;

        		default: cout<<"\n Wrong Choice!!";
}
}//log end

//reg
void reg(){

             cout<<"\n\t\t\t\t\t\t1. Manager"<<endl;
             cout<<"\n\t\t\t\t\t\t2. Student"<<endl;
             cout<<"\n\t\t\t\t\t\t Choose an option: "<<endl;
             cin>>choi;
             
             switch(choi){

 					case 1: manager_reg();
							break;
								
					case 2: student_reg();
					
               				 break;
				    default: cout<<"\n Wrong Choice!!";

}

}//reg end

//func. of checking login inputs

//student login

void student_log(){

             
        int count = 0;
    	string line;
        string uname, pword;
        int i=0;
        cout << "enter username: " << endl;
        cin >> uname;
        cout << "enter password: " << endl;
        cin >> pword;
        ifstream file("Student.txt",ios::in);
        
        if (file.is_open())
        {
            while (!file.eof())
            {
        		
				file>>stu_name>>stu_surname>>stu_sex>>stu_username>>stu_password;
				
               if (uname == stu_username && pword == stu_password)
               {
                
                    cout << "Login successfully." << endl;
                    cout<<stu_name<<"\t"<<stu_surname<<"\t"<<stu_sex<<"\t"<<stu_username<<"\t"<<stu_password;
                    
                  break; 
                }
                
                else
                {
					 continue;
                }
           
            
        }}

    }

        



//manager login

void manager_log(){

    
        int count = 0;
        string uname, pword;
        int i=0;
        cout << "enter username: " << endl;
        cin >> uname;
        cout << "enter password: " << endl;
        cin >> pword;
        ifstream file("Secretary.txt",ios::in);
        
        if (file.is_open())
        {
            while (!file.eof())
            {
        		
				file>>sec_name>>sec_surname>>sec_username>>sec_password;
				
               if (uname == sec_username && pword == sec_password)
               {
                
                    cout << "Login successfully." << endl;
                    cout<<sec_name<<"\t"<<sec_surname<<"\t"<<sec_username<<"\t"<<sec_password;
                    
                  break; 
                }
                
                else
                {
					 continue;
                }
           
            
        }}
        sec_menu();

}//manager login end

 

//student registration

void student_reg(){

             int i=0;
             cout<<"\n\t\t\t\t\t\t Name:";cin>>stu_name;
             cout<<"\n\t\t\t\t\t\t Surname:";cin>>stu_surname;
             cout<<"\n\t\t\t\t\t\t Sex:";cin>>stu_sex;
             cout<<"\n\t\t\t\t\t\t Select an username:";cin>>stu_username;
             cout<<"\n\t\t\t\t\t\t Select a password:";cin>>stu_password;

             ofstream file;
             file.open("Student.txt",ios::binary|ios::app);
             file<<stu_name<<"\t"<<stu_surname<<"\t"<<stu_sex<<"\t"<<stu_username<<"\t"<<stu_password<<endl;
             file.close();

            

}//student registration end

//manager registration

void manager_reg(){


             cout<<"\n\t\t\t\t\t\t Name:";cin>>sec_name;
             cout<<"\n\t\t\t\t\t\t Surname:";cin>>sec_surname;
             cout<<"\n\t\t\t\t\t\t Select an username:";cin>>sec_username;
             cout<<"\n\t\t\t\t\t\t Select a password:";cin>>sec_password;

             ofstream file;
             file.open("Secretary.txt",ios::binary|ios::app);
             file<<sec_name<<"\t"<<sec_surname<<"\t"<<sec_username<<"\t"<<sec_password<<endl;
             file.close();
             

}//manager registration end

//room_reg
void room_reg(){
	
             cout<<"\n\t\t\t\t\t\t Name:";cin>>book_stu_name;
             cout<<"\n\t\t\t\t\t\t Surname:";cin>>book_stu_surname;
             cout<<"\n\t\t\t\t\t\t Enter student sex:";cin>>book_stu_sex;
             cout<<"\n\t\t\t\t\t\t Enter room no:";cin>>room_no;

             ofstream file;
             file.open("Student_room.txt",ios::binary|ios::app);
             file<<book_stu_name<<"\t"<<book_stu_surname<<"\t"<<book_stu_sex<<"\t"<<room_no<<endl;
             file.close();
             
             if(book_stu_sex == "girl") {
    			ifstream file("Girl_Room.txt",ios::in);
    			if(file.is_open()){

				while (!file.eof())
            {
        		
				file>>edit_room_no>>edit_number>>edit_available;
				
               if (room_no == edit_room_no){
			   
			   cout<<edit_available<<endl;
			   edit_available--; 
        	   cout<<edit_available<<endl;   
        	   
			   
			    ofstream file;
				file.open("Girl_Room.txt",ios::binary|ios::app);
                file<<edit_room_no<<"\t"<<edit_number<<"\t"<<edit_available<<endl;
                file.close();
        		
				break;		
				}
				
				}
							}
					
			} 
		
}//room_reg end


//edit rooms
void edit_rooms(){
	
			 cout<<"\n\t\t\t\t\t\t Do you want to add to girl room(1) or boy room(2): ";cin>>gbchoi;
			 
			 if(gbchoi == 1){
		     cout<<"\n\t\t\t\t\t\t Enter room no:";cin>>edit_room_no;
             cout<<"\n\t\t\t\t\t\t Enter people number:";cin>>edit_number;
             cout<<"\n\t\t\t\t\t\t Enter available number:";cin>>edit_available;

             ofstream file;
             file.open("Girl_Room.txt",ios::binary|ios::app);
             file<<edit_room_no<<"\t"<<edit_number<<"\t"<<edit_available<<endl;
             file.close();
			 }
			 else if(gbchoi == 2){
			 cout<<"\n\t\t\t\t\t\t Enter room no:";cin>>edit_room_no;
             cout<<"\n\t\t\t\t\t\t Enter people number:";cin>>edit_number;
             cout<<"\n\t\t\t\t\t\t Enter available number:";cin>>edit_available;

             ofstream file;
             file.open("Boy_Room.txt",ios::binary|ios::app);
             file<<edit_room_no<<"\t"<<edit_number<<"\t"<<edit_available<<endl;
             file.close();
			 }
			 else{
			 	cout<<"Please enter 1 or 2"<<endl;
			 	edit_rooms();
			 }
	
			
	
}//edit rooms end

//display rooms
void display_rooms(){
	
	cout<<"\n\t\t\t\t\t\t Do you want to display girl room(1) or boy room(2): ";cin>>dchoi;
	
	if(dchoi == 1)
	{
	ifstream file("Girl_Room.txt",ios::in);
	if (file.is_open())
        {
        	
        while (!file.eof()){
        	
		file>>edit_room_no>>edit_number>>edit_available; 
		if( file.eof() )
        break;
        
        if(edit_available!=0){
        	cout<<edit_room_no<<"\t"<<edit_number<<"\t"<<edit_available<<endl;
		}	
		}	
		
		}	
	}
	else if(dchoi == 2){
		ifstream file("Boy_Room.txt",ios::in);
	if (file.is_open())
        {
        	
        while (!file.eof()){
        	
		file>>edit_room_no>>edit_number>>edit_available; 
		if( file.eof() )
        break;
        
        if(edit_available!=0){
        	cout<<edit_room_no<<"\t"<<edit_number<<"\t"<<edit_available<<endl;
		}	
		}	
		
		}
	}
	else{
		cout<<"Please enter 1 or 2"<<endl;
		display_rooms();
	}
	
	
}//display rooms end


//delete function

void delete_rec( )
{
int r;
int flag=0;
char ch;
ifstream fin("Student_room.txt",ios::in);
ofstream fout("temp.txt",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(PolDorm));
file>>book_stu_name>>book_stu_surname>>book_stu_sex>>room_no; 
	cout<<"enter r: ";cin>>r;

if(room_no==r)

{

cout<<"\n Name: "<<book_stu_name;
cout<<"\n Surname: "<<book_stu_surname;
cout<<"\n Sex: "<<book_stu_sex;
cout<<"\n Room no: "<<room_no;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(PolDorm));
flag=1;

}

else
fout.write((char*)this,sizeof(PolDorm));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";

else
{

remove("Student_room.txt");
rename("temp.txt","Student_room.txt");

}

}


//END OF DELETE FUNCTION







/*
//delete student record


void del_rec(int r){
	//int r;
	int flag=0;
	char ch;
	ifstream fin("Student_room.txt",ios::in);
	ofstream fout("temp.txt",ios::out);
	
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(*this));
		file>>book_stu_name>>book_stu_surname>>book_stu_sex>>room_no; 
		cout<<"enter r: ";cin>>r;
		if(room_no==r)
		{
			cout<<"\n Name: " <<book_stu_name;
			cout<<"\n Surname: " <<book_stu_surname;
			cout<<"\n Sex: " <<book_stu_sex;
			cout<<"\n Room no: " <<room_no;
			
			
			cout<<"\n\n Do you want to delete this record(y/n): ";
			cin>>ch;
			
			if(ch=='n')
			fout.write((char*)this,sizeof(*this));
			
			flag=1;
		}
		else
			fout.write((char*)this,sizeof(*this));
	}
	
	fin.close();
	fout.close();
	
	if(flag==0)
		cout<<"\n Sorry room no. not found or vacant!!";
	else
	{
		remove("Student_room.txt");
		rename("temp.txt","Student_room.txt");
		
		return 0;
}
//delete student record end */

//secretary menu
void sec_menu(){
	         cout<<"\n\t\t\t\t\t\t1. Book a Room"<<endl;
             cout<<"\n\t\t\t\t\t\t2. Display Rooms"<<endl;
             cout<<"\n\t\t\t\t\t\t3. Edit Rooms"<<endl;
             cout<<"\n\t\t\t\t\t\t4. Display Student Information"<<endl;
             cout<<"\n\t\t\t\t\t\t5. Edit Student Information"<<endl;
             cout<<"\n\t\t\t\t\t\t6. Delete Student Record"<<endl;
             
             cout<<"\n\t\t\t\t\t\t   Enter your choice: ";
             
             cin>>choice;
             switch(choice){
             	
       				case 1: room_reg();
               				 break;

        			case 2: display_rooms();
               				 break;
               				 
               		case 3: edit_rooms();
               				 break;

        			case 4: ;
               				 break;
								
				    case 5: ;
               				 break;	 
               				 
               		case 6: delete_rec( );
               				 break;
                
        			default: cout<<"\n Wrong Choice!!";
}//secretary menu end

}

};

int main(){

             PolDorm pol; 
             pol.menu();
             return 0;
}

