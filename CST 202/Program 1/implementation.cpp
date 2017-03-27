/*
   Bikesh Maharjan
   CS 202
   PROGRAM 1
   IMPLEMENTATION.CPP- IMPLEMENTS ALL THE FUNCTIONS AND FUNCTION MEMBER OF CLASSES
*/

//INCLUDING MAINCLASS.H
#include "mainclass.h"
using namespace std;


//FUNCTION FOR WELCOME
void welcome()
{
      cout<<endl<<"*********WELCOME TO ClOUD PRESENTATION**********";
      cout<<endl<<"*************BY BIKESH MAHARJAN**************"<<endl<<endl;
}

//IMPLEMENTING MEMBER FUNCTION OF CLASS APPLICATION
int application::input()
{
      //CREATING CHARACTER VARIABLES
      char usern[100];
      char passn[100];
      
      cout<<"ENTER YOUR USERNAME: ";
      cin.get(usern,100,'\n');     //GETTING USERNAME FROM USER
      cin.ignore(101,'\n');        //ISTREAM IGNORE
      
      username = NULL;                       //INITIALISING DATA FOR USERNAME
      username = new char[strlen(usern)+1];  //ALLOCATING NEW CHAR
      strcpy(username, usern);               //COPYING DATA
      
      cout<<"ENTER YOUR PASSWORD: ";
      cin.get(passn,100,'\n');     //GETTING PASSWORD FROM USER
      cin.ignore(101,'\n');        //ISTREAM IGNORE
      
      password = NULL;                       //INITIALISING DATA FOR PASSWORD
      password = new char[strlen(passn)+1];  //ALLOCATING NEW CHAR
      strcpy(password,passn);                //COPYING DATA
}

//IMPLEMENTING MEMBER FUNCTION OF CLASS APPLICATION TO ADD
int application::add()
{
    //CREATING VARIABLES TO ADD DIFFERENT TYPES OF DATA
    email data1;               
    datafiles data2;
    browser data3;
    
    //CREATING INTEGER VARIABLE
    int choice;
    
    //DO WHILE LOOP
    do
    {
         cout<<endl<<"ENTER WHICH DATA TO ADD"<<endl;
         cout<<"1. EMAIL"<<endl;
         cout<<"2. DATA FILES"<<endl;
         cout<<"3. BROWSER"<<endl;
         cout<<"4. EXIT"<<endl;
         cout<<endl<<"PLEASE CHOOSE: ";
         
         //GETTING THE CHOICE OF THE USER
         cin>>choice;
         cin.ignore();                               //ISTREAM IGNORE
         
         //IF STATEMENT
         if(choice==1)
               data1.adding();        
         if(choice==2)
               data2.adding();
         if(choice==3)
               data3.adding();     
    }while(choice<1 && choice>3); 
}

//CLASS MEMBER FUNCTION TO REMOVE
int application::remove()
{
    //CREATING VARIABLES TO REMOVE DIFFERENT TYPES OF DATA
    email data1;
    datafiles data2;
    browser data3;
    
    //CREATING INTEGER VARIABLE
    int choice;
    
    //DO WHILE LOOP
    do
    {
         cout<<endl<<"ENTER WHICH DATA TO REMOVE"<<endl;
         cout<<"1. EMAIL"<<endl;
         cout<<"2. DATA FILES"<<endl;
         cout<<"3. BROWSER"<<endl;
         cout<<"4. EXIT"<<endl;
         cout<<endl<<"PLEASE CHOOSE: ";
    
         //GETTING THE USERS CHOICE
         cin>>choice;
         cin.ignore();             //ISTREAM IGNORE
         
         //IF STATEMENT
         if(choice==1)
               data1.removing();        
         if(choice==2)
               data2.removing();
         if(choice==3)
               data3.removing();     
    }while(choice<1 && choice>3); 
}

