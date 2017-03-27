/*
   BIKESH MAHARJAN
   CS 202
   PROGRAM 2
   MAINCLASS.H- DECLARES ALL THE FUNCTIONS AND FUNCTION MEMBER OF THE CLASSES
*/

#include<iostream>
using namespace std;


//CREATING STRUCTURE FOR NODE
struct node
{
      char *data;                          //DYNAMICALLY ALLOCATED ARRAY
      char **datas;                        //FOR LLL OF ARRAY
      node *next;                          //FOR NEXT POINTER
      node *prev;                          //FOR PREVIOUS POINTER
};


//CREATING CLASS LAPTOP FOR STORING FILES IN LAPTOP
class laptop
{
      //PUBLIC MEMBER FUNCTIONS
      public:
             laptop();                     //DEFAULT CONSTRUCTOR   
             ~laptop();                    //DEFAULT DESTRUCTOR
             int adddata(char *);          //MEMBER FUNCTION TO ADD DATA
             int removedata(char *);       //MEMBER FUNCTION TO REMOVE DATA
             int displaydata();            //MEMBER FUNCTION TO DISPLAY DATA
             int editdata(char *, char *); //MEMBER FUNCTION TO EDIT DATA 
      
      //PROTECTED DATA MEMBERS
      protected:
             node *head;                    
};


//CREATING SUBCLASS LAPTOP FOR CREATING INHERITANCE AND DIVIDING WORK
class sublaptop:public laptop
{
      //PUBLIC MEMBER FUNCTIONS
      public:
             sublaptop();                  //DEFAULT CONSTRUCTOR
             ~sublaptop();                 //DEFAULT DESTRUCTOR
             int add();                    //MEMBER FUNCTION TO ADD
             int remove();                 //MEMBER FUNCTION TO REMOVE
             int display();                //MEMBER FUNCTION TO DISPLAY
             int edit();                   //MEMBER FUNCTION TO EDIT
             
      //PROTECTED DATA MEMBERS       
      protected:
             char *data;
};


//CLASS TABLET TO STORE DATA IN TABLET
class tablet
{
      //PUBLIC MEMBER FUNCTIONS
      public:
             tablet();                      //DEFAULT CONSTRUCTOR
             ~tablet();                     //DEFAULT DESTRUCTOR
             int adddata(int, char *);      //MEMBER FUNCTION TO ADD DATA
             int removedata(int);           //MEMBER FUNCTION TO REMOVE DATA
             int displaydata();             //MEMBER FUNCTION TO DISPLAY DATA
             int editdata(char *, char *);  //MEMBER FUNCTION TO EDIT DATA
      
      //PROTECTED DATA MEMBERS
      protected:
             node *head2;         
             int size;
};


//SUBCLASS OF TABLET TO INHERIT PUBLIC DATA MEMBERS FOR DIVIDING WORK
class subtablet:public tablet
{
      //PUBLIC MEMBER FUNCTION
      public:
             subtablet();                   //DEFAULT CONSTRUCTOR
             ~subtablet();                  //DEFAULT DESTRUCTOR
             int add();                     //FUNCTION TO ADD
             int remove();                  //FUNCTION TO REMOVE
             int display();                 //FUNCTION TO DISPLAY
             int edit();                    //FUNCTION TO EDIT
             
      //PROTECTED DATA MEMBERS       
      protected:
             char *data;
};

//CLASS USB TO STORE DATA IN USB
class usb
{
      //PUBLIC MEMBER FUNCTIONS
      public:
             usb();                         //DEFAULT CONSTRUCTOR
             ~usb();                        //DEFAULT DESTRUCTOR 
             int adddata(int key, char *);  //MEMBER FUNCTION TO ADD DATA 
             int removedata(int key);       //MEMBER FUNCTION TO REMOVE DATA
             int displaydata();             //MEMBER FUNCTION TO DISPLAY DATA
             int editdata(char *, char *);  //MEMBER FUNCTION TO EDIT DATA
      
      //PROTECTED DATA MEMBERS
      protected:
             node **head3;                  
             int size;
};

//CREATING SUBCLASS OF USB TO DIVIDE WORK
class subusb:public usb
{
      //PUBLIC MEMBER FUNCTIONS
      public:
             subusb();                      //DEFAULT CONSTRUCTOR
             ~subusb();                     //DEFAULT DESTRUCTOR
             int add();                     //MEMBER FUNCTION TO ADD
             int remove();                  //MEMBER FUNCTION TO REMOVE
             int display();                 //MEMBER FUNCTION TO DISPLAY
             int edit();                    //MEMBER FUNCTION TO EDIT
      
      //PROTECTED DATA MEMBERS
      protected:
             char *data;                    
};


//CREATING CLASS MAIN TO CONTROL ALL THE OTHER CLASSES
class mains
{
      //PUBLIC MEMBER FUNCTIONS
      public:
             mains();                    //DEFAULT CONSTRUCTOR  
             ~mains();                   //DEFAULT DESTRUCTOR          
             int input(int);            //MEMBER FUNCTION TO GET INPUT 
             int add();                 //FUNCTION TO GET THE DEVICE TO ADD
             int remove();              //FUNCTION TO GET THE DEVICE TO REMOVE
             int edit();                //FUNCTION TO GET THE DEVICE TO EDIT
             int displayall();          //MEMBER FUNCTION TO DISPLAY ALL
      
      //PRIVATE DATA MEMBERS
      private:
              char *device;
              sublaptop device1;
              subusb device2;
              subtablet device3;
};

//FUNCTION TO GET THE KEY NUMBER FROM A KEYWORD
int keychanger(char keyword[]);

//FUNCTION TO WELCOME
int welcome();
