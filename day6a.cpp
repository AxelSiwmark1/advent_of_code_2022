#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <vector>

using namespace std;

bool is_key(string str)
{
    for(int i = 0; i < str.length(); i++)
    {   
        for(int j = i + 1; j < str.length(); j++)
        {
            if(str[i] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main ()
{
    int counter = 0;
    string str = "";
    string line;
    
    ifstream myfile ("data_day6a.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            str = std::string() + line.at(counter) + line.at(counter + 1) + line.at(counter + 2) + line.at(counter + 3);

            counter ++;
            while(!is_key(str))
            {
                str = "";
                str = std::string() + line[counter] + line[counter + 1] + line[counter + 2] + line[counter + 3];
                counter++;
           }
        }
    }
    myfile.close();
    cout << counter + 3;
    return 0;
}
    