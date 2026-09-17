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

/* =========================================================
   5. kasiski_analysis()

   Counts how frequently each possible key length occurs
   as a factor of the repeated-pattern distances.

   Returns candidate key lengths in descending order.
   ========================================================= */

vector<int> kasiski_analysis(
    vector<int> distances)
{
    map<int, int> count;

    for (int distance : distances)
    {
        for (int keyLength = 2;
             keyLength <= 20;
             keyLength++)
        {
            if (distance % keyLength == 0)
            {
                count[keyLength]++;
            }
        }
    }

    vector<pair<int, int>> values;

    for (auto x : count)
    {
        values.push_back({x.first, x.second});
    }

    sort(values.begin(), values.end(),
         [](pair<int, int> a, pair<int, int> b)
         {
             return a.second > b.second;
         });

    vector<int> candidates;

    cout << "\n========== KASISKI ANALYSIS ==========\n";

    cout << "Possible key lengths:\n";

    for (auto x : values)
    {
        cout << "Length " << x.first
             << " -> " << x.second
             << " factor occurrences\n";

        candidates.push_back(x.first);
    }

    return candidates;
}


/* =========================================================
   6. calculate_ic()

   Index of Coincidence:

             sum f[i](f[i]-1)
   IC = ----------------------------
             N(N-1)

   English text usually has IC around 0.066.

   Random text has IC around 0.038.
   ========================================================= */

double calculate_ic(string text)
{
    int n = text.length();

    if (n <= 1)
        return 0.0;

    int frequency[26] = {0};

    for (char c : text)
    {
        frequency[c - 'A']++;
    }

    double numerator = 0;

    for (int i = 0; i < 26; i++)
    {
        numerator +=
            frequency[i] * (frequency[i] - 1);
    }

    double denominator = n * (n - 1);

    return numerator / denominator;
}
