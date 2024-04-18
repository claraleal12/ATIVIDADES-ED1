# LISTA ENCADEADA SIMPLES

Sua estrutura consiste em uma sequencia encadeada de elementos em geral chamados de nós da lista.
Um nó da lista é representado por uma estrutura que contém, conceitualmente, dois campos: a informação e 
o ponteiro para o proximo elemento da lista.
a lista é representada por um ponteiro para o primeiro elemento(ou nó). Do primeiro elemento, podemos 
alcançar o segundo, seguindo o encadeamento, e assim por diante.
O último elementoda lista armazena, como proximo elemento, um ponteiro inválido, com valor NULL,
e sinaliza, assim, que não existe um proximo elemento.

```
typedef struct lista{
    int info;
    Lista *prox;
}Lista;

Lista *vet; 
```

-> Devemos notar que se trata de uma estrutura auto-referenciada, pois, alem do campo para armazenar a informação, 
há um campo que é um ponteiro para uma proxima estrutura do mesmo tipo. O tipo lista representa um nó da lista,
e a estrutura de lista encadeada é representada pelo ponteiro para o seu primeiro elemento(tipo Lista*).

-> FUNÇÃO DE CRIAÇÃO

A função que cria uma lista vazia deve ter como valor de retorno uma lista sem nenhum elemento. Como a lista é representada
pelo ponteiro para o primeiro  elemento, uma lista vazia é representada pelo ponteiro NULL, pois não existem 
elementos na lista. A função tem como valor de retorno a lista vazia inicializada, isto é, o valor de retorno é NULL.
Uma possível implementação da função de criação é mostrada a seguir: 

```
 Lista* list_cria(void){
    return NULL;
} 
```

-> FUNÇÃO DE INSERÇÃO

Uma vez criada a lista vazia, podemos inserir nela movos elementos. Para cada elemento inserido, devemos alocar dinamicamente a memória necessária para armazenar o elemento e encadeá-lo na lista existente. A função de inserção mais simples insere o novo elemento no início da lista.
Uma possivel implementação é mostrada a seguir. Devemos notar que o ponteiro que representa a lista deve ter seu valor atualizado, pois a lista deve passar a ser representada pelo ponteiro para o novo primeiro elemento. Por essa razão, a função de inserção recebe como parâmetros de entrada a lista na qual será inserido o novo elemento e a informação do novo elemento e tem como valor de retorno a nova lista, representada pelo ponteiro novo elemento.

```
Lista* list_insere (Lista** l, int i){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = *l;
    return novo;
}
```
Essa função aloca dinamicamente o espaço para armazenar o novo nó da lista, guarda a informação no novo nó e faz ele apontar para o elemento que era o primeiro da lista. A função então tem como valor de retorno a nova lista, representada pelo ponteiro para o novo primeiro elemento.
Dentro da função insere será atualizado o valor da variavel que representa a lista da função da lista principal, por meio dos parametros das funções do tipo ponteiro de ponterio para a lista (Lista** l), e seu conteudo poderia ser acessaddo/atualizado de dedntro da função por meio do operador conteudo(*l). 

-> FUNÇÃO QUE PERCORRE OS ELEMENTOS DA LISTA

Para ilustrar a implementação de uma função que percorre todos os elementos da lista, vamos considerar a criação de uma função que imprime os valores dos elementos armazenados eem uma lista. Uma possível implementação dessa função é mostrada a seguir.

```
void list_imprime(Lista* l){
    Lista* p; /* variável auxiliar para percorrer a lista*/
    for(p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}
```

Recordamos que, para percorrer os elemntos de um vetor, usamos uma variável auxiliar inteira a fim de armazenar os índices dos elementos. No caso da lista encadeada, a variável auxiliar tem de ser um ponteiro, usada para armazenar o endereço de cada elemento. Dentro do laço da função imprime, a variavel aponta para cada um dos elementos da lista, do primeiro ate o ultimo.

-> FUNÇÃO QUE VERIFICA SE A LISTA ESTÁ VAZIA

Pode ser util implementar uma função para verificar se uma lista esta ou não vazia. A função recebe a lista e retorna l se estiver vazia ou 0 se nao estiver vazia. Como sabemos, uma lista está vazia se seu valor é NULL. Uma implementação da função é mostrada a seguir.

```
int list_vazia(Lista* l){
    if (l == NULL)
        return 1;
    else 
        return 0;
}
```

-> FUNÇÃO DE BUSCA

Uma outra função util consiste em verificar se um determinado elemento esta presente na lista. A função recebe a informação referente ao elemento que queremos buscar e fornece como valor de retornoo ponteiro do nó da lista que representa o elemento. Caso o elemento nao seja encontrado na lista, o valor retornado é NULL.

```
Lista* list_busca (Lista* l, int v){
    Lista* p;
    for (p = l; p != NULL; p = p->prox){
        if (p->info == v)
        return p;
    }
    return NULL;
}
```

-> FUNÇÃO QUE RETIRA UM ELEMENTO DA LISTA

Devemos agora considera a implementação de uma função que permita retirar um elemento da lista. A função tem como parametros de entrada a lista e o valor do elemento que desejamos retirar, e deve atualizar o elemento da lista,pois, se o elemento removido for o primeiro da lista, o valor da lista sera atualizado. 
 A função para retirar um elemento da lisra é mais complexa. Se descobrirmos que o elememento a ser retirado é o primeiro da lista, devemos fazer o novo valor da lista passar a ser o ponteiro para o segundo elemento, e entao podemos liberar o espaço alocado para o elemento para o elemento que queremos retirar. Se o elemento a ser removido estiver no meio da lista, devemos fazer com que o elemento anterior a ele passar a apontar para o seguinte, e entao podemos liberar aquele que queremos retirar.

```
Lista* list_retira(Lista*, int v){
    Lista*  ant = NULL; /* ponteiro para o elemento anterior*/
    Lista* p = l; /* ponteiro para percorrer a lista*/

    while(p != NULL && p->nfo != v){ /*procura elemento na lista, guardando o anterior */
        ant = p
        p = p->prox;
    }
    if(p == NULL){ /* verifica se achoou o elemento*/
        return l; /* nao achou o elemento*/
    }

    if ( ant == NULL){ /* retira o elemento*/
        l = p->prox; /* retira elemento do meio da lista*/
    }

    else{ /*retira elemento do meio da lista*/
        ant->prox= p->prox;
    }

    free(p);
    return l;
}
```

-> FUNÇÃO PARA LIBERAR A LISTA

Para completar o conjunto de funções básicas que manipulam uma lista, devemos considerar a função que destroi a lista, com a liberação de todos os elementos alocados. Uma implementação dessa função é mostrada a seguir. A função percorre elemento por elemento, liberando-os. É importante observar que devemos guardar guardar a referencia para o proximo elemento antes de liberar o atual.

```
void list_libera(Lista *l){
    Lista* p = l;
    while(p != NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}
```