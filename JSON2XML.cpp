#include <iostream>
#include <fstream>
#include <string>

std::string GetPropName(const std::string& line)
{
  //Return the string up to the ':' and after the tab special characters (compare to line)
  std::string propName = line.substr(3, line.find(58) - 3);

  //Take off the final '\'
  if (propName != "")
    propName.pop_back();
  

  return propName;
}

std::string GetPropValue(const std::string& line)
{
  std::string value = line.substr(line.find(58), line.length()-1);
  value = value.substr(2, line.length()-2);

  if(value != "")
    value.pop_back();
  return value;
}

int main()
{
    std::ifstream stream("Resources/data.json");
    std::ofstream xmlFile;
    xmlFile.open("Resources/data.xml");

    std::string rootElement;

    std::cout << "Enter a name for the root element. \n";
    std::cin >> rootElement;

    xmlFile << "<?xml version=\"1.0\"?>" << "\n";

    std::string beginRootTag = "<" + rootElement + ">";
    std::string endRootTag = "<\/" + rootElement + ">";

    xmlFile << beginRootTag << std::endl;
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

      if (insideJsonValue && line != "\t{" && line != "\t}" && line != "]")
      {//this line is a json property
         
         std::string propName = GetPropName(line);
         std::string propValue = GetPropValue(line);
         std::string beginTag = "<" + propName + ">";
         std::string endTag = "<\/" + propName + ">";
         std::string xmlValue = beginTag + propValue + endTag + "\n";

         xmlFile << xmlValue;
      }
    }

    xmlFile << endRootTag << std::endl;
    xmlFile.close();

    
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
