#include <stdio.h>

int main() {
    char character[101];
    scanf("%[^\n]", character);

    printf("#include <stdio.h>\n");
    printf("int main()\n");
    printf("{\n");
    printf("    printf(\"%%s\\n\",\"%s\");\n", character);
    printf("    return 0;\n");
    printf("}\n");

    return 0;
}