#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char does_string_contain_char(string s1, string s2, string s3)
{
    char result;
    for (int i = 0; i < s1.length(); i++)
    {
        if(s2.find(s1[i]) != string::npos & s3.find(s1[i]) != string::npos)
        {
            result = s1[i];
        }
    }
    return result;
}

int main()
{
    int sum = 0;
    int counter = 0;
    string line;
    string data;
    string line1;
    string line2;
    ifstream myfile ("data_day3a.txt");
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            if (counter == 0) line1 = line;
            else if (counter == 1) line2 = line;
            else 
            {   
                char item = (does_string_contain_char(line1, line2, line));
                cout << item << endl;
                if(islower(item)) sum += int(item) - 96;
                else sum += int(item) - 38;
                cout << sum << endl;
                counter = 0;
                continue;
            }
            counter ++;
        }
        myfile.close();
    }

    return 0;
}

