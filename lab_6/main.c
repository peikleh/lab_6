/* 
 * File:   main.c
 * Author: nevin.leh
 *
 * Created on June 3, 2014, 11:17 AM
 */

#include <stdio.h>
#include <stdlib.h>
void problem_1();

/*
 * 
 */
void problem_1() {
    char junk;
    printf("this is fucked");
    char p = 'a';
    int cipher_stop = 0;
    int cipher_array[26];

    FILE *cipher = fopen("cipher.txt", "r");
    while (cipher_stop < 26) {
        fscanf(cipher, " %i ", &cipher_array[cipher_stop]);
        fscanf(cipher, " %c", &junk);
        cipher_stop++;
    }

    char letter_array[26];
    char starting_point = 'a';
    int loop;
    for (loop = 0; loop < 26; loop++) {
        letter_array[loop] = starting_point + loop;
    }
    int test;
    for (test = 0; test < 26; test++) {
        printf(" %c \n", p);
    }
    
    
    FILE *message = fopen("message.txt", "r");
    FILE *decode = fopen("decode.txt", "w");
    int decode_done;
    int cur_message;
    while(decode_done!= -1){
       decode_done = fscanf(message, "%i", &cur_message);
       int loop;
       int position;
       for(loop=0; loop<100; loop++){
           if(cur_message==cipher_array[loop]){
               position=loop;
               loop=100;
           }
       }
       printf(" %i", position);
       fprintf(decode, " %c", &letter_array[position]);
       decode_done=fscanf(message, " %c", &junk);
    }
//    int test;
//    for (test = 0; test < 26; test++) {
//        printf(" %c", letter_array[test]);
//    }
   // fprintf(decode, " %c", p );
    
}
   
int main(void) {
        problem_1();


        return (EXIT_SUCCESS);
    }

