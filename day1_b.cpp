#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main () {
  string line;
  ifstream myfile ("example.txt");
  int sum = 0;
  int max1 = 0;
  int max2 = 0;
  int max3 = 0;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        if(line != ""){
            sum = sum + stoi(line);
        }
        else{
            if(sum <= max3){
              sum = 0;
            } 
            else if(max2 > sum & sum > max3){
                max3 = sum;
            }
            else if (max1 > sum & sum > max2){
                max3 = max2;
                max2 = sum;
            }
            else{
                max3 = max2;
                max2 = max1;
                max1 = sum;
            }
            sum = 0;
        }
    }
    cout << max1 << endl << max2 << endl << max3 << endl;
    int result = max1 + max2 + max3;
    cout << result;
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}