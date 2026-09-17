```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>
#include <cctype>

using namespace std;


/* =========================================================
   FUNCTIONS FROM kasiski.cpp

   We declare them here because we are using only two files.
   Their actual definitions are in kasiski.cpp.
   ========================================================= */

string clean_ciphertext(string ciphertext);

vector<string> find_repeated_patterns(string ciphertext);

vector<int> calculate_distances(
    string ciphertext,
    vector<string> patterns);

vector<int> find_factors(
    vector<int> distances);

vector<int> kasiski_analysis(
    vector<int> distances);

double calculate_ic(string text);


/* =========================================================
   7. split_into_groups()

   If key length = 4:

   Ciphertext:
   ABCDEFGHIJKL...

   Group 1:
   A E I M ...

   Group 2:
   B F J N ...

   Group 3:
   C G K O ...

   Group 4:
   D H L P ...
   ========================================================= */

vector<string> split_into_groups(
    string ciphertext,
    int keyLength)
{
    vector<string> groups(keyLength);

    for (int i = 0;
         i < (int)ciphertext.length();
         i++)
    {
        groups[i % keyLength] += ciphertext[i];
    }

    return groups;
}


/* =========================================================
   8. frequency_analysis()

   Displays frequency of A-Z for every group.
   ========================================================= */

void frequency_analysis(
    vector<string> groups)
{
    cout << "\n========== FREQUENCY ANALYSIS ==========\n";

    for (int g = 0; g < (int)groups.size(); g++)
    {
        int frequency[26] = {0};

        for (char c : groups[g])
        {
            frequency[c - 'A']++;
        }

        cout << "\nGroup " << g + 1 << "\n";

        cout << "--------------------------------\n";

        cout << "Letter\tCount\tPercentage\n";

        for (int i = 0; i < 26; i++)
        {
            double percentage =
                (double)frequency[i] /
                groups[g].length() * 100;

            cout << char('A' + i)
                 << "\t"
                 << frequency[i]
                 << "\t"
                 << fixed
                 << setprecision(2)
                 << percentage
                 << "%\n";
        }
    }
}


/* =========================================================
   English letter frequencies

   Used for chi-square frequency analysis.
   ========================================================= */

double englishFrequency[26] =
{
    8.167, 1.492, 2.782, 4.253, 12.702,
    2.228, 2.015, 6.094, 6.966, 0.153,
    0.772, 4.025, 2.406, 6.749, 7.507,
    1.929, 0.095, 5.987, 6.327, 9.056,
    2.758, 0.978, 2.360, 0.150, 1.974,
    0.074
};


/* =========================================================
   9. find_shift()

   Treats one group as a Caesar cipher.

   Tries all 26 possible shifts.

   Uses chi-square to determine which shift produces
   frequencies closest to normal English.

   Returns the probable shift.
   ========================================================= */

int find_shift(string group)
{
    int n = group.length();

    double bestScore = 1e18;

    int bestShift = 0;

    for (int shift = 0;
         shift < 26;
         shift++)
    {
        int frequency[26] = {0};

        /*
           Decrypt using this possible shift.
        */

        for (char c : group)
        {
            int decrypted =
                (c - 'A' - shift + 26) % 26;

            frequency[decrypted]++;
        }

        double chiSquare = 0;

        /*
           Compare observed frequency with
           expected English frequency.
        */

        for (int i = 0; i < 26; i++)
        {
            double expected =
                n * englishFrequency[i] / 100.0;

            if (expected > 0)
            {
                chiSquare +=
                    (frequency[i] - expected) *
                    (frequency[i] - expected) /
                    expected;
            }
        }

        if (chiSquare < bestScore)
        {
            bestScore = chiSquare;

            bestShift = shift;
        }
    }

    return bestShift;
}


/* =========================================================
   10. find_key()

   Finds the shift for every group.

   Example:

   Group 1 -> shift 11 -> L
   Group 2 -> shift 4  -> E
   Group 3 -> shift 12 -> M
   Group 4 -> shift 14 -> O
   Group 5 -> shift 13 -> N

   Key = LEMON
   ========================================================= */

string find_key(vector<string> groups)
{
    string key = "";

    cout << "\n========== KEY RECOVERY ==========\n";

    for (int i = 0;
         i < (int)groups.size();
         i++)
    {
        int shift = find_shift(groups[i]);

        char keyLetter = 'A' + shift;

        cout << "Group " << i + 1
             << " -> Shift = "
             << shift
             << " -> Key letter = "
             << keyLetter
             << "\n";

        key += keyLetter;
    }

    return key;
}


/* =========================================================
   11. vigenere_decrypt()

   Formula:

   P = (C - K + 26) % 26
   ========================================================= */

string vigenere_decrypt(
    string ciphertext,
    string key)
{
    string plaintext = "";

    for (int i = 0;
         i < (int)ciphertext.length();
         i++)
    {
        int c = ciphertext[i] - 'A';

        int k =
            key[i % key.length()] - 'A';

        int p =
            (c - k + 26) % 26;

        plaintext += char('A' + p);
    }

    return plaintext;
}


/* =========================================================
   12. vigenere_encrypt()

   Formula:

   C = (P + K) % 26
   ========================================================= */

string vigenere_encrypt(
    string plaintext,
    string key)
{
    string ciphertext = "";

    for (int i = 0;
         i < (int)plaintext.length();
         i++)
    {
        int p = plaintext[i] - 'A';

        int k =
            key[i % key.length()] - 'A';

        int c =
            (p + k) % 26;

        ciphertext += char('A' + c);
    }

    return ciphertext;
}

