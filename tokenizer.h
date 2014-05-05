#ifndef TOKENIZER_H
#define TOKENIZER_H

int isDelimeter(const char *delimeters, int count, const char c);
void tokenizer(const char *input, char ***output, int *outputCount, const char *delimeters);
void tokenizerDefault(const char *input, char ***output, int *outputCount);

#endif /* TOKENIZER_H */
