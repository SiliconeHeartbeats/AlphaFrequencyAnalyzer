#include "FrequencyAnalyzer.h"

ANFrequency Crypto;

int main() {
    int input = 0;
    Crypto.build();
    Crypto.printfrequency();
    std::cin >> input;
    return 0;
}

