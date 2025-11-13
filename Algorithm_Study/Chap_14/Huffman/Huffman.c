#include "Huffman.h"

HuffmanNode* Huffman_CreateNode( SymbolInfo NewData )
{
    HuffmanNode* NewNode = (HuffmanNode*)malloc( sizeof(HuffmanNode) );
    NewNode->Left    = NULL;
    NewNode->Right   = NULL;
    NewNode->Data    = NewData;

    return NewNode;
}

void Huffman_DestroyNode( HuffmanNode* Node )
{
    free( Node );
}

void Huffman_DestroyTree( HuffmanNode* Node )
{
    if(Node == NULL)
        return ;

    Huffman_DestroyNode( Node->Left );
    Huffman_DestroyNode( Node->Right );
    Huffman_DestroyNode( Node );
}

void Huffman_AddBit( BitBuffer* Buffer, char value )
{
    UCHAR Mask = 0x80;      // // 1000 0000, 2진수로 128

    if ( Buffer->Size % 8 == 0 )
    {
        Buffer->Buffer = 
                realloc( Buffer->Buffer, sizeof(UCHAR) * ((Buffer->Size / 8) + 1) );
        Buffer->Buffer[Buffer->Size / 8] = 0x00;
    }

    Mask >>= Buffer->Size % 8; // 현재 개수만큼 오른쪽 쉬프트 연산

    if ( value == 1 )
        Buffer->Buffer[Buffer->Size / 8] |= Mask;   // 삽입하려는 비트가 1이면, 현재 바이트와 마스크를 | (OR) 연산
    else   
        Buffer->Buffer[Buffer->Size / 8] &= ~Mask; // 마스크 위치 외의 모든 비트는 그대로 두고, 해당 위치의 비트만 0으로 설정

    Buffer->Size ++;
}

void Huffman_BuildCodeTable( HuffmanNode* Tree, HuffmanCode CodeTable[MAX_CHAR],
                             UCHAR Code[MAX_BIT], int Size )
{
    if ( Tree == NULL )
        return ;

    if ( Tree->Left != NULL )
    {
        Code[Size] = 0;
        Huffman_BuildCodeTable( Tree->Left, CodeTable, Code, Size+1 );
    }

    if ( Tree->Right != NULL )
    {
        Code[Size] = 1;
        Huffman_BuildCodeTable( Tree->Right, CodeTable, Code, Size+1 );
    }

    if ( Tree->Left == NULL && Tree->Right == NULL )
    // 리프 노드일 때
    {
        for ( int i=0; i<Size; i++ )
            CodeTable[Tree->Data.Symbol].Code[i] = Code[i];
            // 임시 배열 Code에 저장되어 있던 비트열(0과 1)을 CodeTable의 해당 문자에 복사

        CodeTable[Tree->Data.Symbol].Size = Size;
        // 코드의 최종 길이인 Size를 CodeTable[...].Size에 저장하여 나중에 인코딩할 때 사용하도록 한다.
    }
}

