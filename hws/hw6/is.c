#include "is.h"

is *is_new() 
{
  is *s = (is*)malloc(sizeof(is));
  if (s==NULL) {
    fprintf(stderr,"is_new: malloc failed\n");
    exit(1);
  }
  s->ns = NULL;
  return s;
}

void push(is *s, int n)
{
    if (!s->ns) {
        s->ns = il_singleton(n);
    } else {
        il* fr = il_cons(n, s->ns);
        s->ns = fr;
    }
}

int pop(is *s)
{
    int p = s->ns->n;
    il* temp_top = s->ns;
    il* new_top = s->ns->next;
    s->ns = new_top;
    free(temp_top);
    return p;
}

void is_show(is *s)
{  
  printf("begin stack (%d items, top shown at left)\n",il_len(s->ns));
  printf("  ");
  il_show(s->ns);
  printf("end stack\n");
}

void is_free(is*s)
{
  if (s!=NULL) {
    il_free(s->ns);
    free(s);
  }
}
