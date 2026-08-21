import string

# Standard English letter frequencies (percentages normalized to decimals)
ENGLISH_FREQ = {
    'a': 0.08167, 'b': 0.01492, 'c': 0.02782, 'd': 0.04253, 'e': 0.12702,
    'f': 0.02228, 'g': 0.02015, 'h': 0.06094, 'i': 0.06966, 'j': 0.00153,
    'k': 0.00772, 'l': 0.04025, 'm': 0.02406, 'n': 0.06749, 'o': 0.07507,
    'p': 0.01929, 'q': 0.00095, 'r': 0.05987, 's': 0.06327, 't': 0.09056,
    'u': 0.02758, 'v': 0.00978, 'w': 0.02360, 'x': 0.00150, 'y': 0.01974,
    'z': 0.00074
}

def decrypt_shift(ciphertext: str, shift: int) -> str:
    """Decrypts ciphertext using a given shift value."""
    plaintext = []
    for char in ciphertext:
        if char.isalpha():
            base = ord('a') if char.islower() else ord('A')
            decrypted_char = chr((ord(char) - base - shift) % 26 + base)
            plaintext.append(decrypted_char)
        else:
            plaintext.append(char)
    return "".join(plaintext)

def calculate_chi_squared(text: str) -> float:
    """Calculates the Chi-Squared statistic for a given text sample."""
    clean_text = [c.lower() for c in text if c.isalpha()]
    total_letters = len(clean_text)
    
    if total_letters == 0:
        return float('inf')

    chi_squared = 0.0
    for char in string.ascii_lowercase:
        observed_count = clean_text.count(char)
        expected_count = ENGLISH_FREQ[char] * total_letters
        chi_squared += ((observed_count - expected_count) ** 2) / expected_count
        
    return chi_squared

def chi_square_decryption(ciphertext: str):
    """Breaks a shift cipher by finding the shift with the lowest Chi-Square score."""
    scores = []

    for shift in range(26):
        decrypted = decrypt_shift(ciphertext, shift)
        score = calculate_chi_squared(decrypted)
        scores.append((score, shift, decrypted))

    # Sort candidates by Chi-Square score (ascending)
    scores.sort(key=lambda x: x[0])
    
    best_score, best_shift, best_plaintext = scores[0]
    
    print("Best Score : {best_score} \n Best Shift : {best_shift} \n Best PlainText : {best_plaintext} \n")

