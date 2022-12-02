#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int check_result(char hand1, char hand2)
{
    if (hand1 == hand2)
    {
        return 3;
    }
    else if (hand1 == 'A')
    {
        if (hand2 == 'B') return 6;
        else return 0;
    }
    else if (hand1 == 'B')
    {
        if (hand2 == 'C') return 6;
        else return 0;
    }
    else
    {
        if (hand2 == 'A') return 6;
        else return 0;
    }
}

char map(char k)
{
    string key = "ABC";
    if (k=='X') return key[0];
    else if (k=='Y') return key[1];
    else return key[2];
}

int value_map(char k)
{
    string key = "123";
    if (k=='X') return 1;
    else if (k=='Y') return 2;
    else return 3;

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
            sum = sum + check_result(line[0], map(line[2])) + value_map(line[2]);
            //cout << check_result(line[0], map(line[2])) << endl;
            //cout << value_map(line[2]);
            cout << sum << endl;
        }
        myfile.close();
    }

    int test = check_result('B', 'A');
    cout << sum;
    return 0;
}

