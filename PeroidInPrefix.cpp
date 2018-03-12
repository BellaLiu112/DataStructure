#include <iostream>
#include <string.h>

using namespace std;

char str[1000000];

void GetWord()
{
    str[0] = '\0';
    char ch;
    int i = 0;
    while (1) {
        ch = getchar();
        if (ch == '\n') {
            str[i++] = '\0';
            break;
        }
        else str[i++] = ch;
    }
}


int PrefixK(const char* str, int prefix_length, int pattern_length)
// prefix_length is a multiple of pattern_length
{
    // initialize pattern
    char p[1000000];
    p[0] = '\0';
    for (int i = 0; i < pattern_length; ++i)
        p[i] = str[i];
    p[pattern_length] = '\0';
    // compare
    int m = prefix_length / pattern_length;
    char tmp[1000000];
    tmp[0] = '\0';
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < pattern_length; ++j)
            tmp[j] = str[i*pattern_length + j];
        tmp[pattern_length] = '\0';
        if (strcmp(tmp, p) != 0)
            return 0;
    }
    cout << prefix_length << " " << m << endl;

    return 1;
}

void GetPrefixK(int n_size)
{
    for (int i = 2; i <= n_size; ++i) {
        for (int j = 1; j <= i/2; ++j)
            if((i % j) == 0){
                 int flag = PrefixK(str, i, j);
                if (flag)
                    break;
            }
    }
}

int main()
{
    int n, i = 0;
    while (1) {
        ++i;
        cin >> n;
        if (!n)
            break;
        getchar();
        GetWord();
        printf("Test case #%d\n", i);
        GetPrefixK(n);
        cout << endl;
    }
    return 0;

}
