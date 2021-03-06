#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 210

struct node{
  int numf;
  struct node *f[10];
};

node _nos[MAX];
node *ll[MAX];
int topo;

int n, z;
char codifica[MAX];

node *tree;
int tam;

int marcas[MAX];


node *novo()
{
  node *nv = ll[topo--];
  for(int i = 0; i < n; i++)
    nv->f[i] = NULL;
  nv->numf = 0;
  return nv;
}

void devolve(node *no)
{
  ll[++topo] = no;
}

void inicializa()
{
  for(int i = 0; i < MAX; i++)
    ll[i] = _nos+i;
  topo = MAX-1;
  tree = novo();
  tam = strlen(codifica);
  marcas[z-1] = tam-1;
}


bool vai(int ini, int falta, int abertos)
{
  if(abertos == 0 || falta == 0 || ini == tam)
    return false;
  if(falta == 1 && abertos > 1)
    return false;

  node *arv = tree;
  
  int i = ini;
  while(1){
    char c = codifica[i];
    if(c == '\0')
      return false;
    if(arv->numf == 0 && arv != tree)
      return false;
    if(arv->f[c-'0'] == NULL)
      break;
    arv = arv->f[c-'0'];
    i++;
  }

  if(falta == 1){
    if(i + 1 < tam)
      return false;

    for(int k = 0; k < z; k++){
      printf("%d->", k);
      int j = (k == 0 ? 0 : marcas[k-1]+1);
      while(j <= marcas[k]){
	putchar(codifica[j]);
	j++;
      }
      putchar('\n');
    }
    return true;
  }

  int j = i;
  node *atual = arv, *nv;
  abertos--;
  while(j < tam){
    int k = codifica[j] - '0';
      
    nv = novo();
    atual->f[k] = nv;
    atual->numf++;
    marcas[z-falta] = j;


    if(abertos > falta - 1)
      break;
    if(vai(j+1, falta-1, abertos))
      return true;

    abertos += n-1;
    atual = nv;
    j++;
  }

  atual = arv->f[codifica[i]-'0'];
  arv->f[codifica[i]-'0'] = NULL;
  arv->numf--;
  i++;
  while(1){
    if(atual == NULL)
      break;
    devolve(atual);
    atual = atual->f[codifica[i]-'0'];
    i++;
  }

  return false;

}


void resolve()
{
  inicializa();
  vai(0, z, n);
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  while(casos--){
    scanf(" %d %d %s", &z,&n, codifica);
    resolve();
  }
  return 0;
}
