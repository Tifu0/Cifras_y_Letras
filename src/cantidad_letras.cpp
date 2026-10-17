#include <fstream>
#include <iostream>
#include <cmath>
#include "dictionary.h"
#include "letters_set.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 4){
    cout << "Los parametros son: " << endl;
    cout << "1.- El fichero con el diccionario" << endl;
    cout << "2.- El fichero con las letras" << endl;
    cout << "3.- El fichero de salida"<<endl;
    return 0;
  }

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

  double min_freq = 1.0;
  int total_letters = diccionario.getTotalLetters();
  for(const auto &val : conjunto_letras){
    long long num = diccionario.getOccurrences(val.first);
    if(num > 0 && total_letters > 0){
      double porcentaje = (double)num / total_letters;
      if(min_freq > porcentaje) min_freq = porcentaje;
    }
  }

  double min_log = -log10(min_freq);
  ofstream f_salida(argv[3]);
  if(!f_salida){
      cout << "No puedo abrir el fichero de salida " << argv[3] << endl;
      return 0;
  }
  for(const auto &val : conjunto_letras){
    long long num = diccionario.getOccurrences(val.first);
    double score = 0.0;
    if(num > 0 && total_letters > 0 && min_log > 0){
      score = 10.0 * (-log10((double)num / total_letters) / min_log);
    }
    f_salida << val.first << " " << num << " " << score << endl;
  }

  f_salida.close();
}
