#include<iostream>
#include<string>

using namespace std;//using this so if i get bored i won't write std::cin or std::cout :>


int main(){
    //hello this is a simple game of flames using simple mechaninsm
    std::string na1;
    std::string na2;
    std::cout<<"Enter your name\n";
    std::getline(cin, na1);
    std::cout<<"Enter your partner name\n";
    std::getline(cin, na2);

    //now i converted the string to uppercase for no reasons
    for (int i = 0; i < na1.length(); i++) {
        if (na1[i] >= 'a' && na1[i] <= 'z') {
            na1[i] = na1[i] - 32;
        }
    }//uppercase conversion
    for (int i = 0; i < na2.length(); i++) {
        if (na2[i] >= 'a' && na2[i] <= 'z') {
            na2[i] = na2[i] - 32;
        }
    }//uppercase conversion
    int count = na1.length() + na2.length();//total length of two strings
    int c1{};

    bool used2[100] = {0}; // track used chars in na2

    for (int i = 0; na1[i] != '\0'; i++) {
        for (int j = 0; na2[j] != '\0'; j++) {
            if (na1[i] == na2[j] && !used2[j]) {
                used2[j] = true;
                c1 += 2; // both characters removed
                break;
            }
        }
    }//function for common
    
    int c2 = count-c1;//common out
    char result;
    char copy[6];

    char frnd[] = "flames"; //so this is the string which i will use to calculate relations



    result = frnd[0];
    switch (result) {
        case 'f':
            std::cout<<"You both are friends🫂.";
            break;
        case 'l':
            std::cout<<"You both are Lovers😘.";
            break;
        case 'a':
            std::cout<<"You both are Affectionate to eachother🥹.";
            break;
        case 'm':
            std::cout<<"you both are married💍.";
            break;
        case 'e':
            std::cout<<"you both are enemies👎.";
            break;
        case 's':
            std::cout<<"you both are siblings👥.";
            break;
        default:
            std::cout<<"why code didn't run😵.";
            break;
    
    }

    return 0;

    

}
