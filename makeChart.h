// make a line chart in which the final state of system is shown

#include<iostream>
using namespace std;

// total amount of particles
#define N 250

// parameters for making chart
#define f 1
#define K 300


class makeChart
{
public:
    void printFrame();
    void printSquares(int cnt, int i);
};

void makeChart::printFrame()
{
    cout << "  velocity range"
        << "\t"
        << "percent" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
}

void makeChart::printSquares(int cnt, int i)
{
    double i2 = (double)i;
    double i3 = (double)N;
    double i4 = 100;
    double cnt1 = cnt;

    cout << i2 / f << "\t"
         << "-"
         << "\t" << (i2 + 1) / f;
    cout << "\t" << (cnt1 / i3) * i4 << "%"
         << "\t";
    for (int j = 0; j < int((cnt1 / N) * K); j++)
    {
        cout << "#";
    }
    cout << endl;
}