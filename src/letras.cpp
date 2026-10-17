#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "dictionary.h"
#include "letters_bag.h"
#include "letters_set.h"
#include "solver.h"

using namespace std;

int main(int argc, char *argv[]){
  if(argc != 5){
    cout << "Los parametros son: " << endl;
    cout << "1.- El fichero con el diccionario" << endl;
    cout << "2.- El fichero con las letras" << endl;
    cout << "3.- Número de letras generadas aleatorias" << endl;
    cout << "4.- El modo de juego (L/P)" << endl;
    return 1;
  }

  int numaleatorias = atoi(argv[3]);
  bool score_game = argv[4][0] == 'P';
  vector<char> aleatorias;
  string sol = "";
  char continuar = 'S';

  ifstream f_diccionario(argv[1]);
  if(!f_diccionario){
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 1;
  }
  Dictionary diccionario;
  f_diccionario >> diccionario;

  ifstream f_letras(argv[2]);
  if(!f_letras){
    cout << "No puedo abrir el fichero " << argv[2] << endl;
    return 1;
  }
  LettersSet conjunto_letras;
  f_letras >> conjunto_letras;

  while(continuar == 'S'){

    LettersBag bag(conjunto_letras);
    aleatorias = bag.extractLetters(numaleatorias);

    Solver solver(diccionario,conjunto_letras);
    pair<vector<string>,int> vecsols = solver.getSolutions(aleatorias,score_game);

    cout << "Las letras son: ";
    for(int i = 0; i < aleatorias.size();i++){
      cout << aleatorias[i] << " ";
    }
    cout << endl;
    cout << "Dime tu solucion:";
    cin >> sol;
    cout << sol << " Puntuacion: " << conjunto_letras.getScore(sol) << endl;
    cout << "Mis soluciones son:" << endl;
    for(const string &word : vecsols.first){
      cout << word << " Puntuacion:" << vecsols.second << endl;
    }
    cout << "Mejor Solucion:" << vecsols.first[vecsols.first.size()-1] << endl;
    cout << "¿Quieres seguir jugando[S/N]?" << endl;
    cin >> continuar;

  }
}
