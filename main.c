#include <stdio.h>
#include <string.h>

// these are the function names for the first 4 tasks 
void RcipherEncrypt(char *OGtext, int key);
void RcipherDecrypt(char *OGtext, int key);
void ScipherEncrypt(char *OGtext, char *textkey);
void ScipherDecrypt(char *OGtext, char *textkey);

int main() { 

    int choice;
    int key = 0;
    char textkey[100];
    char OGtext[100];
    printf("Enter text here: \n");
    scanf("%[^\n]", OGtext);
    printf("press 1 \n");
    printf("Press 2 \n");
    printf("Press 3 \n");
    printf("press 4 \n");
    scanf("%d", &choice); 
        
        switch (choice) //this takes the choice and then uses that number to choose etween switch cases. 
        {
            case 1:                        //chooses the first function 
                RcipherEncrypt(OGtext, key);
                break; 
                
            case 2:                         //chooses  second function 
                RcipherDecrypt(OGtext, key);
                break;
                
            case 3:                         //chooses third funciton 
                ScipherEncrypt(OGtext, textkey);
                break;
                
            case 4:                         //chooses fourth function 
                ScipherDecrypt(OGtext, textkey);
                break;
                
            default:                        //incase the user enters a number that is not between 1 & 4
                printf("Enter a valid option (a number between 1 and 4) \n");
                break;
                //switch case ends and the option is passed onto the function that is chosen. the user can the enter words to be encrypted/decrypted and keys......
        }
    return 0; 
}   //code is finished
 
void RcipherEncrypt(char *OGtext, int key) {
    
    int i; // this is the iteration moving through the string
    char c; //c is the character  
    printf("please enter a key (from 1 to 25): \n");
    scanf("%d", &key);
    
        for(i = 0; OGtext[i] != '\0' ; ++i) { //loop through the string
            c = OGtext[i];
            
            if (c >= 'A' && c<= 'Z'){
                c = c + key;
                
                if (c > 'Z'){
                    c = c - 'Z' +'A' - 1; 
                }
            OGtext[i] = c; 
            }
        }   
        printf("encrypted message using rotation cipher is: %s", OGtext);
}// here i the end of the rotation cipher funcction for encrypting messages

void RcipherDecrypt(char *OGtext, int key){  //this function is almost the same as the encyption one above but we are subtracting a key from the orginal text
    
    int i;
    char c;
    printf("please enter a key (1 to 25): \n");
    scanf("%d", &key);
    
        for(i = 0; OGtext[i] != '\0' ; ++i){ //loop through the string
            c = OGtext[i];
                
            if (c >= 'A' && c <= 'Z'){
                c = c - key;
                    
                if (c < 'A'){
                    c = c + 26; 
                }
            OGtext[i] = c; 
            }
        }   
            printf("encrypted message using rotation cipher is: %s\n", OGtext);
}// here i the end of the rotation cipher funcction for encrypting messages


void ScipherEncrypt(char *OGtext, char *textkey) { // for this function the key will be a work and noot number
    
    int i= 0;
    printf("enter a key: \n");
    scanf("%s", textkey);
    char c;
    
        for (i = 0; OGtext[i] != '\0'; i++) {
            c = OGtext[i];
                
                if (c >= 'A' && c <= 'Z') {
                    c = textkey[c - 'A'];
                }
            OGtext[i] = c;
        }
        
    printf("decrypted message is : %s\n", OGtext);
}


void ScipherDecrypt(char *OGtext, char *textkey) {
    
    int i;
    int ix = 0;  //this is the second iteration 
    int c;  //c for character
    printf("enter and encrytion key\n");
    scanf("%s", textkey);
    
        for (i = 0; OGtext[i] != '\0'; i++) {
            
            c = OGtext[i];
                
                if (c >= 'A' && c <= 'Z'){ 
                
                    for(ix = 0; ix < 27; ix++){
                        if(OGtext[i] == textkey[ix]) {
                            break;
                        }
                    }
                    OGtext[i] = ix + 'A';
            }           

             }
        
        printf("decrypted message is: %s\n", OGtext);
    
}
        
    
    














