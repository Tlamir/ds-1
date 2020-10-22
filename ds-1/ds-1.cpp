

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
    

    string line;
    vector <string> tokens;

    

    
   
    ifstream myfile("blobs1.txt");
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
            }
            cout << line << '\n';
            firstlineflag = 1;
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    
    

    return 0;
}


