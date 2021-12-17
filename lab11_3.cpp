#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    ifstream source("score.txt");
    double SD, mean = 0;
    string str_num;
    int N = 0;

    double sum = 0;
    while (getline(source, str_num)) {
        sum += atof(str_num.c_str());

        N++;
    }
    mean = sum / N;
    
    sum = 0;
    source.close();
    source.open("score.txt");
    while (getline(source, str_num)) {
        sum += pow(atof(str_num.c_str())-mean, 2);
    }
    SD = sqrt(sum / N);

    cout << "Number of data = " << N << endl;
    cout << setprecision(3);
    cout << "Mean = " << mean << endl;
    cout << "Standard deviation = " << SD;
}