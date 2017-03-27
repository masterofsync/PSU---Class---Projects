/*
BIKESH MAHARJAN
CS 163
PROGRAM 5
IMPLEMENTATION.CPP- IMPLEMENTS ALL THE MEMBER FUNCTION AND FUNCTIONS
*/

//INCLUDING MAINCLAS.H HEADER FILE
#include "mainclas.h"


//FUNCTION FOR ADDING CORRESPONDING WITH THE USER
void adding (table &items)
{
  //CREATING A VARIABLE OF CLASS   
  task newitem;
  
  //DECLARING VARIABLES
  char descriptions[100];
    
  cout<<endl<<"PLEASE ENTER THE DESCRIPTION: ";       
  cin.get (descriptions, 100);                       //GETTING TASK INFORMATION
  cin.ignore (101, '\n');                            //ISTREAM IGNORE

  //CALLING FUNCTION TO ADD DESCRIPTION
  newitem.adddescription (descriptions);
  
  //CALLING FUNCTION TO PUT DETAILS IN THE GRAPH
  items.addvertices(newitem);
  cout<<endl<<"ITEM ADDED"<<endl<<endl;
}


//FUNCTION TO SEARCH THE REQUIRED AFTER TASK
void find()
{
     //CREATING A CLASS VARIABLE
     table items;                             
     
     int key;
     
     //CALLING THE DISPLAY FUNCTION TO SEE THE NEXT TASK
     items.display();
     
     cout<<endl<<"ENTER OPTIONS: ";
     cin>>key;                                  //GETTING THE KEY
     cin.ignore();                              //ISTREAM IGNORE
     
     //GETTING THE POSITION AND DISPLAYING
     if(items.search(key)==0)
     {
         cout<<endl<<"NO TASK LEFT"<<endl<<endl;
     }
     else
     {
         items.search(key);
     }
}


//FUNCTION TO ADD EDGES
void addingedges()
{
     //DECLARING INT VALUE
     int result;
     
     //DECLARING CLASS VARIABLE
     table items;
     
     //DECLARING INTEGER VARIABLES
     int basenumber;
     int edgenumber;
     
     //CALLING THE FUNCTION TO DISPLAY THE OPTIONS
     items.display();
     
     cout<<endl<<endl<<"ENTER THE NUMBER WHERE YOU WANT TO ADD THE TASK:";  
     cin>>basenumber;
     cin.ignore();
     
     cout<<"ENTER THE TASK NUMBER THAT YOU WANT TO ADD:";
     cin>>edgenumber;
     cin.ignore();
     
     //CALLING THE FUNCTION
     result = items.addedges(basenumber, edgenumber);
     
     if(result==0)
         cout<<endl<<"THE EDGE COULD NOT BE ADDED"<<endl;
     else
         cout<<endl<<"THE EDGE IS ADDED"<<endl;
     
}

//DEFAULT CONSTRUCTOR
task :: task()
{
       //INITIALIZING THE VALUES
       description = NULL;
}

//DEFAULT DESTRUCTOR
task :: ~task()
{
       //DESTROYING THE VALUES     
       delete []description;
       description = NULL;
}

int task :: adddescription(char newdescription[])
{
    if (newdescription)  //CLEAR CURRENT CONTENTS, IF ANY
    delete [] newdescription;
    description = new char [strlen(newdescription)+1];
    strcpy (description, newdescription);
    return 1;
}

int task :: display()
{
      if(!description)                       //RETURNING FAILURE IF DATA IS NULL
             return 0;
      cout<<endl<<"TASK: "<<description <<endl;  
      return 1;;
}

//MEMBER FUNCTION COPY TO COPY THE DATA
int task :: copy (task & empty)
{
    if(!description)  //RETURN FAILURE IF DATA IS NULL
        return 0;
    
    if(empty.description != NULL)  //DELETE CONTENTS OF ARGUMENT IF ANY
        delete empty.description;
    empty.description = new char [strlen(description)+1];
    strcpy (empty.description, description);
        
    return 1;
}

//DEFAULT CONSTRUCTOR
table :: table()
{
     int i;
              
    //INITIALIZING THE VALUES
    verticeslength = 10;    
       
    //CREATING ALL THE VERTICES IN THE TABLE WITH VALUE NULL
    array = new node*[verticeslength];
    for(i=0;i<verticeslength;++i)
    {
        array[i]=NULL;             
    };   
}
          
          
//DEFAULT DESTRUCTOR
table :: ~table()
{
     //GETTING INTO ALL THE VERTICES OF THE TABLE AND DESTROYING IT   
     for (int i = 0; i < verticeslength; i++)
          if (array[i] != NULL) 
          {
               node *prevEntry = NULL;
               node *entry = array[i];
               while (entry != NULL) 
               {
                     prevEntry = entry;
                     entry = entry->next;
                     delete[] array;         
                     delete prevEntry;
               }
          }            
}


//GETTING THE DATA AND ADDING FROM THE MEMBER FUNCTION
int table :: addvertices(task &item)
{
      int verticesindex = 0;    
      while(array[verticesindex] != NULL && verticesindex < verticeslength)
      {
           verticesindex +=1;
      }
            
      //CHECKING IF THE DATA IT NULL
      if (array[verticesindex] == NULL)
      {     
                   //ALLOCATING A NEW NODE
                   array[verticesindex]= new node;
                   
                   //MAKING NEXT NODE NULL
                   array[verticesindex]->next=NULL;
                   
                   //COPYING ALL DATA INTO TABLE
                   item.copy (array[verticesindex]->nodedata);
                   array[verticesindex]->verticesindex=verticesindex;
      }   
      else 
      { 
                   return 0;
      }
      return 1;
}


//CLASS MEMBER FUNCTION TO ADD EDGES GIVEN WHERE TO ADD AND WHICH TO ADD
int table :: addedges(int basenumber, int edgenumber)
{
    node *temp;
    
    //DISPLAYING ALL TO SHOW WHAT DATA THE USER HAVE TO ADD EDGE
    display();
    
    if(array[basenumber] != NULL)
    {
          temp = array[basenumber];
          temp->next = new node;
          temp = temp->next;
          temp->verticesindex = edgenumber;
          temp->nodedata.~task();
          temp->next = NULL;
    }
    else
    {
          return 0;
    }
    return 1;
}

//CLASS MEMBER FUNTION TO SEARCH THE TASK AFTER THAT
int table :: search(int number)
{
        
        node *temp = array[number];
        if(array[number]!=NULL)
        {                  
               temp=temp->next;
               temp->nodedata.display();
               return 1;
        }
        else 
        return 0;
}

//CLASS MEMBER FUNTION TO DISPLAY
void table :: display()
{
            int i;
        
            cout<<"LIST OF VERTICES :"<<endl;
            for(i=0 ;i<verticeslength ;++i)
            {
                  if(array[i]!=NULL)
                  {
                        cout<<(i+1)<<"."<<array[i]->nodedata.display();
                  }
            }             
        
}
