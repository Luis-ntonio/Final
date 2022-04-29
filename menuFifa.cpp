#ifndef MENUFIFA_CPP
#define MENUFIFA_CPP

#include "ExtendibleHashing/CSVReader.h"
#include "ExtendibleHashing/FifaGenerator.h"
#include "ExtendibleHashing/ExtendibleHashing.h"

#include <iostream>
bool isBuilded = 1;

bool buildFifa() {
    generate_fifa_dat();
    isBuilded = 1;
}
std::hash<std::string> hash_fn_str;



extern "C"
bool inserted(char* record, long pos) {
    if (!isBuilded) buildFifa();
    Registros::CartaFifa fifa;
    fifa.readCSVLine2(record);
    ExtendibleHashing<size_t, 3, 3> eh("fifa");
    size_t value = hash_fn_str(fifa.id);    
    return eh.insert(value, pos);
} // Like line in csv

extern "C"
char* searched(char* id, char* aux) {
    if (!isBuilded) buildFifa();
    ExtendibleHashing<size_t, 3, 3> eh("fifa");
    size_t key = hash_fn_str(id);
    Record <size_t> record = eh.search(key);
    readAt(record.pos, aux);
    cout<<"llegue hasta aqui";
    return aux;
} // Like id in csv

extern "C"
bool removed(char* id) {
    if (!isBuilded) throw(runtime_error("Fifa not builded"));
    ExtendibleHashing<int, 3, 3> eh("fifa");
    size_t key = hash_fn_str(id);
    return eh.remove(key);
}

#endif