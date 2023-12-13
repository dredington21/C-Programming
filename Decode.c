#include <stdio.h>
#include <string.h>

#define totwords 1000
#define totlength 100
#define totlength 100
/*Code by Daniel Redington:
This program deciphers hidden messages in files by reading the first letter of each word in a file and then storing 
each letter in a seperate file to reveal a hidden message
*/

void decode(char words[][totlength], int num_words, char *result);
//This function takes the first letter of each word and stores it in a seperate strinng
void decode(char words[][totlength], int num_words, char *result) {
    for (int i = 0; i < num_words; i++) {
        result[i] = words[i][0]; 
        result[i+1]= '\0';
    }
    
}
int main() {
    char name[totlength];
    char words[totwords][totlength];
    char result[totwords];
    int num_words = 0;

    printf("Enter the file name: ");
    scanf("%s", name);

    FILE *file1 = fopen(name, "r");
 

    char input[totlength];
   //this section stores each word into the words array and increments the number of words for each word added
    while (fscanf(file1, "%s", input) == 1) {
        
            strncpy(words[num_words], input, totlength);
            num_words++;
        
    }

    fclose(file1);

    decode(words, num_words, result);

    char file2[totlength + 8]; 
    snprintf(file2, sizeof(file2), "decoded_%s", name);

    FILE *output_file = fopen(file2, "w");

    fprintf(output_file, "%s", result);

    fclose(output_file);

    printf("%s\n",result);

    return 0;
}

