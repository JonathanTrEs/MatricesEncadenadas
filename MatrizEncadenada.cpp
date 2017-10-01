
#include "MatrizEncadenada.h"

MatrizEncadenada::MatrizEncadenada() {

}

MatrizEncadenada::MatrizEncadenada(int n) {
  pedirMatrices(n);
  calcularDimenciones();
}

void MatrizEncadenada::pedirMatrices(int tamano) {
  int m = 0;
  int n = 0;
  for (int i = 0; i < tamano; i++) {
    cout << "Introduce las dimensiones de la matriz " << i + 1 << endl;
    cin >> m >> n;
    Matriz matriz(m, n);
    v_matriz_.push_back(matriz);
  }
}

void MatrizEncadenada::calcularDimenciones() {
  dimenciones_.push_back(v_matriz_[0].getM());
  for (int i = 0; i < v_matriz_.size(); i++)
    dimenciones_.push_back(v_matriz_[i].getN());
}

MatrizEncadenada::~MatrizEncadenada() {

}

void  MatrizEncadenada::calcularTablaDiagonal() {
  vector<vector<int> > tabla;
  //Iniciamos la tabla a 0
  for (int i = 0; i < v_matriz_.size(); i++) {
    vector<int> aux;
    tabla.push_back(aux);
    for (int j = 0; j < v_matriz_.size(); j++)
      tabla[i].push_back(0);
  } 

  //inicializamos la tabla de parentesis
  vector<vector<int> > tablaParentesis;
  //Iniciamos la tabla a 0
  for (int i = 0; i < v_matriz_.size(); i++) {
    vector<int> aux;
    tablaParentesis.push_back(aux);
    for (int j = 0; j < v_matriz_.size(); j++) {
      tablaParentesis[i].push_back(-1);
      if(i == j)
        tablaParentesis[i][j] = i;
    }
  }

  int i = 0;
  int cont = 1;
  int d = cont; //j
  int j = 0; //k
  bool fin = false;
  while (!fin) { 
    //Condición para saber si hemos rellenado la tabla (si estamos en la casilla superior derecha de la tabla)
    if ((d ==  (v_matriz_.size() - 1)) && (i == 0))
      fin = true;
    tabla[i][d] = tabla[i][j] + tabla[j + 1][d] + (dimenciones_[i] * dimenciones_[j + 1] * dimenciones_[d + 1]);
    tablaParentesis[i][d] = j;
    int increment = 0; //para avanzar por k
    // bucle para calcular el minimo
    while (tabla[j + 1 + increment][d] != 0) {
      increment++;
      int aux = (tabla[i][j + increment] + tabla[j + 1 + increment][d] + (dimenciones_[i] * dimenciones_[j + 1 + increment] * dimenciones_[d + 1]));
      if (aux < tabla[i][d]) {
        tabla[i][d] = aux;
        tablaParentesis[i][d] = j+increment;
      }
    }
    //condiciones para saber si hemos rellenado la diagonal
    if (d == (v_matriz_.size() - 1)) {
      j = 0;
      i = 0;
      cont++;
      d = cont;
    }
    else {
      j++;
      i++;
      d++;
    }
  }
  
  cout << endl << "Matriz Resultado" << endl;
  for (int i = 0; i < tabla.size(); i++) {
    for (int j = 0; j < tabla[i].size(); j++)
      cout << tabla[i][j] << " ";
    cout << endl;
  } 

  cout << endl << endl << "Matriz Parentesis" << endl;
  for (int i = 0; i < tablaParentesis.size(); i++) {
    for (int j = 0; j < tablaParentesis[i].size(); j++)
      cout << tablaParentesis[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl << "Parentizacion: ";
  calcularParentesis(0, v_matriz_.size()-1, tablaParentesis);

  for(int i = 1; i < parentesis.size(); i++) {
    if(parentesis[i] == 'M' && parentesis[i-1] == '(' && parentesis[i+1] == ')') {
      parentesis[i-1] = '1';
      parentesis[i+1] = '1';
    }
  }

  int contador = 0;
  for(int i = 0; i < parentesis.size(); i++){
    if(parentesis[i] != '1') {
      if(parentesis[i] == 'M') {
        cout << parentesis[i] << contador;
        contador++;
      }
      else
        cout << parentesis[i];
    }
  }
}

void MatrizEncadenada::calcularParentesis(int ini, int fin, vector<vector<int> > tabla) {
  if(ini != fin) {
    int pivote = tabla[ini][fin];
    parentesis.push_back('(');
    calcularParentesis(ini, pivote, tabla);
    parentesis.push_back(')');
    parentesis.push_back('x');
    parentesis.push_back('(');
    calcularParentesis(pivote+1,fin,tabla);
    parentesis.push_back(')');
  }
  else {
    parentesis.push_back('M');
  }
}

void  MatrizEncadenada::calcularTablaFilas() {
    vector<vector<int> > tabla;
  //Iniciamos la tabla a 0
  for (int i = 0; i < v_matriz_.size(); i++) {
    vector<int> aux;
    tabla.push_back(aux);
    for (int j = 0; j < v_matriz_.size(); j++)
      tabla[i].push_back(0);
  } 

  //inicializamos la tabla de parentesis
  vector<vector<int> > tablaParentesis;
  //Iniciamos la tabla a 0
  for (int i = 0; i < v_matriz_.size(); i++) {
    vector<int> aux;
    tablaParentesis.push_back(aux);
    for (int j = 0; j < v_matriz_.size(); j++) {
      tablaParentesis[i].push_back(-1);
      if(i == j)
        tablaParentesis[i][j] = i;
    }
  }

  int i =  v_matriz_.size()-2;
  int cont = v_matriz_.size()-1;
  int d = v_matriz_.size()-1; //j
  int j = i; //k
  bool fin = false;
  while (!fin) { 
    //Condición para saber si hemos rellenado la tabla (si estamos en la casilla superior derecha de la tabla)
    if ((d ==  (v_matriz_.size() - 1)) && (i == 0))
      fin = true;
    tabla[i][d] = tabla[i][j] + tabla[j + 1][d] + (dimenciones_[i] * dimenciones_[j + 1] * dimenciones_[d + 1]);
    tablaParentesis[i][d] = j;
    int increment = 0; //para avanzar por k
    // bucle para calcular el minimo
    while (tabla[j + 1 + increment][d] != 0) {
      increment++;
      int aux = (tabla[i][j + increment] + tabla[j + 1 + increment][d] + (dimenciones_[i] * dimenciones_[j + 1 + increment] * dimenciones_[d + 1]));
      if (aux < tabla[i][d]) {
        tabla[i][d] = aux;
        tablaParentesis[i][d] = j+increment;
      }
    }
    //condiciones para saber si hemos rellenado la fila
    if (d == (v_matriz_.size() - 1)) {
      i = i-1;
      j = i;
      cont = cont -1;
      d = cont;
    }
    else {
      d++;
      j=i;
    }
  }
  
  cout << endl << "Matriz Resultado" << endl;
  for (int i = 0; i < tabla.size(); i++) {
    for (int j = 0; j < tabla[i].size(); j++)
      cout << tabla[i][j] << " ";
    cout << endl;
  } 

  cout << endl << endl << "Matriz Parentesis" << endl;
  for (int i = 0; i < tablaParentesis.size(); i++) {
    for (int j = 0; j < tablaParentesis[i].size(); j++)
      cout << tablaParentesis[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl << "Parentizacion: ";
  calcularParentesis(0, v_matriz_.size()-1, tablaParentesis);

  for(int i = 1; i < parentesis.size(); i++) {
    if(parentesis[i] == 'M' && parentesis[i-1] == '(' && parentesis[i+1] == ')') {
      parentesis[i-1] = '1';
      parentesis[i+1] = '1';
    }
  }

  int contador = 0;
  for(int i = 0; i < parentesis.size(); i++){
    if(parentesis[i] != '1') {
      if(parentesis[i] == 'M') {
        cout << parentesis[i] << contador;
        contador++;
      }
      else
        cout << parentesis[i];
    }
  }
}

void  MatrizEncadenada::calcularTablaColumnas() {
    vector<vector<int> > tabla;
  //Iniciamos la tabla a 0
  for (int i = 0; i < v_matriz_.size(); i++) {
    vector<int> aux;
    tabla.push_back(aux);
    for (int j = 0; j < v_matriz_.size(); j++)
      tabla[i].push_back(0);
  } 

  //inicializamos la tabla de parentesis
  vector<vector<int> > tablaParentesis;
  //Iniciamos la tabla a 0
  for (int i = 0; i < v_matriz_.size(); i++) {
    vector<int> aux;
    tablaParentesis.push_back(aux);
    for (int j = 0; j < v_matriz_.size(); j++) {
      tablaParentesis[i].push_back(-1);
      if(i == j)
        tablaParentesis[i][j] = i;
    }
  }

  int i =  0;
  int d = 1; //j
  int j = i; //k
  bool fin = false;
  while (!fin) { 
    //Condición para saber si hemos rellenado la tabla (si estamos en la casilla superior derecha de la tabla)
    if ((d ==  (v_matriz_.size() - 1)) && (i == 0))
      fin = true;
    tabla[i][d] = tabla[i][j] + tabla[j + 1][d] + (dimenciones_[i] * dimenciones_[j + 1] * dimenciones_[d + 1]);
    tablaParentesis[i][d] = j;
    int increment = 0; //para avanzar por k
    // bucle para calcular el minimo
    while (tabla[j + 1 + increment][d] != 0) {
      increment++;
      int aux = (tabla[i][j + increment] + tabla[j + 1 + increment][d] + (dimenciones_[i] * dimenciones_[j + 1 + increment] * dimenciones_[d + 1]));
      if (aux < tabla[i][d]) {
        tabla[i][d] = aux;
        tablaParentesis[i][d] = j+increment;
      }
    }
    //condiciones para saber si hemos rellenado la columna
    if (i == 0) {
      d = d+1;
      i = d-1;
      j = i;
    }
    else {
      i = i-1;
      j=i;
    }
  }
  
  cout << endl << "Matriz Resultado" << endl;
  for (int i = 0; i < tabla.size(); i++) {
    for (int j = 0; j < tabla[i].size(); j++)
      cout << tabla[i][j] << " ";
    cout << endl;
  } 

  cout << endl << endl << "Matriz Parentesis" << endl;
  for (int i = 0; i < tablaParentesis.size(); i++) {
    for (int j = 0; j < tablaParentesis[i].size(); j++)
      cout << tablaParentesis[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl << "Parentizacion: ";
  calcularParentesis(0, v_matriz_.size()-1, tablaParentesis);

  for(int i = 1; i < parentesis.size(); i++) {
    if(parentesis[i] == 'M' && parentesis[i-1] == '(' && parentesis[i+1] == ')') {
      parentesis[i-1] = '1';
      parentesis[i+1] = '1';
    }
  }

  int contador = 0;
  for(int i = 0; i < parentesis.size(); i++){
    if(parentesis[i] != '1') {
      if(parentesis[i] == 'M') {
        cout << parentesis[i] << contador;
        contador++;
      }
      else
        cout << parentesis[i];
    }
  }
}