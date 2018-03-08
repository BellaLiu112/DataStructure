#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

void multi_add(int g_results[], int n)
{
    //memset(g_results, 0, sizeof(int) * n);
    int coef, power, max = -1;
    while (true) {
        cin >> coef;
        cin >> power;
        if (power < 0)
            break;
        g_results[power] += coef;
        if (power > max)
            max = power;
    }
}

void pretty_print(int g_results[], int n)
{
    for (int i = n-1; i >= 0; --i)
        if (g_results[i])
            cout << "[ " << g_results[i] << " " << i << " ] ";
    cout << endl;
}


int main()
{
    int n;
    cin >> n;
    int g_results[1024];
    while (n--) {
        memset(g_results, 0, sizeof(int) * 1024);
        multi_add(g_results, 1024);
        multi_add(g_results, 1024);
        pretty_print(g_results, 1024);
    }
    return 0;
}




