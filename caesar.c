#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char ShiftCharacter(char aChar, int aK)
{
  if (!isalpha(aChar))
    return aChar;

  int isUpperCase = 0;
  if (aChar == toupper(aChar))
    isUpperCase = 1;

  aChar = tolower(aChar);
  aChar = ((aChar - 'a') + aK) % 26 + 'a';

  return isUpperCase ? toupper(aChar) : aChar;
}

void CaesarCypher(char * aText, int aK)
{
  char * iter = aText;

  for (; *iter != '\0'; ++iter)
  {
      *iter = ShiftCharacter(*iter, aK);
  }
}

void CaesarDecypher(char * aText, int aK)
{
  char * iter = aText;

  for (; *iter != '\0'; ++iter)
  {
      *iter = ShiftCharacter(*iter, 26 - aK);
  }
}

int main()
{
  int k;
  printf("k=");
  scanf("%d", &k);

  k = k % 26;
  if (k < 0)
    k = 26 + k;

  // get rid of the newline after reading k
  char text[1000];
  fgets(text, sizeof(text), stdin);
  
  printf("message=");
  fgets(text, sizeof(text), stdin);

  CaesarCypher(text, k);
  printf("Cyphered text: %s\n", text);

  CaesarDecypher(text, k);
  printf("Decyphered text: %s", text);

  return 0;
}
