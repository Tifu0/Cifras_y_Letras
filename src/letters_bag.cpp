#include "letters_bag.h"

LettersBag::LettersBag(const LettersSet &LS){
    for(const auto &val : LS){
        int cont = val.second.repetitions;
        while(cont--){
            letters.push_back(val.first);
        }
    }
}

unsigned int LettersBag::size() const{
    return letters.size();
}

void LettersBag::insertLetter(const char c){
    letters.push_back(c);
}

void LettersBag::erase(const char c){
    for(auto it = letters.begin();it != letters.end();++it){
        if(*it == c){
            letters.erase(it);
            return;
        }
    }
}

void LettersBag::clear(){
    letters.clear();
}
char LettersBag::extractLetter() {
    // rand() % letters.size() nos da un numero entre 0 y size-1
    int indice = rand() % letters.size();
    char res = letters[indice];
    letters.erase(letters.begin() + indice);
    
    return res;
}

vector<char> LettersBag::extractLetters(int num){
    vector<char> res;
    while(num--){
        res.push_back(extractLetter());
    }
    return res;
}
