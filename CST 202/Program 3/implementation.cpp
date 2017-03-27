/*
     BIKESH MAHARJAN
     CS 202
     PROGRAM 3
     IMPLEMENTATION.CPP- IMPLEMENTS ALL THE MEMBER FUNCTIONS OF CLASSES
*/

//INCLUDING MAINCLAS.H HEADER FILE
#include "mainclass.h"

//DEFAULT CONSTRUCTOR FOR INITIALIZATION
application::application()
{
    name = NULL;
}

//DEFAULT DESTRUCTOR FOR DESTROYING
application::~application()
{
    delete name;
}

//MEMBER FUNCTION TO ADD DATA
void application::adding (table &items)
{  
    //DECLARING VARIABLES
    char clas[100];
    table item;
    
    cout<<endl<<"PLEASE ENTER THE CLASS NAME: ";       
    cin.get (clas, 100,'\n');                       //GETTING TASK INFORMATION
    cin.ignore (101, '\n');                         //ISTREAM IGNORE
    
    //CALLING FUNCTION TO ADD NAME OF THE CLASS
    item.adddescription (clas);
    
  
    //CALLING FUNCTION TO APPEND NAME INTO THE ADJACENCY LIST
    items.addvertices(item);
  
    cout<<endl<<"ITEM ADDED"<<endl<<endl;
}

//MEMBER FUNCTION TO FIND PRE-REQ
void application::find(table &items)
{
     //DECLARING INTEGER VARIABLES
     int key;
     int vertex;
     
     //CALLING THE DISPLAY FUNCTION TO SEE THE NEXT TASK
     items.display();
     
     cout<<endl<<"ENTER OPTIONS: ";
     cin>>key;                                  //GETTING THE KEY
     cin.ignore();                              //ISTREAM IGNORE
	
     //TO CHECK IF THERE IS ANY TASK AFTER THAT     
     vertex = items.vertexindex(key);	
    
     if(vertex == 100)
     {
          cout<<endl<<"NO PRE-REQ RECORDED FOR THAT"<<endl;
     }
     else
     {
          //GETTING THE POSITION AND DISPLAYING
          items.search(vertex);
     }
}

//FUNCTION TO ADD PRE-REQ
void application::addingedges(table &items)
{
     //DECLARING INT VARIABLES
     int result;
     int basenumber;
     int edgenumber;
     
     //CALLING THE FUNCTION TO DISPLAY THE OPTIONS
     items.display();
     
     cout<<endl<<endl<<"ENTER THE NUMBER WHERE YOU WANT TO ADD THE CLASS:";  
     cin>>basenumber;
     cin.ignore();
     
     cout<<"ENTER THE CLASS NUMBER THAT YOU WANT TO ADD:";
     cin>>edgenumber;
     cin.ignore();
     
     //CALLING THE FUNCTION TO ADD PRE-REQS
     result = items.addedges(basenumber, edgenumber);
     
     if(result==0)
         cout<<endl<<" THE PRE-REQ COULD NOT BE ADDED "<<endl;
     else
         cout<<endl<<" THE PRE-REQ IS ADDED "<<endl;
     
}

//DEFAULT CONSTRUCTOR
info :: info()
{
       //INITIALIZING THE VALUES
       description = NULL;
}

//IMPLEMENTATION OF COPY CONSTRUCTOR
info::info(const info &data)
{
    //IF DESCRIPTION IS NOT NULL             
    if(!description)
        description = NULL;
    else 
    {
        description = new char[strlen(description)];
        strcpy(data.description,description);
    }
}

//DEFAULT DESTRUCTOR
info :: ~info()
{
       //DESTROYING THE DATA
       delete []description;
       description = NULL;
}

//MAKING DATA NULL
void info::makenull()
{
    //GIVING THE VALUE OF DESCRIPTION TO NULL 
    description = NULL;
}

//MEMBER FUNCTION TO ADD NEW CLASS NAMES
int info :: adddescription(char newdescription[])
{
    if (newdescription)                    //CLEAR CURRENT CONTENTS, IF ANY
    delete [] newdescription;
    description = new char [strlen(newdescription)+1];
    strcpy (description, newdescription);
    return 1;
}

//FUNCTION TO DISPLAY CLASS
void info :: displays()
{
      if(description != NULL)                       //IF DATA IS NOT NULL
             cout<<" CLASS: "<<description <<endl;  
}

int info :: desc()
{
      if(!description)
		return 0;
      else  
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
    
    for(i = 0; i < verticeslength; ++i)
    {
        array[i] = NULL;             
    };   
}

//COPY CONSTRUCTOR
table::table(const table &data)
{
    int i;
              
    //INITIALIZING THE VALUES
    verticeslength = 10;    
       
    //CREATING ALL THE VERTICES IN THE TABLE WITH VALUE NULL
    array = new node*[verticeslength];
    
    for(i = 0; i < verticeslength; ++i)
    {
        data.array[i] = NULL;             
    };       
}
          
          
          
//DEFAULT DESTRUCTOR
table :: ~table()
{
     //GETTING INTO ALL THE VERTICES OF THE TABLE AND DESTROYING IT   
     for (int i = 0; i < verticeslength; i++)
     {
          if (array[i] != NULL) 
          {
               node *prevEntry = NULL;
               node *entry = array[i];
            
            //WHILE ENTRY IS NOT EQUAL TO NULL   
	        while (entry != NULL) 
               {
                     prevEntry = entry;
                     entry = entry->next;
                     delete[] prevEntry;         
               }
          }   
      }
      delete []array;         
}


//GETTING THE DATA AND ADDING FROM THE MEMBER FUNCTION
int table :: addvertices(info &item)
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
                   array[verticesindex] = new node;
                   
                   //MAKING NEXT NODE NULL
                   array[verticesindex]->next = NULL;
                   
                   //COPYING ALL DATA INTO TABLE
                   info (array[verticesindex]->nodedata);
                   array[verticesindex]->verticesindex = verticesindex;
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

    if(array[basenumber]->nodedata.desc() == 1)
    {
          temp = array[basenumber];
          temp->next = new node;
          temp = temp->next;
          temp->verticesindex = edgenumber;
	      temp->nodedata.makenull();
          temp->next = NULL;
    }
    else
    {
          return 0;
    }
    return 1;
}

int table::vertexindex(int num)
{
	node *temp = array[num];
       
	if(array[num] != NULL)
	{     
	     temp=temp->next;
	     return temp->verticesindex;	
	}
	else 
	     return 100;
} 

//CLASS MEMBER FUNTION TO SEARCH THE TASK AFTER THAT
int table::search(int number)
{
        
        node *temp = array[number];

        if(array[number] != NULL)
        {                  
		 cout<<"THE PRE-REQ FOR THAT CLASS IS:";
               temp->nodedata.displays();
               return 1;
        }
        else 
               return 0;
}

//CLASS MEMBER FUNTION TO DISPLAY
void table::display()
{
            int i;
        
            cout<<"LIST OF CLASSES :"<<endl;

            for(i = 0 ;i < verticeslength ;++i)
            {
                  if(array[i] != NULL)
                  {
                        cout<<endl<<i<<".";
			   array[i]->nodedata.displays();
                  }		
            }                  
}
