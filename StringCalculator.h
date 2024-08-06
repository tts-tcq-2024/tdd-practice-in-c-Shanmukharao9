#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*To find out the delimiter in the input string*/
int isdelimiter(char character, const char *delimiter) {
    while (*delimiter != '\0') {
        if (character == *delimiter) {
            return 1;
        }
        delimiter++;
    }
    return 0;
}

int maxLimit(int num)
{
    return (num>=0 && num<=1000) ? num : 0;
}

/* positive single digit logic inorder to reduce the complexity logic for the positive_single_number function*/
bool positive_single_digit(int count,int set,char *token)
{
    return ((count>0) && set==0 && (!isalpha(*token)));
}

bool positive_single_number(int flg,int count,int set,char *token)
{
    bool is_singledigit=positive_single_digit(count,set,token);
    return (!flg  && is_singledigit);
}

/* positive multiple digits logic inorder to reduce the complexity logic for the positive_multiple_numbers function*/
bool positive_multiple_digits(int flg,int count,int set,char *token)
{
    return ((flg || (set>0)));
}

bool positive_multiple_numbers(int flg,int set,char *token,int count)
{
    bool is_multipledigits=positive_multiple_digits(flg,count,set,token);
    return (is_multipledigits);
}

int stringCalculation(char *token,int flg,int count,int set) {

    static int sum=0;
    int prev=atoi(token);
    bool pos_mn=positive_multiple_numbers(flg,set,token,count);
    bool pos_sn=positive_single_number(flg,count,set,token);

    /* Logic for multiple numbers separated by delimiters */
    if(pos_mn)
    {
        prev=maxLimit(prev);
        sum=sum+prev;
        return sum;
    }

    /* Logic for single digit number without delimiter */
    if(pos_sn)
    {
        int result=maxLimit((atoi(token)));
        return (result);
    }

    return atoi(token);

}

/*To handle the last character in the input string */
int lastCharacter(int flg,int set,char *strptr,int count,int result)
{
    if (*strptr != '\0') {
        result=stringCalculation(strptr,flg,count,set);
        return result;
    }
    return result;
}

/* Splitting the strings into substring logic for calculation */
int splitString(const char *input, const char *delimiters) {
    char *copyptr;
    copyptr = (char *)malloc(strlen(input) + 1);
    strcpy(copyptr,input);//Copying the input string into copyptr inorder to form substring from the input
    char *strptr = copyptr;
    int result, count, set=0;
    while (*copyptr != '\0') {
        int isDelimiterFound = isdelimiter(*copyptr, delimiters);
        if (isDelimiterFound) {
            set++;
            // Found a delimiter, terminate the current substring
            *copyptr='\0';
            result=stringCalculation(strptr,isDelimiterFound,count,set);
            strptr = copyptr + 1;  // Update start pointer to next character after delimiter
        }
        copyptr++;
        count++;
    }
    result = lastCharacter(delimiters,set,strptr,count,result);
    return result;
}


int add(const char* input)
{
    int result=0;
    const char delimiters[] = ",;\n[]*//";
    return splitString(input, delimiters);;
}