//MEMBER FUNCTION TO SEARCH
int application::search()
{
    //CREATING DATA VARIABLES TO SEARCH
    email data1;
    datafiles data2;
    browser data3;
    
    //CREATING INTEGER VARIABLE TO GET THE CHOICE OF THE USER
    int choice;
    
    //DO WHILE LOOP
    do
    {
         cout<<endl<<"ENTER WHICH DATA TO SEARCH"<<endl;
         cout<<"1. EMAIL"<<endl;
         cout<<"2. DATA FILES"<<endl;
         cout<<"3. BROWSER"<<endl;
         cout<<"4. EXIT"<<endl;
         cout<<endl<<"PLEASE CHOOSE: ";
    
         //GETTING THE USERS CHOICE
         cin>>choice;
         cin.ignore();             //ISTREAM IGNORE
         
         if(choice==1)
               data1.searching();        
         else if(choice==2)
               data2.searching();
         else if(choice==3)
               data3.searching();     
    }while(choice<1 && choice>3); 
}


//MEMBER FUNCTION TO DISPLAY
int application::display()
{
    //CREATING VARIABLES OF DATA TYPES
    email data1;
    datafiles data2;
    browser data3;
    
    //CREATING INTEGER VARIABLE
    int choice;
    
    do
    {
         cout<<endl<<"ENTER WHICH DATA TO DISPLAY"<<endl;
         cout<<"1. EMAIL"<<endl;
         cout<<"2. DATA FILES"<<endl;
         cout<<"3. BROWSER"<<endl;
         cout<<"4. EXIT"<<endl;
         cout<<endl<<"PLEASE CHOOSE: ";
    
         cin>>choice;
         cin.ignore();
         
         if(choice==1)
               data1.displaying();        
         else if(choice==2)
               data2.displaying();
         else if(choice==3)
               data3.displaying();     
    }while(choice<1 && choice>3); 
}

//DEFAULT CONSTRUCTOR
email::email()
{
     emailname= NULL;
}

//DEFAULT DESTRUCTOR
email::~email()
{
     delete []emailname;
     delete emailname;
}
             
//MEMBER FUNCTION TO ADD             
int email::adding()
{
      data data2;                 //CREATING A VARIABLE FOR STRUCT DATA
      
      char itemname[100];         //ARRAY OF CHARACTERS
        
      cout<<"ENTER A EMAIL: ";
      cin.get(itemname,100,'\n'); //GETTING DATA FROM USER
      cin.ignore(101,'\n');       //ISTREAM IGNORE
     
      data2.itemname = NULL;      //INITIALIZING THE VALUE
      data2.itemname = new char[strlen(itemname)+1]; //ALLOCATING NEW CHAR 
      strcpy(data2.itemname, itemname);              //COPYING THE DATA
      
      add(data2);               //CALLING THE FUNCTION
       
      cout<<endl<<"DATA ADDED"<<endl;
}

//MEMBER FUNCTION TO REMOVE
int email::removing()
{
       //CALLING THE FUNCTION REMOV TO REMOVE ALL EMAILS
       remov();
}

//MEMBER FUNCTION TO SEARCH             
int email::searching()
{
        //CALLING THE SEARCHFILE TO GET NAME AND SEARCH
        searchfile();
}

//MEMBER FUNCTION TO DISPLAY
int email::displaying()
{
        //CALLING THE DISPLAY FUNCTION TO DISPLAY DATA
        display();
}

//DEFAULT CONSTRUCTOR
datafiles::datafiles()
{
                      
     datafilename = NULL;
}

//DEFAULT DESTRUCTOR
datafiles::~datafiles()
{
     delete []datafilename;
     delete datafilename;
}
             
//MEMBER FUNCTION TO ADD
int datafiles::adding()
{
      data data2;                 //CREATING A VARIABLE FOR STRUCT DATA
      
      char itemname[100];         //ARRAY OF CHARACTERS
        
      cout<<"ENTER THE NAME: ";
      cin.get(itemname,100,'\n'); //GETTING DATA FROM USER
      cin.ignore(101,'\n');       //ISTREAM IGNORE
     
      data2.itemname = NULL;      //INITIALIZING THE VALUE 
      data2.itemname = new char[strlen(itemname)+1]; //ALLOCATING NEW CHAR 
      strcpy(data2.itemname, itemname); //COPYING THE DATA
      
      add(data2);               //CALLING THE FUNCTION
       
      cout<<endl<<"DATA ADDED"<<endl;
         
}

