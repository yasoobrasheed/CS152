#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cs152coin.h"


dep_wd_t* parse_dep_wd()
{
    char* s = NULL;
    double d = 0;
    
    read_string(&s);

    dep_wd_type type;

    if (!strcmp(s, "DEPOSIT")) {
        type = DEPOSIT;
    } else if (!strcmp(s, "WITHDRAWAL")) {
        type = WITHDRAWAL;
    } else {
        return NULL;
    }

    next_token();
    
    dep_wd_t* dw = calloc(1, sizeof(dep_wd_t));
    dw->type = type;
    
    read_string(&s);
    dw->addr = strdup(s);
    next_token();
    
    read_double(&d);
    dw->amount = d;
    next_token();
    
    return dw;
}


trans_t* parse_trans()
{
    char* s = NULL;
    trans_t* trans = malloc(sizeof(trans_t));
    
    // BEGIN_TRANSACTION
    read_string(&s);

    // <transaction id>
    next_token();
    read_string(&s);
    trans->id = strdup(s);

    // BEGIN_INPUTS
    next_token();

    // WITHDRAWAL || END_INPUTS
    next_token();
    read_string(&s);

    int i = 0; 
    while (strcmp(s, "END_INPUTS") != 0) {
        trans->inputs[i] = parse_dep_wd();

        // END_INPUTS || WITHDRAWAL
        read_string(&s);
        i++;
    }
    trans->num_inputs = i;

    // DEPOSIT
    next_token();
    trans->output = parse_dep_wd();
    return trans;
}


block_t* parse_block()
{ 
    char* s = NULL;
    block_t* block = malloc(sizeof(block_t));

    //DEPOSIT
    next_token();
    read_string(&s);

    block->miner = parse_dep_wd();
    block->trans = parse_trans();

    // BEGIN TRANSACTION || END_BLOCK
    next_token();
    read_string(&s);

    trans_t* prev_trans = block->trans;
    while (strcmp(s, "END_BLOCK") != 0) {
        trans_t* new_trans = parse_trans();
        prev_trans->next = new_trans;
        prev_trans = new_trans;
        // BEGIN_TRANSACTION || END_BLOCK
        next_token();
        read_string(&s);
    }
    return block;
}


blockchain_t* parse_blockchain()
{
    char* s = NULL;
    blockchain_t* blockchain = malloc(sizeof(blockchain_t));
    blockchain->blocks = parse_block();
    
    // END_BLOCK || NULL
    next_token();
    block_t* curr_block = blockchain->blocks;
    while (read_string(&s) != 0) {
        block_t* new_block = parse_block();
        curr_block->next = new_block;
        curr_block = new_block;
        // END_BLOCK || NULL
        next_token();
    }
    return blockchain;
}


void dep_wd_free(dep_wd_t* dw)
{
    free(dw->addr);
    free(dw);
}


void trans_free(trans_t* trans)
{
    free(trans->id);
    for (int i = 0; i < 5; i++) {
        if (trans->inputs[i]) {
            dep_wd_free(trans->inputs[i]);
        } else {
            break;
        }
    }    
    dep_wd_free(trans->output);
    free(trans);
}


void block_free(block_t* block)
{
    dep_wd_free(block->miner);
    trans_t* curr_trans = block->trans;
    while (curr_trans) {
        trans_t* next_trans = curr_trans->next;
        trans_free(curr_trans);
        curr_trans = next_trans;
    }
    free(block);
}


void blockchain_free(blockchain_t* bc)
{
    block_t* curr_block = bc->blocks;
    while (curr_block) {
        block_t* next_block = curr_block->next;
        block_free(curr_block);
        curr_block = next_block;
    }
    addr_bal_free(bc->addr_bal);
    free(bc->dbl_spends);
    free(bc);
}


void check_dbl_spend(dbl_spends_t** ds, addr_bal_t* ab, char* id, char* addr) {
    double bal = 0;
    get_balance(addr, &bal, ab);
    if (bal < 0) {
        add_dbl_spend(id, addr, *ds);
        if ((*ds)->next) {
            *ds = (*ds)->next;
        }
    }
}


void compute_stats(blockchain_t* bc)
{
    int num_blocks = 0;
    int num_trans = 0;
    double sum_trans_value = 0;
    int first = 0;

    addr_bal_t* ab = addr_bal_new(); 
    dbl_spends_t* ds = dbl_spends_new();
    bc->dbl_spends = ds;
    dbl_spends_t* curr_ds = ds;

    while (bc->blocks) {
        char* m_addr = bc->blocks->miner->addr;
        double m_amount = bc->blocks->miner->amount;
        set_balance(m_addr, m_amount, ab);
        num_blocks++;
        while (bc->blocks->trans) {
            for (int i = 0; i < 5; i++) {
                if (bc->blocks->trans->inputs[i]) {
                    if (first == 0 && i == 1) { 
                        first++;
                        break;
                    }
                    char* trans_id = bc->blocks->trans->id;
                    char* t_addr = bc->blocks->trans->inputs[i]->addr;
                    double t_amount = -1 * bc->blocks->trans->inputs[i]->amount;
                    set_balance(t_addr, t_amount, ab);
                    check_dbl_spend(&curr_ds, ab, trans_id, t_addr);
                } else {
                    break;
                }
            }
            char* o_addr = bc->blocks->trans->output->addr;
            double o_amount = bc->blocks->trans->output->amount;
            set_balance(o_addr, o_amount, ab);
            num_trans++;
            sum_trans_value += bc->blocks->trans->output->amount;
            bc->blocks->trans = bc->blocks->trans->next;
        }
        bc->blocks = bc->blocks->next;
    }   
    bc->addr_bal = ab;
    bc->num_blocks = num_blocks;
    bc->num_trans = num_trans;
    bc->avg_trans_value = sum_trans_value / num_trans;
}


void print_stats(blockchain_t* bc)
{
    if (bc == NULL) return;
    
    printf("Number of blocks: %lu\n", bc->num_blocks);
    printf("Number of transactions: %lu\n", bc->num_trans);
    printf("Average transaction value: %lf\n", bc->avg_trans_value);
    printf("\n");

    printf("Double spends:\n");
    dbl_spends_show(bc->dbl_spends, stdout);
    printf("\n");
}


int main(int argc, char* argv[])
{
    init_parser();

    blockchain_t* bc = parse_blockchain();
    
    compute_stats(bc);
    print_stats(bc);
    
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    
        double bal = 0;
        if (get_balance(argv[i], &bal, bc->addr_bal)) {
            printf("Balance for address %s: %lf\n", argv[i], bal);
        } else {
            printf("Address %s: not found\n", argv[i]);
        }      
    }
    
    blockchain_free(bc);
    return 0;
}
