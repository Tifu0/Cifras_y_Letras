#include "dictionary.h"

void Dictionary::clear() {
    words.clear();
}
unsigned int Dictionary::size() const{
    return words.size();
}
bool Dictionary::empty() const {
    return words.empty();
}
bool Dictionary::exists(const string &val) const{
    return words.find(val) != words.end();
}
bool Dictionary::erase(const string &word){
    return words.erase(word);
}
int Dictionary::getOccurrences(const char c) const {
    int res = 0;
    for(const string &w : words){
        for(char letra : w){
            if(letra == c){
                res++;
            }
        }
    }
    return res;
}
int Dictionary::getTotalLetters() const {
    int res = 0;
    for (const string &w : words) {
        res += w.size();
    }
    return res;
}
vector<string> Dictionary::getWordsLength(const int len){
    vector<string> res;
    for(const string &w : words){
        if(w.size() == len) res.push_back(w);
    }
    return res;
}

Dictionary::iterator::iterator(set<string>::iterator iter) {
    it = iter;
}
bool Dictionary::iterator::operator==(const iterator &i) const {
    return it == i.it;
}
bool Dictionary::iterator::operator!=(const iterator &i) const {
    return it != i.it;
}
Dictionary::iterator& Dictionary::iterator::operator++() {
    ++it;
    return *this;
}
const string& Dictionary::iterator::operator*() {
    return *it;
}
Dictionary::const_iterator::const_iterator(set<string>::const_iterator iter) {
    it = iter;
}
bool Dictionary::const_iterator::operator==(const const_iterator &i) const {
    return it == i.it;
}
bool Dictionary::const_iterator::operator!=(const const_iterator &i) const {
    return it != i.it;
}
Dictionary::const_iterator& Dictionary::const_iterator::operator++() {
    ++it;
    return *this;
}
const string& Dictionary::const_iterator::operator*() {
    return *it;
}
Dictionary::iterator Dictionary::begin() {
    return iterator(words.begin());
}
Dictionary::const_iterator Dictionary::begin() const {
    return const_iterator(words.begin());
}
Dictionary::iterator Dictionary::end() {
    return iterator(words.end());
}
Dictionary::const_iterator Dictionary::end() const {
    return const_iterator(words.end());
}

pair<Dictionary::iterator,Dictionary::iterator> Dictionary::range_prefix(const string &prefix){
    if(prefix.empty()) {
        return {(*this).end(), (*this).end()};
    }
    pair<Dictionary::iterator,Dictionary::iterator> res;
    string next = prefix;
    next.back()++;
    res = {Dictionary::iterator(words.lower_bound(prefix)),Dictionary::iterator(words.lower_bound(next))};
    return res;
}
Dictionary::iterator Dictionary::find(const string &word){
    return Dictionary::iterator(words.find(word));
}
pair<Dictionary::iterator, bool> Dictionary::insert(const string &word) {
    pair<Dictionary::iterator, bool> res;
    pair<set<string>::iterator, bool> aux = words.insert(word);
    res = {Dictionary::iterator(aux.first),aux.second};
    return res;
}

istream& operator>>(istream& is, Dictionary& dic){
    string palabra;
    while (is >> palabra) {
        dic.words.insert(palabra);
    }
    return is;
}
ostream &operator<<(ostream &os, const Dictionary &dic) {
    for (const string &w : dic.words) {
        os << w << endl;
    }
    return os;
}
