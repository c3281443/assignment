#include <stdio.h>
#include <string.h>

// these are the function names for the first 5 tasks 
void RcipherEncrypt(char *OGtext, int key);  
void RcipherDecrypt(char *OGtext, int key);
void ScipherEncrypt(char *OGtext, char *textkey);
void ScipherDecrypt(char *OGtext, char *textkey);
void RcipherDecryptJUSTTEXT(char *OGtext, int key); 

int main(){ 

    int choice; //variable that allows the user to select between different choices of switch statements
    int key = 0; //this is the key for the 1st and 2nd functions
    char textkey[30]; //this is an array for the alphabet substitutions entered by the user 
    char OGtext[10000];  //an array for the text entered by the user that needs to be encrypted or decrypted 
    
    printf("Enter text here in CAPITAL LETTERS ONLY: \n");
    scanf("%[^\n]", OGtext); //this reads the users input for the text that needs to be encrypted or decrypted and ignores spaces. it will stop reading when it reaches '\0'
    printf("Press 1 for: Encryption of a message with a rotation cipher given the message text and rotation amount \n");
    printf("Press 2 for: Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount \n");
    printf("Press 3 for: Encryption of a message with a substitution cipher given message text and alphabet substitution \n");
    printf("press 4 for: Decryption of a message encrypted with a substitution cipher given cipher text and substitutions \n");
    printf("Press 5 for: Decryption of a message encrypted with a rotation cipher given cipher text only\n");
    scanf("%d", &choice); 
        
        switch (choice){ //this takes the choice and then uses that number to choose between switch cases. 
        
            case 1:                        
                RcipherEncrypt(OGtext, key); //executes the first function 
                break; 
                
            case 2:                         //executes the second function 
                RcipherDecrypt(OGtext, key);
                break;
                
            case 3:                         //executes the third funciton 
                ScipherEncrypt(OGtext, textkey);
                break;
                
            case 4:                         //executes the fourth function 
                ScipherDecrypt(OGtext, textkey);
                break;
                
            case 5:                         //executes the fourth function
                RcipherDecryptJUSTTEXT(OGtext, key);
                break;
                
            default:                        //incase the user enters a number that is not between 1 & 5 they will be able to select again
                printf("Enter a valid option (a number between 1 and 5) \n");
                break;
        }
    return 0; //code finished
}   
 
void RcipherEncrypt(char *OGtext, int key){ //function definition for Encryption of a message with a rotation cipher given the message text and rotation amount
    
    int i; // this is the iteration moving through the string
    char c; //this character is changed by the key and passed to the OGtext array. this is repeated until \0 is reached in the OGtext
    printf("Please enter a key (from 1 to 25): \n"); //user enters a key for the rotation cipher
    scanf("%d", &key); //scans the int entered by the user and stores it in int key
    
        for(i = 0; OGtext[i] != '\0' ; ++i){ //this for loop executes until it hits \0. its initialised at 0. 
            c = OGtext[i]; //a memory address of OGtext is allocated to c
            
            if (c >= 'A' && c<= 'Z'){  //if the value is in the ASCII range for uppercase letters the line of code is executed
                c = c + key;  //chracter is now the character + the key. 
                
                if (c > 'Z'){             // if adding the key to the character moves it higher than the ASCII upper case range
                    c = c - 'Z' +'A' - 1; // this moves the character back wihin the ASCII Upper case range  
                }
            OGtext[i] = c; //the character is passed to the array and repeated until \0 is reached.
            }
        }   
        printf("Encrypted message using rotation cipher is: %s", OGtext);
} //the end of the rotation cipher funcction for encrypting messages

