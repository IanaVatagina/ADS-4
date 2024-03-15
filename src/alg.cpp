// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
    int counter = 0;
    int lowInd = 0;
    int highInd = size-1;
    while (lowInd <= highInd) {
        int middleInd = (highInd+lowInd)/2;
        if (arr[middleInd] > value) {
            highInd = middleInd-1;
        } else if (arr[middleInd] < value) {
            lowInd = middleInd+1;
        } else {
            counter++;
            int nowInd = middleInd-1;
            middleInd++;
            while (arr[middleInd] == value) {
                middleInd++;
                counter++;
            }
            while (arr[nowInd] == value) {
                nowInd--;
                counter++;
            }
            break;
        }
    }
    return counter;
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
    int counter = 0;
    int stepRight = len-1;
    while (arr[stepRight] > value)
        stepRight--;
    counter += countPairs1(arr, stepRight, value);
    return counter;
}
int countPairs3(int *arr, int len, int value) {
    int counter = 0;
    int stepLeft = 0;
    while (stepLeft < len) {
        int ostSlag = value - arr[stepLeft];
        counter += cbinsearch(&arr[stepLeft+1], len - stepLeft - 1, ostSlag);
        stepLeft++;
    }
    return counter;
}
