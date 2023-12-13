#include <stdio.h>
#define STR_LEN 1000
//Code by Daniel Redington:
// This program works to abbreviate messages with repeat characters
// if a character is repeated three or more times in a row, it will instead be replaced with the number and character aaa=3a
// This function is what reads in the user's input and stores it
    int read_line(char *str, int n){
        int ch, i=0;
        while ((ch=getchar()) !='\n')
        {if (i<n) {
            *str++=ch;
            i++;
        }
        }
        *str = '\0';
        return i;
    }
    // This function compress the input
    void compress(char*input, char*output){
    int count[STR_LEN];
    int x = 1;
    int y =0;
  
        for (int i=0; i<STR_LEN && *(input +i) != '\0';i++){
            if (*(input+i) == *(input+i+1)){
                    x++;
                }
              else if(x>2) { 
                *(output+y)= (x+'0');
                y++;
                *(output+y)=*(input+i);
                y++;
                x=1;
                }
                else if (x==2 && *(input +i) != *(input +i +1)){
                *(output+y)=*(input+i);
                y++;
                *(output+y)=*(input+i);
                y++;
                x=1;

            }
                else if(x<2 && *(input+i) != *(input +i +1)){
                *(output+y)=*(input+i);
                y++;
            
            } 
        }
        *(output+y)='\0';
        
    }
   
    int main(){
       
         int num_chars;
        char sen[STR_LEN+1];
        char *output = sen;
        printf("Enter message:");
        num_chars = read_line(sen, STR_LEN);
           // printf("you entered: %s, it has %d characters\n", sen, num_chars); (this line was useful for checking the input values)
        char *input = sen;
        compress(input, output);
        printf("Output: ");
        printf("%s\n",output);
  
    }
   