# ConcurrencyFluid

чтоб собрать, нужно
```bash
g++ -std=c++20 -fopenmp main.cpp
```

чтоб запускать, то можно передавать параметры --T=... кол-во итераций и --threads=... кол-во потоков

T = 500
time NoConcurrency 69.8194
time DefaultMain 133.459

T = 300
time Concurrency 69.145 (10 потоков)
time NoConcurrency 19.7052
time DefaultMain 106.305

видно значительное ускорение кода без применения многопоточности и незначительное с ней (не смог придумать адекватно)
