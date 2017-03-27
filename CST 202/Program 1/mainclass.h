/*
   BIKESH MAHARJAN
   CS 202
   PROGRAM 1
   MAINCLASS.H- DECLARES ALL THE FUNCTIONS AND FUNCTION MEMBER OF THE CLASSES
*/

//INPUT AND OUTPUT STANDARD LIBRARY
#include <iostream>
using namespace std;

//CREATING THE CLASS APPLICATION 
class application
{
      //PUBLIC MEMBERS
      public:
             int input();       //FUNCTION TO GET USERDATA FOR LOGIN 
             int add();         //FUNCTION TO ADD DATA
             int remove();      //FUNCTION TO REMOVE DATA           
             int search();      //FUNCTION TO SEARCH
             int display();     //FUNCTION TO DISPLAY
      
      //PROTECTED DATAS
      protected:
             char  *username;   //CHAR DATA MEMBER FOR USERNAME  
      
      //PRIVATE DATAS
      private:
              char  *password;  //CHAR DATA MEMBER FOR PASSWORD
      
};

//DECLARATION OF STRUCTURE KEY TO STORE THE VALUE ENTERED BY THE USER
struct key
{
    char *itemname;          //DYNAMICALLY ALLOCATED ARRAY FOR ITEM NAME        
};


//DECLARATION OF STRUCTURE DATA FOR STORING DATA FOR USE OF SEARCHING
struct data
{
      char *itemname;        //DYNAMICALLY ALLOCATED ARRAY FOR ITEM NAME 
};


//DECLARATION OF STRUCTURE NODE
struct node  
{
      data  value;              //CREATING A VARIABLE FOR STRUCT DATA
      node *left;               //CREATING A POINTER VARIABLE OF THE NODE
      node *right;              //CREATING A POINTER VARIABLE OF THE NODE
};


//CREATING THE BASE CLASS OPERATE
class operate
{
      //PUBLIC DATA MEMBERS
      public:
            operate();                    //DEFAULT CONSTRUCTOR
            ~operate();                   //DEFAULT DESTRUCTOR
            int add( data &);             //MEMBER FUNCTION TO ADD DATA
            int search( key &, data &);   //MEMBER FUNCTION TO SEARCH DATA
            int remove(node *&root);      //MEMBER FUNCTION TO REMOVE THE DATA
            int display();                //MEMBER FUNCTION TO DISPLAY ALL DATA
      
      //PRIVATE DATA MEMBERS      
      private:
            node *root;                      //ROOT POINTER VARIABLE 
            int add(node *&root, data &);    //FOR RECURSION TO ADD
            int remove(node *&root, key &);  //FOR RECURSION TO REMOVE
            int search(node *root, key &, data &); //FOR RECURSION TO SEARCH
            int display(node *root);         //FOR RECURSION TO DISPLAY
};

//SUBCLASS EMAIL OF CLASS OPERATE
class email:public operate
{
      //PUBLIC DATA MEMBERS
      public:
             email();                       //DEFAULT CONSTRUCTOR
             ~email();                      //DEFAULT DESTRUCTOR
             int adding();                  //MEMBER FUNCTION TO ADD
             int removing();                //MEMBER FUNCTION TO REMOVE
             int searching();               //MEMBER FUNCTION TO SEARCH
             int displaying();              //MEMBER FUNCTION TO DISPLAY
      
      //PRIVATE DATA MEMBERS
      private:
              char *emailname;             
              
};


//SUBCLASS DATAFILES OF CLASS OPERATE
class datafiles:public operate
{
      //PUBLIC DATA MEMBERS
      public:
             datafiles();                    //DEFAULT CONSTRUCTOR
             ~datafiles();                   //DEFAULT DESTRUCTOR
             int adding();                   //MEMBER FUNCTION TO ADD
             int removing();                 //MEMBER FUNCTION TO REMOVE
             int searching();                //MEMBER FUNCTION TO SEARCH
             int displaying();               //MEMBER FUNCTION TO DISPLAY
      
      //PRIVATE DATA MEMBERS
      private:
              char *datafilename;
};



//SUBCLASS BROWSER OF CLASS OPERATE
class browser:public operate
{
      //PUBLIC DATA MEMBERS
      public:
             browser();                //DEFAULT CONSTRUCTOR
             ~browser();               //DEFAULT DESTRUCTOR
             int adding();             //FUNCTION TO ADD
             int removing();           //FUNCTION TO REMOVE
             int searching();          //FUNCTION TO SEARCH
             int displaying();         //FUNCTION TO DISPLAY
             
      //PRIVATE DATA MEMBERS       
      private:
              char *browsername;
};


//DECLARING FUNCTIONS
void welcome();                         //FUNCTION TO WELCOME APPLICATION USERS
void displaydatas(data &);              //FOR DISPLAYING DATA 
void copy(data &copyfrom, data &tocopy);//FUNCTION TO COPY THE USER DATA
void remov();                            //FUNCTION TO REMOVE DATA
void searchfile();                       //FUNCTION TO SEARCH
void remove(data &datas);               //TO DEALLOCATE DATA
