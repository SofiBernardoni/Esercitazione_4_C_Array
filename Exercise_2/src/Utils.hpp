
#pragma once
#include "iostream"



using namespace std;
bool ImportData(const string& fileName,
                size_t& n,
                double*& ptrW,
                double*& ptrR,
                double& S);

double portfolio(const size_t& n,
                 const double* const& v1,
                 const double* const& v2);


bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double& S,
                  const double* const& v1,
                  const double* const& v2,
                  const double& somma);



