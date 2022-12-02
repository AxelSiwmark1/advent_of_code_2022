#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int check_result(char hand2)
{
    if(hand2 == 'X') return 0;
    else if(hand2 == 'Y') return 3;
    else return 6;
}

char map(char k)
{
    string key = "ABC";
    if (k=='X') return key[0];
    else if (k=='Y') return key[1];
    else return key[2];
}

int value_map(char hand1, char hand2)
{
    if(hand1 == 'A' & hand2 == 'X') return 3;
    else if(hand1 == 'A' & hand2 == 'Y') return 1;
    else if(hand1 == 'A' & hand2 == 'Z') return 2;
    else if(hand1 == 'B' & hand2 == 'X') return 1;
    else if(hand1 == 'B' & hand2 == 'Y') return 2;
    else if(hand1 == 'B' & hand2 == 'Z') return 3;
    else if(hand1 == 'C' & hand2 == 'X') return 2;
    else if(hand1 == 'C' & hand2 == 'Y') return 3;
    else return 1;
}

int main()
{
    const char hand[3] = {'A', 'B', 'C'};
    string line;
    ifstream myfile ("data_day2a.txt");
    int sum = 0;
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            sum = sum + check_result(line[2]) + value_map(line[0], line[2]);
            //cout << check_result(line[0], map(line[2])) << endl;
            //cout << value_map(line[2]);
            cout << sum << endl;
        }
        myfile.close();
    }

    
    cout << sum;
    return 0;
}

