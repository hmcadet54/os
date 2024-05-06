#include "word_counter.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

word_counter::word_counter() {}

void word_counter::countWords(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            for (char& c : word) {
                if (ispunct(c)) {
                    c = ' ';
                } else {
                    c = tolower(c);
                }
            }
            if (!word.empty()) {
                wordFrequencies[word]++;
            }
        }
    }

    file.close();
}

void word_counter::displayWordFrequencies() const {
    int frword=0;
    for (const auto& pair : wordFrequencies) {
        cout << pair.first << ": " << pair.second << endl;
        frword+=pair.second;

    }
    cout<<"Total words: "<<frword<<endl;
}
