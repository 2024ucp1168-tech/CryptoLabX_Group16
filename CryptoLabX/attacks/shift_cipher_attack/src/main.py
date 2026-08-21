import shift_cipher.py as sc 
import brute_force_dictionary.py as bfd 
import chi_square_attack.py as cst 

string str= input("Enter Plaintext")
int key = int(input("Enter a key (0-25) :"))

string enc = sc.encrypt(str , key) 

string decrypted_bfd = bfd.dictionary_attack(str) 
string decrypted_cst = cst.chi_square_decryption(str) 

