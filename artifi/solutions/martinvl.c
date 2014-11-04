#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char word[10];
    scanf("%s", word);

    printf("%s\n", strcmp(word, "yes") ? "yes" : "no");
}
