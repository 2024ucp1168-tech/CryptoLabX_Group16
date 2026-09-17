#include "cipher.h"
#include <iostream>

using namespace std;

// ---------------------------------------------------------
// MONOALPHABETIC SUBSTITUTION ENCRYPTION
// ---------------------------------------------------------
// key[0] = substitution for A
// key[1] = substitution for B
// ...
// key[25] = substitution for Z
//
// Example:
// plaintext alphabet : ABCDEFGHIJKLMNOPQRSTUVWXYZ
// key                : QWERTYUIOPASDFGHJKLZXCVBNM
//
// A -> Q
// B -> W
// C -> E
// etc.
// ---------------------------------------------------------

string encrypt(string plaintext, string key)
{
    string ciphertext = "";

    for (int i = 0; i < (int)plaintext.length(); i++)
    {
        char ch = plaintext[i];

        // Uppercase letter
        if (ch >= 'A' && ch <= 'Z')
        {
            int index = ch - 'A';
            ciphertext += key[index];
        }

        // Lowercase letter
        else if (ch >= 'a' && ch <= 'z')
        {
            int index = ch - 'a';
            ciphertext += key[index] + ('a' - 'A');
        }

        // Space, punctuation, number, etc.
        else
        {
            ciphertext += ch;
        }
    }

    return ciphertext;
}


// ---------------------------------------------------------
// FREQUENCY ANALYSIS
// ---------------------------------------------------------

void frequency_analysis(string ciphertext)
{
    int frequency[26];

    // Initialize frequency array
    for (int i = 0; i < 26; i++)
    {
        frequency[i] = 0;
    }

    int totalLetters = 0;

    // Count letters
    for (int i = 0; i < (int)ciphertext.length(); i++)
    {
        char ch = ciphertext[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            frequency[ch - 'A']++;
            totalLetters++;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            frequency[ch - 'a']++;
            totalLetters++;
        }
    }

    cout << "\n========== LETTER FREQUENCY ANALYSIS ==========\n";

    cout << "\nTotal letters: " << totalLetters << "\n\n";

    cout << "Letter\tCount\tPercentage\n";

    for (int i = 0; i < 26; i++)
    {
        double percentage = 0;

        if (totalLetters > 0)
        {
            percentage = ((double)frequency[i] / totalLetters) * 100;
        }

        cout << char('A' + i)
             << "\t"
             << frequency[i]
             << "\t"
             << percentage
             << "%\n";
    }

    // -----------------------------------------------------
    // Sort letters according to frequency
    // -----------------------------------------------------

    char letters[26];

    for (int i = 0; i < 26; i++)
    {
        letters[i] = 'A' + i;
    }

    // Manual selection sort
    for (int i = 0; i < 25; i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < 26; j++)
        {
            if (frequency[j] > frequency[maxIndex])
            {
                maxIndex = j;
            }
        }

        // Swap frequency
        int tempFrequency = frequency[i];
        frequency[i] = frequency[maxIndex];
        frequency[maxIndex] = tempFrequency;

        // Swap letters
        char tempLetter = letters[i];
        letters[i] = letters[maxIndex];
        letters[maxIndex] = tempLetter;
    }

    cout << "\n========== DESCENDING FREQUENCY ==========\n";

    cout << "Rank\tLetter\tCount\n";

    for (int i = 0; i < 26; i++)
    {
        cout << i + 1
             << "\t"
             << letters[i]
             << "\t"
             << frequency[i]
             << "\n";
    }

    cout << "\nMost frequent letters:\n";

    int highestFrequency = frequency[0];

    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] == highestFrequency && highestFrequency > 0)
        {
            cout << letters[i] << " ";
        }
    }

    cout << "\n";
}


// ---------------------------------------------------------
// WORD FREQUENCY ANALYSIS
// ---------------------------------------------------------

