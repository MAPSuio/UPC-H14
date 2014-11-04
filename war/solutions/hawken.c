/*
# @EXPECTED_RESULTS@: CORRECT
 */

#include <stdio.h>
#include <stdlib.h>

/* Queue stuff: insersions in back, removing in front */
typedef struct qe_t qe;
struct qe_t {
    int card;
    qe *next;
};
typedef struct queue_t {
    qe *start;
    qe *end;
} queue;
void q_i(queue *q){
    q->start = NULL;
    q->end = NULL;
}
qe *q_gen(int card) {
    qe *q = malloc(sizeof(qe));
    q->next = NULL;
    q->card = card;
    return q;
}
void q_in(queue *q, qe *elem) {
    if(q->end == NULL) {
        q->start = q->end = elem;
        elem->next = NULL;
    } else {
        q->end->next = elem;
        q->end = elem;
        elem->next = NULL;
    }
}
qe *q_rem(queue *q) {
    /* Remove from top */
    qe *elem;
    if(!q->start) return NULL;
    elem = q->start;
    q->start = elem->next;
    if(!q->start) q->end = NULL;
    return elem;
}

typedef struct testcase_t {
    int p1;
    int p2;
    int *p1a;
    int *p2a;
} testcase;

int test(testcase *t) {
    queue p1stack, p2stack, p1bet, p2bet;
    qe *p1card = NULL, *p2card = NULL, *tmp;
    int i, j;
    unsigned long long iterations = 0;

    q_i(&p1stack);
    q_i(&p2stack);
    q_i(&p1bet);
    q_i(&p2bet);

    for(i=0;i<t->p1;i++) {
        q_in(&p1stack, q_gen(t->p1a[i]));
    }
    for(i=0;i<t->p2;i++) {
        q_in(&p2stack, q_gen(t->p2a[i]));
    }

    while(p1stack.start && p2stack.start) {
        p1card = q_rem(&p1stack);
        p2card = q_rem(&p2stack);
        if(p1card->card == p2card->card) {
            q_in(&p1bet, p1card);
            q_in(&p2bet, p2card);
            for(i=0;i<3;i++) {
                if((p1card = q_rem(&p1stack)))
                    q_in(&p1bet, p1card);
                if((p2card = q_rem(&p2stack)))
                    q_in(&p2bet, p2card);
            }
        } else if(p1card->card > p2card->card) {
            while((tmp = q_rem(&p1bet)))
                q_in(&p1stack, tmp);
            q_in(&p1stack, p1card);

            while((tmp = q_rem(&p2bet)))
                q_in(&p1stack, tmp);
            q_in(&p1stack, p2card);
        } else /* if(p2card->card > p1card->card) */ {
            while((tmp = q_rem(&p2bet)))
                q_in(&p2stack, tmp);
            q_in(&p2stack, p2card);

            while((tmp = q_rem(&p1bet)))
                q_in(&p2stack, tmp);
            q_in(&p2stack, p1card);
        }
	iterations++;
    }
    i = p1stack.start != NULL ? 1 : 0;
    j = p2stack.start != NULL ? 1 : 0;
    while((tmp = q_rem(&p2bet)))   free(tmp);
    while((tmp = q_rem(&p1bet)))   free(tmp);
    while((tmp = q_rem(&p2stack))) free(tmp);
    while((tmp = q_rem(&p1stack))) free(tmp);

    fprintf(stderr, "DEBUG: iterations: %llu\n", iterations);

    if(i == 0 && j == 0) {
        return  0; // draw
    } else if(i == 0) {
        return -1; // player2
    } else /* if(j == 0) */ {
        return 1; // player1
    }
}

int main(){
    testcase t;
    int i;

    scanf("%d", &t.p1);
    scanf("%d", &t.p2);
    t.p1a = malloc(sizeof(int)*t.p1);
    t.p2a = malloc(sizeof(int)*t.p1);

    for(i=0;i<t.p1;i++) {
        scanf("%d", t.p1a+i);
    }
    for(i=0;i<t.p2;i++) {
        scanf("%d", t.p2a+i);
    }
    i = test(&t);
    switch(i) {
        case  0: printf("draw\n");    break;
        case  1: printf("PLAYER1\n"); break;
        case -1: printf("PLAYER2\n"); break;
    }

    free(t.p1a);
    free(t.p2a);
    return 0;
}
