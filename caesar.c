#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// prototypes
char encode(char src, int key);
bool is_upper(char src);
bool is_lower(char src);
bool is_in_range(char src, char min, char max);
char rotate(char src, char anchor, int key, int range);

int main(int argc, string argv[])
{
    // no key entered
    if (argc < 2)
    {
        printf("Usage: caesar <key> \n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plain_text;
    int plain_len;
    
    // user inputs
    do
    {
        printf("Enter text to encrypt: ");
        plain_text = GetString();
        plain_len = strlen(plain_text);
    }
    while (plain_len == 0);
     
    printf("Rotate by %i: \n%s \n", key, plain_text);
   
    // begin processing
    for (int i = 0; i < plain_len; i++)
    {
        char result = encode(plain_text[i], key);
        printf("%c", result);
    }
    printf("\n");
    // success
    return 0;
}

/*
 * Encode char if it's a letter, or return original
 */
char encode(char src, int key)
{
    if (is_upper(src))
    {
        return rotate(src, 'A', key, 26);
    }
    if (is_lower(src))
    {
        return rotate(src, 'a', key, 26);
    }
    else
    {
        return src;
    }
}

/*
 * Is char an upper case letter
 */
bool is_upper(char src)
{
    return (is_in_range(src, 'A', 'Z'));
}

/*
 * Is char a lower case letter
 */
bool is_lower(char src)
{
    return (is_in_range(src, 'a', 'z')); 
}

/*
 * Is char between the other two chars, inclusive
 */
bool is_in_range(char src, char min, char max)
{
    return (src >= min && src <= max);
}

/*
 * Rotate char by key mod a given anchor and range
 */
char rotate(char src, char anchor, int key, int range)
{
    return (char) (anchor + (((src - anchor) + key) % range));
}
