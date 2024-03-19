#include "word_counter.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    word_counter counter;
    counter.countWords(argv[1]);
    counter.displayWordFrequencies();

    return 0;
}
