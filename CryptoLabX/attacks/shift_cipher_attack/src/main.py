from shift_cipher import encrypt, decrypt
from brute_force_dictionary import load_dictionary, dictionary_attack
from chi_square_attack import chi_square_attack


def main():
    print("SHIFT CIPHER CRYPTANALYSIS")
    print("--------------------------")

    plaintext = input("Enter plaintext: ")
    key = int(input("Enter key (0-25): "))

    ciphertext = encrypt(plaintext, key)

    print("\nEncrypted Text:", ciphertext)

    print("\n--- Brute Force ---")

    for k in range(26):
        print("Key", k, ":", decrypt(ciphertext, k))

    dictionary_file = "../dictionary/english_words.txt"

    try:
        dictionary = load_dictionary(dictionary_file)

        dictionary_key, dictionary_text, dictionary_score_value = \
            dictionary_attack(ciphertext, dictionary)

        print("\n--- Dictionary Attack ---")
        print("Predicted Key:", dictionary_key)
        print("Decrypted Text:", dictionary_text)
        print("Dictionary Score:", dictionary_score_value)

    except FileNotFoundError:
        print("\nDictionary file not found.")
        print("Make sure english_words.txt is present in dictionary folder.")

    chi_key, chi_text, chi_score = chi_square_attack(ciphertext)

    print("\n--- Chi-Square Attack ---")
    print("Predicted Key:", chi_key)
    print("Decrypted Text:", chi_text)
    print("Chi-Square Score:", chi_score)

    print("\n--- Comparison ---")
    print("Actual Key:", key)
   
    if 'dictionary_key' in locals():
        print("Dictionary Key:", dictionary_key)
        print("Dictionary Correct:", dictionary_key == key)

    print("Chi-Square Key:", chi_key)
    print("Chi-Square Correct:", chi_key == key)


if __name__ == "__main__":
    main()