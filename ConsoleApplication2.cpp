#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<string>
#include<fstream>
using namespace std;

typedef unsigned char byte;

int RC4()
{
    byte S[256];  //  배열 "S"는 초기화 과정에서 0에서 255까지의 값을 담습니다.
    byte K[256];  //  배열 "K"는 자신의 길이와 modula 연산을 통해 "S"의 내용값을 뒤섞습니다.
    byte key_Streambyte;
    //  "key_Streambyte"는 Key값으로 섞인 배열 "S"에서 평문과 암호화할 바이트 하나를 선택합니다.

    int i, j = 0, t;
    int counter = 0;
    
    char key[] = "";  //  키 값과 바이트 단위로 암호화할 평문입니다.
  
    while(1)
    {
        cout <<"5~16byte 의 key 값을 입력하세요: ";
        cin >> key;

        if (5 > strlen(key) )
        {
            cout << "key값이 5byte 미만입니다."<<endl;
        
        }
        else if (16< strlen(key))
        {
            cout << "key값이 16byte를 초과하였습니다."<<endl;
        
        }
        else
        {

            char plainText[] = "";
            string in_line;
            ifstream in("sample_text.txt");
            getline(in, in_line);
            strcpy(plainText, in_line.c_str());

                in.close();

                //  초기화 과정은 우선 256단계의 반복을 통해 "S"에 순열을 대입합니다.
                for (i = 0; i < 256; i++)
                {
                    S[i] = i;
                    K[i] = key[i % strlen(key)];
                }


                //  0에서 255까지의 값이 정렬된 "S"에 "K"와 swap() 함수를 통해 셔플링합니다.
                for (i = 0; i < 256; i++)
                {
                    j = (j + S[i] + K[i]) % 256;
                    swap(S[i], S[j]);
                }

                i = j = 0;


                cout << "Current key value : " << key << endl << endl;
                //  현재의 key 값을 출력합니다.

                //  평문의 바이트 길이만큼 암호화가 반복적으로 이루어집니다.
                for (counter = 0; counter < strlen(plainText); counter++)
                {
                    i = (i + 1) % 256;
                    j = (j + S[i]) % 256;
                    swap(S[i], S[j]);

                    t = (S[i] + S[j]) % 256;
                    key_Streambyte = S[t];

                    plainText[counter] ^= S[key_Streambyte];  //  암호화/

                    cout << (counter + 1) << "'s key_Streambyte  :  ";  //  평문의 한 바이트마다
                    cout << (unsigned int)key_Streambyte << endl;  //  key_Streambyte를 확인합니다.
                }

                cout << endl << "Decrypted PlainText  :  "
                    << plainText << endl;  //  암호화할 때마다 매번 복호화해서 평문이 그대로 출력됩니다.

                ofstream out("sample_text.txt");

                out << plainText << endl;
                out.close();

                exit(0);
            }
    }
}

int main()
{
    RC4();
}