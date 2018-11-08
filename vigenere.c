#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define KEY "LUCIAN"

void Encrypt(char * aText, const char * aKey)
{
  const char * keyChar = aKey;

  for (; *aText != '\0'; aText++)
  {
    if (*aText == '\n' || *aText == ' ')
      continue;

    unsigned char isLowerCase = islower(*aText);

    char toEncode = toupper(*aText);
    *aText = (((*keyChar - 'A') + (toEncode - 'A')) % 26) + 'A';

    if (isLowerCase)
      *aText = tolower(*aText);

    keyChar++;
    if (*keyChar == '\0')
      keyChar = aKey;
  }
}

void Decrypt(char * aText, const char * aKey)
{
  const char * keyChar = aKey;

  for (; *aText != '\0'; aText++)
  {
    if (*aText == '\n' || *aText == ' ')
      continue;

    unsigned char isLowerCase = islower(*aText);

    char toDecode = toupper(*aText);
    if (toDecode < *keyChar)
      toDecode += 26;

    *aText = (toDecode - *keyChar) + 'A';

    if (isLowerCase)
      *aText = tolower(*aText);

    keyChar++;
    if (*keyChar == '\0')
      keyChar = aKey;
  }
}

int main()
{
  char text[1000];
  
  printf("message=");
  fgets(text, sizeof(text), stdin);

  Encrypt(text, KEY);
  printf("Cyphered text: %s\n", text);

  Decrypt(text, KEY);
  printf("Decyphered text: %s", text);

  return 0;
}
