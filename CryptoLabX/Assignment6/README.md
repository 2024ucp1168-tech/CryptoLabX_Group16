# Vigenère Cipher Cryptanalysis

## Cryptanalysis of Vigenère Cipher using Kasiski Examination and Frequency Analysis

This project implements the **cryptanalysis of a Vigenère cipher** using:

* Kasiski Examination
* Index of Coincidence (IC)
* Frequency Analysis
* Chi-Square Test

The program attempts to recover the **key length**, **probable key**, and **plaintext** from a given ciphertext.

It also verifies the recovered result by **re-encrypting the plaintext** and comparing the generated ciphertext with the original ciphertext.

---

## Aim

To implement cryptanalysis of the Vigenère cipher using **Kasiski Examination and Frequency Analysis**, recover the probable encryption key, decrypt the ciphertext, and verify the result.

---

## Objectives

The program performs the following tasks:

1. Preprocess the ciphertext.
2. Find repeated patterns in the ciphertext.
3. Calculate distances between repeated patterns.
4. Find factors of the distances.
5. Estimate candidate key lengths using Kasiski Examination.
6. Calculate the Index of Coincidence.
7. Select a probable key length.
8. Divide the ciphertext into groups according to the key length.
9. Perform frequency analysis on each group.
10. Estimate the Caesar shift for each group.
11. Recover the probable Vigenère key.
12. Decrypt the ciphertext.
13. Re-encrypt the recovered plaintext.
14. Verify that the generated ciphertext matches the original ciphertext.

---

## Algorithms Used

### 1. Vigenère Cipher

The Vigenère cipher is a polyalphabetic substitution cipher.

For encryption:

```text
C = (P + K) mod 26
```

For decryption:

```text
P = (C - K + 26) mod 26
```

where:

* `P` = plaintext letter
* `C` = ciphertext letter
* `K` = key letter

Each letter is represented by a number:

```text
A = 0
B = 1
C = 2
...
Z = 25
```

---

### 2. Kasiski Examination

Kasiski Examination is used to estimate the **key length**.

The algorithm:

```text
Find repeated patterns
        ↓
Find positions of repetitions
        ↓
Calculate distances
        ↓
Find factors of distances
        ↓
Count frequently occurring factors
        ↓
Candidate key lengths
```

For example, if a repeated pattern occurs at positions:

```text
10 and 40
```

then:

```text
Distance = 40 - 10 = 30
```

Factors of 30 include:

```text
2, 3, 5, 6, 10, 15
```

If a particular number occurs frequently as a factor of many distances, it can be a candidate for the key length.

---

### 3. Index of Coincidence

The Index of Coincidence is used as an additional method for estimating the key length.

It is calculated as:

```text
             Σ f(i)(f(i)-1)
IC = -------------------------------
             N(N-1)
```

where:

* `f(i)` = frequency of letter `i`
* `N` = total number of letters

For normal English text, the IC is approximately:

```text
0.066
```

while random text has an IC closer to:

```text
0.038
```

The program uses IC to help select a probable key length from the candidates obtained through Kasiski Examination.

---

### 4. Frequency Analysis

After estimating the key length, the ciphertext is divided into groups.

For example, for a key length of `5`:

```text
Ciphertext:
C1 C2 C3 C4 C5 C6 C7 C8 C9 C10 ...

Group 1:
C1 C6 C11 ...

Group 2:
C2 C7 C12 ...

Group 3:
C3 C8 C13 ...

Group 4:
C4 C9 C14 ...

Group 5:
C5 C10 C15 ...
```

Each group behaves approximately like a **Caesar cipher**.

The program calculates the frequency of letters `A-Z` in every group.

---

### 5. Chi-Square Analysis

For every group, all 26 possible Caesar shifts are tested.

The observed frequencies are compared with standard English letter frequencies using the chi-square test.

The shift having the **lowest chi-square value** is selected as the probable shift.

For example:

```text
Group 1 → Shift 11 → L
Group 2 → Shift 4  → E
Group 3 → Shift 12 → M
Group 4 → Shift 14 → O
Group 5 → Shift 13 → N
```

Therefore:

```text
Recovered Key = LEMON
```

---

## Project Structure

The project is divided into two C++ files so that two team members can work on different files and commit independently to GitHub.

```text
Vigenere-Cryptanalysis/
│
├── kasiski.cpp
├── vigenere.cpp
└── README.md
```

### `kasiski.cpp`

Contains the Kasiski Examination and Index of Coincidence functions:

```text
clean_ciphertext()
find_repeated_patterns()
calculate_distances()
find_factors()
kasiski_analysis()
calculate_ic()
```

### `vigenere.cpp`

Contains the frequency analysis, key recovery, encryption, decryption and verification functions:

```text
split_into_groups()
frequency_analysis()
find_shift()
find_key()
vigenere_decrypt()
vigenere_encrypt()
verify()
main()
```

---

## Function Description

| Function | Purpos
