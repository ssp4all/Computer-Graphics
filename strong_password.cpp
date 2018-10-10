#include <bits/stdc++.h>

using namespace std;

int min_num(int n, string psw) {

    int temp = n ;
    int digit=0,lower=0,upper=0,special=0;
    for(int i=0;i<n;i++)
    {
        if(isdigit(psw[i]))
            digit++;
        else if(isupper(psw[i]))
            upper++;
        else if(islower(psw[i]))
            lower++;
        else
            special++;
    }
    int count=0;
    if(digit == 0)
    {
        count++;
        temp++;
    }

    if(upper == 0)
    {
        count++;
        temp++;
    }
    if(lower == 0)
    {
        count++;
        temp++;
    }
    if(special == 0)
    {
        count++;
        temp++;
    }
    int diff;
    if(temp<6)
    {
        diff = 6 - temp;
        count += diff;


    }
    return count;
    // Return the minimum number of characters to make the psw strong
}

int main() {
    int n;
    cin >> n;
    string psw;
    cin >> psw;
    int answer = min_num(n, psw);
    cout << answer << endl;
    return 0;
}
