// JSONCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream stream("Resources/data.json");
    std::string line;
    bool insideJsonValue = false;
    while (std::getline(stream, line))
    {
      if (line == "\t{")
      {
        insideJsonValue = true;
      }

      if (line == "\t},")
      {
        insideJsonValue = false;
      }

      if (insideJsonValue && line != "\t{")
      {
        std::string parseUntil = "\t";
        //this line is a json property
       int index = line.find(parseUntil);
       //std::cout << line[3];

       std::string propName;

       //Return the string up to the ':' and after the tab special characters (compare to line)
       propName = line.substr(3, line.find(58) - 3);

       

       //Take off the final '\'
       propName.pop_back();


       std::cout << propName << std::endl;
      }
      
    }

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
