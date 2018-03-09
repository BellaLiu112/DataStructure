//
//  main.cpp
//  LargeIntMultiply_
//
//  Created by Chen Liu on 3/1/18.
//  Copyright © 2018 Chen Liu. All rights reserved.
//


#include<string>
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

void printArray(int* arr, int n);
void _add(int* left, int* right, int* result, int left_length, int right_length);
int cut_zero(int* vec, int length);
void reverse_array(int* arr, int length);
int LargeIntMulti(int* num1, int l1, int* num2, int l2, int* p, int n);


void _add(int* left, int* right, int* result, int left_length, int right_length)
// left is long, right is short, both reverse
// result is a vector of all zero, size left * right + 2
{
    int carry = 0, factor, digit;
    int i, j;
    for (i = 0; i < right_length; ++i) {
        factor = right[i];
        for (j = 0; j < left_length; ++j) {
            digit = left[j] * factor + carry;
            if (digit > 9){
                carry = digit / 10;
                digit %= 10;
            } else {
                carry = 0;
            }
            result[i+j] += digit;
            if (result[i+j] > 9) {
                carry += (result[i+j]/10);
                result[i+j] %= 10;
            }
        }
        result[i+j] += carry;
        carry = 0;
    }
}

int cut_zero(int* vec, int length)
// cut off pre-leading 0
{
    int i = 0;
    for (; i < length; ++i)
        if (vec[i] != 0)
            break;
    return i;
}

void reverse_array(int* arr, int length)
{
    for (int i = 0; i < length/2; ++i) {
        int temp = arr[i];
        arr[i] = arr[length -1 - i];
        arr[length -1 - i] = temp;
    }
}

int LargeIntMulti(int* num1, int l1, int* num2, int l2, int* p, int n)
{
    // cut off pre-leading zero
    // left is long, right is short
    int *left = num1, *right = num2;
    if (l2 > l1) {
        left = num2;
        right = num1;
        int tmp = l1;
        l1 = l2;
        l2 = tmp;
    }
    // reverse both left and right
    reverse_array(left, l1);
    reverse_array(right, l2);
    _add(left, right, p, l1, l2);
    reverse_array(p, n);
    int n_zero = cut_zero(p, n);
    return n_zero;
}

void printArray(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i];
    //cout << endl;
}


int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int num1, num2;
 
    int l1 = (int)s1.size(), l2 = (int)s2.size();
    int SIZE = l1 + l2 + 2;
    int left[l1], right[l2];
    for (int i = 0; i < l1; ++i)
        left[i] = s1[i] - 48;
    for (int i = 0; i < l2; ++i)
        right[i] = s2[i] - 48;
    
    int* p = new int[SIZE];
    memset(p, 0, SIZE * sizeof(int));
    int n = LargeIntMulti(left, l1, right, l2, p, SIZE);
    printArray(p+n, SIZE-n);
    //cout << endl;
    
    delete [] p;
    
    return 0;
}



