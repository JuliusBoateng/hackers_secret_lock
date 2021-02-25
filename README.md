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



