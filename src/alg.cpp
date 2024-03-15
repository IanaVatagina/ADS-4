// Copyright 2021 NNTU-CS
int sortArr(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        bool isSorted = true;
        for (int j = 0; j < size - i; j++) {
            if (arr[j] > arr[j+1]) {
                int param = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = param;
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
    return 0;
}
int countPairs1(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; i++) {
        int num1 = arr[i];
        for (int j = 0; j < len; j++) {
            int num2 = arr[j];
            if (num1+num2 == value) {
                counter++;
            }
        }
    }
    return counter;
}
int countPairs2(int *arr, int len, int value) {
    sortArr(arr, len);
    int counter = 0;
    int stepRight = len-1;
    while (arr[stepRight] > value)
        stepRight--;
    counter += countPairs1(arr, stepRight, value);
    return counter;
}
int countPairs3(int *arr, int len, int value) {
    sortArr(arr, len);
    int counter = 0;
    int stepRight = len-1;
    int stepLeft = 0;
    while (stepLeft <= stepRight) {
        int summa = arr[stepLeft] + arr[stepRight];
        if (summa > value) {
            stepRight--;
        } else if (summa < value) {
            stepLeft++;
        } else {
            counter++;
            while (summa == value) {
                countPairs3(arr, stepRight, value);
            }
        }
    }
    return counter;
}
