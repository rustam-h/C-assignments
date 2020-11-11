//
// Created by rusta on 11-Nov-20.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void function(char *source, char *integers, char *nonIntegers){
    int i = 0, intIndex = 0, nonIntIndex = 0;
    for( ; source[i] != '\0'; i++){
        if(source[i] >= 48 && source[i] <= 57){
            integers[intIndex] = source[i];
            intIndex++;
        }else{
            nonIntegers[nonIntIndex] = source[i];
            nonIntIndex++;
        }
        integers[intIndex] = '\0';
        nonIntegers[nonIntIndex] = '\0';
    }
}

int main(){

    char source[] = "abcdefg37847348 !!@$!";
    char integers[256];
    char nonIntegers[256];
    function(source, integers, nonIntegers);
    printf("source string:%s\n", source);
    printf("integer string:%s\n", integers);
    printf("noninteger string:%s\n", nonIntegers);

    return 0;
}
