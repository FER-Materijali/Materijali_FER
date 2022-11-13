#include <stdio.h>
#include <stdlib.h>

// Moguće boje čvorova.
#define BLACK 0
#define RED   1

typedef struct node node;

struct node {
  int   *value;
  node  *parent;
  node  *left;
  node  *right;
  short  color;
};

// Stvori čvor koji predstavlja list stabla: crne je boje i ne sadrži
// ikakav podatak.
node *leaf(node *parent) {
  node *n   = malloc(sizeof(node));
  n->value  = NULL;
  n->color  = BLACK;
  n->parent = parent;
  n->left   = NULL;
  n->right  = NULL;
  return n;
}

// Stvori novi čvor koji sadrži neku vrijednost: podrazumijeva se da
// je u početku crvene boje i nema roditelja.
node *new(int value) {
  node *n   = malloc(sizeof(node));
  n->value  = malloc(sizeof(int));
  *(n->value) = value;
  n->color  = RED;
  n->parent = NULL;
  n->left   = leaf(n);
  n->right  = leaf(n);
  return n;
}

// Dohvati roditelja roditelja čvora.
node *grandparent(node *n) {
  if (n == NULL || n->parent == NULL) {
    return NULL;
  } else {
    return n->parent->parent;
  }
}

// Dohvati korijen stabla tako da rekurzivno pratiš poveznice
// do roditelja sve dok ne naiđeš na korijenski čvor.
node *top(node *n) {
  if (n->parent == NULL) {
    return n;
  } else {
    return top(n->parent);
  }
}

// Nađi čvor koji je brat roditeljskog čvora.
node *uncle(node *n) {
  node *g = grandparent(n);

  if (g == NULL) {
    return NULL;
  }

  if (n->parent == g->left) {
    return g->right;
  } else {
    return g->left;
  }
}

// Dodaj čvor u stablo na isti način kao što bi to činio da se radi o
// običnom binarnom sortiranom neuravnoteženom stablu. Nakon ove
// procedure pozivamo dodatne koje će uravnotežiti stablo.
node *unsafe(node *n, int value) {
  node *t;

  if ((n == NULL) || (n->value == NULL)) {
    n->value = malloc(sizeof(int));
    *(n->value) = value;
    n->left = leaf(n);
    n->right = leaf(n);
    printf("Unsafely placed as root.\n");
    return n;

  } else if (value < *(n->value)) {
    t = n->left;

    if (t->value == NULL) {
      t->value = malloc(sizeof(int));
      *(t->value) = value;
      t->left = leaf(t);
      t->right = leaf(t);
      t->color = RED;
      printf("Unsafely placed left under %d.\n", *(n->value));
      return t;
    } else {
      return unsafe(t, value);
    }

  } else {
    t = n->right;

    if (t->value == NULL) {
      t->value = malloc(sizeof(int));
      *(t->value) = value;
      t->left = leaf(t);
      t->right = leaf(t);
      t->color = RED;
      printf("Unsafely placed right under %d.\n", *(n->value));
      return t;
    } else {
      return unsafe(t, value);
    }
  }
}

void left_rotate(node *root) {
  node *toplv = root->parent;
  node *pivot = root->right;
  node *child = pivot->left;

  // Top-level now points to the pivot.
  if (toplv == NULL) {
    ; // Nothing.
  } else if (toplv->right == root) {
    toplv->right = pivot;
  } else {
    toplv->left = pivot;
  }
  pivot->parent = toplv;

  // Pivot now points to the root.
  pivot->left = root;
  root->parent = pivot;

  // Root now points to child.
  root->right = child;
  child->parent = root;

  // Pivot now *becomes* root.
  root = pivot;
}

void right_rotate(node *root) {
  node *toplv = root->parent;
  node *pivot = root->left;
  node *child = pivot->right;

  // Top-level now points to the pivot.
  if (toplv == NULL) {
    ; // Nothing.
  } else if (toplv->right == root) {
    toplv->right = pivot;
  } else {
    toplv->left = pivot;
  }
  pivot->parent = toplv;

  // Pivot now points to the root.
  pivot->right = root;
  root->parent = pivot;

  // Root now points to child.
  root->left = child;
  child->parent = root;

  // Pivot now *becomes* root.
  root = pivot;
}

