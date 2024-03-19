#ifndef WORD_COUNTER_H
#define WORD_COUNTER_H

#include <string>
#include <unordered_map>

class word_counter {
public:
    word_counter();
    void countWords(const std::string& filename);
    void displayWordFrequencies() const;

private:
    std::unordered_map<std::string, int> wordFrequencies;
};

#endif // WORD_COUNTER_H
