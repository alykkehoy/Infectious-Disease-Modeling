#include <sstream>
#include <string>

//parse input text
auto text_parse::input() //TODO add input file parameter
{
  string iline;
  while(getline(cin, iline))
  {
    istringstream iss(iline);
    string pname, type, value; 
    iss >> pname;
    iss >> type;
    iss >> value;
    
    if(pname == "name")
    {

    }
    else if(pname == "alpha")
    {
       
    }
    else if(pname == "beta")
    {
      
    }
    else if(pname == "mortality")
    {
      
    }
    else if(pname == "range")
    {
      
    }   
  }  
}

//functions for conversion of data types
