 /* equals import in java*/
#include "crypto.h"
/* defines stdin, stdout, stderr */
#include <stdio.h>

/**
 * Key used in de- and encryption.
 */
typedef struct {
    int type; /* Type of the key. */
    char* chars; /* Key characters. */
} KEY;

 /**
	char* indicates pass by value with pointers which equals pass by reference; pass ^= call
 */
/**
 * Encrypt the given text and return the encrypted version. The input text
 * may only contain the letters A-Z. No space or other characters are
 * allowed. In case of illegal characters in the text, the function
 * returns E_MESSAGE_ILLEGAL_CHAR. The key must contain a valid character set
 * and have a sufficient length. For XOR encryption only the characters
 * A-Z are valid in the key. The key must have at least a length of 1.
 *
 * @param key Key to be used for the encryption
 * @param input Clear text
 * @param output Encrypted text
 * @return 0 on success, otherwise error code
 */
int encrypt(KEY key, const char* input, char* output) {
	int err = isKeyValid(key);
	if(err !=0) {
		return err;
	}
	for(input : o) {
		if(!MESSAGE_CHARACTERS.contains(o)) {
			return E_MESSAGE_ILLEGAL_CHAR;
		}
	}
	
	int keyIterator = 0;
	char[] temp = new char[input.length];
	int cypherTextIterator = 0;
	for (input : o) {
		/* so
		temp[cypherTextIterator] = o ^ key[keyIterator]; /* Darf ich so auf key zugreifen? Ist key ein array? Muss es in der Signatur nicht als solches deklariert werden? 
		   oder so */
		temp[cypherTextIterator] = (o - 'A') ^ (key[keyIterator] - 'A');
		temp[cypherTextIterator] = temp[cypherTextIterator] + 'A';
		cypherTextIterator++;
		keyIterator++;
		if (keyIterator == key.length) {
			keyIterator = 0;
		}
	}
	output = temp;
	printf(output);
	return 0;
}

int isKeyValid(KEY key) {
	if(key.length < 1) {
		return E_KEY_TOO_SHORT;
	}
	for(key : o) {
		if(!KEY_CHARACTERS.contains(o)) {
			return E_KEY_ILLEGAL_CHAR;
		}
	}
	return 0;
}
/**
 * Decrypt the given text and return the decrypted version. The cypher text
 * may only contain the characters defined as output of the encrypt function.
 * For other characters the function will return E_CYPHER_ILLEGAL_CHAR.
 * The key must contain a valid character set
 * and have a sufficient length. For XOR encryption only the characters
 * A-Z are valid in the key. The key must have at least a length of 1.
 *
 * @param key Key to be used for the decryption
 * @param cypherText Cypher text
 * @param output Decrypted text
 * @return 0 on success, otherwise error code
 */
int decrypt(KEY key, const char* cypherText, char* output) {
	int err = isKeyValid(key);
	if(err !=0) {
		return err;
	}
	
	for(cypherText : o) {
		if(!CYPHER_CHARACTERS.contains(o)) {
			return E_CYPHER_ILLEGAL_CHAR;
		}
	}
	
	
	int keyIterator = 0;
	char[] temp = new char[cypherText.length];
	int cypherTextIterator = 0;
	for (cypherText : o) {
		/* so  
		temp[cypherTextIterator] = o ^ key[keyIterator];
		   oder so */
		temp[cypherTextIterator] = (o - 'A') ^ (key[keyIterator] - 'A');
		temp[cypherTextIterator] = temp[cypherTextIterator] + 'A';
		cypherTextIterator++;
		keyIterator++;
		if (keyIterator == key.length) {
			keyIterator = 0;
		}
	}
	output = temp;
	printf(output);
	return 0;
}
