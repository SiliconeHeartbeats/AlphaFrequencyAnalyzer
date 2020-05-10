#pragma once
#include "FrequencyAnalyzer.h"

ANFrequency crypto;

int main() {
    int input = 0;
    crypto.build();
    crypto.printfrequency();
    std::cin >> input;
    return 0;
}

