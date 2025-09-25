#include <bits/stdc++.h>
using namespace std;

// Function to find the best rhyming word
string rhymeWords(const string& S, const vector<string>& D) {
    string best_word = "No Word";
    int max_match_length = 0;

    for (const string& word : D) {
        if (word == S) continue; // Skip the same word

        int min_length = min(S.size(), word.size());
        int match_length = 0;

        // Compare from the end of both strings
        for (int i = 1; i <= min_length; i++) {
            if (S[S.size() - i] == word[word.size() - i]) {
                match_length++;
            } else {
                break;
            }
        }

        // Update the best word if we find a longer suffix
        if (match_length > max_match_length) {
            max_match_length = match_length;
            best_word = word;
        }
    }

    return best_word;
}

int main() {
    string S = "thunder";
    vector<string> D = {"pukle", "thunder", "powder", "blender", "under"};

    string output = rhymeWords(S, D);
    cout << output << endl;  // Expected: under

    return 0;
}
