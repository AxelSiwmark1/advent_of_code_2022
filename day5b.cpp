#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <vector>

using namespace std;


int find_blank_space(vector<string> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i].size() == 0) return i;
    }
    return -1;
}




int main ()
{
    std::vector<string> input;
    string line;
    ifstream myfile ("data_day5a.txt");

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            input.push_back(line);
        }
    }
    myfile.close();
    int blank_space = find_blank_space(input);

   
    std::vector<std::stack<char> > stacks;
    std::stack<char> moving_list;

    for(int i = 0; i < input[1].size(); i++)
    {
        if(!isdigit(input[blank_space - 1][i])) continue;

        std::stack<char> current_stack;
        for(int line_index = blank_space - 2; line_index >= 0; --line_index)
        {
            char current_value = input[line_index][i];
            if(current_value == ' ')
            {
                break ;
            }
            current_stack.push(current_value);

        }
        stacks.push_back(current_stack);
    }

    

    for(int i = blank_space + 1; i < input.size(); i++)
    {
        string n1 = "";
        string n2 = "";
        string n3 = "";
        int counter = 5;
        while(isdigit(input[i][counter]))
        {
            n1 = n1 + input[i][counter];
            counter ++;
        }
        if (isdigit(input[i][counter]))
        {
            cout << blank_space << n1 << endl;
        }
        counter += 6;
        while(isdigit(input[i][counter]))
        {
            n2 = n2 + input[i][counter];
            counter ++;
        }
        counter +=4;
        while(isdigit(input[i][counter]))
        {
            n3 = n3 + input[i][counter];
            counter ++;
        }

        cout << i << endl << input.size();
        
        int count = stoi(n1);
        int from = stoi(n2) - 1;
        int to = stoi(n3) - 1;

        while (count > 0)
        {
            char crate = stacks[from].top();
            moving_list.push(crate);
            stacks[from].pop();
            if(count == 1)
            {
                while(moving_list.size() != 0)
                {   
                    char move = moving_list.top();
                    stacks[to].push(move);
                    moving_list.pop();
                }
                
                
            }
            count -= 1;
        }

        
    }
    for(int i = 0; stacks.size(); i++)
    {   
        char crate = stacks[i].top();
        cout << crate << endl;
    }
   
    
    return 0;
}