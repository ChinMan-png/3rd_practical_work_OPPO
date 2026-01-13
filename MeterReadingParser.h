#pragma once
#include <sstream>
#include <string>

using namespace std;

#include "MeterReading.h"
#include "ParserException.h"

class MeterReadingParser {
public:
    static MeterReading Parse(const string& input) {
        stringstream ss(input);

        string object_type;
        ss >> object_type;

        if (object_type != "MeterReading") {
            throw ParserException("Неизвестный тип объекта");
        }

        MeterReading reading;
        reading.resource_type = ParseQuotedString(ss);

        if (!(ss >> reading.date)) {
            throw ParserException("Ошибка чтения даты");
        }

        if (!(ss >> reading.value)) {
            throw ParserException("Ошибка чтения значения");
        }

        return reading;
    }

private:
    static string ParseQuotedString(stringstream& ss) {
        ss >> ws;

        if (ss.peek() != '"') {
            throw ParserException("Ожидалась строка в кавычках");
        }

        ss.get();
        string result;
        getline(ss, result, '"');

        if (result.empty()) {
            throw ParserException("Пустая строка ресурса");
        }

        return result;
    }
};

