#ifndef DICTIONARY_H
#define DICTIONARY_H


#include <string>
#include <iostream>
#include <set>

#include <vector>
using namespace std;

class Dictionary {
private:
  set<string> words;
public:
  /**
   * @brief Constructor por defecto
   *
   * Crea un Dictionary vacío
   */
  Dictionary() = default;
  /**
   * @brief Destructor
   */
  ~Dictionary() = default;
  /**
   * @brief Limpia el Dictionary
   *
   * @post el diccionario queda con 0 palabras
   */
  void clear();
  /**
   * @brief Tamaño del diccionario
   *
   * @return Número de palabras guardadas en el diccionario
   */
  unsigned int size() const;
  /**
   * @brief Comprueba si el diccionario está vacio.
   * @return true si el diccionario está vacío, false en caso contrario
   */
  bool empty() const;
  /**
   * @brief Indica si una palabra esta en el diccionario o no.
   * Este método comprueba si una determinada palabra se encuentra o no en el dicccionario
   * @param word: la palabra que se quiere buscar.
   * @return Booleano indicando si la palabra existe o no en el diccionario
   */
  bool exists(const string &word) const;
  /**
   * @brief Elimina una palabra del diccionario
   *
   * @param word Palabra a borrar del diccionario
   *
   * @return Booleano que indica si la palabra se ha borrado del diccionario
   */
  bool erase(const string &word);
  /**
   * @brief Indica el numero de apariciones de una letra.
   *
   *
   * @param c letra a buscar.
   * @return Un entero indicando el numero de apariciones.
   */
  int getOccurrences(const char c) const;
  /**
  * @brief Indica el numero totales de letras
  * @return Un entero indicando el numero totales de letras
  */
  int getTotalLetters() const;
  /**
   * @brief Obtiene todas las palabras de una longitud
   * @param len: valor de longitud de la palabras a devolver
   * @return un vector con palabra de la longitud dada
   **/
  vector<string> getWordsLength(const int len);

  /**
  * @brief Iterador del diccionario. Obtiene las palabras ordenadas alfabéticamente
  */
  class iterator {
  private:
    set<string>::iterator it;
  public:
    iterator() = default;
    //añadido para no tener que usar friend
    //usado por ejemplo en begin y end
    iterator(set<string>::iterator iter);

    bool operator==(const iterator &i) const;
    bool operator!=(const iterator &i) const;
    iterator& operator++();
    const string& operator*();
  };
  /**
   * @brief Iterador constante del diccionario. Obtiene las palabras ordenadas alfabéticamente
   */
  class const_iterator {
  private:
    set<string>::const_iterator it;
  public:
    const_iterator() = default;
    //añadido para no tener que usar friend
    //para la implementacion en begin y end
    const_iterator(set<string>::const_iterator iter);

    bool operator==(const const_iterator &i) const;
    bool operator!=(const const_iterator &i) const;
    const_iterator& operator++();
    const string& operator*();
  };

  /**
   * @brief Obtiene el iterador apuntando a la primera palabra del diccionario
   */
  iterator begin();
  const_iterator begin() const;
  /**
   * @brief Obtiene el iterador apuntando al final del diccionario.
   */
  iterator end();
  const_iterator end() const;

  /**
   * @brief Indica si una palabra esta en el diccionario
   * @return iterador apuntando a la palabra si esta o end si no esta
   */
  iterator find(const string &word);
  /**
   * @brief Inserta una palabra en el diccionario
   *
   * @param word palaba a insertar en el diccionario
   * @return Booleano que indica si la inserción ha tenido éxito. Una palabra se inserta
   * con éxito si no existía previamente en el diccionario. El iterador apunta a la palabra
   */
  pair<iterator, bool> insert(const string &word);
  /**
   * @brief Busca un las palabras con un prefijo
   *
   * @param val prefijo a buscar
   * @return un pair con dos iteradores el primero apuntando a la primera palaba con el prefijo y
   * el segundo donde ya no contiene el prefijo. Si no existe el prefijo se devuelve los dos
   * iteradores apuntando a end()
   */
  pair<iterator,iterator> range_prefix(const string &prefix);
  
  /**
   * @brief Sobrecarga del operador de entrada
   *
   * Permite leer las palabras de un fichero de texto e introducirlas en el
   * diccionario
   * @param is Flujo de entrada
   * @param dic Diccionario a rellenar
   * @return Flujo de entrada para poder encadenar el operador
   */
  friend istream& operator>>(istream& is, Dictionary& dic);
  /**
   * @brief Sobrecarga del operador de salida
   *
   * Permite imprimir el diccionario completo a un flujo de salida
   *
   * @param os Flujo de salida, donde imprimir el diccionario
   * @param dic Diccionario a imprimir
   * @return Flujo de salida, para poder encadenar el operador
   */
  friend ostream &operator<<(ostream &os, const Dictionary &dic);
};
#endif 
