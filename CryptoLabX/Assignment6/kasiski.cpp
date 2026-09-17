#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;


/* =========================================================
   1. clean_ciphertext()

   Removes spaces, digits and special characters.
   Converts all letters to uppercase.
   ========================================================= */

string clean_ciphertext(string ciphertext)
{
    string clean = "";

    for (char c : ciphertext)
    {
        if (isalpha(c))
        {
            clean += toupper(c);
        }
    }

    return clean;
}


/* =========================================================
   2. find_repeated_patterns()

   Finds repeated sequences of length 3.

   Example:

   ABC........ABC

   The pattern ABC is repeated.
   ========================================================= */

vector<string> find_repeated_patterns(string ciphertext)
{
    vector<string> patterns;

    for (int i = 0; i <= (int)ciphertext.length() - 3; i++)
    {
        string pattern = ciphertext.substr(i, 3);

        bool alreadyFound = false;

        for (string p : patterns)
        {
            if (p == pattern)
            {
                alreadyFound = true;
                break;
            }
        }

        if (alreadyFound)
            continue;

        for (int j = i + 3;
             j <= (int)ciphertext.length() - 3;
             j++)
        {
            if (ciphertext.substr(j, 3) == pattern)
            {
                patterns.push_back(pattern);
                break;
            }
        }
    }

    return patterns;
}