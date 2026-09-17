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

/*

3. calculate_distances()

   For every repeated pattern, find the distance between
   consecutive occurrences.

   Example:

   ABC occurs at positions 5 and 35

   Distance = 35 - 5 = 30
   ========================================================= */

vector<int> calculate_distances(
    string ciphertext,
    vector<string> patterns)
{
    vector<int> distances;

    for (string pattern : patterns)
    {
        vector<int> positions;

        for (int i = 0;
             i <= (int)ciphertext.length() - 3;
             i++)
        {
            if (ciphertext.substr(i, 3) == pattern)
            {
                positions.push_back(i);
            }
        }

        for (int i = 1; i < (int)positions.size(); i++)
        {
            int distance = positions[i] - positions[i - 1];

            distances.push_back(distance);
        }
    }

    return distances;
}


/* =========================================================
   4. find_factors()

   Finds possible key lengths from the distances.

   Example:

   Distance = 30

   Factors:
   2, 3, 5, 6, 10, 15

   We normally consider key lengths from 2 to 20.
   ========================================================= */

vector<int> find_factors(vector<int> distances)
{
    vector<int> factors;

    for (int distance : distances)
    {
        for (int i = 2; i <= 20; i++)
        {
            if (distance % i == 0)
            {
                factors.push_back(i);
            }
        }
    }

    return factors;
}
