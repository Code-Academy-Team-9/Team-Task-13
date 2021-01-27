/* "Напишете функция, която преброява колко думи има в един стринг, който й се подава като параметър." */
#include <stdio.h> 

/* Създаваме функция която ще използваме, за да можем да прочетем даден текст, въведен от потребителя. */
void getInput(char *str);

/* Създаваме функция която ще премине през всички символи в подаден стринг и ще преброи думите. */
unsigned countTheWords(char *str);

/* Нашата main функция в която искаме от потребителя да въведе своя текст и ние му връщаме броя на думите в него. */
int main(void) {
    char str[256];

    printf("Enter your text here:"); 
    getInput(str);
    printf("Numbers of words in \"%s\" : %d", str, countTheWords(str));
    return 0;
}

void getInput(char *str){
    char c ;
    int count=0;
    /* Създаваме цикъл при който потребителя въвежда символи, докато не натисне нов ред. Всеки символ се добавя към стринга. */
    while ((c = getchar()) != '\n'){
        *str++ = c;
        count++;
        if(count == 254){//1
            break;
        }
    }
    *str ='\0';
}

unsigned countTheWords(char *str) {
    /* Дефинираме две константи. Една за знак и една за буква.*/
    const int SIGN = 0;
    const int LETTER = 1;
    
    int state = SIGN;
    unsigned WordCounter = 0;

    /* Обхождаме стринга / низа */
    while (*str)
    {
        /* Проверяваме дали символа е различен от буква. */
        if (!((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))) {
            state = SIGN;
        } else if (state == SIGN) {
            state = LETTER;
            ++WordCounter;/* Брояч на думите. */
        }
        ++str; /* Преминаваме на следващият символ. */
    }
    return WordCounter; /* Връщаме брой думи. */
}