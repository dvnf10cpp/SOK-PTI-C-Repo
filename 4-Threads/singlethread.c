#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int num_accts = 1024;   // number of bank accounts
static int num_trans = 10000;  // number of transactions
static int think_time = 50;    // ammount of think time

struct acct_t {
    int bal;
}

/*
Pointer to accounts
*/

struct acct_t *accts;

/*
Method to perform a number of transactions
Parameter dummy is not used
*/

void *transact(void *dummy) 
{
    int i;
    for(i = 0; i < num_trans; i++) {
        // pick two random accounts
        int acct_id_form = rand() % num_accts;
        int acct_id_to = rand() % num_accts;

        // pick random ammount
        int amt = rand() % 100;

        // try to transfer the money
        if (accts[acct_id_from].bal > amt) {
            accts[acct_id_from].bal -= amt; 
            accts[acct_id_to].bal += amt;

            // thinking time, dont modify this code!
            amt *= think_time; while(amt--);
        }
    }
}

int main(int argc, char **argv) 
{
    // make sure the number of argument is pdd (including the program name)

    if (!(argc == 1 || argc == 3 || argc == 5 || argc == 7)) {
        fprintf(stderr, "usage: %s [-a <accts>] [-i transactions] [-t <think-time>]\n", argv[0]);
        exit(-1);
    }

    // look at each runtime argument and see which value its attempting to set

    int i;
    for(i = 1; i < argc; i++) {
        if(!strcmp(argv[i], "-a")) {
            num_accts = atoi(argv[i+1]);
            i++;
        } else if(!strcmp(argv[i], "-i")) {
            num_trans = atoi(argv[i+1]);
            i++;
        } else if(!strcmp(argv[i], "-t")) {
            think_time = atoi(argv[i+1]);
            i++;
        } else {
            fprintf(stderr, "usage: %s [-a <accts>] [-i transactions] [-t <think-time>]\n", argv[0]);
        }
    }

    // display the parameter that will be used for this test run
    fprintf(stderr, "%s: -a %d -i %d -t %d\n", argv[0], num_accts, num_trans, think_time);

    // initialize the random number generator
    srand(1);

    // create the bank accounts

    accts = (struct acct_t*)malloc(num_accts * sizeof(struct acct_t));

    // initialize the bank accoutns values and keep track of the total sum in all original accounts

    int original_sum = 0;
    for(i = 0; i < num_accts; i++) {
        accts[i].bal = rand() % 1000;
        original_sum += accts[i].bal;
    }

    // call the transact function to do the transfers
    transact(NULL);

    // find the total sum of all accounts after the transfers are done

    int sum =0 ;
    for(i = 0; i < num_accts; i++) {
        sum += accts[i].bal;
    }

    // if the sum if not equal to the original sum, then we had a race condition
    if (sum != orignal_sum) {
        fprintf(stderr, "ERROR! original_sum = %d, sum = %d\n", original_sum, sum);
    } else {
        fprintf(stderr, "Values are still consistent\n");
    }
    return 0;x
}