#include "MazeSolver.h"

int Solve( MazeInfo* Maze )
{
    int i=0;
    int j=0;
    int StartFound = FAIL;
    int Result = FAIL;

    Position Start;


    for(i=0; i<Maze->RowSIze; i++)
    {
        for(j=0; j<Maze->ColumnSize; j++)
        {
            if( Maze->Data[i][j] == START )
            {
                Start.X = j;    // Column
                Start.Y = i;    // Row
                StartFound = SUCCEED;
                break;
            }
        }
    }

    if ( StartFound == FAIL )
        return FAIL;

    if( MoveTo ( Maze, &Start, NORTH ) )
        Result = SUCCEED;
    else if ( MoveTo ( Maze, &Start, SOUTH ) )
        Result = SUCCEED;
    else if ( MoveTo ( Maze, &Start, EAST ) )
        Result = SUCCEED;
    else if ( MoveTo ( Maze, &Start, WEST ) )
        Result = SUCCEED;

    Maze->Data[Start.X][Start.Y] = START;

    return Result;
}

int MoveTo( MazeInfo* Maze, Position* Current, int Direction )
{
    int i=0;
    int Dirs[] = { NORTH, SOUTH, EAST, WEST };
    
    Position Next;

    // 목표 지점에 도달했을 때
    if ( Maze->Data[Current->Y][Current->X] == GOAL )
        return SUCCEED;

    Maze->Data[Current->Y][Current->X] = MARKED;

    for ( i=0; i<4; i++ ) // 1. 네 방향(NORTH, SOUTH, EAST, WEST)을 순회
    {
        // 2. 다음 단계가 유효한지 확인
        if ( GetNextStep( Maze, Current, Dirs[i], &Next ) == FAIL )
            continue; // 유효하지 않으면 다음 방향으로 건너뜀

        // 3. 재귀적 탐색 시도
        if ( MoveTo( Maze, &Next, NORTH ) == SUCCEED )
            return SUCCEED; // 다음 단계에서 목표를 찾았으면 성공 반환
    }

    // 경로가 실패했음을 표시
    // 상위 호출 함수가 다른 방향으로 시도해 볼 수 있도록 길을 "되돌려 놓는(백트래킹)" 과정
    Maze->Data[Current->Y][Current->X] = WAY;

    return FAIL;
}

int GetNextStep( MazeInfo* Maze, Position* Current, int Direction, Position* Next )
{
    switch ( Direction )
    {
    case NORTH:
        Next->X = Current->X;
        Next->Y = Current->Y - 1;

        if ( Next->Y == -1 ) return FAIL;

        break;

    case SOUTH:
        Next->X = Current->X;
        Next->Y = Current->Y + 1;

        if ( Next->Y == Maze->RowSIze ) return FAIL;

        break;

    case EAST:
        Next->X = Current->X + 1;
        Next->Y = Current->Y;

        if ( Next->X == Maze->ColumnSize ) return FAIL;

        break;

    case WEST:
        Next->X = Current->X - 1;
        Next->Y = Current->Y;

        if ( Next->X == -1 ) return FAIL;

        break;
    }

    if ( Maze->Data[Next->Y][Next->X] == WALL ) return FAIL;
    if ( Maze->Data[Next->Y][Next->X] == MARKED )return FAIL;

    return SUCCEED;
}

int GetMaze( char* FilePath, MazeInfo* Maze )
{
    int i=0;
    int j=0;
    int RowSize = 0;
    int ColumnSize = INIT_VALUE;

    FILE* fp;
    char buffer[MAX_BUFFER];

    // 1. 파일 열기 및 초기 검사
    if ( (fp = fopen( FilePath, "r" )) == NULL )
    {
        printf("Cannot open file : %s\n", FilePath);
        return FAIL;
    }

    // 2. 미로 크기 파악 및 데이터 유효성 검사
    while ( fgets( buffer, MAX_BUFFER, fp ) != NULL )
    {
        RowSize++;

        if ( ColumnSize == INIT_VALUE )
            ColumnSize = strlen( buffer ) - 1;

        else if ( ColumnSize != strlen( buffer ) - 1 )
        {
            printf("Maze data in file : %s is not valid.\n", FilePath);
            fclose( fp );
            return FAIL;
        }
    }

    // 3. 메모리 할당 및 파일 포인터 초기화
    Maze->RowSIze = RowSize;
    Maze->ColumnSize = ColumnSize;
    Maze->Data = (char**)malloc(sizeof(char*) * RowSize);

    for ( i=0; i<RowSize; i++ )
        Maze->Data[i] = (char*)malloc(sizeof(char) * ColumnSize);
    rewind( fp );       // 파일 포인터를 파일의 시작 지점으로 되돌림

    // 4. 미로 데이터 로드 및 종료
    for ( i=0; i<RowSize; i++ )
    {
        fgets( buffer, MAX_BUFFER, fp );

        for ( j=0; j<ColumnSize; j++ )
            Maze->Data[i][j] = buffer[j];
    }

    fclose( fp );
    return SUCCEED;
}