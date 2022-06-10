#ifndef FUNKCJE
#define FUNKCJE
#include <string>
#include <vector>
#include "komponenty/komponent.h"
#include "producenci/producent.h"
#include "others/storageHandler.h"

//!
//!SIUnit
//!
/**
 * @brief Pobiera od uzytkownika parametr w postaci SI (wartosc i mnoznik)
 * @param msg Monit do wyswietlenia uzytkownikowi
 * @return SIUnit
 */
SIUnit getSIUnit(const char*, SIUnit = {-1, ""});
SIUnit getSIUnit(std::istream&);
/**
 * @brief Konwertuje wejscie do typu SIUnit
 * @param input Wartosc do konwersji
 * @return SIUnit 
 */
SIUnit convertToSI(const std::string&);
/**
 * @brief Standaryzuje wartosc typu SIUnit (zmienia mnoznik na najbardziej optymalny, np. 22e+6m -> 22k)
 * @param SI Wartosc do zestandaryzowania
 * @return Zestandaryzowana kopia wejscia
 */
SIUnit standardiseSI(SIUnit&);

//!
//!String
//!
/**
 * @brief Pobiera od uzytkownika ciag znakow, usuwajac z niego biale znaki
 * @param msg Monit do wyswietlenia
 * @param default_value Domyslna wartosc po kliknieciu enter, domyslnie ""
 * @return Wejscie bez bialych znakow
 */
std::string getString(const char*, std::string = "");
std::string getString(std::istream&);
std::string convertToString(ComponentType);
std::string convertToString(SolderType);
/**
 * @brief Usuwa z wejscia biale znaki
 * @param str Ciag znakow do oczyszczenia
 */
inline void removeWhiteSpace(std::string&);
/**
 * @brief Zamienia ciag znakow na male litery
 * @param str Ciag znakow do konwersji
 * 
 */
inline void convertToLower(std::string&);

//!
//!Basic
//!
/**
 * @brief Pobiera liczbe calkowita od uzytkownika
 * @param msg Monit do wyswietlenia
 * @param default_value Domyslna wartosc po kliknieciu enter, domyslnie -1
 * @return Wprowadzona wartosc
 */
int getInt(const char*, int = -1);
int getInt(std::istream&);
/**
 * @brief Pobiera liczbe zmiennoprzecinkowa od uzytkownika
 * @param msg Monit do wyswietlenia
 * @param default_value Domyslna wartosc po kliknieciu enter, domyslnie -1
 * @return Wprowadzona wartosc 
 */
double getDouble(const char*, double = -1);
double getDouble(std::istream&);

//!
//!ComponentType
//!
ComponentType getComponentType(const char*, ComponentType = ComponentType::Undefined);
ComponentType getComponentType(std::istream&);
ComponentType convertToComponentType(std::string&);
ComponentType convertToComponentType(int);

//!
//!SolderType
//!
SolderType getSolderType(const char*, SolderType = SolderType::Undefined);
SolderType getSolderType(std::istream&);
SolderType convertToSolderType(std::string&);


Producent getProducent();
#endif