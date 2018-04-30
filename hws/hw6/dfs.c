#include <stdio.h>
#include <stdlib.h>

#include "is.h"
#include "graph.h"

il *dfs(graph *g, unsigned int start_key)
{
    is* s = is_new();
    push(s, start_key);
    g->vs[start_key]->visited = 1;
    il* in_order_list = NULL;

    while (s->ns) {
        int p = pop(s);

        il* neighbor = graph_neighbors(g, p);
        while (neighbor) {
            if (g->vs[neighbor->n]->visited == 0) {
                push(s, neighbor->n);
                g->vs[neighbor->n]->visited = 1;
            }
            neighbor = neighbor->next;
        }
        
        if (!in_order_list) {
            in_order_list = il_singleton(start_key);
        } else {
            il_append(in_order_list, il_singleton(p));
        }
    }
    is_free(s);
    return in_order_list;
}

int main(int argc, char *argv[])
{
  graph *g;
  
  if (argc>1)
    g = sample_graph(atoi(argv[1]));
  else
    g = sample_graph(0);
  
  printf("--- graph ---\n");
  graph_show(g);
  putchar('\n');

  printf("--- depth-first search ---\n");
  il *ns = dfs(g,0);
  graph_show_labels(g,ns);
  putchar('\n');

  il_free(ns);
  graph_free(g);

  return 0;
}
