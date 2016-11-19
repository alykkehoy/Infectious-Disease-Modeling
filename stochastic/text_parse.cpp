#include <sstream>
#include <string>
#include <iostream>

using std::istringstream;
using std::cout;
using std::string;
using std::cin;

//parse input text
void Text_parse::Text_parse() //TODO add input file parameter
{
  string iline;
  while(getline(cin, iline))
  {
    istringstream iss(iline);
    string pname, type, value; 
    iss >> pname;
    iss >> value;

    if(pname == "diseaseName")
    {

    }
    else if(pname == "diseaseModel")
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
    else if(pname == "pop_width")
    {

    }
    else if(pname == "pop_height")
    {

    }
    else if(pname == "sim_len")
    {

    }
    else if(pname == "seed")
    {

    }
    else //incorrect input
    {
      cout << "Incorrect input, please check parameters";
    }

  }
}
