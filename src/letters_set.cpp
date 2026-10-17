#include "letters_set.h"

unsigned int LettersSet::size() const{
    return charSet.size();
}

int LettersSet::getScore(const string &word) const{
    int res = 0;
    for(const char c : word){
        res += charSet.at(c).score;
    }
    return res;
}

void LettersSet::insert(const pair<char,LetterInfo> &val){
    charSet[val.first].repetitions = val.second.repetitions;
    charSet[val.first].score = val.second.score;
}

bool LettersSet::empty() const{
    return charSet.empty();
}

void LettersSet::clear(){
    charSet.clear();
}

void LettersSet::erase(const char c){
    charSet.erase(c);
}

LettersSet::iterator::iterator(map<char, LetterInfo>::iterator iter){
    it = iter;
}
bool LettersSet::iterator::operator==(const iterator &i) const {
    return it == i.it;
}
bool LettersSet::iterator::operator!=(const iterator &i) const {
    return it != i.it;
}
LettersSet::iterator& LettersSet::iterator::operator++() {
    ++it;
    return *this;
}
LettersSet::iterator& LettersSet::iterator::operator--() {
    --it;
    return *this;
}
const pair<const char, LetterInfo>& LettersSet::iterator::operator*() {
    return *it;
}
LettersSet::const_iterator::const_iterator(map<char, LetterInfo>::const_iterator iter) {
    it = iter;
}
bool LettersSet::const_iterator::operator==(const const_iterator &i) const {
    return it == i.it;
}
bool LettersSet::const_iterator::operator!=(const const_iterator &i) const {
    return it != i.it;
}
LettersSet::const_iterator& LettersSet::const_iterator::operator++() {
    ++it;
    return *this;
}
LettersSet::const_iterator& LettersSet::const_iterator::operator--() {
    --it;
    return *this;
}
const pair<const char, LetterInfo>& LettersSet::const_iterator::operator*() {
    return *it;
}
LettersSet::iterator LettersSet::begin() {
    return iterator(charSet.begin());
}
LettersSet::const_iterator LettersSet::begin() const {
    return const_iterator(charSet.begin());
}
LettersSet::iterator LettersSet::end() {
    return iterator(charSet.end());
}
LettersSet::const_iterator LettersSet::end() const {
    return const_iterator(charSet.end());
}


LetterInfo& LettersSet::operator[](char c) {
    return charSet[c];
}

const LetterInfo& LettersSet::operator[](char c) const {
    return charSet.at(c);
}

istream& operator>>(istream& is, LettersSet & letterset){
    string linea;

    //ignorar la primera linea
    if (!getline(is, linea)) return is; 

    while (getline(is,linea)) {
        istringstream ss(linea);
        char letra;
        unsigned int repetitions, score;
        ss >> letra;
        ss >> repetitions;
        ss >> score;
        letterset.charSet[letra] = LetterInfo(repetitions,score);
    }
    return is;
}

ostream& operator<<(ostream& os,const LettersSet & letterset){
    os << "Letra Cantidad Puntos" << endl;
    for(const auto &val : letterset.charSet){
        os << val.first << " " << val.second.repetitions << " " << val.second.score << endl;
    }
    return os;
}
