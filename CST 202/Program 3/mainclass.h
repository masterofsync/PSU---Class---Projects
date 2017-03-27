/*
    BIKESH MAHARJAN
    CS 202
    PROGRAM 3
    MAINCLASS.H- DECLARES ALL THE CLASSES AND ITS MEMBER FUNCTIONS
*/

//INPUT AND OUTPUT STANDARD LIBRARY
#include<iostream>

using namespace std;         

//DECLARATION OF THE CLASS INFO FOR CLASS INFORMATION
class info
{
      //PUBLIC SECTION OF THE CLASS
      public:
             info();                               //DEFAULT CONSTRUCTOR
             info(const info &);                   //COPY CONSTRUCTOR
             ~info();                              //DEFAULT DESTRUCTOR       
             int adddescription(char description[]);//MEMBER FUNCTION TO ADD
             void displays();                       //MEMBER FUNCTION TO DISPLAY
             int copy (info & empty);               //MEMBER FUNCTION TO COPY
	         int desc();   //MEMBER FUNCTION TO CHECK IF DESCRIPTION IS NULL
	         void makenull();	   //MEMBER FUNCTION TO MAKE DESCRIPTION NULL
      
      //PRIVATE SECTION OF THE CLASS
      private:
             char *description;                  //DECLARING CHAR POINTER
};


//DECLARATION OF THE STRUCT NODE FOR EACH EDGE
struct node
{
       int verticesindex;                        //DECLARING AN INTEGER
       info nodedata;                            //VARIABLE OF CLASS
       node *next;                               //NEXT POINTER FOR RECURSION
};
    


//DECLARATION OF THE CLASS TABLE
class table:public info
{
      //PUBLIC SECTION OF THE CLASS
      public:
             table();                            //DEFAULT CONSTRUCTOR
             table(const table &);               //COPY CONSTRUCTOR
             ~table();                           //DEFAULT DESTRUCTOR
             int addvertices(info &);            //MEMBER FUNCTION TO ADD
             int addedges(int, int);             //MEMBER FUNCTION TO ADD         
             int search(int number);             //MEMBER FUNCTION PRE-REQS
             void display();           			     //MEMBER FUNCTION TO DISPLAY
  	         int vertexindex(int num); 	        
      
      //PRIVATE SECTION OF THE CLASS
      private:
             node **array;          
             int verticeslength;        
};


class application
{
      //PUBLIC MEMBER FUNCTIONS
      public:
             application();             //DEFAULT CONSTRUCTOR
             ~application();            //DEFAULT DESTRUCTOR
             void adding (table &items);//MEMBER FUNCTION TO ADD
             void addingedges(table &items);//MEMBER FUNCTION TO ADD PRE-REQS
             void find(table &items);   //MEMBER FUNCTION TO SEARCH 
             
      //PRIVATE SECTION OF THE CLASS       
      private:
             char *name; 
};
