#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int is_prime(int n)
{
    if (n <= 1)
        return 0;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

int primes_count_in_interval(int start, int finish)
{
    int ret = 0;
    for (int i = start; i < finish; i++)
        if (is_prime(i) != 0)
            ret++;
    return ret;
}

// The structure that will be passed to the threads, corresponding to an interval to count the number of primes in.
typedef struct prime_counter_request
{
    int start, finish, res;
} prime_counter_request;

void *prime_counter(void *arg)
{

    prime_counter_request *bounded = (prime_counter_request *)arg;
    bounded->res = primes_count_in_interval(bounded->start, bounded->finish);
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]), n_threads = atoi(argv[2]);
    int segment_size = n / n_threads;

    pthread_t *threads = malloc(n_threads * sizeof(pthread_t));

    prime_counter_request *requests = malloc(n_threads * sizeof(prime_counter_request));

    void **results = malloc(n_threads * sizeof(void *));

    for (int i = 0; i < n_threads; i++)
    {
        (requests + i)->res = 0;
        if(i + 1 == n_threads) {
            (requests + i)->start = segment_size * i;
            (requests + i)->finish = n - 1;
        }
        else {
            (requests + i)->start = segment_size * i;
            (requests + i)->finish = segment_size * (i + 1) - 1;
        }
        pthread_create(&*(threads + i), NULL, prime_counter, (void*) &requests[i]);
    }

    for (int i = 0; i < n_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    int total_result = 0;
    for (int i = 0; i < n_threads; i++)
        total_result += requests[i].res;

    free(requests);
    free(results);

    exit(EXIT_SUCCESS);
}
