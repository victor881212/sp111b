#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    TOK_INT,
    TOK_PLUS,
    TOK_END
} TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;

Token getNextToken(char** input)
{
    Token token;
    char* current = *input;

    while (isspace(*current))
        current++;

    if (*current == '\0') {
        token.type = TOK_END;
    } else if (*current == '+') {
        token.type = TOK_PLUS;
        current++;
    } else if (isdigit(*current)) {
        token.type = TOK_INT;
        token.value = atoi(current);
        while (isdigit(*current))
            current++;
    } else {
        printf("無法識別的詞彙單元：%c\n", *current);
        exit(1);
    }

    *input = current;
    return token;
}

int main()
{
    char input[] = "42 + 13";
    char* current = input;

    Token token = getNextToken(&current);
    while (token.type != TOK_END) {
        if (token.type == TOK_INT) {
            printf("整數：%d\n", token.value);
        } else if (token.type == TOK_PLUS) {
            printf("加號\n");
        }

        token = getNextToken(&current);
    }

    return 0;
}