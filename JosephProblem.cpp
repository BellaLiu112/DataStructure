//
//  main.cpp
//  temp
//
//  Created by Chen Liu on 2/16/18.
//  Copyright © 2018 Chen Liu. All rights reserved.
//

#include <list>
#include <iostream>

using namespace std;

int joseph(int n, int m)
    //total n, number m killed
{
    list<int> lst;
    for(int i = 1; i < n+1; ++i)
        lst.push_back(i);
    int j = 1, target = 0;
    list<int>::iterator it = lst.begin();
    while(!lst.empty()){
        while (j != m) {
            if(it == lst.end())
                it = lst.begin();
            else
                if(++it == lst.end())
                    it = lst.begin();
            j++;
        }
        target = *it;
        //cout << "round" << target << endl;
        it = lst.erase(it);
        if(it == lst.end())
            it = lst.begin();
        j = 1;
    }
    return target;
}

int main(int argc, char** argv)
{
    //const char *str_n = argv[1], *str_m = argv[2];
    int n, m;
    //sscanf(str_n, "%d", &n);
    //sscanf(str_m, "%d", &m);
    cin >> n;
    cin >> m;

    //cout << n <<","<< m << endl;

    int target;
    target = joseph(n, m);
    cout << target << endl;

    return 0;
}