//MEMBER FUNCTION TO REMOVE
int datafiles::removing()
{
       remov();                 //CALLING FUNCTION TO REMOVE SPECIFIED DATA
}
             
//MEMBER FUNCTION TO SEARCH
int datafiles::searching()
{
    
        searchfile();           //CALLING FUNCTION TO SEARCH FILE
}

//MEMBER FUNCTION TO DISPLAY
int datafiles::displaying()
{
        display();              //CALLING FUNCTION TO DISPLAY
}


//DEFAULT CONSTRUCTOR
browser::browser()
{
     browsername = NULL;         //INITIALISING THE NAME TO NULL         
}

//DEFAULT DESTRUCTOR
browser::~browser()
{
     delete []browsername;
     delete browsername;
}
             
//MEMBER FUNCTION TO ADD
int browser::adding()
{
      data data2;                 //CREATING A VARIABLE
      
      char itemname[100];         //ARRAY OF CHARACTERS
        
      cout<<"ENTER THE NAME: ";
      cin.get(itemname,100,'\n'); //GETTING DATA FROM USER
      cin.ignore(101,'\n');       //ISTREAM IGNORE
     
      data2.itemname = NULL;      //INITIALIZING THE VALUE 
      data2.itemname = new char[strlen(itemname)+1]; //ALLOCATING NEW CHAR 
      strcpy(data2.itemname, itemname); //COPYING THE DATA
      
      add(data2);               //CALLING THE FUNCTION
       
      cout<<endl<<"DATA ADDED"<<endl;
         
}

//MEMBER FUNCTION TO REMOVE
int browser::removing()
{
     remov();
}
             
//MEMBER FUNCTION TO SEARCH FILE
int browser::searching()
{
        searchfile();
}

//MEMBER FUNCTION TO DISPLAY
int browser::displaying()
{
        display();
}

//FUNCTION TO DISPLAY DATA
void displaydatas(data &datas)
{
     //DISPLAYING ALL THE DATA
     cout<<endl<<"ITEM NAME: "<<datas.itemname<<endl;
}


//FUNCTION TO COPY ALL THE USER SUBMITTED DATA
void copy(data &copyfrom, data &tocopy)
{    
     tocopy.itemname = NULL;     //INITIALIZING THE VALUE TO NULL
     tocopy.itemname = new char[strlen(copyfrom.itemname)]; //ALLOCATING CHAR
     strcpy(tocopy.itemname, copyfrom.itemname);
}

//FUNCTION TO REMOVE DATA
void remov()
{
    operate data;        //CREATING VARIABLE
    data.~operate();     //CALLING THE DESTRUCTOR
    cout<<endl<<"DATA REMOVED"<<endl;
}


//FUNCTION TO GET NAME FROM THE USER AND SEARCH IT
void searchfile()
{
    key userdata;     //VARIABLE FOR STRUCTURE KEY
    data sdata;       //VARIABLE FOR STRUCTURE DATA
    
    operate process;     //VARIABLE OF CLASS
    int sign = 0;     //DECLARING AND INITIALIZING THE VALUE 
    
    char itemname[100];  //DECLARING A CHARACTER VARIABLE
    
    cout<<"ENTER DATA TYPE: ";
    cin.get(itemname, 100, '\n');    //GETTING DATA TYPE NAME
    cin.ignore(101,'\n');         //ISTREAM IGNORE
    
    userdata.itemname = NULL;   //INITIALIZING THE THE VALUE TO NULL
    userdata.itemname = new char[strlen(itemname)+1]; //ALLOCATING NEW CHAR
    strcpy(userdata.itemname, itemname); //COPYING DATA
        
    sign = process.search(userdata, sdata); //CHECK IF SEARCHING IS OK
  
    if(sign == 0)
    {
         cout<<"NO MATCH";
    }
    else
    {
         displaydatas(sdata);     //DISPLAYING DATA IF SEARCH IS FOUND 
    }
}


//FUNCTION TO REMOVE DATA
void removedata(data &datas)
{
     //DEALLOCATING AND SETTING VALUES TO NULL
     
     delete []datas.itemname;   
     datas.itemname = NULL;
}


