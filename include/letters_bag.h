#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "letters_set.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;


class LettersBag {
private:
    vector<char> letters;
public:
  /**
   * @brief Constructor por defecto
   *
   * Crea un lettersbag vacío
   */
    LettersBag() = default;
  /**
   * @brief Constructor por letterset
   *
   * Crea un lettersbag a base de un letterset
   */
    LettersBag(const LettersSet &LS);
  /**
   * @brief Destructor
   */
    ~LettersBag() = default;

  /**
   * @brief Tamaño del letterbag
   *
   * @return Número de letras guardadas
   */
    unsigned int size() const;
  /**
     * @brief Inserta en letterbag
     *
     * @param c letra a insertar
     */
    void insertLetter(const char c);
  /**
   * @brief Elimina una letra de lettersbag
   *
   * @param c letra a borrar del lettersbag
   *
   */
    void erase(const char c);
  /**
   * @brief Limpia el lettersbag
   *
   * @post el letterbag queda vacio
   */
    void clear();
  /**
   * @brief Extrae una letra del lettersbag
   *
   * @return extrae eliminando la primera letra
   */
    char extractLetter();
  /**
   * @brief Extrae varias letras del lettersbag
   * @param num numero de letras a extraer
   * @return extrae las primeras letras
   */
    vector<char> extractLetters(const int num);
};

#endif
