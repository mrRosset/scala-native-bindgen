#ifndef SCALA_NATIVE_BINDGEN_ENUM_H
#define SCALA_NATIVE_BINDGEN_ENUM_H


#include <string>
#include <vector>
#include "TypeDef.h"
#include <llvm/Support/raw_ostream.h>

class Enumerator {
public:
    Enumerator(std::string name, uint64_t value);

    std::string getName();

private:
    std::string name;
    uint64_t value;
};


class Enum {
public:
    Enum(std::string name, std::vector<Enumerator> enumerators);

    bool isAnonymous() const;

    TypeDef generateTypeDef() const;

    friend llvm::raw_ostream &operator<<(llvm::raw_ostream &s, const Enum &e);

private:
    std::string name; // might be empty
    std::vector<Enumerator> enumerators;
};


#endif //SCALA_NATIVE_BINDGEN_ENUM_H