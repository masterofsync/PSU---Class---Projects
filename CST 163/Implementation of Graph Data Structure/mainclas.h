/*
BIKESH MAHARJAN
CS 163
PROGRAM 5
MAINCLAS.H- DECLARES ALL THE FUNCTIONS AND FUNCTION MEMBER OF THE CLASS
*/

//INPUT AND OUTPUT STANDARD LIBRARY
#include<iostream>

using namespace std;

//DECLARATION OF THE CLASS TASK FOR THE WORK INFORMATION
class task
{
      //PUBLIC SECTION OF THE CLASS
      public:
             task();                             //DEFAULT CONSTRUCTOR
             ~task();                            //DEFAULT DESTRUCTOR       
             int adddescription(char description[]);   //MEMBER FUNCTION TO ADD
             int display();                      //MEMBER FUNCTION TO DISPLAY
             int copy (task & empty);            //MEMBER FUNCTION TO COPY
      
      //PRIVATE SECTION OF THE CLASS
      private:
             char *description;                  //DECLARING CHAR POINTER
};


//DECLARATION OF THE CLASS NODE FOR EACH EDGE
struct node
{
       int verticesindex;                        //DECLARING AN INTEGER
       task nodedata;                            //VARIABLE OF CLASS
       node *next;                               //NEXT POINTER FOR RECURSION
};
             

//DECLARATION OF THE CLASS TABLE
class table
{
      //PUBLIC SECTION OF THE CLASS
      public:
             table();                            //DEFAULT CONSTRUCTOR
             ~table();                           //DEFAULT DESTRUCTOR
             int addvertices(task &);            //MEMBER FUNCTION TO ADD
             int addedges(int, int);             //MEMBER FUNCTION TO ADD         
             int search(int number);             //MEMBER FUNCTION FOR NEXT TASK
             void display();
      
      //PRIVATE SECTION OF THE CLASS
      private:
             node **array;          
             int verticeslength;        
};


//FUNCTION TO INTERACT WITH USER AND ADD
void adding (table &items);

//FUNCTION TO ADD EDGES IN THE GRAPH
void addingedges();

//FUNCTION TO SEARCH TASK THAT IF AFTER THE GIVEN
void find();
