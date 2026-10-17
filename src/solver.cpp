#include "solver.h"

Solver::Solver(Dictionary dict, LettersSet letterset){
    dictionary = dict;
    letters_set = letterset;
}

bool Solver::construible(const string& word, vector<int> vec) {
    for(const char c : word){
        char index = c;
        
        if(vec[index] > 0){
            vec[index]--;
        } else {
            return false; // No quedan letras de este tipo
        }
    }
    return true;
}

pair<vector<string>, int> Solver::getSolutions(const vector<char> & available_letters,bool score_game){
    pair<vector<string>, int> res;
    int best = 0;
    vector<string> soluciones;
    //vector de capacidad tabla
    vector<int> total(256,0);
    for(const char c : available_letters){
        total[c]++;
    }
    int numletters = available_letters.size();
    for(const string &word : dictionary){

        //optimizacion
        if(word.size() > numletters) continue;
        //optimizacion
        if(!score_game && word.size() < best) continue;

        if(construible(word,total)){
            int curr = 0;
            if(score_game){
                curr = letters_set.getScore(word);
            }else{
                curr = word.size();
            }

            if(curr > best){
                best = curr;
                soluciones.clear();
                soluciones.push_back(word);
            }else if(curr == best){
                soluciones.push_back(word);
            }
        }
    }
    res = {soluciones,best};
    return res;
}
