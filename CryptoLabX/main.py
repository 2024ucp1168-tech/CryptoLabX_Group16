import os
from collections import Counter
from datetime import datetime

# Setup paths
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DATASETS_DIR = os.path.join(BASE_DIR, "datasets")
LOGS_DIR = os.path.join(BASE_DIR, "logs")
LOG_FILE = os.path.join(LOGS_DIR, "activity.log")

def log_action(option_name):
    """Task 5: Maintains a log file recording date, time, and selected menu option."""
    if not os.path.exists(LOGS_DIR):
        os.makedirs(LOGS_DIR)
        
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    log_entry = f"[{timestamp}] User selected: {option_name}\n"
    
    with open(LOG_FILE, "a", encoding="utf-8") as f:
        f.write(log_entry)

def analyze_file():
    """Task 4: Reads a text file from the datasets folder and prints stats."""
    filename = input("Enter the filename inside 'datasets/' (e.g., sample1.txt): ").strip()
    filepath = os.path.join(DATASETS_DIR, filename)

    if not os.path.exists(filepath):
        print(f"\nError: File '{filename}' not found in datasets folder.\n")
        return

    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    lines = content.splitlines()
    words = content.split()
    total_chars = len(content)
    unique_chars = len(set(content))

    # Case-insensitive frequency for alphabetic letters
    letters_only = [char.lower() for char in content if char.isalpha()]
    letter_freq = Counter(letters_only)

    print("\n" + "=" * 40)
    print(f" FILE ANALYSIS: {filename}")
    print("=" * 40)
    print(f"Total Characters : {total_chars}")
    print(f"Total Words      : {len(words)}")
    print(f"Total Lines      : {len(lines)}")
    print(f"Unique Characters: {unique_chars}")
    print("\nLetter Frequencies (Alphabetic):")
    for letter, count in sorted(letter_freq.items()):
        print(f"  {letter.upper()}: {count}")
    print("=" * 40 + "\n")

def main():
    """Task 3: Menu-Driven Command-Line Interface."""
    while True:
        print("=== Cryptography Tool CLI ===")
        print("1. Encrypt")
        print("2. Decrypt")
        print("3. Attack")
        print("4. Analyze")
        print("5. Exit")
        
        choice = input("Select an option (1-5): ").strip()

        if choice == '1':
            log_action("1. Encrypt")
            print("\n[Encrypt] Coming Soon!\n")
        elif choice == '2':
            log_action("2. Decrypt")
            print("\n[Decrypt] Coming Soon!\n")
        elif choice == '3':
            log_action("3. Attack")
            print("\n[Attack] Coming Soon!\n")
        elif choice == '4':
            log_action("4. Analyze")
            analyze_file()
        elif choice == '5':
            log_action("5. Exit")
            print("\nExiting program. Goodbye!")
            break
        else:
            log_action(f"Invalid Selection ({choice})")
            print("\nInvalid selection. Please choose an option between 1 and 5.\n")

if __name__ == "__main__":
    main()