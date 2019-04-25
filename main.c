#include <stdio.h>
#include <string.h>sssssssssssssssss
#include<stdlib.h>



void cipher(char *decrypted, int key);

int main() {

    int key; //this is the key the user enters 
    char text[35]; //this is where he word entered by the user to be encrypted is stored
    

    printf("enter a word to be encrypted : \n");
    scanf( "%s", text);    //$s will read a string and not \o when it reads a space. 
    printf("enter a key (between 1 and 25): \n");
    scanf("%d", &key);
    
    
    printf("the ciphered text is:  ");
  
    cipher(decrypted, key);ddddddddddddddddd
   
    
  //printf("the encrypted text using a cipher with with a key shift of %d is \n", key );
    
}
//encryption using cipher = text + key mod 26. 
 void cipher(char *decrypted, int key) {
    
    int i=0;  //for the for loop
    int cipherText;
    int ciphered;
    
    while( decrypted[i] != '\0' && strlen(ciphered)-1 > i) {
        cipherText = ((int)decrypted[i] - 65 + key) % 26 + 65;
        ciphered = (char)(cipherText);
        
        printf("%c", cipher);
        i++;
    }
            
    printf("\n");
}