// Nakon što smo ubacili vrijednost u stablo na odgovarajuće mjesto,
// sada uravnotežujemo stablo.
void correct(node *n) {
  printf("Correcting node %d.\n", *(n->value));
  node *p = n->parent;
  node *u = uncle(n);
  node *g = grandparent(n);

  // Is the current node also the root? Paint it black.
  if (p == NULL) {
    printf("This node is root, color it black.\n");
    n->color = BLACK;
  }

  // If the parent is black, all is well.
  else if (p->color == BLACK) {
    printf("Parent is black, return.\n");
    return;
  }

  // From now on, we can assume a grandparent exists because no black
  // parent exists and because this node isn't the root. So, also, an
  // uncle exists, thought it might be a leaf (NULL).

  // If both parent and uncle are red, they are repainted black and
  // the grandparent becomes red. Repeat recursively on grandparent.
  else if ((u != NULL) && (u->color == RED)) {
    printf("Parent and uncle are red, repainting recursively.\n");
    p->color = BLACK;
    u->color = BLACK;
    g->color = RED;
    correct(g);
  }

  else {
    // The parent is red but the uncle black. Node is right child, and
    // parent is left child. A left rotation switching the node with the
    // parent is performed; vice-versa for reversed sides.
    if (n == p->right && g->left != NULL && p == g->left) {
      printf("Parent is red but uncle black. ");
      printf("I'm right and parent left. Left rotate.\n");
      left_rotate(p);
      n = n->left;
      printf("Node is now %d.\n", *(n->value));

    } else if ((n == p->left) && (p == g->right)) {
      printf("Parent is red but uncle black. ");
      printf("I'm left and parent right. Right rotate.\n");
      right_rotate(p);
      n = n->right;
      printf("Node is now %d.\n", *(n->value));
    }

    p = n->parent;
    g = grandparent(n);
    p->color = BLACK;
    g->color = RED;
    printf("Set parent to black and grandparent to red.\n");

    if ((n == p->left) && (p == g->left)) {
      printf("Me and parent are left. Right rotate.\n");
      right_rotate(g);
    } else if ((n == p->right) && (p == g->right)) {
      printf("Me and parent are right. Left rotate.\n");
      left_rotate(g);
    }
  }
}

// Vrijednosti ubacujemo na valjan način tako da ih prvo ubacimo
// na običan način, a zatim uravnotežimo stablo.
void insert(node *n, int value) {
  correct(unsafe(top(n), value));
}

// Vrati određen broj razmaka, služi kao tab za prikaz stabla.
char *spaces(int count) {
  char *buf = malloc((count+1)*sizeof(char));
  buf[count] = '\0';
  while (count > 0) {
    *(buf+count-1) = ' ';
    *(buf+count-2) = ':';
    count -= 2;
  }
  return buf;
}

// Rekurzivno iscrtaj stablo, podrazumijevajući da je *n
// pokazivač na korijenski čvor.
void shownode(node *n, int tab) {
  printf("%s", spaces(tab));
  if (n == NULL) {
    ; // Do nothing, these are the leaves' leaves.
  } else if (n->value == NULL) {
    printf("b\n"); // The leaves.
  } else {
    printf("%d%c\n", *(n->value), n->color == RED ? 'r' : 'b');
    shownode(n->left, tab+2);
    shownode(n->right, tab+2);
  }
}

void shownodeln(node *n) {
  shownode(n, 0);
}

// Učitaj stablo iz datoteke brojeva. Vrati korijenski čvor.
node *from_file(const char *path) {
  FILE *f = fopen(path, "r");
  node *n = leaf(NULL);
  int current;

  if (f == NULL) {
    printf("No such file: %s.", path);
    exit(1);
  }

  while (fscanf(f, "%d", &current) != EOF && fgetc(f) != EOF) {
    printf("Inserting %d.\n", current);
    insert(n, current);
  }

  return n;
}

// Učitaj stablo iz datoteke ako je dobivena putem argumenata programu.
// Nakon toga dozvoli unos novih vrijednosti u stablo.
int main(int argc, char **argv) {
  node *root = NULL;
  int   pick;

  switch (argc) {
  case 1:
    printf("No file given, tree is empty.\n");
    root = leaf(NULL);
    break;
  default:
    printf("Loading tree from file: %s\n", argv[1]);
    root = from_file(argv[1]);
  }

  while (1) {
    shownodeln(top(root));
    printf("> ");

    if (scanf("%d", &pick) == -1) {
      printf("Quit!\n");
      break;
    } else {
      insert(root, pick);
    }
  }

  return 0;
}



