#!/usr/bin/env python

START = ord("a")
END = ord("z")

def polySub(usr_char, key_char):
    val = ord(usr_char)
    offset = ord(key_char) - START

    new_val = (val + offset) % (END + 1)
    
    if new_val < START:
        new_char = START + new_val
    else:
        new_char = new_val

    return chr(new_char)

def reversePolySub(encrypted_char, key_char):
    row = ord(key_char)
    val = ord(encrypted_char)

    diff = (val - row) % ((END - START) + 1)

    return chr(START + diff)

def encrypting(usr, key):
    new_usr = usr.lower() # Case insensitive b/c polysub (vigenere table) is case insentive
    new_key = key.lower()
    
    result = ""
    for i in range(len(usr)):
        result += polySub(new_usr[i], new_key[i % (len(key))])
    
    return result

def decrypting(encrypted, key):
    new_encrypted = encrypted.lower()
    new_key = key.lower()

    result = ""
    for i in range(len(encrypted)):
        result += reversePolySub(new_encrypted[i], new_key[i % (len(key))])
    
    return result

def main():
    usr = "Julius"
    key = "Boateng"

    encrypted = encrypting(usr, key)
    print("Input: " + usr + " Key: " + key + " Encrypted: " + encrypted)
    decrypted = decrypting(encrypted, key)
    print("Decrypted: " + decrypted)

if __name__ == "__main__":
    main()

