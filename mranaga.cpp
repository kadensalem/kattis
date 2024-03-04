#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int wordCount, letters;
    std::vector<std::string> words;

    // Read input
    std::cin >> wordCount >> letters;
    for(int i = 0; i < wordCount; i++) {
        std::string s;
        std::cin >> s;
        std::sort(s.begin(), s.end());
        words.push_back(s);
    }

    std::sort(words.begin(), words.end());

    int out = 0;
    int index = 0;
    while(index < wordCount) {
        // Check if we're at the last element in the array
        if(index == wordCount - 1) {
            out++;
            break;
        }

        std::string curr = words[index];
        std::string next = words[index + 1];

        // Unique word
        if(curr != next) {
            index++;
            out++;
            continue;
        }

        // Duplicate word
        else {
            int tempIndex = index;
            while(curr == next) {
                tempIndex++;
                next = words[tempIndex];
            }
            index = tempIndex;
        }
    }

    std::cout << out;
}
