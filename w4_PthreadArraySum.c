// #include <bits/stdc++.h>  
#include <pthread.h>
#include <stdio.h>

// using namespace std;
pthread_mutex_t key;

int len = 16, partition = 4, part = 0;
int arr[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220 };
int sum[4] = { 0 };

void arraySum (void *arg) {
    pthread_mutex_lock(&key);

    int index = part * (len/partition);

    for (int i = index; i < index+partition; i++) {
        sum[part] += arr[i];
    }
    // cout << "part" << part << " sum " << sum[part] << endl;
    printf("part%d sum %d\n", part, sum[part]);
    ++part;

    pthread_mutex_unlock(&key);
}

int main(int argc, char const *argv[]) {
    
    pthread_t threads[partition];

    for (int i = 0; i < partition; i++) {
        pthread_create(&threads[i], NULL, (void*) arraySum, NULL);
    }

    for (int i = 0; i < partition; i++) {
        pthread_join(threads[i], NULL);
    }

    int total = 0;
    for (int i = 0; i < partition; i++) {
        total += sum[i];
    }

    // cout << "The sum is " << total << endl; 
    printf("The sum is %d\n", total);

    return 0;
}
