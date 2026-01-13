#pragma once
#include <stdexcept>
#include <string>

using namespace std;

class ParserException : public runtime_error {
public:
    explicit ParserException(const string& message)
        : runtime_error(message) {
    }
};
