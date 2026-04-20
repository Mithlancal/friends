#include<iostream>
#include<string>

using namespace std;

int main(){
    string na1;
    string na2;

    cout<<"Enter your name\n";
    getline(cin, na1);
    cout<<"Enter your partner name\n";
    getline(cin, na2);

    // uppercase conversion
    for (int i = 0; i < na1.length(); i++) {
        if (na1[i] >= 'a' && na1[i] <= 'z') {
            na1[i] = na1[i] - 32;
        }
    }
    for (int i = 0; i < na2.length(); i++) {
        if (na2[i] >= 'a' && na2[i] <= 'z') {
            na2[i] = na2[i] - 32;
        }
    }

    int count = na1.length() + na2.length();
    int c1{};

    bool used2[100] = {0};

    // remove common characters
    for (int i = 0; na1[i] != '\0'; i++) {
        for (int j = 0; na2[j] != '\0'; j++) {
            if (na1[i] == na2[j] && !used2[j]) {
                used2[j] = true;
                c1 += 2;
                break;
            }
        }
    }

    int c2 = count - c1;

    char frnd[] = "flames";
    int size = 6;

    int cop = c2 % 6;
    if (cop == 0) cop = 6;

    int idx = 0;
    int removed = 0;

    // your "mark as x" logic but FIXED
    while (removed < 5) { // remove until 1 left
        int step = 0;

        while (step < cop) {
            if (frnd[idx] != 'x') {
                step++;
            }
            if (step == cop) break;

            idx = (idx + 1) % 6;
        }

        // mark as removed
        frnd[idx] = 'x';
        removed++;

        // move to next valid position
        while (frnd[idx] == 'x') {
            idx = (idx + 1) % 6;
        }
    }

    char result;

    // find the one not 'x'
    for (int i = 0; i < 6; i++) {
        if (frnd[i] != 'x') {
            result = frnd[i];
        }
    }

    switch (result) {
        case 'f':
            cout<<"You both are friends🫂.";
            break;
        case 'l':
            cout<<"You both are Lovers😘.";
            break;
        case 'a':
            cout<<"You both are Affectionate to eachother🥹.";
            break;
        case 'm':
            cout<<"you both are married💍.";
            break;
        case 'e':
            cout<<"you both are enemies👎.";
            break;
        case 's':
            cout<<"you both are siblings👥.";
            break;
        default:
            cout<<"why code didn't run😵.";
            break;
    }

    return 0;
}