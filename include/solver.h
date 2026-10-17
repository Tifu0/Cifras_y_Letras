#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <string>
#include <utility>
#include <vector>

#include "letters_set.h"
#include "dictionary.h"

using namespace std;

class Solver{
private:
  Dictionary dictionary;
  LettersSet letters_set;

/**
   * @brief ver si es construible una palabra
   * @param word la palabra
   * @param vec vector de disponibles
   * @return true si es construible false en caso contrario
   */
  bool construible(const string& word, vector<int> vec);
public:
/**
   * @brief Constructor por defecto
   *
   * Crea un solver vacío
   */
  Solver() = default;
/**
   * @brief Constructor con parametros
   *
   * Crea un solver a base de diccionario y letterset
   */
  Solver(Dictionary dict, LettersSet letterset);
/**
   * @brief obtener soluciones
   * @param available_letters vector de letras disponibles
   * @param score_game si true modo de juego puntos en caso contrario por longitud
   * @return soluciones en formato de vector de string con correspondiente puntuacion máxima
   */
  pair<vector<string>, int> getSolutions(const vector<char> & available_letters,bool score_game);
};

#endif // __SOLVER_H__
