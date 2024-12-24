#include <bits/stdc++.h>
#include <omp.h>
#include "NoConcurrency.h"
#include "DefaultMain.h"
using namespace std;

void Test(){
    clock_t start, finish;
    start = clock();
    NoConcurrency nc;
    nc.run_NoConcurrency();
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;

    clock_t start1 = clock();

    DefaultMain df;
    df.run_DefaultMain();
    clock_t finish1 = clock();
    double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
    cout << "time NoConcurrency " << duration << std::endl;
    cout << "time DefaultMain " << duration1 << std::endl;
}

int main() {
    Test();
}