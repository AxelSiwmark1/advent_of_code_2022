#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main () {
  string line;
  ifstream myfile ("example.txt");
  int sum = 0;
  int max = 0;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        if(line != ""){
            sum = sum + stoi(line);
        }
        else{

            if(sum > max){
              max = sum;
            } 
            sum = 0;
        }
    }
    cout << max;
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}