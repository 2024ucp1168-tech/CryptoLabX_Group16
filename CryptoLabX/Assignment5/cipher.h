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

#endif