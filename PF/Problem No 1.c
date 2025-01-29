#include <stdio.h>

void Analysis(int array[10][10]) {
    int max_empty_row = -1;
    int max_empty_count = 0;
    int total_disabled = 0;
    int empty_count_row;
    int largest_block = 0;

   
    for (int i = 0; i < 10; i++) {
        empty_count_row = 0;
        for (int j = 0; j < 10; j++) {
            if (array[i][j] == 0) {
                empty_count_row++;
            }
        }
        if (empty_count_row > max_empty_count) {
            max_empty_count = empty_count_row;
            max_empty_row = i;
        }
    }

    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (array[i][j] == 3) {
                total_disabled++;
            }
        }
    }
    int is_10_percent_disabled = (total_disabled >= 10);


    for (int i = 0; i < 10; i++) {
        int current_block = 0;
        for (int j = 0; j < 10; j++) {
            if (array[i][j] == 0) {
                current_block++;
            } else {
                if (current_block > largest_block) {
                    largest_block = current_block;
                }
                current_block = 0;
            }
        }
        if (current_block > largest_block) {
            largest_block = current_block;
        }
    }

  
    for (int j = 0; j < 10; j++) {
        int current_block = 0;
        for (int i = 0; i < 10; i++) {
            if (array[i][j] == 0) {
                current_block++;
            } else {
                if (current_block > largest_block) {
                    largest_block = current_block;
                }
                current_block = 0;
            }
        }
        if (current_block > largest_block) {
            largest_block = current_block;
        }
    }

    
    printf("1. Row with the highest number of empty spaces: %d (with %d empty spaces)\n", max_empty_row, max_empty_count);
    printf("2. At least 10%% of the parking spaces are designated for disabled parking: %s\n", is_10_percent_disabled ? "Yes" : "No");
    printf("3. Largest contiguous block of empty spaces: %d\n", largest_block >= 4 ? largest_block : 0);
}

int main() {
    int parking[10][10] = {
        {0, 1, 0, 3, 0, 4, 0, 0, 1, 1},
        {0, 0, 0, 3, 0, 1, 0, 1, 4, 1},
        {3, 3, 0, 1, 0, 1, 0, 1, 0, 0},
        {4, 1, 1, 3, 3, 1, 0, 1, 0, 1},
        {0, 1, 0, 0, 0, 4, 1, 1, 1, 1},
        {3, 3, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 3, 0, 3, 4},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 3, 0, 1, 1, 4, 1, 0, 0},
        {3, 0, 0, 0, 1, 1, 1, 0, 4, 4}
    };

    Analysis(parking);

    return 0;
}