void word_frequency_analysis(string ciphertext)
{
    string words[1000];
    int frequencies[1000];

    int wordCount = 0;

    // Initialize
    for (int i = 0; i < 1000; i++)
    {
        frequencies[i] = 0;
    }

    string currentWord = "";

    for (int i = 0; i <= (int)ciphertext.length(); i++)
    {
        char ch;

        if (i == (int)ciphertext.length())
        {
            ch = ' ';
        }
        else
        {
            ch = ciphertext[i];
        }

        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z'))
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + ('a' - 'A');
            }

            currentWord += ch;
        }
        else
        {
            if (currentWord.length() > 0)
            {
                // Search if word already exists
                int found = -1;

                for (int j = 0; j < wordCount; j++)
                {
                    if (words[j] == currentWord)
                    {
                        found = j;
                        break;
                    }
                }

                if (found != -1)
                {
                    frequencies[found]++;
                }
                else if (wordCount < 1000)
                {
                    words[wordCount] = currentWord;
                    frequencies[wordCount] = 1;
                    wordCount++;
                }

                currentWord = "";
            }
        }
    }

    // Sort by frequency
    for (int i = 0; i < wordCount - 1; i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < wordCount; j++)
        {
            if (frequencies[j] > frequencies[maxIndex])
            {
                maxIndex = j;
            }
        }

        int tempFreq = frequencies[i];
        frequencies[i] = frequencies[maxIndex];
        frequencies[maxIndex] = tempFreq;

        string tempWord = words[i];
        words[i] = words[maxIndex];
        words[maxIndex] = tempWord;
    }

    cout << "\n========== WORD FREQUENCY ANALYSIS ==========\n";

    cout << "Word\tFrequency\n";

    for (int i = 0; i < wordCount; i++)
    {
        cout << words[i] << "\t" << frequencies[i] << "\n";
    }
}

void pattern_analysis(string ciphertext)
{
    string words[1000];
    int wordCount = 0;

    string currentWord = "";

    for (int i = 0; i <= (int)ciphertext.length(); i++)
    {
        char ch;

        if (i == (int)ciphertext.length())
            ch = ' ';
        else
            ch = ciphertext[i];

        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z'))
        {
            if (ch >= 'A' && ch <= 'Z')
                ch = ch + ('a' - 'A');

            currentWord += ch;
        }
        else
        {
            if (currentWord.length() > 0)
            {
                words[wordCount] = currentWord;
                wordCount++;

                currentWord = "";
            }
        }
    }

    cout << "\n========== WORD PATTERN ANALYSIS ==========\n";

    // -----------------------------------------------------
    // One-letter words
    // -----------------------------------------------------

    cout << "\nOne-letter words:\n";

    for (int i = 0; i < wordCount; i++)
    {
        if (words[i].length() == 1)
        {
            cout << words[i] << " ";
        }
    }

    // -----------------------------------------------------
    // Two-letter words
    // -----------------------------------------------------

    cout << "\n\nTwo-letter words:\n";

    for (int i = 0; i < wordCount; i++)
    {
        if (words[i].length() == 2)
        {
            cout << words[i] << " ";
        }
    }

    // -----------------------------------------------------
    // Three-letter words
    // -----------------------------------------------------

    cout << "\n\nThree-letter words:\n";

    for (int i = 0; i < wordCount; i++)
    {
        if (words[i].length() == 3)
        {
            cout << words[i] << " ";
        }
    }

    // -----------------------------------------------------
    // Repeated words
    // -----------------------------------------------------

    cout << "\n\nRepeated words:\n";

    for (int i = 0; i < wordCount; i++)
    {
        bool alreadyDisplayed = false;

        for (int k = 0; k < i; k++)
        {
            if (words[k] == words[i])
            {
                alreadyDisplayed = true;
                break;
            }
        }

        if (alreadyDisplayed)
            continue;

        int count = 0;

        for (int j = 0; j < wordCount; j++)
        {
            if (words[i] == words[j])
            {
                count++;
            }
        }

        if (count > 1)
        {
            cout << words[i]
                 << " -> "
                 << count
                 << " times\n";
        }
    }

    // -----------------------------------------------------
    // Repeated letter patterns
    // -----------------------------------------------------

    cout << "\nRepeated letter patterns:\n";

    for (int i = 0; i < wordCount; i++)
    {
        string pattern = "";

        int nextNumber = 0;
        int mapping[26];

        for (int j = 0; j < 26; j++)
        {
            mapping[j] = -1;
        }

        for (int j = 0; j < (int)words[i].length(); j++)
        {
            int index = words[i][j] - 'a';

            if (mapping[index] == -1)
            {
                mapping[index] = nextNumber;
                nextNumber++;
            }

            // Convert number to character for displaying pattern
            pattern += char('0' + mapping[index]);
        }

        cout << words[i] << " -> " << pattern << "\n";
    }
}
void display_partial_plaintext(string ciphertext,
                               string substitution)
{
    string partial = apply_substitution(ciphertext,
                                         substitution);

    cout << "\n========== PARTIAL PLAINTEXT ==========\n";

    cout << partial << "\n";
}
string apply_substitution(string ciphertext, string substitution)
{
    string result = "";

    for (int i = 0; i < (int)ciphertext.length(); i++)
    {
        char ch = ciphertext[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            int index = ch - 'A';

            if (substitution[index] != '?')
                result += substitution[index];
            else
                result += '_';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            int index = ch - 'a';

            if (substitution[index] != '?')
                result += substitution[index];
            else
                result += '_';
        }
        else
        {
            result += ch;
        }
    }

    return result;
}