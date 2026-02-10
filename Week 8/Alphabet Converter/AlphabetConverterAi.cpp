#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LINEBUF 256

// trim newline and trailing spaces
void rtrim(char *s) {
    int n = strlen(s);
    while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r' || isspace((unsigned char)s[n-1]))) s[--n] = '\0';
}

// read next non-empty line, return 1 if ok, 0 on EOF
int next_non_empty_line(FILE *f, char *out) {
    while (fgets(out, LINEBUF, f) != NULL) {
        rtrim(out);
        int allspace = 1;
        for (int i = 0; out[i]; i++) {
            if (!isspace((unsigned char)out[i])) { allspace = 0; break; }
        }
        if (!allspace && strlen(out) > 0) return 1;
    }
    return 0;
}

void print_freq(int freq[26]) {
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c %d\n", 'A' + i, freq[i]);
        }
    }
}

// helper: count freq of string s after applying map function mapFn(letter)->char
void count_with_map_and_print(const char *label, const char *X, char map[26]) {
    int freq[26] = {0};
    for (int i = 0; X[i]; i++) {
        char c = X[i];
        if (c >= 'A' && c <= 'Z') freq[(map[c - 'A']) - 'A']++;
    }
    printf("=== %s ===\n", label);
    print_freq(freq);
    printf("\n");
}

int main(void) {
    FILE *fp = fopen("testdata.in", "r");
    if (!fp) { perror("testdata.in"); return 1; }

    char line[LINEBUF];
    if (!next_non_empty_line(fp, line)) return 0;
    int T = atoi(line);

    for (int tc = 0; tc < T; tc++) {
        if (!next_non_empty_line(fp, line)) break;
        char X[105]; strncpy(X, line, sizeof(X)-1); X[sizeof(X)-1]=0; rtrim(X);

        if (!next_non_empty_line(fp, line)) break;
        int N = atoi(line);

        // store processes
        char A[30], B[30];
        int pc = 0;
        for (int i = 0; i < N; ) {
            if (!next_non_empty_line(fp, line)) break;
            char a=0,b=0;
            if (sscanf(line, " %c %c", &a, &b) == 2) {
                A[pc] = a; B[pc] = b; pc++; i++;
            } else {
                // skip malformed
            }
        }

        printf("---- Testcase %d: X=\"%s\"  N=%d ----\n\n", tc+1, X, pc);

        // 1) SEQUENTIAL
        {
            char Y[105]; strcpy(Y, X);
            for (int p = 0; p < pc; p++) {
                char a = A[p], b = B[p];
                for (int i = 0; Y[i]; i++) if (Y[i] == a) Y[i] = b;
            }
            int freq[26]={0};
            for (int i = 0; Y[i]; i++) if (Y[i]>='A' && Y[i]<='Z') freq[Y[i]-'A']++;
            printf("=== SEQUENTIAL ===\n"); print_freq(freq); printf("\n");
        }

        // 2) APPLY-ONCE DIRECT (map each left to right, apply to original)
        {
            char map[26];
            for (int i=0;i<26;i++) map[i] = 'A'+i;
            for (int p=0;p<pc;p++) map[A[p]-'A'] = B[p];
            count_with_map_and_print("APPLY-ONCE-DIRECT", X, map);
        }

        // 3) TRANSITIVE CLOSURE (chain): repeatedly map until stable
        {
            char map[26];
            for (int i=0;i<26;i++) map[i] = 'A'+i;
            for (int p=0;p<pc;p++) map[A[p]-'A'] = B[p];
            // closure: follow chain until fixed
            for (int i=0;i<26;i++) {
                char cur = map[i];
                while (map[cur - 'A'] != cur) cur = map[cur - 'A'];
                map[i] = cur;
            }
            count_with_map_and_print("TRANSITIVE-CLOSURE", X, map);
        }

        // 4) SKIP-IF-LEFT-USED: if left letter A already used as left before, skip that process
        {
            char map[26];
            for (int i=0;i<26;i++) map[i] = 'A'+i;
            int usedLeft[26]={0};
            for (int p=0;p<pc;p++) {
                char a=A[p], b=B[p];
                if (usedLeft[a-'A']) continue;
                usedLeft[a-'A']=1;
                map[a-'A']=b;
            }
            count_with_map_and_print("SKIP-IF-LEFT-USED", X, map);
        }

        // 5) SKIP-IF-TARGET-ALREADY-RESULT: if target B already appears as a result of prior mapping, skip (variant)
        {
            char map[26];
            for (int i=0;i<26;i++) map[i] = 'A'+i;
            int resultUsed[26]={0};
            for (int p=0;p<pc;p++) {
                char a=A[p], b=B[p];
                if (resultUsed[a-'A']) continue; // or maybe skip if a was already result? try both heuristics
                // Here we skip also if the target has been used as a result before:
                if (resultUsed[b-'A']) continue;
                map[a-'A'] = b;
                resultUsed[b-'A'] = 1;
            }
            count_with_map_and_print("SKIP-IF-TARGET-ALREADY-RESULT (variant)", X, map);
        }

        printf("---- end testcase %d ----\n\n", tc+1);
    }

    fclose(fp);
    return 0;
}
