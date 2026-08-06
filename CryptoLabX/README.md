# CryptoLabX

## Cryptography Laboratory Toolkit

### Course

**Cryptography Lab**

### Assignment

**Assignment 1 (Week 1): Build Your CryptoLabX Toolkit**

---

# Project Overview

CryptoLabX is a modular cryptography toolkit developed as part of the Cryptography Laboratory course. The objective of this project is to build a reusable framework that will gradually evolve into a complete cryptanalysis platform throughout the semester.

The toolkit has been designed with a modular architecture so that new encryption algorithms, attack techniques, mathematical utilities, and analysis tools can be integrated in future assignments without affecting the overall project structure.

The current implementation establishes the project foundation by providing a menu-driven command-line interface, text file analysis, activity logging, and organized project directories.

---

# Team Members

Puvvala Charan Sai Naga Laxman 2024UCP1168
Garv Srivastava                2024UCP1153

---

# Project Structure

```
CryptoLabX/
│
├── classical/          # Classical cipher implementations
├── attacks/            # Cryptanalysis and attack modules
├── math/               # Mathematical helper functions
├── modern/             # Modern cryptographic algorithms
├── analysis/           # Text and cipher analysis modules
├── datasets/           # Input text files
├── outputs/            # Generated logs and outputs
├── docs/               # Documentation
├── tests/              # Test cases
├── utils/              # Utility modules
│
├── main.py             # Main application entry point
├── README.md           # Project documentation
└── requirements.txt    # Project dependencies
```

---

# Features Implemented (Week 1)

###  Project Initialization

* Professional project directory structure
* Git repository initialized
* Version control enabled

###  Menu-Driven Command Line Interface

The application provides the following options:

* Encrypt
* Decrypt
* Attack
* Analyze File
* Exit

The encryption, decryption, and attack modules currently display a "Coming Soon" message and serve as placeholders for future assignments.

---

### ✔ File Analysis

The toolkit reads text files from the **datasets** folder and computes:

* Total number of characters
* Total number of words
* Total number of lines
* Number of unique characters
* Letter frequency analysis (A–Z)

---

### ✔ Activity Logging

Every execution records:

* Date
* Time
* Selected menu option

The log file is automatically generated inside the **outputs** directory.

---

### ✔ Dataset Repository

The project contains multiple sample text files inside the **datasets** directory that will be used for testing encryption, decryption, and cryptanalysis algorithms in future assignments.

---

# Technologies Used

* Python 3
* Git
* GitHub

---

# How to Run

Clone the repository:

```bash
git clone <repository-url>
```

Navigate to the project directory:

```bash
cd CryptoLabX_Group16
```

Run the application:

```bash
python main.py
```

---

# Sample Menu

```
========== CryptoLabX ==========

1. Encrypt
2. Decrypt
3. Attack
4. Analyze File
5. Exit

Enter your choice:
```

---

# Sample File Analysis Output

```
----- File Analysis -----

Characters : 152
Words      : 28
Lines      : 4
Unique Characters : 31

Letter Frequency

a : 18
b : 3
c : 5
...
```

---

# Log File Format

```
2026-08-06 22:15:03 -> Encrypt
2026-08-06 22:18:45 -> Analyze
2026-08-06 22:20:10 -> Exit
```
