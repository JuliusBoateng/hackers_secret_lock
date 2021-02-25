# Gridlocked
## Hackers in the Bazaar CSE 40842 Project 01 
Contributors: jboateng, esmith36, shannon3

## Requirements 
You need a C89 compiler and make to run our code; we tested on gcc 6.3.0.

## How to Run
1. Clone the repository
2. Choose whether to encode/decode 
- To decode: do nothing 
- To encode: remove the 3 lines that say `DELETE ME` to make the padlock appear locked 
3. Make the executable: `make` 
4. Execute: `./gridlock key text` where `key` is the key you want to use for the cipher and `text` is the text to be encoded/decoded

## Output 
- If the output is a string of characters like `ogpyk` that is your encrypted/decrypted result! 
- If the output is `Usage: ./gridlock key text` then you did not enter the correct number of arguments 
- If the output is `Key must be letters` then your key argument contained characters that are not allowed. Please only enter alphabetic characters. 

## Historical Background/Context 
The Vigenere-cipher was invented in the 16th-century by Blaise de Vigenère. For over 200 years, the cipher was considered impregnable and was known as “le chiffre indéchiffrable” or “the unbreakable cipher.” The reason why the cipher was so difficult to break was because it obscured the frequency of repeated characters, thus it was difficult to crack with simple frequency analysis techniques. This is due to the fact that the key is repeated until its length matches the length of the plaintext, making the mapping between characters difficult to decipher. It took until 1861 for a general solution breaking the cipher to be published by cryptanalyst Friedrich W. Kasiski. His work was important because it decrypted the cipher without relying on knowledge of plaintext or common words as keys. His solution uses the knowledge that identical pairing of plaintext and key characters produce the same encoded characters.

In keeping with the spirit of concealment we decided to combine ciphers with obfuscation. The International Obfuscated C Code Contest (IOCCC) is a coding contest centered around creating clever obfuscated C code. The contest began in 1984 and now is in its 27th cycle. It originally started after the founders were comparing notes after having trouble fixing some very poorly written code for the Bourne shell. The inspiration for the contest was a result of dealing with terrible code, thus they created a contest centered around finding the most difficult to read but functional code possible. Winning entries fit into categories such as, “Most percussive, Most phony, Most Erratic Behavior, etc”. In keeping with the hacker ideal of programming for the sake of programming, the reward for submitting a winning entry is your entry being announced on the contest website.




