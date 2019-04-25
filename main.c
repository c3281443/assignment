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
    
 