void RcipherDecrypt(char *OGtext, int key){  //function definition for Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
    
    int i; // this is the iteration moving through the string
    char c; //this character is changed by the key and passed to the OGtext array. this is repeated until \0 is reached in the OGtext
    printf("Please enter a key (from 1 to 25): \n"); //user enters a key for the rotation cipher
    scanf("%d", &key); //scans the int entered by the user and stores it in int key
    
        for(i = 0; OGtext[i] != '\0' ; ++i){ //loop executes until it hits \0. its initialised at 0.
            c = OGtext[i]; //a memory address of OGtext is allocated to c
                
            if (c >= 'A' && c <= 'Z'){ //if the value is in the ASCII range for uppercase letters the line of code is executed
                c = c - key; //chracter is now the character + the key.
                    
                if (c < 'A'){ 
                    c = c + 26; //if key shift moves a character out of the ASCII upper case rage it is now moved back within that range
                }
            OGtext[i] = c; //the character is passed to the array and repeated until \0 is reached.
            }
        }   
            printf("Decrypted message using rotation cipher is: %s\n", OGtext); //decrypted message is printed as a string
}// end of the rotation cipher funcction for encrypting messages


void ScipherEncrypt(char *OGtext, char *textkey){ //function definition for Encryption of a message with a substitution cipher given message text and alphabet substitution
    
    int i= 0; //iteration movning through a string. initialised to 0
    printf("Enter a key an encryption key (26 letters long): \n"); 
    scanf("%s", textkey); //reads the substitued alphabet entered by the user and stores it as a srting
    char c; //this character is changed by the key and passed to the OGtext array. this is repeated until \0 is reached in the OGtext
    
        for (i = 0; OGtext[i] != '\0'; i++){ //this for loop executes until it hits \0. its initialised at 0.
            c = OGtext[i]; //a memory address of OGtext is allocated to c
                
                if (c >= 'A' && c <= 'Z'){ //if the value of c is in the ASCII upper case range the line of code is executed
                    c = textkey[c - 'A']; //
                }
            OGtext[i] = c; //the character is passed to the array and repeated until \0 is reached.
        }
        
    printf("Encrypted message is : %s\n", OGtext); //encrypted message is printed as a string
}


void ScipherDecrypt(char *OGtext, char *textkey){ //function definition for Decryption of a message encrypted with a substitution cipher given cipher text and substitutions
    
    int i; // this is the iteration moving through the string
    int ix = 0;  //this is the second iteration 
    int c;  //this character is changed by the key and passed to the OGtext array. this is repeated until \0 is reached in the OGtext
    printf("Please Enter an decrytion key (26 letters long)\n");
    scanf("%s", textkey); //reads the substitued alphabet entered by the user and stores it as a srting
    
        for (i = 0; OGtext[i] != '\0'; i++){ //this for loop executes until it hits \0. its initialised at 0.
             c = OGtext[i]; //a memory address of OGtext is allocated to c
                
                if (c >= 'A' && c <= 'Z'){ //if the value of c is in the ASCII upper case range the line of code is executed
                
                    for(ix = 0; ix < 27; ix++){ 
                        if(OGtext[i] == textkey[ix]){
                            break;
                        }
                    }
                    OGtext[i] = ix + 'A'; 
              }           

        }
        
        printf("Decrypted message is: %s\n", OGtext); //decrypted message is printed as a string
    
}

void RcipherDecryptJUSTTEXT(char *OGtext, int key){
    int i; // this is the iteration moving through the string
    char c; //this character is changed by the key and passed to the OGtext array. this is repeated until \0 is reached in the OGtext
    int count = 1; //initialises count to 1 so that it counts from 1 to 26
        for(count = 1; count <= 26; count++){ //this for loop loops through numbers 1 to 26 so each output can be numbered. 
            
            for(i = 0; OGtext[i] != '\0'; ++i){ //for loop executes until it hits \0. its initialised at 0.
                
                c = OGtext[i]; //a memory address of OGtext is allocated to c
                key = 1; //key initialised to 1
                    
                    if(c >= 'A' && c <= 'Z'){ //if the value of c is in the ASCII upper case range the line of code is executed
                        c = c - key; //character is now the character + key
                			
                		    if(c < 'A'){  //               		 
                				c = c + 'Z' - 'A' + 1; //moves the character back into the ASCII upper case range
                			}
                			
                			        OGtext[i] = c; //the character is passed to the array and repeated until \0 is reached.
                	}
                                key++; //key increases by 1 every time this code is looped. 
            }
        printf("Message is: %s key used is: %d\n", OGtext, count); //prints the decrytpted text and what key was used to decrypt it 
        }
    
}


    














