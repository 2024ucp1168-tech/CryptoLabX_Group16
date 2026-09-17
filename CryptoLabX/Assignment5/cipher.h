#ifndef CIPHER_H
#define CIPHER_H

#include <string>

using namespace std;

// Encryption
string encrypt(string plaintext, string key);

// Frequency analysis
void frequency_analysis(string ciphertext);

// Word frequency analysis
void word_frequency_analysis(string ciphertext);

void pattern_analysis(string ciphertext);
string apply_substitution(string ciphertext, string substitution);
void display_partial_plaintext(string ciphertext, string substitution);
bool verify_solution(string plaintext,
                     string ciphertext,
                     string key);

#endif