void Huffman_BuildPrefixTree( HuffmanNode** Tree,
                              SymbolInfo SymbolInfoTable[MAX_CHAR] )
{
    PQNode Result;
    PriorityQueue* PQ = PQ_Create(0);

    for ( int i=0; i<MAX_CHAR; i++ )    
    {
        if ( SymbolInfoTable[i].Frequency > 0 ) // 1. 빈도수가 0보다 큰 문자만 처리
        {
            HuffmanNode* BitNode = Huffman_CreateNode( SymbolInfoTable[i] ); // 2. 새 노드 생성
            PQNode NewNode;
            NewNode.Priority = SymbolInfoTable[i].Frequency; // 3. 빈도수를 우선순위로 설정
            NewNode.Data = BitNode; // 4. 노드를 데이터로 설정
            PQ_Enqueue( PQ, NewNode ); // 5. 우선순위 큐에 삽입
        }
    }

    while ( PQ->UsedSize > 1 )  // 큐에 노드가 1개(최종 루트)만 남을 때까지 반복
    {
        SymbolInfo NewData = { 0, 0 };
        HuffmanNode* BitNode = Huffman_CreateNode( NewData );
        HuffmanNode* Left;
        HuffmanNode* Right;

        PQNode QLeft;
        PQNode QRight;
        PQNode NewNode;

        PQ_Dequeue( PQ, &QLeft );  // 1. 가장 작은 빈도수의 노드 추출 (Left)
        PQ_Dequeue( PQ, &QRight ); // 2. 두 번째로 작은 빈도수의 노드 추출 (Right)

        Left  = (HuffmanNode*)QLeft.Data;
        Right = (HuffmanNode*)QRight.Data;
    
        // 3. 새로운 부모 노드(BitNode) 생성
        BitNode->Data.Symbol = 0; // 내부 노드이므로 심볼은 의미 없음 (0으로 설정)
        BitNode->Data.Frequency = 
            Left->Data.Frequency + Right->Data.Frequency; // 4. 빈도수의 합으로 새로운 가중치 설정

        BitNode->Left  = Left;   // 5. 추출한 두 노드를 Left, Right 자식으로 연결
        BitNode->Right = Right;

        NewNode.Priority = BitNode->Data.Frequency; // 6. 새로운 부모 노드의 빈도수를 우선순위로 설정
        NewNode.Data     = BitNode;

        PQ_Enqueue( PQ, NewNode ); // 7. 새로운 부모 노드를 큐에 다시 삽입
    }

    PQ_Dequeue( PQ, &Result );
    *Tree = (HuffmanNode*)Result.Data;
}

void Huffman_Encode( HuffmanNode** Tree, UCHAR* Source, BitBuffer* Encoded,
                      HuffmanCode CodeTable[MAX_BIT] )
{
    int i=0, j=0;
    SymbolInfo SymbolInfoTable[MAX_CHAR];
    UCHAR Temporary[MAX_BIT];

    for (i=0; i<MAX_CHAR; i++)
    {
        // SymbolInfoTable 초기화
        SymbolInfoTable[i].Symbol = i;
        SymbolInfoTable[i].Frequency = 0;
    }

    i=0;
    while ( Source[i] != '\0' )
    {
        // 소스의 각 빈도수 측정
        SymbolInfoTable[Source[i++]].Frequency++;
    }

    Huffman_BuildPrefixTree ( Tree, SymbolInfoTable ); // 트리 구성
    Huffman_BuildCodeTable ( *Tree, CodeTable, Temporary, 0 ); // CodeTable 구성

    i=0;
    while ( Source[i] != '\0' )
    {
        int BitCount = CodeTable[Source[i]].Size;

        for(j=0; j<BitCount; j++)
            Huffman_AddBit( Encoded, CodeTable[Source[i]].Code[j] );

        i++;
    }
}

void Huffman_Decode( HuffmanNode* Tree, BitBuffer* Encoded, UCHAR* Decoded )
{
    int Index = 0;
    HuffmanNode* Current = Tree;

    for ( int i=0; i<=Encoded->Size; i++ )
    {
        UCHAR Mask = 0x80; // 1000 0000

        if ( Current->Left == NULL && Current->Right == NULL )
        {
            Decoded[Index++] = Current->Data.Symbol;
            Current = Tree;
        }

        Mask >>= i % 8;

        if ( (Encoded->Buffer[i/8] & Mask) != Mask )
            Current = Current->Left;
        else
            Current = Current->Right;
    }

    Decoded[Index] = '\0';
}

void Huffman_PrintBinary( BitBuffer* Buffer )
{
    for ( int i=0; i<Buffer->Size; i++ )
    {
        UCHAR Mask = 0x80; // 1000 0000
        Mask >>= i % 8;

        printf("%d", (Buffer->Buffer[i/8] & Mask) == Mask);
    }
}