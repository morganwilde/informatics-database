#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char delimeters[] = " ~`!@#$%^&*()_-+={[}]|\\:;\"'<,>.?/";
int isDelimeter(const char *delimeters, int count, const char c)
{
    int i;
    for (i = 0; i < count; i++) {
        if (delimeters[i] == c) {
            return 1;
        }
    }
    if (c == '\n') {
        return 1;
    }
    return 0;
}
void tokenizer(const char *input, char ***output, int *outputCount, const char *delimeters)
{
    //
    // The designated tokenizer
    //
    // This will hold all the tokens
    char **tokens = (char **)malloc(sizeof(char *));
    int tokensLength = 0;
    // What symbols delimit tokens

    // Start reading
    char c;
    char *token = (char *)malloc(sizeof(char) * 1);
    int tokenLength = 0;
            
    // Read tokens from input
    int i;
    for (i = 0; i < strlen(input); i++) {
        c = input[i];
        //printf("c = %c\n", c);
        if (isDelimeter(delimeters, strlen(delimeters), c) || ((i+1) == strlen(input))) {
            // Delimeter
			if (!isDelimeter(delimeters, strlen(delimeters), c) && ((i+1) == strlen(input))) {
				// Append the last character
				tokenLength++;
				token[tokenLength-1] = c;
			}
			//printf("tokenLength : %d\n", tokenLength);
            if (tokenLength) {
                // Add terminating string char
                token = realloc(token, sizeof(char *) * (tokenLength+1));
                token[tokenLength] = '\0';
                // Proceed
                tokensLength++;
                tokens = realloc(tokens, sizeof(char *) * tokensLength);
                tokens[tokensLength - 1] = (char *)malloc(sizeof(char) * (tokenLength+2));
                strcpy(tokens[tokensLength - 1], token);
                tokenLength = 0;
                token = realloc(token, 0);
            }
        } else {
            // Token
            tokenLength++;
            if (token == NULL) {
                token;// = (char *)malloc(sizeof(char) * tokenLength);
            } else {
                token = (char *)realloc(token, sizeof(char) * tokenLength);
            }
            token[tokenLength - 1] = c;
        }
    }
    // Save the tokens into output
    *output = tokens;
    *outputCount = tokensLength;
}

void tokenizerDefault(const char *input, char ***output, int *outputCount)
{
    tokenizer(input, output, outputCount, delimeters);
}
