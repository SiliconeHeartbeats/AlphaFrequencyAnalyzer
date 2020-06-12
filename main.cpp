#include "FrequencyAnalyzer.h"

ANFrequency crypto;

int main() {
    int input = 0;
    int choice = 0;
    std::cout << "(1)Enter text directly or (2)read from file?: ";
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    if (choice == 1) {
        crypto.build();
        crypto.printfrequency();
    }
    else if (choice == 2) {
        crypto.scanbuild();
        crypto.printfrequency();
    }
    else {
        std::cout << "\nInvalid entry :c\n";
        return 1;
    }
   
    std::cout << "\nEnter any character to exit\n";
    std::cout << crypto.whiteSpaceFreeInput.size() << "\n";
    std::cin >> input;
    return 0;
}
