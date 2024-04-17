
#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip>

using namespace std;

bool ImportData(const string& fileName,
                size_t& n,
                double*& ptrW,
                double*& ptrR,
                double& S)
{

    ifstream ifstr(fileName); // create istream object and open file

    if(ifstr.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }

    string line;
    getline(ifstr, line);

    char separator;

    stringstream ss(line);
    char ch;
    ss >> ch >> separator >> S;

    getline(ifstr, line);

    stringstream ss1(line);
    char chn;
    ss1 >> chn >> separator >> n;

    string heater;
    ifstr >> heater;
    int i=0;
    ptrW = new double[n];
    ptrR = new double[n];

    while(ifstr>>line)
    {
        stringstream ss2(line);
        ss2 >> *(ptrW+i) >> separator >> *(ptrR+i);
        i++;
    }

    return true;


}
double portfolio(const size_t& n,
                 const double* const& v1,
                 const double* const& v2)
{
    double portfolio = 0;
    for (unsigned int i = 0; i < n; i++)
        portfolio += v1[i] * v2[i];

    return portfolio;
}

bool ExportResult(const string& outputFile,
                  const size_t& n,
                  const double& S,
                  const double* const& ptrW,
                  const double* const& ptrR,
                  const double& somma)
{

    ofstream file;
    file.open(outputFile);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file<< "S = " <<fixed << setprecision(2)<< S << ", n = " << n << endl;
    cout<< "S = " << fixed << setprecision(2)<< S << ", n = " << n << endl;
    stringstream l1;
    l1 << "W = [";

    for (unsigned int i = 0; i < n; i++)
        l1 << (i != 0 ? " " : "")<< *(ptrW+i);
    l1<< " ] " << endl;

    string W=l1.str();
    file << W;
    cout << W;

    stringstream l2;
    l2 << "r = [";

    for (unsigned int i = 0; i < n; i++)
        l2 << (i != 0 ? " " : "")<< *(ptrR+i);
    l2<< " ] " << endl;

    string R=l2.str();
    file << R ;
    cout << R ;

    file<< "Rate of return of the portfolio: "<< fixed << setprecision(4) <<somma << endl;
    file<<"V: " << fixed << setprecision(2)<< (1+somma)*S << endl;
    cout<< "Rate of return of the portfolio: "<< fixed << setprecision(4) <<somma << endl;
    cout<<"V: " << fixed <<setprecision(2)<< (1+somma)*S <<  endl;

    file.close();

    return true;
}


