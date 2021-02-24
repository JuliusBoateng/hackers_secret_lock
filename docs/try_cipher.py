#!/usr/bin/env python

print("Python Implementation of Polyalphabetic Substituion Ciper...\n")


print("making 26 x 26 alphabet table (Vigenere Square)...\n") 
v_square = []
alphabet_len = 26
alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
for i in range(alphabet_len): 
    row = [] 
    for j in range(alphabet_len):
        if i+j >= len(alphabet): # account for wrapping around indicies 
            new_index = (len(alphabet) - (i+j))*-1
            row.append(alphabet[new_index])
        else: 
            row.append(alphabet[j+i])
    v_square.append(row)
print(v_square)


key = "APPLE"
text = "EDUCBA"
print("\nkey: {}, text: {}\n".format(key, text))
answer = ""
print("Encrypting...\n")
for i,l in enumerate(text): 
    if i >= len(key): # account for wrapping around indicies 
        j = (len(key)-i)*-1
        print("row: {} ({}), col: {} ({})".format(l, ord(l)-65, key[j], ord(key[j])-65))
        row = ord(l)-65 
        col = ord(key[j])-65 
    else: 
        print("row: {} ({}), col: {} ({})".format(l, ord(l)-65, key[i], ord(key[i])-65))
        row = ord(l)-65 
        col = ord(key[i])-65 
    print("Encryption letter: {}".format(v_square[row][col])) 
    answer += v_square[row][col] 
print("\nEncrypted answer: {}".format(answer))


