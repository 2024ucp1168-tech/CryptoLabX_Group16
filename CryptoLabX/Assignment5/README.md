# Monoalphabetic Substitution Cipher & Cryptanalysis

## Overview

This project implements a **Monoalphabetic Substitution Cipher** in C++ and performs basic cryptanalysis using **frequency analysis, word frequency analysis, and pattern analysis**.

The program also provides tools to iteratively recover the plaintext by applying suspected substitutions and finally verifies the recovered key by re-encrypting the plaintext.

## Features

* Encrypt plaintext using a monoalphabetic substitution key.
* Perform **letter-frequency analysis** on ciphertext.
* Perform **word-frequency analysis**.
* Identify:

  * One-letter words
  * Two-letter words
  * Three-letter words
  * Repeated words
  * Repeated letter patterns
* Apply a partially recovered substitution key.
* Display partially recovered plaintext.
* Verify a recovered key by re-encrypting the plaintext.
* Read plaintext directly from `plaintext.txt`.
* Interactive menu-based interface.

## Project Structure

```text
.
├── main.cpp
├── cipher.cpp
├── cipher.h
├── plaintext.txt
└── README.md
```

### File Description

| File            | Purpose                                                  |
| --------------- | -------------------------------------------------------- |
| `main.cpp`      | Main program, input handling, menu and workflow          |
| `cipher.cpp`    | Implementation of encryption and cryptanalysis functions |
| `cipher.h`      | Function declarations                                    |
| `plaintext.txt` | Input plaintext used for encryption                      |
| `README.md`     | Project documentation                                    |

## Technologies Used

* **Language:** C++17
* **Compiler:** g++
* **Libraries:** Standard C++ libraries such as `<iostream>`, `<fstream>`, and `<string>`

No Python or ready-made cryptanalysis library is used.

---

# How the Cipher Works

A monoalphabetic substitution cipher replaces every plaintext letter with another letter according to a fixed substitution key.

For example, if the key is:

```text
QWERTYUIOPASDFGHJKLZXCVBNM
```

then:

```text
Plain:  ABCDEFGHIJKLMNOPQRSTUVWXYZ
Cipher: QWERTYUIOPASDFGHJKLZXCVBNM
```

So:

```text
HELLO
```

becomes:

```text
ITSSG
```

The same substitution is used throughout the entire message.

Spaces, punctuation, numbers, and other non-alphabetic characters are preserved.

---

# Cryptanalysis

The program provides several techniques to help recover the substitution key.

## 1. Frequency Analysis

`frequency_analysis()` counts how frequently each letter occurs in the ciphertext.

The frequencies are displayed in descending order along with their percentages.

This can help identify likely plaintext letters because letters such as `E`, `T`, `A`, `O`, etc. tend to occur frequently in English text.

---

## 2. Word Frequency Analysis

`word_frequency_analysis()` analyzes the words appearing in the ciphertext.

It identifies:

* Most frequently occurring words
* One-letter words
* Two-letter words
* Three-letter words
* Repeated words

Repeated words can provide useful clues when trying to determine their plaintext equivalents.

---

## 3. Pattern Analysis

`pattern_analysis()` identifies repeated letter patterns within words.

For example:

```text
hello
```

has the pattern:

```text
01223
```

because:

```text
h → 0
e → 1
l → 2
l → 2
o → 3
```

Similarly, repeated patterns in ciphertext words can be compared with common English word patterns.

---

# Substitution Recovery

The program allows the user to enter a partially recovered substitution mapping.

The mapping is:

```text
Ciphertext alphabet → Plaintext alphabet
```

For example:

```text
KXVMC?????????????????????
```

means:

```text
A → K
B → X
C → V
D → M
E → C
```

while the remaining mappings are unknown.

Unknown mappings are represented using:

```text
?
```

The program can then display the resulting partial plaintext.

---

# Verification

After recovering the complete substitution key, the program can verify the solution.

The program:

