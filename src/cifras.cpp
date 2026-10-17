#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <random>
#include <algorithm>

using namespace std;

bool esMejor(pair<int,vector<char>> actual, pair<int,vector<char>> best, int objetivo){
    bool es_mejor;
    if (best.second.empty() && best.first == 0 && actual.first != 0) {
        es_mejor = true;
    } else{
        if(abs(actual.first - objetivo) < abs(best.first - objetivo)){
        es_mejor = true;
        }else if(abs(actual.first - objetivo) > abs(best.first - objetivo)){
        es_mejor = false;
        }else{ 
        es_mejor = actual.second.size() < best.second.size();
        }
    }
    return es_mejor;
}

vector<pair<int,vector<char>>> GeneraOperaciones(pair<int,vector<char>> actual,int n){
    vector<pair<int,vector<char>>> res;

    vector<char> suma = actual.second;
    suma.push_back('+');
    res.emplace_back(actual.first+n,suma);

    if(actual.first - n > 0){
        vector<char> diferencia = actual.second;
        diferencia.push_back('-');
        res.emplace_back(actual.first-n,diferencia);
    }

    //evitamos multiplicar por 0 para no generar resultados redundantes
    if(n != 0 && actual.first != 0){
        vector<char> multiplicacion = actual.second;
        multiplicacion.push_back('*');
        res.emplace_back(actual.first*n,multiplicacion);
    }

    if(actual.first != 0 && n != 0 && actual.first % n == 0){
        vector<char> division = actual.second;
        division.push_back('/');
        res.emplace_back(actual.first/n,division);
    }
    return res;
}

bool Cifras(vector<int> S,int objetivo,pair<int,vector<char>> &actual,pair<int,vector<char>> &best){
    if(actual.first == objetivo){
        best = actual;
        return true;
    }
    if(esMejor(actual,best,objetivo)){
        best = actual;
    }
    if(S.empty()) return false;
    for(int i = 0; i< S.size();i++){
        int num = S[i];
        vector<int> restantes(S);
        restantes.erase(restantes.begin()+i);
        
        auto operaciones = GeneraOperaciones(actual,num);
        for(auto op : operaciones){
            if(Cifras(restantes,objetivo, op,best)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int> C = {1,2,3,4,5,6,7,8,9,10,25,50,75,100};
    
    random_device rd;
    mt19937 gen(rd());
    //elementos aleatorios de C con repeticion
    uniform_int_distribution<> distC(0, C.size() - 1);
    vector<int> S;
    cout << "Numeros escogidos: ";
    for (int i = 0; i < 6; i++) {
        int index = distC(gen);
        cout << C[index] << " ";
        S.push_back(C[index]);
    }
    cout << "\n";
    //numero aleatorio de 3 cifras
    cout << "Numero de 3 cifras: ";
    uniform_int_distribution<> dist3(100, 999);
    int numero3cifras = dist3(gen);
    cout << numero3cifras << "\n";

    pair<int,vector<char>> vacio = {0, {}};
    pair<int,vector<char>> best = {0, {}};
    if(Cifras(S,numero3cifras,vacio,best)){
        cout << "Se puede llegar" << "\n";
    }else{
        cout << "No se puede llegar" << "\n";
        if (best.first != 0) {
            cout << "La mejor aproximación fue: " << best.first << "\n";
        } else {
            cout << "\n";
        }
    }
}

