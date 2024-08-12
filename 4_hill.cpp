#include<bits/stdc++.h>
using namespace std;

void getKeyMatrix(string key, int keyMatrix[][3]){
    int k=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            keyMatrix[i][j] = key[k] % 65;
            k++;
        }
    }
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int plainTextVector[][1]) {
    for(int i=0; i<3; i++){
        for(int j=0; j<1; j++){
            cipherMatrix[i][j] = 0;
            for(int k=0; k<3; k++){
                cipherMatrix[i][j] += keyMatrix[i][k] * plainTextVector[k][j];
            }
            cipherMatrix[i][j] %= 26;   
        }
    }
}

void HillCipher(string plainText, string key) {
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);
 
    int plainTextVector[3][1];
 
    for (int i = 0; i < 3; i++)
        plainTextVector[i][0] = (plainText[i]) % 65;
 
    int cipherMatrix[3][1];
 
    encrypt(cipherMatrix, keyMatrix, plainTextVector);
 
    string CipherText;
 
    for (int i = 0; i < 3; i++)
        CipherText += cipherMatrix[i][0] + 65;
 
    cout << " Ciphertext : " << CipherText;
}
 
int main()
{
    // string plainText = "SBT";
    // string key = "HAIEOPFUR";
 
    string plainText;
    string key;

    cout << "Enter plainText : ";
    cin >> plainText;

    cout << "Enter Key : ";
    cin >> key;

    cout << endl;

    HillCipher(plainText, key);
 
    return 0;
}