1. Takes the original plaintext.
2. Encrypts it using the recovered encryption key.
3. Compares the generated ciphertext with the original ciphertext.
4. Reports whether they match.

If they match:

```text
Verification successful!
Re-encrypted ciphertext matches.
```

This confirms that the recovered key is correct for the given plaintext/ciphertext pair.

---

# Compilation

Open a terminal in the project directory.

Compile using:

```bash
g++ main.cpp cipher.cpp -o cipher
```

For C++17 explicitly:

```bash
g++ -std=c++17 main.cpp cipher.cpp -o cipher
```

---

# Running the Program

On Windows PowerShell:

```powershell
.\cipher.exe
```

The program reads the plaintext from:

```text
plaintext.txt
```

You will then be asked to enter a **26-letter encryption key**.

Example:

```text
QWERTYUIOPASDFGHJKLZXCVBNM
```

The key must contain all 26 alphabetic characters exactly once.

---

# Menu

The program provides the following options:

```text
1. Frequency Analysis
2. Word Frequency Analysis
3. Pattern Analysis
4. Apply Substitution
5. Display Partial Plaintext
6. Verify Solution
7. Display Ciphertext
8. Display Original Plaintext
0. Exit
```

A typical cryptanalysis workflow is:

```text
1 → Frequency Analysis
2 → Word Frequency Analysis
3 → Pattern Analysis
4/5 → Apply suspected substitutions
4/5 → Inspect partial plaintext
      ↓
   Modify/reject hypotheses
      ↓
   Recover complete key
      ↓
6 → Verify Solution
```

---

# Example Encryption Key

For testing the encryption functionality:

```text
QWERTYUIOPASDFGHJKLZXCVBNM
```

The corresponding inverse mapping, used by Options 4 and 5, is:

```text
KXVMCNOPHQRSZYIJADLEGWBUFT
```

The inverse mapping should only be used for testing the program. During actual cryptanalysis, the substitution should be recovered from the ciphertext using the available clues.

---

# Functions Implemented

| Function                      | Description                                   |
| ----------------------------- | --------------------------------------------- |
| `encrypt()`                   | Encrypts plaintext using the substitution key |
| `frequency_analysis()`        | Calculates ciphertext letter frequencies      |
| `word_frequency_analysis()`   | Analyzes word frequencies and repetitions     |
| `pattern_analysis()`          | Finds repeated letter patterns                |
| `apply_substitution()`        | Applies a recovered/partial mapping           |
| `display_partial_plaintext()` | Displays plaintext with known substitutions   |
| `verify_solution()`           | Verifies the recovered key                    |

---

# Cryptanalysis Approach

The substitution key is recovered iteratively rather than using an automated solver.

The general approach is:

1. Generate the ciphertext.
2. Calculate letter frequencies.
3. Identify common ciphertext letters.
4. Analyze common and repeated words.
5. Examine word patterns.
6. Propose possible ciphertext → plaintext substitutions.
7. Apply the substitutions.
8. Inspect the resulting partial plaintext.
9. Reject incorrect substitutions when they produce impossible or unlikely words.
10. Continue until meaningful plaintext is recovered.
11. Recover the complete substitution key.
12. Re-encrypt the plaintext to verify the solution.

---

# Requirements

* C++ compiler supporting C++17
* `g++` recommended
* Windows, Linux, or macOS
* `plaintext.txt` placed in the same directory as the executable

## Example

```bash
g++ -std=c++17 main.cpp cipher.cpp -o cipher
./cipher
```

On Windows PowerShell:

```powershell
g++ -std=c++17 main.cpp cipher.cpp -o cipher
.\cipher.exe
```

---

## Academic Context

This project was developed as part of a **Cryptography Laboratory** assignment on:

**Monoalphabetic Substitution Cipher and its Cryptanalysis Using Frequency and Pattern Analysis.**

The implementation demonstrates both the encryption process and classical cryptanalytic techniques used to analyze substitution ciphers.