
#include "MatrizEncadenada.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

double timeval_diff(struct timeval *a,struct timeval *b){
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) - (double)(b->tv_sec + (double)b->tv_usec/1000000);
}

int opcion() {
  cout << endl;
  cout << "1. Rellenar por Diagonales" << endl;
  cout << "2. Rellenar por Columnas" << endl;
  cout << "3. Rellenar por Filas" << endl;
  cout << ">";
  int opc;
  cin >> opc;
  cout << endl;
  return opc;
}

void menu(MatrizEncadenada a) {
  srand(time(NULL));
  struct timeval iniTime, endTime;
  int opc = opcion();
  switch (opc) {
    case 1:
        gettimeofday(&iniTime, NULL);
    	a.calcularTablaDiagonal();
    	gettimeofday(&endTime, NULL);
    	break;
    case 2:
    	gettimeofday(&iniTime, NULL);
    	a.calcularTablaColumnas();
    	gettimeofday(&endTime, NULL);
    	break;
    case 3:
    	gettimeofday(&iniTime, NULL);
    	a.calcularTablaFilas();
    	gettimeofday(&endTime, NULL);
    	break;
    default:
    	cout << "opcion Incorrecta" << endl;
    	break;
    }
    cout << endl << timeval_diff(&endTime, &iniTime) << " Segundos" << endl;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "\nNúmero de parametros incorrecto. Encontrado " << argc-1 << " requerido 1."<< endl;
    exit(-1);
  }
  MatrizEncadenada a(atoi(argv[1]));
  menu(a);
  return 0;
}

