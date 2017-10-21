//260_list

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

struct elem
{
    int owner_points;
    int opp_points;
    char match[20];
    char name[10];
    char opponent[20];
    char* opponenr[20];

    elem* left;
    elem* right;
    elem* parent;

};

class Tree
{
    elem* root;
public:
    Tree();
    ~Tree();
    void print(elem* node); //Печать от указанного узла
    elem* search(elem* node, char* key); //Поиск от указанного элемента
    elem* min(elem* node); //min от указанного эелемента
    elem* max(elem* node); //max от указанного элемента
    elem* next(elem* node); //след от указанного элемента
    elem* prev(elem* node); //предыдущий от указанного элемента
    void insert(elem* z); //вставка узла
    void del(elem* z = 0); //удаление ветки дерева.0-удаление всего дерева
    elem* get_root();
};

Tree::Tree()
{
    root = NULL;
}

Tree::~Tree()
{
    del();
}

void Tree::print(elem *node)
{
    if(node != 0)
    {
        print(node->left);
        std::cout << node->match
                  << node->match
                  << node->opponent
                  << std::endl;
        print(node->right);
    }
}

elem *Tree::search(elem *node, char *key)
{
    while (node != 0 && strcmp(key, node->name) != 0) {
        if (strcmp(key, node->name) < 0) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

elem *Tree::min(elem *node)
{
    if(node != 0) {
        while (node->left != 0) {
            node = node->left;
        }
    }
    return node;
}

elem *Tree::max(elem *node)
{
    if(node != 0) {
        while (node->right != 0) {
            node = node->right;
        }
    }
    return node;
}

elem *Tree::next(elem *node)
{
    elem* y = 0;

    if(node != 0) {
        if (node->right != 0) {
            return min(node->right);
        }
        y = node->parent;
        while (y != 0 && node == y->right) {
            node = y;
            y = y->parent;
        }
    }
    return y;
}

elem *Tree::prev(elem *node)
{
    elem* y = 0;

    if(node != 0) {
        if(node->left != 0) {
            return max(node->left);
        }

        y = node->parent;

        while (y != 0 && node == y->left) {
            node = y;
            y = y->parent;
        }
    }
    return y;
}

void Tree::insert(elem *z)
{
    z->left = NULL;
    z->right = NULL;

    elem* y = NULL;
    elem* node = root;

    while (node != 0) {
        y = node;
        if (strcmp(z->name, node->name) < 0) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    z->parent = y;

    if (y == 0) {
        root = z;
    } else if (strcmp(z->name, y->name) < 0) {
        y->left = z;
    } else {
      y->right = z;
    }
}

void Tree::del(elem *z)
{
    if (z != 0) {
        elem* node;
        elem* y;

        if (z->left == 0 || z->right == 0) {
            y = z;
        } else {
            y = next(z);
        }

        if (y->left != 0) {
            node = y->left;
        } else {
            node = y->right;
        }

        if (node != 0) {
            node->parent = y->parent;
        }

        if (y->parent == 0) {
            root = node;
        } else if (y == y->parent->left) {
            y->parent->left = node;
        } else {
            y->parent->right = node;
        }

        if (y != z) {
            strcpy(z->name, y->name);
            strcpy(z->opponent, y->opponent);
            strcpy(z->match, y->match);
            z->opp_points= y->opp_points;
            z->owner_points = y->owner_points;
        }

        delete y;
    } else {
        while (root != 0) {
            del(root);
        }
    }
}

elem *Tree::get_root()
{
    return root;
}

Tree tournament;

void Game(char Commands[][20], int N)
{
    int i, j;
    int p1, p2;
    int k;
    elem* temp;

    for (k = 0; k < 2; ++k) {
        for (i = 0; i < N - 1; ++i) {
            for (j = i + 1; j < N - 1; ++j) {
                temp = new elem;

                if (k == 0) {
                    strcpy(temp->name, Commands[i]);
                    strcpy(temp->opponent, Commands[j]);
                } else {
                    strcpy(temp->name, Commands[j]);
                    strcpy(temp->opponent, Commands[i]);
                }

                p1 = rand() % 6;
                p2 = rand() % 6;

                if (p1 > p2) {
                    temp->owner_points = 3;
                    temp->opp_points = 1;
                } else if (p1 == p2) {
                    temp->owner_points = 1;
                    temp->opp_points  = 1;
                } else {
                    temp->owner_points = 0;
                    temp->opp_points = 3;
                }

                sprintf(temp->match, " %d : %d ", p1, p2);
                tournament.insert(temp);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    const int N = 4;

    char commands[4][20] =
    {
        "Arsenal",
        "Liverpool",
        "Lids United",
        "Manchester United"
    };
    Game(commands, N);
    tournament.print(tournament.get_root());
    return 0;
}
