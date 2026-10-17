#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <iostream>
#include <map>
#include <sstream>

using namespace std;

struct LetterInfo{
  unsigned int repetitions;
  unsigned int score;

  /**
   * @brief Constructor por defecto
   */
  LetterInfo(): repetitions(0), score(0){}

  /**
   * @brief Constructor con parámetros
   *
   * @param reps Número de repeticiones del carácter en la partida
   * @param score Puntuación del carácter
   */
  LetterInfo(unsigned int reps, unsigned int score): repetitions(reps), score(score){};
};


class LettersSet{
private:
  map<char, LetterInfo> charSet;
public:
  /**
   * @brief Constructor por defecto
   *
   * Crea un letterset vacío
   */
  LettersSet() = default;
  /**
   * @brief Destructor
   */
  ~LettersSet() = default;
  /**
   * @brief Tamaño del letterset
   *
   * @return Número de letras guardadas
   */
  unsigned int size() const;
  /**
     * @brief score de una palabra
     * @param word la palabra
     * @return el score de la palabra
     */
  int getScore(const string &word) const;
  /**
     * @brief Inserta en letterset
     *
     * @param val info a insertar en el letterset
     */
  void insert(const pair<char,LetterInfo> &val); 
  /**
   * @brief Comprueba si el letterset está vacio.
   * @return true si el letterset está vacío, false en caso contrario
   */
  bool empty() const;
  /**
   * @brief Limpia el letterset
   *
   * @post el letterset queda vacio
   */
  void clear();
  /**
   * @brief Elimina una letra e info de letterset
   *
   * @param c letra a borrar del letterset
   *
   */
  void erase(const char c);

  /**
  * @brief Iterador del letterset.
  */
  class iterator {
  private:
    map<char, LetterInfo>::iterator it;
  public:
    iterator() = default;
    //añadido para no tener que usar friend
    //usado por ejemplo en begin y end
    iterator(map<char, LetterInfo>::iterator iter);

    bool operator==(const iterator &i) const;
    bool operator!=(const iterator &i) const;
    iterator& operator++();
    iterator& operator--();
    const pair<const char, LetterInfo>& operator*();
  };
  /**
   * @brief Iterador constante del letterset
   */
  class const_iterator {
  private:
    map<char, LetterInfo>::const_iterator it;
  public:
    const_iterator() = default;
    //añadido para no tener que usar friend
    //para la implementacion en begin y end
    const_iterator(map<char, LetterInfo>::const_iterator iter);

    bool operator==(const const_iterator &i) const;
    bool operator!=(const const_iterator &i) const;
    const_iterator& operator++();
    const_iterator& operator--();
    const pair<const char, LetterInfo>& operator*();
  };
  /**
   * @brief Obtiene el iterador apuntando a lo primero
   */
  iterator begin();
  const_iterator begin() const;
  /**
   * @brief Obtiene el iterador apuntando al final
   */
  iterator end();
  const_iterator end() const;
  
  /**
   * @brief Sobrecarga del operador []
   *
   * Permite hacer que hacer [] sobre objeto actue como si
   * hicieras [] con el miembro privado
   * @param c letra de clave
   * @return Letterinfo correspondiente
   */
  LetterInfo& operator[](char c);
  /**
   * @brief Sobrecarga del operador [] constante
   *
   * Permite hacer que hacer [] sobre objeto actue como si
   * hicieras [] con el miembro privado
   * @param c letra de clave
   * @return Letterinfo correspondiente
   */
  const LetterInfo& operator[](char c) const;
  /**
   * @brief Sobrecarga del operador de entrada
   *
   * Permite leer las letras de un fichero de texto e introducirlas en el
   * letterset
   * @param is Flujo de entrada
   * @param letterset Letterset a rellenar
   * @return Flujo de entrada para poder encadenar el operador
   */
  friend istream& operator>>(istream& is, LettersSet & letterset);
  /**
   * @brief Sobrecarga del operador de salida
   *
   * Permite imprimir el letterset completo a un flujo de salida
   *
   * @param os Flujo de salida, donde imprimir el letterset
   * @param letterset Letterset a imprimir
   * @return Flujo de salida, para poder encadenar el operador
   */
  friend ostream &operator<<(ostream &os, const LettersSet & letterset);
};

#endif
