#include <string.h>
#include<stdlib.h>

//Check is String Empty or Null  
bool isEmptyString(const char* value){
    return (value == NULL || value[0] == '\0');
}

int isLessThanThousand(const char *value){    
    int sum = 0;
    int input = atoi(value); // string to int
    return input < 1000 && input > 0 ? sum += input : 0;
}

int calculateSum(const char* input, char* delimiter)
{
    int sum = 0;
    char* Duplicate_inp = NULL;
    Duplicate_inp = strdup (input); // duplicate the string 
    char* token = strtok(Duplicate_inp, delimiter); //tokenizing strings
    while(token != NULL)
    {
        isLessThanThousand(token);
        token = strtok(NULL,delimiter);
    }
    return isLessThanThousand(token);
}

void appendCustomDelimiter(const char* input, char* delimiter) {
    int i = 2; 
    while(input[i] != '\n')
    {
        char src[1] = {input[i]};
        strncat (delimiter, src,1);
        i += 1;
    }
}

//ExpectSumWithCustomDelimiter("//;\n1;2")
void checkCustomDelimiter(const char* input, char* delimiter)
{
    if (input[0] == '/' && input[1] == '/'){
        strcpy(delimiter, "");
        appendCustomDelimiter(input,delimiter);
    }
    else{
        delimiter = ",\n";
    }
}

//ExpectSumWithCustomDelimiter
int add(const char* input)
{
    char delimiter[128] = ",\n";
    if (1 == isEmptyString(input))
    {
        return 0;
    }
    checkCustomDelimiter(input, delimiter);
    return calculateSum(input, delimiter);
    
}
