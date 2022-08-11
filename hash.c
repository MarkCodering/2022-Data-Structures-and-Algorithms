#include <stdio.h>
#include <stdlib.h>

int hash(char *str);
char *hashToString(int hashInput);

int main(void){
    int hashValue = 0;
    hashValue = hash("Hello");
    printf("%d\n", hashValue);
    
    char *str = hashToString(hashValue);
    printf("%s\n", str);

    return 0;    
}

//Create a hashing function for UUID
//Input: a string
//Output: a hash value
int hash(char *str){
    int hash = 0;
    int i = 0;
    while(str[i] != '\0'){
        hash = hash + str[i];
        i++;
    }
    return hash;
}

//Create a function that takes a hash value and return the value of the hash function in string format
//Input: a hash value
//Output: a string
char *hashToString(int hash){
    char *str = (char *)malloc(sizeof(char) * 10);
    
    return str;
}