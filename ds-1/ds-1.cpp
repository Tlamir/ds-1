#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int NumberOfPixel = 0;
int BlobPixel = 0;


void blobsCalculate(char** Blobs,int** VisitedPixels, int i, int j,int row,int col) {


    /*if ( j<col-1)
    {
        if (Blobs[i][j] == *"x")
        {
            NumberOfPixel++;
           
        }

        j++;
        blobsCalculate(Blobs, i, j,row,col);
        
       
    }
    else if(i<row-1)
    {
        if (Blobs[i][j] == *"x")
        {
            NumberOfPixel++;
        }
        i++;
        blobsCalculate(Blobs, i,0, row, col);
        
    }
    else{
    
        return;


    }*/
  
    if (i<0||i>=row||j<0||j>=col)
    {
        return;
        
    }
   
    if (VisitedPixels[i][j]==0)
    {

        VisitedPixels[i][j] = 1;
        if (Blobs[i][j] == *"x" || Blobs[i][j] == *"X")
        {
            NumberOfPixel++;
        }
        blobsCalculate(Blobs, VisitedPixels, i + 1, j, row, col);
        blobsCalculate(Blobs, VisitedPixels, i, j + 1, row, col);
        blobsCalculate(Blobs, VisitedPixels, i - 1, j, row, col);
        blobsCalculate(Blobs, VisitedPixels, i, j - 1, row, col);
        
    }
       
}
int main()
{
    int row = 0;
    int col = 0;

    bool flag = false;

    string filename;

    cout << "Please enter File Name: ";
    cin >> filename;

    string line;
    vector <string> tokens;
    string lines;
    vector<vector<string>> vect;

    int count = 0;
    ifstream myfile(filename);
    bool firstlineflag = 0;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            //To get col row value from file
            if (firstlineflag == 0) {

                stringstream check1(line);

                string intermediate;

                while (getline(check1, intermediate, ' '))
                {
                    tokens.push_back(intermediate);
                }
                row = stoi(tokens[0]);
                col = stoi(tokens[1]);
            }
                    
            if (count > 0)
                lines = lines + line;

            count++;
        }
        myfile.close();


        //declare dynamic array
        char** a = new char* [row];
        for (char i = 0; i < row; ++i)
            a[i] = new char[col];
        //declare dynamic array for vizited pixels
        int** VisitedPixels = new int* [row];
        for (int i = 0; i < row; ++i)
            VisitedPixels[i] = new int[col];

       
       

        //get file to array
        int k = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                a[i][j] = (char)lines[k];
                k++;

                //fill visited pixels
                VisitedPixels[i][j] = 0;
            }
        }

        cout << endl;
        cout << endl;

            
        //Write to screen
        row = row + 4;
        col = col + 4;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                //numbers on table
                if (i==0 || i == row - 1)
                {
                    if (j==0||j==1||j==col-1||j==col-2)                   
                        cout << " ";
                    
                    else                                        
                        cout << (j-2)%10;
                                                                                            
                }
                else if ((i == 1 || i == row-2)) //Borders on table
                {
                    if (j == 0 || j == col - 1)                    
                        cout << " ";                  
                    else if ((i == 1 && j == 1)||(i==1&& j==col-2)||(i==row-2 && j==1)||(i==row-2 && j==col-2 ))
                        cout << "+";
                    else
                        cout << "-";                                                                                              
                }
                else if ((j == 0 && i > 0 && i < row - 2) || (j == col - 1 && i > 0 && i < row - 2)) //numbers on table
                {
                    if (i>12)
                    {
                        cout << ( (i - 2)%10) ;
                    }
                    cout << i - 2;
                }
                else if((j==1 && i!=0 && i!=row-2)||j==col-2)                
                    cout << "|";               
                else //print array
                    cout << a[i-2][j-2];
              
            }
            cout<<endl;
        }
        row = row - 4;
        col = col - 4;

        blobsCalculate(a, VisitedPixels,0,0,row,col);
        cout << "===========" << NumberOfPixel<<"===========";

    }
    else cout << "Unable to open file";

    return 0;
}


