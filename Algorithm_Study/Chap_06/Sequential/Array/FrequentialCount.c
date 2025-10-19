#include <stdio.h>
#include <stdlib.h> // for qsort (정렬에 사용할 경우)

// 전역 변수로 배열과 빈도수 배열 선언
// 실제 애플리케이션에서는 구조체 안에 캡슐화하는 것이 더 좋은 방법입니다.
#define MAX_SIZE 100 // 최대 배열 크기 정의
int global_arr[MAX_SIZE];
int global_frequency[MAX_SIZE];
int current_size = 0; // 현재 배열에 저장된 요소의 개수

// 배열에 요소 추가 (테스트용)
void initialize_array(int arr_data[], int size) {
    if (size > MAX_SIZE) {
        printf("초과된 크기입니다.\n");
        return;
    }
    current_size = size;
    for (int i = 0; i < size; i++) {
        global_arr[i] = arr_data[i];
        global_frequency[i] = 0; // 빈도수 초기화
    }
}

// 리스트 상태 출력
void print_array_status() {
    printf("Array Status: [");
    for (int i = 0; i < current_size; i++) {
        printf("%d(F:%d)", global_arr[i], global_frequency[i]);
        if (i < current_size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// 자기구성 순차 탐색 - 배열 계수법 (재정렬 포함)
// 반환값: 찾은 요소의 인덱스 (찾지 못하면 -1)
int SequentialSearch_Counting(int Target) {
    int target_index = -1;

    // 1. 타겟 요소 찾기 및 빈도수 증가
    for (int i = 0; i < current_size; i++) {
        if (global_arr[i] == Target) {
            global_frequency[i]++; // 빈도수 증가
            target_index = i;
            break;
        }
    }

    // 타겟을 찾지 못했으면 -1 반환
    if (target_index == -1) {
        printf("No unit (%d).\n", Target);
        return -1;
    }

    printf("Unit %d found at index %d. Frequency increased to %d.\n",
           Target, target_index, global_frequency[target_index]);

    // 2. 재정렬 로직: 현재 타겟 요소의 빈도수를 기준으로 앞으로 이동
    // 배열에서는 요소를 이동시키는 것이 연결 리스트보다 복잡합니다.
    // 여기서는 간단한 버블-업(bubble-up) 방식으로 구현합니다.
    // 더 효율적인 정렬이 필요하면 삽입 정렬이나 다른 방법을 고려할 수 있습니다.

    int current_val = global_arr[target_index];
    int current_freq = global_frequency[target_index];

    // 현재 위치부터 시작하여 자신보다 빈도수가 낮은(또는 같은) 요소를 만날 때까지 앞으로 이동
    int j = target_index;
    while (j > 0 && current_freq > global_frequency[j - 1]) {
        // 현재 요소를 한 칸 뒤로 밀기 (이동할 공간 확보)
        global_arr[j] = global_arr[j - 1];
        global_frequency[j] = global_frequency[j - 1];
        j--;
    }

    // 타겟 요소를 찾은 최종 위치에 삽입
    global_arr[j] = current_val;
    global_frequency[j] = current_freq; // 증가된 빈도수 반영

    printf("Array reordered. New index for %d is %d.\n", Target, j);
    return j; // 재정렬 후의 새로운 인덱스 반환
}

int main() {
    int data[] = {5, 3, 1, 4, 2, 8, 6};
    initialize_array(data, 7);

    printf("--- Initial Array ---\n");
    print_array_status();

    printf("\n--- Search for 4 ---\n");
    SequentialSearch_Counting(4);
    print_array_status();

    printf("\n--- Search for 2 ---\n");
    SequentialSearch_Counting(2);
    print_array_status();

    printf("\n--- Search for 4 (again) ---\n");
    SequentialSearch_Counting(4); // 4의 빈도수가 2가 되어 앞으로 이동
    print_array_status();

    printf("\n--- Search for 8 ---\n");
    SequentialSearch_Counting(8);
    print_array_status();

    printf("\n--- Search for 4 (again) ---\n");
    SequentialSearch_Counting(4); // 4의 빈도수가 3이 되어 더 앞으로 이동
    print_array_status();

    printf("\n--- Search for 7 (not in array) ---\n");
    SequentialSearch_Counting(7);
    print_array_status();

    return 0;
}