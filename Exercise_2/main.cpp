#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Utils.hpp"

using namespace std;

int main()
{


    const string fileName = "data.csv"; // file name
    double *ptrW=nullptr;
    double *ptrR=nullptr;
    size_t n=0;
    double S=0;

    ImportData(fileName, n, ptrW, ptrR, S);

    double somma = portfolio(n, ptrW, ptrR);

    string outputFileName = "result.txt";
    if (!ExportResult(outputFileName, n, S, ptrW, ptrR, somma))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;


    delete [] ptrW;
    delete [] ptrR;


  return 0;
}



