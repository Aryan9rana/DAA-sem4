#include <stdio.h>
#include <string.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int CommonSequence(char *S1, char *S2, int len1, int len2)
{
    int lcs[len1 + 1][len2 + 1];
    int i, j;
    for (i = 0; i <= len1; i++)
    {
        for (j = 0; j <= len2; j++)
        {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    return lcs[len1][len2];
}

int main()
{
    char S1[100], S2[100];
    printf("Enter the first sequence: ");
    fgets(S1, sizeof(S1), stdin);
    S1[strcspn(S1, "\n")] = '\0';

    printf("Enter the second sequence: ");
    fgets(S2, sizeof(S2), stdin);
    S2[strcspn(S2, "\n")] = '\0';

    int len1 = strlen(S1);
    int len2 = strlen(S2);

    int length = CommonSequence(S1, S2, len1, len2);

    printf("Length of the longest common subsequence: %d\n", length);

    return 0;
}
