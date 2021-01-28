/* "Напишете функция, която преброява колко думи има в един стринг, който й се подава като параметър." */
#include <stdio.h> 

/*Change from team 8: We added global constant variables for the small and big letters code from ASCII*/
const char g_A = 65; 
const char g_a = 97;
const char g_Z = 90;
const char g_z = 122;

/* We create a function that we will call to read the string inputted from the user */
void getInput(char *str);

/* We create a function that will read all of the symbols and will count the words */
unsigned countTheWords(char *str);

void PrintOnScreen(char *String);

/* This is our main function in which we want to read the string inputted 
from the user and it returns the number of words in it*/
int main(void) {
    char str[256]; 
    PrintOnScreen(str);
    
    return 0;
}

/* Change from team 8: We create a function for printing the menu*/
void PrintOnScreen(char *String){
        printf("Enter your text here: \n"); 
        getInput(String);
        printf("Numbers of words in \"%s\" : %d\n", String, countTheWords(String));
}

void getInput(char *str){
    char c;
    int count = 0;
    /* We create a loop in which the user input characters until the user press a new line 
    and every character gets added to the string */
    while ((c = getchar()) != '\n'){
        *str++ = c;
        count++;
        if(count == 254){
            break;
        }
    }
    *str = '\0';
}

unsigned countTheWords(char *str) {
    /* Define two constant variables. The first is for the sign and the second is for the letter */
    const int SIGN = 0;
    const int LETTER = 1;
    
    int state = SIGN;
    unsigned WordCounter = 0;

    /* Traverse the whole string */
    while (*str)
    {
        /* Check if the character is not a letter */
        if (!((*str >= g_A && *str <= g_a) || (*str >= g_Z && *str <= g_z))) {
            state = SIGN;
        } else if (state == SIGN) {
            state = LETTER;
            ++WordCounter;/* word counter */
        }
        ++str; /* continue to the next character */
    }
    return WordCounter; /* return word count */
}
