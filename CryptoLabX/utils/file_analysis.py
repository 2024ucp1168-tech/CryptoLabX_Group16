from collections import Counter
import os


def analyze_file(filename):

    path = os.path.join("datasets", filename)

    try:
        with open(path, "r", encoding="utf-8") as f:
            text = f.read()

        characters = len(text)
        words = len(text.split())
        lines = len(text.splitlines())
        unique_chars = len(set(text))

        freq = Counter()

        for ch in text.lower():
            if ch.isalpha():
                freq[ch] += 1

        print("\n----- File Analysis -----")
        print("Characters :", characters)
        print("Words      :", words)
        print("Lines      :", lines)
        print("Unique Characters :", unique_chars)

        print("\nLetter Frequency")

        for letter in sorted(freq):
            print(letter, ":", freq[letter])

    except FileNotFoundError:
        print("File not found.")