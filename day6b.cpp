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
            for(int i = 0; i < 14; i++)
            {
                str += std::string() + line.at(i);
            }
            counter ++;
            while(!is_key(str))
            {
                str = "";
                for(int j = counter; j < 14 + counter; j++)
                {
                    str += std::string() + line.at(j);
                }
                counter++;
           }
        }
    }
    myfile.close();
    cout << counter + 13;
    return 0;
}
    