#include <stdio.h>
#include <stdlib.h>

#include "iq.h"
#include "graph.h"

il *bfs(graph *g, unsigned int start_key)
{
    iq* q = iq_new();
    enqueue(q, start_key);
    g->vs[start_key]->visited = 1;
    il* in_order_list = il_singleton(start_key);

    while (q->n != 0) {
        int deq = dequeue(q);
        il* neighbor = graph_neighbors(g, deq);

        while (neighbor) {
            if (g->vs[neighbor->n]->visited == 0) {
                enqueue(q, neighbor->n);
                g->vs[neighbor->n]->visited = 1;
                il_append(in_order_list, il_singleton(neighbor->n));
            }
            neighbor = neighbor->next;
        }
    }
    iq_free(q);
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

  printf("--- breadth-first search ---\n");
  il *ns = bfs(g,0);
  graph_show_labels(g,ns);
  putchar('\n');

  il_free(ns);
  graph_free(g);

  return 0;
}
