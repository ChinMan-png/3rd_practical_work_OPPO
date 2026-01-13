#pragma once
#include <iostream>

using namespace std;

#include "MeterReadingParser.h"

class Tests {
public:
    static void RunAll() {
        TestValidInput();
        TestInvalidType();
        TestMissingQuotes();
        TestInvalidNumber();
    }

private:
    static void TestValidInput() {
        try {
            MeterReadingParser::Parse(
                "MeterReading \"Water\" 2024.12.01 10.5");
            cout << "[OK] Valid input\n";
        }
        catch (...) {
            cout << "[FAIL] Valid input\n";
        }
    }

    static void TestInvalidType() {
        try {
            MeterReadingParser::Parse(
                "WrongType \"Water\" 2024.12.01 10.5");
            cout << "[FAIL] Invalid type\n";
        }
        catch (...) {
            cout << "[OK] Invalid type\n";
        }
    }

    static void TestMissingQuotes() {
        try {
            MeterReadingParser::Parse(
                "MeterReading Water 2024.12.01 10.5");
            cout << "[FAIL] Missing quotes\n";
        }
        catch (...) {
            cout << "[OK] Missing quotes\n";
        }
    }

    static void TestInvalidNumber() {
        try {
            MeterReadingParser::Parse(
                "MeterReading \"Water\" 2024.12.01 abc");
            cout << "[FAIL] Invalid number\n";
        }
        catch (...) {
            cout << "[OK] Invalid number\n";
        }
    }
};

