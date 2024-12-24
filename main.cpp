#include <bits/stdc++.h>
#include <omp.h>
#include "NoConcurrency.h"
#include "Concurrency.h"
#include "DefaultMain.h"
using namespace std;

void Test(int T, int numThreads){
    clock_t start0, finish0;
    NoConcurrency nc;
    start0 = clock();
    nc.run_NoConcurrency(T);
    finish0 = clock();
    double duration0 = (double)(finish0 - start0) / CLOCKS_PER_SEC;

    clock_t start1, finish1;

    DefaultMain df;
    start1 = clock();
    df.run(T);
    finish1 = clock();
    double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;

    if(numThreads != -1){
        clock_t start2, finish2;
        Concurrency c;
        start2 = clock();
        c.run_Concurrency(T, numThreads);
        finish2 = clock();
        double duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
        cout << "time Concurrency " << duration2 << std::endl;
    }
    cout << "time NoConcurrency " << duration0 << std::endl;
    cout << "time DefaultMain " << duration1 << std::endl;
}

int main(int argc, char **argv) {
    int numThreads = -1;
    int T = 200;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.find("--T=") == 0) T = std::stoi(arg.substr(4));
    }
    Test(T, numThreads);
}