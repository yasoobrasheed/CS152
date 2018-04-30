#ifndef _ADDR_BAL_H
#define _ADDR_BAL_H

// ======================================================================
// Declare any other structs you need in order to implement addr_bal here
// ======================================================================

typedef struct bucket bucket;
struct bucket {
  char* addr;
  double balance;
  unsigned long int hash;
  bucket* next;
};

typedef struct addr_bal {
    unsigned long int(*hash_func)(const char*);
    
    bucket** buckets;
    size_t n_buckets;
} addr_bal_t;


// Returns a new heap-allocated data structure for tracking the balance of each address.
addr_bal_t* addr_bal_new();

// Frees a heap-allocated data structure for tracking the balance of each address.
void addr_bal_free(addr_bal_t* ab);

// Get the balance associated with address addr and store the result in the double
// pointed to by out_bal.
// Returns 0 if the address couldn't be found and nonzero otherwise.
int get_balance(const char* addr, double* out_bal, addr_bal_t* ab);

// Set the balance associated with address addr to bal.
void set_balance(const char* addr, double bal, addr_bal_t* ab);


// =========================================================================
// Declare any other functions you need in order to implement addr_bal below
// =========================================================================

/*
 * Bucket Methods
 */

// Construct a new bucket with an address, a balance, and a hash value
bucket* bucket_cons(char* addr, double bal, unsigned long int hash, bucket* prev_head);

// Does this bucket contain a specific address
int bucket_contains(char* addr, unsigned long int hash, bucket* b);

// Frees a heap allocated bucket
void bucket_free(bucket* b);

// Print out a bucket
void bucket_show(bucket* b);

/*
 * Hash Set Methods
 */

// Good hash function for hashing values in the hash set
unsigned long int good_hash(const char* addr);

// Inset an address into a bucket in the hash set
void ab_insert(char* addr, double bal, addr_bal_t* ab);

// Print out the hash set
void ab_show(addr_bal_t* ab);

#endif /* _HSET_H */
