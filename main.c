#include <stdio.h>
#include <string.h>

void cipher(char text, int key);

int main() {

    int key; //this is the key the user enters 
    char text[35]; //this is where he word entered by the user to be encrypted is stored

    printf("enter a word to be encrypted : ");
    scanf( "%s", text);              //$s will read a string and not \o when it reads a space. 
    printf("enter a key: ");
    scanf("%d", &key);
    
    printf("the encrypted text using a cipher with with a key shift of %d is \n", key );
    
   cipher(text, key);

        return 0;
}
//encryption using cipher = text + key mod 26. 
void cipher(char text, int key) {
    
    int i;  //for the for loop
    int a;  //ASCII value 
    char cipherText;
    
    
    //loop through the text(string)
    for (i = 0; i != '\0'; i++) {
        
        a = ((text[i] - 'a')+ key) % (26 + 'a');
        cipherText = a;
        printf("%c", cipherText);  //prints the string for main()
    }
    
    
    
}













