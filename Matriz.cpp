
#include "Matriz.h"

Matriz::Matriz() {
  m_ = 0;
  n_ = 0;
}

Matriz::Matriz(int m, int n) {
  m_ = m;
  n_ = n;
}

Matriz::~Matriz() {

}

int Matriz::getM() {
  return m_;
}

void Matriz::setM(int m) {
  m_ = m;
}

int Matriz::getN() {
  return n_;
}

void Matriz::setN(int n) {
  n_ = n;
} 
