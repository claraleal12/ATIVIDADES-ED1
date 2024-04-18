typedef struct lista Lista;

Lista *list_cria(void);

Lista *list_insere(Lista *list_orig, int valor);

int maiores(Lista list_orig, int valor);

Lista *ultimo(Lista * list_orig);