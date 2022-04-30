#ifndef MENUFIFA_CPP
#define MENUFIFA_CPP
#include <iostream>
#include "./ExtendibleHashing/ExtendibleHashing.h"
#include "./ExtendibleHashing/CSVReader.h"

bool inserted(char* line, long pos) {
    Registros::CartaFifa fifa;
    std::string str(line);
    fifa.readCSVLine(str);
    ExtendibleHashing<size_t,3,3> eh("./ExtendibleHashing/fifa");
    std::hash<std::string> hash_fifa;
    size_t pre_hash = hash_fifa(fifa.id);
    return eh.insert(pre_hash, pos);
}

bool removed(char* line) {
    std::hash<std::string> hash_fifa;
    ExtendibleHashing<size_t,3,3> eh("./ExtendibleHashing/fifa");
    size_t pre_hash = hash_fifa(line);
    return eh.remove(pre_hash);
}
extern "C"
char* searched(char* line, char* aux) {
    Registros::CartaFifa fifa;;
    ExtendibleHashing<size_t,3,3> eh("./ExtendibleHashing/fifa");
    std::hash<std::string> hash_fifa;
    std::string str(line);
    size_t pre_hash = hash_fifa(str);
    Record<size_t> output = eh.search(pre_hash);
    std::ifstream fin("./ExtendibleHashing/fifa.dat", std::ios::binary);
    if (!fin.is_open()) std::cout << "No se pudo abrir fifa.dat";
    fin.seekg(output.pos, std::ios::beg);
    fin >> fifa;
    fifa.writeCSVLine(aux);
    return aux;
}
int main(){
    char* aux =  "";
    searched("Pele", aux);
}
#endif