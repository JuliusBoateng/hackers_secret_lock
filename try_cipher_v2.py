#!/usr/bin/env python

START = ord("a")
END = ord("z")

def polySub(usr_char, key_char):
    val = ord(key_char)
    offset = ord(usr_char) - START

    new_val = (val + offset) % (END + 1)
    
    if new_val < START:
        new_char = START + new_val
    else:
        new_char = new_val

    return chr(new_char)

def encrypting(usr, key):
    new_usr = usr.lower() # Case insensitive b/c polysub (vigenere table) is case insentive
    new_key = key.lower()

    result = ""
    for i in range(len(new_usr)):
        if i >= len(new_key):
            result += new_usr[i]
        else:
            result += polySub(new_usr[i], new_key[i])
    
    print(result)

def main():
    usr = "EDUCBA"
    key = "APPLE"

    encrypting(usr, key)

if __name__ == "__main__":
    main()

