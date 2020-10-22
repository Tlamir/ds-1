

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int row = 0;
    int col = 0;
    
    string filename;

    cout << "Please enter File Name: ";
    cin >> filename;

    string line;
    vector <string> tokens; 

    vector<vector<string>> vect;
   
    ifstream myfile(filename);
    bool firstlineflag = 0;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            //To get col row value from file
            if (firstlineflag==0) {

                stringstream check1(line);
                
                string intermediate;

                while (getline(check1, intermediate, ' '))
                {
                    tokens.push_back(intermediate);  
                }
                row = stoi(tokens[0]);
                col = stoi(tokens[1]);  

                //declare dynamic array
                char** a = new char* [row];
                for (char i = 0; i < row; ++i)
                    a[i] = new char[col];

            }
            //write file to screen
            cout << line << '\n';   
        }
        
        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}


