#include "math.h"
#include "php.h"

void IntToString(char* intager, int len);
char* ReserveString(char* a, int len);
char* Plus(char* a, int a_len, char* b, int b_len);
char* Multiply(char* a, int a_len, char* b, int b_len);
char* Divide(char* a, int a_len, char* b, int b_len);
char* Minus(char* a, int a_len, char* b, int b_len);