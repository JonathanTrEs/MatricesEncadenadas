
#ifndef MATRIZ_H_
#define MATRIZ_H_

#include <iostream>
#include <stdio.h>
using namespace std;

class Matriz {
  private:
    int m_;
    int n_;
  public:
    Matriz();
    Matriz(int, int);
    ~Matriz();
    int getM();
    void setM(int);
    int getN();
    void setN(int);
};

#endif /* MATRIZ_H_ */
