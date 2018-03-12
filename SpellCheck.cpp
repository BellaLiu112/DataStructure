#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

vector<string> dict;

void GetDict()
{
    char ch;
    string str;
    while (1) {
        ch = getchar();
        if (ch == '\n') {
            dict.push_back(str);
            str.clear();
        } else if (ch == '#'){
            break;
        } else {
            str.push_back(ch);
        }
    }
}

int correct(const string& word)
{
    int l = (int)dict.size();
    for (int i = 0; i < l; ++i) {
        if (strcmp(word.c_str(), dict[i].c_str()) == 0) {
            printf("%s is correct\n", word.c_str());
            return 1;
        }
    }
    return -1;
}

void DeleteOnesSimilar(const string& A, const string& B, vector<string>& similar_words)
{
    int A_len = (int)A.size();
    int B_len = (int)B.size();
    if (A_len - B_len == 1) {
        string tmp;
        for (int i = 0; i < A_len; ++i) {
            tmp = A;
            if (strcmp(tmp.erase(i, 1).c_str(), B.c_str()) == 0) {
                similar_words.push_back(A);
                return;
            }
        }
    } else
        return;
}

void ReplaceOneSimilar(const string& A, const string& B, vector<string>& similar_words)
{
    int A_len = (int)A.size();
    int B_len = (int)B.size();
    if (A_len == B_len) {
        string tmp;
        for (int i = 0; i < A_len; ++i) {
            tmp = A;
            if (A[i] != B[i]) {
                tmp[i] = B[i];
                if (strcmp(tmp.c_str(), B.c_str()) == 0) {
                    similar_words.push_back(A);
                    return;
                }
            }
        }
    } else
        return;
}

void AddOneSimilar(const string& A, const string& B, vector<string>& similar_words)
{
    int A_len = (int)A.size();
    int B_len = (int)B.size();
    if (A_len - B_len == -1) {
        string tmp;
        for (int i = 0; i < A_len; ++i) {
            tmp = A;
            if (A[i] != B[i]) {
                tmp.insert(i, 1, B[i]);
                if (strcmp(tmp.c_str(), B.c_str()) == 0) {
                    similar_words.push_back(A);
                    return;
                }
            }
        }
        tmp = A;
        tmp.push_back(B[A_len]);
        if (strcmp(tmp.c_str(), B.c_str()) == 0) {
            similar_words.push_back(A);
            return;
        }
    } else
        return;

}

void GetSimilarWords(const string& word, vector<string>& similar_words)
{
    int l = (int)dict.size();
    for (int i = 0; i < l; ++i) {
        DeleteOnesSimilar(dict[i], word, similar_words);
        ReplaceOneSimilar(dict[i], word, similar_words);
        AddOneSimilar(dict[i], word, similar_words);
    }
    return;
}

void GetWords(vector<string>& words)
{
    char ch;
    string str;
    while (1) {
        ch = getchar();
        if (ch == '\n') {
            if (str.length() != 0) {
                words.push_back(str);
                str.clear();
            }
        } else if (ch == '#'){
            break;
        } else {
            str.push_back(ch);
        }
    }
}

int main()
{
    GetDict();
    vector<string> words;
    vector<string> similar_words;
    GetWords(words);
    for (int i = 0; i < (int)words.size(); ++i) {
        if (correct(words[i]) == 1) {
            continue;
        } else {
            similar_words.clear();
            GetSimilarWords(words[i], similar_words);
            if (similar_words.size() == 0) {
                printf("%s:\n", words[i].c_str());
            } else {
                printf("%s:", words[i].c_str());
                for (int j = 0; j < (int)similar_words.size(); ++j) {
                    printf(" %s", similar_words[j].c_str());
                }
                cout << endl;
            }
        }
    }
    return 0;
}
