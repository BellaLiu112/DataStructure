#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;

struct StringIntPair {
    const char* k;
    int         v;
};

const StringIntPair pairs[] = {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10},
    {"eleven", 11},
    {"twelve", 12},
    {"thirteen", 13},
    {"fourteen", 14},
    {"fifteen", 15},
    {"sixteen", 16},
    {"seventeen", 17},
    {"eighteen", 18},
    {"nineteen", 19},
    {"twenty", 20},
    {"thirty", 30},
    {"forty", 40},
    {"fifty", 50},
    {"sixty", 60},
    {"seventy", 70},
    {"eighty", 80},
    {"ninety", 90},
    {"hundred", 100},
    {"thousand", 1000},
    {"million", 1000000}
};

int StringIntFind(const char* str)
{
    int res = 0;
    int l = sizeof(pairs) / sizeof(StringIntPair);
    for (int i = 0; i < l; ++i) {
        if (strcmp(str, pairs[i].k) == 0){
            res = pairs[i].v;
            return res;
        }
    }
    return res;
}


void input(char *str)
{
    char ch;
    while (1) {
        ch = getchar();
        if (ch == '\n')
        break;
        *str++ = ch;
    }
    *str++ = '\0';
}

void transfer_to_int(const char *str, vector<int>& container)
{
        //int res = 0;
    int flag = 1;
    int n = (int)strlen(str);
    char tmp[32];
    tmp[0] = '\0';
    int j = 0, i = 0;
    for (; i < n; ++i) {
        if (str[i] != ' ') {
            tmp[i-j] = str[i];
        } else {
            tmp[i-j] = '\0';
            j = i+1;
            if (strcmp(tmp, "negative") == 0) {
                flag = -1;
                container.push_back(flag);
                tmp[0] = '\0';
            } else {
                int number = StringIntFind(tmp);
                container.push_back(number);
                tmp[0] = '\0';
            }
        }
    }
    
    if (tmp[0] != '\0') {
        tmp[i-j] = '\0';
        int number = StringIntFind(tmp);
        container.push_back(number);
    }
}
/*
 int reorganize(vector<int>& container)
 {
 int res = 0;
 int flag = 1;
 int i = 0;
 for (; i < container.size(); ++i) {
 int tmp = container[i];
 if (tmp > 99) {
 if (tmp > res) {
 res *= tmp;
 } else {
 res -= container[i-1];
 res += container[i]*container[i-1];
 }
 } else if (tmp == -1){
 flag = -1;
 } else {
 res += container[i];
 }
 }
 res *= flag;
 return res;
 }
 */

int reorganize(vector<int>& container)
{
    int res = 0;
    int flag = 1;
    int tmp = 0;
    for (int i = 0; i < container.size(); ++i) {
        int num = container[i];
        if (num == 100) {
            tmp = (container[i-1] * 100);
        } else if (num == 1000){
            tmp *= 1000;
            res += tmp;
            tmp = 0;
        } else if (num == 1000000){
            tmp *= 1000000;
            res += tmp;
            tmp = 0;
        } else if (num == -1){
            flag = -1;
        } else {
            tmp += num;
        }
    }
    res += tmp;
    res *= flag;
    return res;
}


int main(int argc, char *argv[])
{
    vector<int> container;
    while (1) {
        container.clear();
        char buff[1024];
        buff[0] = '\0';
        input(buff);
        if (!strlen(buff))
        break;
        transfer_to_int(buff, container);
        int res = reorganize(container);
        cout << res << endl;
    }
    return 0;
}
