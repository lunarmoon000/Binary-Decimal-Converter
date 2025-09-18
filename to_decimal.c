#include <stdio.h> 
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define sleep_rate 1
#define MAX_BUFFER_SIZE 33 // one more than 32 so that it can be checked if a number exceeds 31 digits + newline.
#define wait_period 5 // used for the dots that appear after truncation message


int decimal(char* binary_num, int length){
    int decimal_num = 0;
    for(int j = length-1; j >= 0; j--){
        
        int curr_digit = binary_num[j] - '0';
        if(curr_digit > 9){
            printf("invalid input, you wrote something non-numeric!");
            return -1;
        } else if (curr_digit != 0 && curr_digit != 1){
            printf("\ninvalid digit, number is not binary.");
            return -1;
        }
        if(j != length-1){
            sleep(sleep_rate);
            printf("\n");
        }
        printf("--------Converted Number So Far: %d\n", decimal_num);
  
        printf("current binary digit: %d", curr_digit);
        if(curr_digit == 1){
            int exponent = (length - (j+1));
            int curr_power = (int) pow(2, exponent);
            decimal_num += curr_power;
            printf(", add 2^%d (which is %d) to converted decimal.", exponent, curr_power);
        } else{
            printf(", add nothing.");
        }
    }
    sleep(sleep_rate);
    return decimal_num;
}
int main(){
    puts("Welcome to Binary to Decimal Converter\n");
    while(true){
        puts("Enter -1 to exit,\nInsert a binary number: ");
        char binary_buffer[MAX_BUFFER_SIZE];
        fgets(binary_buffer, sizeof(binary_buffer),stdin);
        if(strcmp(binary_buffer, "-1\n") == 0){
            return 0;
        }
        int length = 0;
        for(int x = 0; binary_buffer[x] != '\0'; x++){
            if(binary_buffer[x] == '\n'){
                binary_buffer[x] = '\0';
            } else{
                length += 1;
            }
            
        }
        if(length == MAX_BUFFER_SIZE-1){
            printf("Maximum Digits Exceeded, must be no more than %d digits\nRe-run the program to try again.\n", (MAX_BUFFER_SIZE-2));
            return 1;
        }
        int converted = decimal(binary_buffer,length);
        if(converted >= 0){
            printf("\n--------Converted Decimal = %d\n", converted);
        } else{
            printf("\nCONVERSION FAILED.\n");
        }

        memset(binary_buffer, 0, length*sizeof(binary_buffer[0]));
    }


}