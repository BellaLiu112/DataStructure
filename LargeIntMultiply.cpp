#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

void _add(int* left, int* right, int* result, int left_length, int right_length)
// left is long, right is short, both reverse
// result is a vector of all zero, size left * right + 2
{
    int carry = 0, factor, tmp, digit;
    int i, j;
    for (i = 0; i < right_length; ++i) {
        factor = right[i];
        for (j = 0; j < left_length; ++j) {
            tmp = left[j] * factor + carry;
            if (tmp > 9){
                carry = tmp / 10;
                digit = tmp % 10;
            }
            result[i+j] += digit;
        }
        result[i+j+1] += carry;
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
    int n_zero_1 = cut_zero(num1, l1);
    int n_zero_2 = cut_zero(num2, l2);
    l1 -= n_zero_1;
    num1 += n_zero_1;
    l2 -= n_zero_2;
    num2 += n_zero_2;
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

int main()
{
    int left[5] = {0, 2, 3, 4, 5};
    int right[6] = {0, 1, 1, 1, 6, 0};
    int SIZE = 5 + 6 + 2;
    int* p = new int[SIZE]();// initialize
    int n = LargeIntMulti(left, 5, right, 6, p, SIZE);
    for (int i = n; i < SIZE; ++i) {
        cout << p[i];
    }
    cout << endl;
    return 0;
}


