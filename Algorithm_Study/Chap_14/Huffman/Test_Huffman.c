#include "Huffman.h"
#include <string.h>

int main()
{
    char* Source = "This Is Algorithms.";
    char* Decoded = "";

    HuffmanNode* Tree = NULL;
    BitBuffer Encoded = {NULL, 0};      //  압축 데이터
    HuffmanCode CodeTable[MAX_CHAR];    // 심볼(문자)과 그에 해당하는 비트 코드(Bit Code)를 매핑해 놓은 자료구조
    // 즉 허프만 코드가 있음.

    memset ( &CodeTable, 0, sizeof(HuffmanCode) * MAX_CHAR );

    Huffman_Encode( &Tree, (UCHAR*)Source, &Encoded, CodeTable );

    printf("Original Size : %ld, Encoded Size : %d\n",
                    (strlen(Source) + 1) * sizeof(char) * 8, Encoded.Size);

    Decoded = (char*)malloc( sizeof(char) * (strlen(Source) + 1) );
    Huffman_Decode( Tree, &Encoded, (UCHAR*)Decoded );

    printf("Original : %s\n", Source );
    printf("Encoded : ");
    Huffman_PrintBinary( &Encoded );
    printf("\n");

    printf("Decoded : %s\n", Decoded);
    Huffman_DestroyTree( Tree );
    free( Decoded );

    return 0;
}