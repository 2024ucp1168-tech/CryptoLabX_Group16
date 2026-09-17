#include <iostream>
#include <fstream>
#include <string>
#include "cipher.h"

using namespace std;

int main()
{
    string plaintext;
    string ciphertext;
    string key;

    cout << "=============================================\n";
    cout << " MONOALPHABETIC SUBSTITUTION CIPHER\n";
    cout << "=============================================\n";

    // -----------------------------------------------------
    // READ PLAINTEXT FROM FILE
    // -----------------------------------------------------

    ifstream file("plaintext.txt");

    if (!file)
    {
        cout << "\nError: Could not open plaintext.txt\n";
        cout << "Make sure plaintext.txt is in the same folder as the program.\n";
        return 1;
    }

    string line;

    while (getline(file, line))
    {
        plaintext += line;
        plaintext += "\n";
    }

    file.close();

    if (plaintext.length() == 0)
    {
        cout << "\nError: plaintext.txt is empty.\n";
        return 1;
    }

    cout << "\nPlaintext successfully loaded from plaintext.txt.\n";
    cout << "Plaintext length: " << plaintext.length() << " characters\n";

    // -----------------------------------------------------
    // INPUT SUBSTITUTION KEY
    // -----------------------------------------------------

    cout << "\nEnter 26-letter substitution key.\n";
    cout << "Example: QWERTYUIOPASDFGHJKLZXCVBNM\n";
    cout << "Key: ";

    cin >> key;

    // -----------------------------------------------------
    // VALIDATE KEY LENGTH
    // -----------------------------------------------------

    if (key.length() != 26)
    {
        cout << "\nError: Key must contain exactly 26 letters.\n";
        return 1;
    }

    // -----------------------------------------------------
    // VALIDATE THAT KEY HAS UNIQUE LETTERS
    // -----------------------------------------------------

    bool used[26];

    for (int i = 0; i < 26; i++)
    {
        used[i] = false;
    }

    for (int i = 0; i < 26; i++)
    {
        char ch = key[i];

        // Convert lowercase to uppercase
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - ('a' - 'A');
            key[i] = ch;
        }

        if (ch < 'A' || ch > 'Z')
        {
            cout << "\nError: Key must contain only alphabetic letters.\n";
            return 1;
        }

        int index = ch - 'A';

        if (used[index])
        {
            cout << "\nError: Key contains repeated letters.\n";
            cout << "A substitution key must contain all 26 letters exactly once.\n";
            return 1;
        }

        used[index] = true;
    }

    // -----------------------------------------------------
    // GENERATE CIPHERTEXT
    // -----------------------------------------------------

    ciphertext = encrypt(plaintext, key);

    cout << "\n========== CIPHERTEXT ==========\n";
    cout << ciphertext << "\n";

    // -----------------------------------------------------
    // MENU
    // -----------------------------------------------------

    int choice;

    do
    {
        cout << "\n\n========== MENU ==========\n";

        cout << "1. Frequency Analysis\n";
        cout << "2. Word Frequency Analysis\n";
        cout << "3. Pattern Analysis\n";
        cout << "4. Apply Substitution\n";
        cout << "5. Display Partial Plaintext\n";
        cout << "6. Verify Solution\n";
        cout << "7. Display Ciphertext\n";
        cout << "8. Display Original Plaintext\n";
        cout << "0. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        // -------------------------------------------------
        // FREQUENCY ANALYSIS
        // -------------------------------------------------

        if (choice == 1)
        {
            frequency_analysis(ciphertext);
        }

        // -------------------------------------------------
        // WORD FREQUENCY ANALYSIS
        // -------------------------------------------------

        else if (choice == 2)
        {
            word_frequency_analysis(ciphertext);
        }

        // -------------------------------------------------
        // PATTERN ANALYSIS
        // -------------------------------------------------

        else if (choice == 3)
        {
            pattern_analysis(ciphertext);
        }

        // -------------------------------------------------
        // APPLY SUBSTITUTION
        // -------------------------------------------------

        else if (choice == 4)
        {
            string substitution;

            cout << "\nEnter substitution mapping.\n";
            cout << "Use '?' for unknown letters.\n";
            cout << "Example: ?t?e????????????????????\n";

            cout << "Mapping: ";
            cin >> substitution;

            if (substitution.length() != 26)
            {
                cout << "\nInvalid substitution length.\n";
                cout << "The mapping must contain exactly 26 characters.\n";
            }
            else
            {
                cout << "\n========== RESULT ==========\n";

                cout << apply_substitution(
                    ciphertext,
                    substitution
                ) << "\n";
            }
        }

        // -------------------------------------------------
        // DISPLAY PARTIAL PLAINTEXT
        // -------------------------------------------------

        else if (choice == 5)
        {
            string substitution;

            cout << "\nEnter current substitution mapping: ";
            cin >> substitution;

            if (substitution.length() != 26)
            {
                cout << "\nInvalid substitution length.\n";
            }
            else
            {
                display_partial_plaintext(
                    ciphertext,
                    substitution
                );
            }
        }

        // -------------------------------------------------
        // VERIFY SOLUTION
        // -------------------------------------------------

        else if (choice == 6)
        {
            string recoveredPlaintext;
            string recoveredKey;

            cin.ignore();

            cout << "\nEnter recovered plaintext:\n";
            getline(cin, recoveredPlaintext);

            cout << "\nEnter recovered key:\n";
            cin >> recoveredKey;

            if (recoveredKey.length() != 26)
            {
                cout << "\nInvalid key length.\n";
            }
            else
            {
                verify_solution(
                    recoveredPlaintext,
                    ciphertext,
                    recoveredKey
                );
            }
        }

        // -------------------------------------------------
        // DISPLAY CIPHERTEXT
        // -------------------------------------------------

        else if (choice == 7)
        {
            cout << "\n========== CIPHERTEXT ==========\n";
            cout << ciphertext << "\n";
        }

        // -------------------------------------------------
        // DISPLAY ORIGINAL PLAINTEXT
        // -------------------------------------------------

        else if (choice == 8)
        {
            cout << "\n========== ORIGINAL PLAINTEXT ==========\n";
            cout << plaintext << "\n";
        }

        // -------------------------------------------------
        // INVALID CHOICE
        // -------------------------------------------------

        else if (choice != 0)
        {
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 0);

    cout << "\nProgram terminated.\n";

    return 0;
}