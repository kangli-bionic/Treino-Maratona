#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 5010

int G[MAX][MAX];
int num[MAX];
int Ginv[MAX][MAX];
int numinv[MAX];
int n;

int numcomp;
int comp[MAX];

int tempo;
int final[MAX];
bool vis[MAX];

void dfs1(int i)
{
  if(vis[i]) return;
  vis[i] = true;
  for(int k = 0; k < num[i]; k++)
    dfs1(G[i][k]);
  final[tempo++] = i;
}

void dfs2(int i, int cp)
{
  if(comp[i] != -1)
    return;
  comp[i] = cp;

  for(int k = 0; k < numinv[i]; k++)
    dfs2(Ginv[i][k], cp);
}

void encontra_componentes()
{
  for(int i = 0; i < n; i++){
    vis[i] = false;
    comp[i] = -1;
  }
  tempo = 0;
  for(int i = 0; i < n; i++)
    dfs1(i);

  numcomp = 0;
  for(int i = n-1; i >= 0; i--){
    int j = final[i];
    if(comp[j] == -1)
      dfs2(j, numcomp++);
  }
}

bool ehfolha[MAX];

void imprime_folhas()
{
  for(int i = 0; i < numcomp; i++)
    ehfolha[i] = true;

  for(int i = 0; i < n; i++){
    if(!ehfolha[comp[i]]) continue;
    for(int k = 0; k < num[i]; k++){
      int j = G[i][k];
      if(comp[i] != comp[j]){
	ehfolha[comp[i]] = false;
	break;
      }
    }
  }

  bool prim = true;
  for(int i = 0; i < n; i++){
    if(ehfolha[comp[i]]){
      if(!prim)
	putchar(' ');
      printf("%d", i+1);
      prim = false;
    }
  }
  putchar('\n');
}


int main()
{
  while(1){
    scanf(" %d", &n);
    if(n == 0) break;
    for(int i = 0; i < n; i++)
      num[i] = numinv[i] = 0;
    int m;
    scanf(" %d", &m);
    while(m--){
      int i, j;
      scanf(" %d %d", &i, &j);
      i--; j--;
      G[i][num[i]++] = j;
      Ginv[j][numinv[j]++] = i;
    }

    encontra_componentes();
    imprime_folhas();
  }
  return 0;
}



