#include <string.h>
#include<stdlib.h>

//Check is String Empty or Null  
bool isEmptyString(const char* value){
    return (value == NULL || value[0] == '\0')? TRUE : FALSE;
}

int isLessThanThousand(const char *value){    
    int sum = 0;
    int input = atoi(val); // string to int
    return input < 1000 ? sum += input : 0+sum;
}
