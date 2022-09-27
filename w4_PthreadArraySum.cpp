#include <bits/stdc++.h>  
// #include <pthread.h>
// #include <stdio.h>

using namespace std;
pthread_mutex_t key;

int len = 16, Partition = 4, part = 0;
int arr[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220 };
int sum[4] = { 0 };

void* arraySum (void *arg) {
    pthread_mutex_lock(&key);

    int index = part * (len/Partition);

    for (int i = index; i < index+Partition; i++) {
        sum[part] += arr[i];
    }
    // cout << "part" << part << " sum " << sum[part] << endl;
    printf("part%d sum %d\n", part, sum[part]);
    ++part;

    pthread_mutex_unlock(&key);
    return NULL;
}

int main(int argc, char const *argv[]) {
    
    pthread_t threads[Partition];

    for (int i = 0; i < Partition; i++) {
        pthread_create(&threads[i], NULL, arraySum, NULL);
    }

    for (int i = 0; i < Partition; i++) {
        pthread_join(threads[i], NULL);
    }

    int total = 0;
    for (int i = 0; i < Partition; i++) {
        total += sum[i];
    }

    // cout << "The sum is " << total << endl; 
    printf("The sum is %d\n", total);

    return 0;
}
