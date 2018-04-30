#include "iq.h"

iq *iq_new()
{
  iq *q = (iq*)malloc(sizeof(iq));
  if (q==NULL) {
    fprintf(stderr,"iq_new: malloc failed\n");
    exit(1);
  }
  q->n = 0;
  q->front = q->back = NULL;
  return q;
}

void enqueue(iq *q, int n)
{ 
    if (!q->back) {
        q->front = q->back = il_singleton(n);
    } else {
        il* bk = il_snoc(q->back, n);
        q->back = bk;
    }
    q->n += 1;
}

int dequeue(iq *q)
{
    int deq = q->front->n;
    il* temp_deq = q->front;
    if (q->n == 1) {
        q->front = q->back = NULL;
    } else {
        il* fr = q->front->next;
        q->front = fr;
        free(temp_deq);
    }
    q->n -= 1;
    return deq;
}

void iq_show(iq *q)
{
  printf("begin queue (%d items, front shown at left))\n",q->n);
  printf("  ");
  il_show(q->front);
  printf("end queue\n");
}

void iq_free(iq *q)
{
  if (q!=NULL) {
    il_free(q->front);
    free(q);
  }
}
