#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

bool does_ints_contain_ints(int n1, int n2, int n3, int n4)
{
    if ((n1 >= n3 & n2 <= n4) | (n3 >= n1 & n4 <= n2)) return true;
    else return false;
}

int main ()
{
    list<int> ints;
    string a = "4-90,1-4";
    string number;
    
    int sum = 0;
    
    
    string line;
    ifstream myfile ("data_day4a.txt");
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            int i = 0;
            while (i < line.length() + 1)
            {
                if(!isdigit(line[i]))
                    {
                        ints.push_back(stoi(number));
                        number = "";
                        i++;
                        continue;
                    }
                number = number + line[i];
                i++;
            }

            int first = ints.front();
            ints.pop_front();
            int second = ints.front();
            ints.pop_front();
            int third = ints.front();
            ints.pop_front();
            int fourth = ints.front();
            ints.pop_front();
            sum += does_ints_contain_ints(first, second, third, fourth);
        }
        myfile.close();
    }
    cout << sum;
    return 0;
}