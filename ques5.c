//snake game
#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
//#include <conio.h>
//kbhit();
int getch()
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
struct food
{
    int x, y;
    char val;
};
struct snake
{
    int x, y;
    char val;
    struct snake *ptr;
};
int checkfood(struct food *f,struct snake *s)
{
    struct snake *p=s;
    for(;;p=p->ptr)
    {
        if(p->x==f->x&&p->y==f->y)
        {
            return 1;
        }
        if(p->ptr==NULL)
        break;
    }
    return 0;
}
void createfood(struct food *f,struct snake *s)
{
    //printf("Inside create food\n");
    f->x = rand()%40;
    f->y = rand()%50;
    f->val = 'f';
    if(checkfood(f,s))
    {
        createfood(f,s);
        //printf("overlaping food with snake\n");
    }
}
/*
struct snake* createsnake()
{
    struct snake *s = (struct snake*)malloc(sizeof(struct snake));
    s->x=20;s->y=20;s->val='H';
    //s->ptr=NULL;
    s->ptr = (struct snake*)malloc(sizeof(struct snake));
    s->ptr->x=20;s->ptr->y=21;s->ptr->val='#';
    s->ptr->ptr = (struct snake*)malloc(sizeof(struct snake));
    s->ptr->ptr->x=20;s->ptr->ptr->y=22;
    s->ptr->ptr->val='T';s->ptr->ptr->ptr=NULL;
    return s;    
}
*/
struct snake *createsnake()
{
    struct snake *h = (struct snake *)malloc(sizeof(struct snake));
    h->x = 20;
    h->y = 20;
    h->val = 'H';
    //h->ptr=NULL;
    struct snake *b1 = (struct snake *)malloc(sizeof(struct snake));
    b1->x = 20;
    b1->y = 21;
    b1->val = '#';
    struct snake *b2 = (struct snake *)malloc(sizeof(struct snake));
    b2->x = 20;
    b2->y = 22;
    b2->val = '#';
    struct snake *t = (struct snake *)malloc(sizeof(struct snake));
    t->x = 20;
    t->y = 23;
    t->val = 'T';
    h->ptr = b1;
    b1->ptr = b2;
    b2->ptr = t;
    t->ptr = NULL;
    return h;
}
void displayboard(char **b)
{
    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            printf("%c", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void impfoodonboard(char **b, struct food f)
{
    b[f.x][f.y] = f.val;
}
void impsnakeonboard(char **b, struct snake *s)
{
    b[s->x][s->y] = s->val;
    if (s->ptr != NULL)
    {
        impsnakeonboard(b, s->ptr);
    }
}
void copysnake(struct snake *p)
{
    if (p->ptr == NULL)
    {
        return;
    }
    else
    {
        copysnake(p->ptr);
        p->ptr->x = p->x;
        p->ptr->y = p->y;
    }
}
void movesnake(struct snake *s, char direction, struct food *f)
{
    if (direction == 'a')
    {
        if (s->y - 1 == s->ptr->y)
        {
            return;
        }
        else if (s->y - 1 == f->y && s->x == f->x)
        {
            struct snake *n = (struct snake *)malloc(sizeof(struct snake));
            n->x = s->x;
            n->y = s->y;
            n->ptr = s->ptr;
            n->val = '#';
            s->ptr = n;
            s->y = s->y - 1;
            if (s->y < 0)
                s->y = 49;
            createfood(f,s);
        }
        else
        {
            copysnake(s);
            s->y = s->y - 1;
            if (s->y < 0)
                s->y = 49;
        }
    }
    else if (direction == 'd')
    {
        if (s->y + 1 == s->ptr->y)
        {
            return;
        }
        else if (s->y + 1 == f->y && s->x == f->x)
        {
            struct snake *n = (struct snake *)malloc(sizeof(struct snake));
            n->x = s->x;
            n->y = s->y;
            n->ptr = s->ptr;
            n->val = '#';
            s->ptr = n;
            s->y = s->y + 1;
            if (s->y > 49)
                s->y = 0;
            createfood(f,s);
        }
        else
        {
            copysnake(s);
            s->y = s->y + 1;
            if (s->y > 49)
                s->y = 0;
        }
    }
    else if (direction == 'w')
    {
        if (s->x - 1 == s->ptr->x)
        {
            return;
        }
        else if (s->x - 1 == f->x && s->y == f->y)
        {
            struct snake *n = (struct snake *)malloc(sizeof(struct snake));
            n->x = s->x;
            n->y = s->y;
            n->ptr = s->ptr;
            n->val = '#';
            s->ptr = n;
            s->x = s->x - 1;
            if (s->x < 0)
                s->x = 39;
            createfood(f,s);
        }
        else
        {
            copysnake(s);
            s->x = s->x - 1;
            if (s->x < 0)
                s->x = 39;
        }
    }
    else if (direction == 's')
    {
        if (s->x + 1 == s->ptr->x)
        {
            return;
        }
        else if (s->x + 1 == f->x && s->y == f->y)
        {
            struct snake *n = (struct snake *)malloc(sizeof(struct snake));
            (*n).x = s->x;
            n->y = s->y;
            n->ptr = s->ptr;
            n->val = '#';
            s->ptr = n;
            s->x = s->x + 1;
            if (s->x >= 40)
                s->x = 0;
            createfood(f,s);
        }
        else
        {
            copysnake(s);
            s->x = s->x + 1;
            if (s->x >= 40)
                s->x = 0;
        }
    }
}
int checkoverlap(struct snake *s, struct snake *p)
{
    if (p->x == s->x && p->y == s->y)
        return 1;
    else if (p->ptr == NULL)
        return 0;
    else
    {
        return checkoverlap(s, p->ptr);
    }
}
void increasesnakelength(struct snake *s)
{
    struct snake *h, *n, *b;
    h = s;
}
void clearboard(char **b)
{
    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            b[i][j] = '.';
        }
    }
}
void printsnake(struct snake *s)
{
    for (struct snake *p = s;; p = p->ptr)
    {
        printf("y = %d\n", p->y);
        printf("x = %d\n", p->x);
        printf("val = %c\n", p->val);
        if (p->ptr == NULL)
            break;
    }
}
int main()
{
    //creating board
    char **board;
    board = (char **)malloc(sizeof(char *) * 40);
    for (int i = 0; i < 40; i++)
    {
        board[i] = (char *)malloc(sizeof(char) * 50);
    }
    struct snake *s = createsnake();
    clearboard(board);
    struct food f;
    createfood(&f,s);
    char direction = 'a';
    impfoodonboard(board, f);
    impsnakeonboard(board, s);
    int x=0;
    while (1)
    {
        displayboard(board);
        x = checkoverlap(s, s->ptr);
        if(x==1)
        {
            printf("GAME OVER\n\n");
            break;
        }
        printf("Enter value\n");
        direction=getch();
        movesnake(s, direction, &f);
        clearboard(board);
        impfoodonboard(board, f);
        impsnakeonboard(board, s);
    }
    free(board);
    free(s);
    //free(&f);
    return 0;
}