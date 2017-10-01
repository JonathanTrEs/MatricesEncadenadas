
#ifndef MATRIZENCADENADA_H_
#define MATRIZENCADENADA_H_

#include "Matriz.h"
#include <vector>

class MatrizEncadenada {
  private:
    vector<Matriz> v_matriz_;
    vector<int> dimenciones_;
    vector<char> parentesis;
  public:
    MatrizEncadenada();
    MatrizEncadenada(int);
    ~MatrizEncadenada();
    void pedirMatrices(int);
    void calcularDimenciones();
    void calcularTablaDiagonal();
    void calcularTablaFilas();
    void calcularTablaColumnas();
    void calcularParentesis(int ini, int fin, vector<vector<int> > tabla);
};

#endif /* MATRIZENCADENADA_H_  */