//DEFAULT CONSTRUCTOR
operate::operate()
{
     //INITIALIZING THE VALUE TO NULL       
     root = NULL;           
}

//DEFAULT DESTRUCTOR
operate::~operate()
{
       remove(root);              //CALLING THE FUNCTION TO REMOVE ALL THE DATA      
}

//CLASS MEMBER FUNCTION TO ADD DATA
int operate::add(data &datas)
{
      //CALLING THE FUNCTION TO ADD DATA   
      add(root,datas);
      
	  return 0;
}


//MEMBER FUNCTION TO ADD DATA USING RECURSION
int operate::add(node *&root, data &empty)
{
   //IF STATEMENT 
   if (root == NULL)                  //WHEN ROOT IS NULL
   {
       root = new node;               //ALLOCATING NEW NODE
       copy(empty, root->value);      //COPYING THE DATA BY CALLING THE FUNCTION
       root->left = NULL;             //SETTING THE LEFT PART TO NULL
       root->right = NULL;            //SETTING THE RIGHT PART TO NULL
       return 1;
   }
   else
   {
       //COMPARING THE USER DATA AND THE STORED DATA 
       int compareResult = strcmp(empty.itemname, root->value.itemname);

      //COMPARING NAMES IF THEY ARE SAME
      if (compareResult == 0)
      {
          compareResult = strcmp(empty.itemname, root->value.itemname);
      }
   
      //RETURNING IF BOTH THE DATAS ARE SAME
      if (compareResult == 0)
      {
         return 1;
      }
   
      //ADDING DATA TO LEFT NODE IF DATA IS LESS
      if (compareResult > 0)
      {
          add(root->left, empty);       
      }
   
      //ADDING DATA TO RIGHT IF DATA IS MORE
      else if (compareResult < 0)
      {
          add(root->right, empty);       
      }
   }
   return 0;
}

//CLASS MEMBER FUNCTION TO DISPLAY
int operate::display()
{
    //CALLING THE FUNCTION TO DISPLAY
    display(root);
    return 0;
}

//MEMBER FUNCTION TO DISPLAY THE DATA USING RECURSION
int operate::display(node *root)
{
     if(root)
     {
             display(root->left);
             displaydatas(root->value);
             display(root->right);
     }

     return 0;
}

//MEMBER FUNCTION TO REMOVE DATA USING RECURSION
int operate::remove(node *&root)
{
     if(root)
     {
             remove(root->left);         //MOVING TO LEFT
             remove(root->right);        //MOVING TO RIGHT
             removedata(root->value);    //REMOVING DATA
             
             delete root;                //DELETING THE ROOT
             root = NULL;                //SETTING THE ROOT VALUE TO NULL
     }
     return 0;
}

//CLASS MEMBER FUNCTION TO SEARCH DATA
int operate::search( key &datauser, data &copy)
{
    int sign = 0;            //DECLARING AND INITIALIZING THE SIGN VALUE TO NULL
    sign = search(root, datauser, copy); //SETTING THE VALUE FOR CHECKING  

    if(sign == 0)
    {
        return 0;
    }
    else
        return 1;
}

//MEMBER FUNCTION USING RECURSION TO SEARCH DATA
int operate::search(node *root, key &userdata, data &value)
{  
   //DECLARING AND SETTING THE VALUE TO CHECK IF SEARCH IS FOUND OR NOT 
   int compareResult = strcmp(root->value.itemname, userdata.itemname);
   
   
   if(!root)
        return 0;
   else if(compareResult == 0)
   {
       //COMPARING THE RESULT IF NAMES ARE SAME
       compareResult = strcmp(value.itemname, userdata.itemname);
   }
   

   if (compareResult == 0)
   {
        //COPYING THE VALUE TO DISPLAY             
        copy(root->value, value); 
        return 1;
   }
   else if (compareResult > 0)
   {
          //MOVING TO LEFT IF DATA IS NOT FOUND        
          search(root->left, userdata, value);
   }            
   else 
   {
          //MOVING TO RIGHT IF DATA IS NOT YET FOUND
          search(root->right, userdata, value);
   }
}
