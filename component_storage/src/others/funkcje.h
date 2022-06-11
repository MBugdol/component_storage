#ifndef FUNKCJE
#define FUNKCJE
#include <string>
#include <vector>
#include "komponenty/komponent.h"
#include "producenci/producent.h"
#include "others/storageHandler.h"

// 
// SIUnit
// 
SIUnit getSIUnit(const std::string&, SIUnit = {-1, ""});
SIUnit getSIUnit(std::istream&);
SIUnit convertToSI(const std::string&);
SIUnit standardiseSI(SIUnit&);

// 
// String
// 
std::string getString(const std::string&, std::string = "");
std::string getString(std::istream&, char delim = ';');
std::string convertToString(ComponentType);
std::string convertToString(SolderType);
inline void removeWhiteSpace(std::string&);
inline void convertToLower(std::string&);
std::string copyToLower(const std::string&);
//
// Basic
//
int getInt(const std::string&, int = -1);
int getInt(std::istream&);
double getDouble(const std::string&, double = -1);
double getDouble(std::istream&);

//
// ComponentType
//
ComponentType getComponentType(const std::string&, ComponentType = ComponentType::Undefined);
ComponentType getComponentType(std::istream&);
ComponentType convertToComponentType(std::string&);
ComponentType convertToComponentType(int);

//
// SolderType
//
SolderType getSolderType(const std::string&, SolderType = SolderType::Undefined);
SolderType getSolderType(std::istream&);
SolderType convertToSolderType(std::string&);


Producent getProducent();
#endif