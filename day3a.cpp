#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char does_string_contain_char(string s1, string s2)
{
    char result;
    for (int i = 0; i < s1.length(); i++)
    {
        if(s2.find(s1[i]) != string::npos)
        {
            result = s1[i];
        }
    }
    return result;
}

int main()
{
    int sum = 0;
    string line;
    ifstream myfile ("data_day3a.txt");
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            std::string half = line.substr(0, line.length()/2);
            std::string otherHalf = line.substr(line.length()/2);
            char item = does_string_contain_char(half, otherHalf);
            if(islower(item)) sum += int(item) - 96;
            else sum += int(item) - 38;
        }
        myfile.close();
    }
    cout << sum;
    return 0;
}

