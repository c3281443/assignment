#include <stdio.h>
#include <string.h>

void cipher(char *text, int length, int key);

int main() {

    int key; //this is the key the user enters 
    char text[35]; //this is where he word entered by the user to be encrypted is stored
    int length;

    printf("enter a word to be encrypted : \n");
    scanf( "%s", text);    //$s will read a string and not \o when it reads a space. 
    printf("enter a key: \n");
    scanf("%d", &key);
    length = strlen(text);
    
    
  
    
    fdgfd = cipher(text, key, length);
    
  //printf("the encrypted text using a cipher with with a key shift of %d is \n", key );
        return 0;
}
//encryption using cipher = text + key mod 26. 
 cipher(char *text, int length, int key) {
    
    int i;  //for the for loop
    int a;  //ASCII value 
    char cipherText;
    
    //loop through the text(string)
    for (i = 0; i<=length; i++) {
        
        a = ((*text)+ key) % 26 + 'a';
        printf("a = %d\n", a);
        cipherText = a;
        printf("%c", cipherText);  //prints the string for main()
        text++;
        
    }
     printf(" \n");
     
    
    
}













