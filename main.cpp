#include <iostream>
#include <string>

using namespace std;

#include "Tests.h"
#include "MeterReadingParser.h"

int main() {
    setlocale(LC_ALL,"rus");
    Tests::RunAll();

    cout << "Введите показания счетчика([MeterReading] \"[Тип ресурса]\" [Дата] [Значение])\n";

    string input;
    getline(cin, input);

    try {
        MeterReading r = MeterReadingParser::Parse(input);
        cout << "Тип ресурса: " << r.resource_type << endl;
        cout << "Дата: " << r.date << endl;
        cout << "Значение: " << r.value << endl;
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}

