#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/timeb.h>
//flag for printing three similar words
int f=1;
char postfix[1000][1000],stack_temp[1000][1000];
int top=0,top_t=0;
struct inp2 * solve(struct inp2 * tmep1,struct inp2 * temp2,char op[]);
char * pop(char stack[],int * top);
void push (char stack[],char entry[],int *top);
struct inp2 * bk(char op[80]);
//determine if a character is a symbol or not
int isop(char sign)
{
	if( sign == '^' ||
        sign == '&' ||
        sign == '|' ||
        sign == '!' )
        return 1;
    else if (sign == ')')
		return 3;
	else if (sign == '(')
        return 2;
    else
        return 0;
}
//defining some structs for further need
struct inlist
{
    char word[100];
    struct inp2 * filename;
    struct inlist * next;
};
struct list
{
    struct list * left;
    struct list * right;
    struct inlist * next;
};
struct inp2
{
    int re;
    char filename[300];
    struct inp2* next;
};
struct p
{
    char word[300];
    char filename[300];
    struct p *next;
};
struct p2
{
    char word[300];
    struct p2* left;
    struct p2* right;
    struct inp2 * filename;
};
    struct p *first;
    struct p *last;
    struct p2 *firstp2;
    struct p2* lastp2;
    struct list* firstl;
    struct list* lastl;

void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void color (int x)
{
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),x) ;
}
//drawing the colorful background
void draw()
{
	int x,i,j=0,y=5,T=20;
	color(8);
	//white background
	for (j=0;j<10;j++)
	{
		gotoxy(10,y);
		for (i=0;i<100;i++)
			printf("%c",219);
		y++;
	}
	//the color in the middlestrcpy(temp->word=word);
	y=7;
	color(15);
	for (j=0;j<5;j++)
	{
		gotoxy(20,y);
		for (i=0;i<80;i++)
			printf("%c",219);
		y++;
	}
	//writing the word in the middle
	x=43; y=7;
	{ Sleep(1);
		color(4);
		gotoxy(x,y);
		printf("%c%c%c%c",219,219,219,219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		y++;
		gotoxy(x,y);
		printf("%c%c%c%c",219,219,219,219);
		Sleep(T);
		y++; x+=3;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++; x-=3;
		gotoxy(x,y);
		printf("%c%c%c%c",219,219,219,219);
		Sleep(T);
	}
	{
		x+=5; y-=4;
		gotoxy(x,y);
		printf("%c%c%c%c",219,219,219,219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c%c%c%c",219,219,219,219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c%c%c%c",219,219,219,219);
		Sleep(T);
	}
	{
		x+=5; y-=4;
		gotoxy(x,y);
		printf("%c%c%c%c",219,219,219,219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c%c%c%c",219,219,219,219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y-=4; x+=4;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
	}
	{
	x+=2; y-=4;
		gotoxy(x,y);
		printf("%c%c%c%c%c",219,219,219,219,219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		x+=4;
		gotoxy(x,y);
		printf("%c",219);
		y++; x-=4;
		gotoxy(x,y);
		printf("%c%c%c%c%c",219,219,219,219,219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c%c",219,219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		x+=2;
		gotoxy(x,y);
		printf("%c%c",219,219);
	}
	{
    x+=4; y-=4;
        gotoxy(x,y);
        printf("%c%c%c%c%c",219,219,219,219,219);
        Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c%c%c%c%c",219,219,219,219,219);
		Sleep(T);
	}
	{
    x+=6; y-=4;
        gotoxy(x,y);
        printf("%c",219);
        Sleep(T);
		x+=4;
        gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
        printf("%c",219);
        Sleep(T);
		x-=4;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c%c%c%c%c",219,219,219,219,219);
		Sleep(T);
		y++; x+=4;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y++;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		x-=4;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
		y--;
		gotoxy(x,y);
		printf("%c",219);
		Sleep(T);
	}
	color(3);
	y+=3;
	x-=27;
	gotoxy(x,y);

}
// determine if a word is off limits or not
// if its off limits , 1 is returned , else 0 is returned
int skip(char word[],char path[])
{
    //checking to see if its a symbol
 if((word[0]>=33 && word[0]<=47) ||
    (word[0]>=58 && word[0]<=64) ||
    (word[0]>=91 && word[0]<=96) ||
    (word[0]>=123 && word[0]<=126))
        return 0;
    char temp[100];
    //checking the word with skip words
    FILE *fp=fopen(path,"r");
    while(!feof(fp))
    {
        fscanf (fp,"%s",temp);
        if (strcmp(word,temp)==0)
            return 0;
    }
    return 1;
}
// adding a node to the link lists of phase one
struct p * fillnode(struct p * last,char word[])
{
    struct p * temp;
    firstp2->left=NULL;
    firstp2->right=NULL;
    temp=(struct p *)malloc(sizeof(struct p));
    strcpy(temp->word,word);
    temp->next=last->next;
    last->next=temp;
    return temp;
}
//determine if a path is a directory or not
int isDirectory(const char *path)
{
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}
//reading all words in a file and adding them to a link list
void readtxt(char path[],char skippath[])
{
    char word[300];
    FILE *fp=fopen(path,"r");
    if (first->next==NULL)
    {
        fscanf(fp,"%s",word);
        if (skip(word,skippath))
        {
            strcpy(first->word,word);
            strcpy(first->filename,path);
            first->next=first;
        }
    }
    while (!feof(fp)&&first->next!=NULL)
    {
        fscanf(fp,"%s",word);
        if (skip(word,skippath))
        {
            last=fillnode(last,word);
            strcpy(last->filename,path);
            last->next=NULL;
        }
    }
}
//read all statements of a file
int readfile(char path[],char skippath[])
{
    int i,j;
    struct dirent *dir;
    DIR *dr;
    //if the path , points to a directory , we open it
    if (isDirectory(path))
    {
        dr = opendir(path);
        // if something goes wrong with opening the path , NULL is returned
        if (dr == NULL)
        {
            printf("error!\n");
            return 0;
        }
        //constructing a struct dir
        while (dir=readdir(dr))
        {
            if (isDirectory(path))
            {
                if (strcmp(".", dir->d_name) == 0 ||
                    strcmp("..", dir->d_name) == 0)
                    continue;
                else
                {
                    //editing the path
                    path=strcat(path,"\\");
                    path=strcat(path,dir->d_name);
                    readfile(path,skippath);
                    for (i=strlen(path);i>0;i--)
                        if (path[i]=='\\')
                        {
                            j=i;
                            i=strlen(path);
                            while (j<i)
                            {
                                path[j]=NULL;
                                j++;
                            }
                            break;
                        }
                }
            }
            //if the path points to a file , we'll read it
            else
            {
                readtxt(path,skippath);
                return 0;
            }
        }
    }
    //if (again) the path points to a file , we'll read it
    else
    {
        readtxt(path,skippath);
        return 0;
    }
}
// creating a node for phase two's link list
struct p2 * fillnodep2(struct inp2* temp2,char word[],char filename[])
{
    struct p2* t;
    t=(struct p2*) malloc(sizeof(struct p2));
    temp2=t;
    strcpy(t->word,word);
    t->left=NULL;
    t->right=NULL;
    struct inp2* tf;
    tf=(struct inp2*) malloc(sizeof(struct inp2));
    t->filename=tf;
    strcpy(tf->filename,filename);
    tf->next=NULL;
    return t;
};
//creating a link list inside the link list of phase two
struct inp2 * fillnodeinp2(struct p2* tempp2,char filename[])
{
    struct inp2* t=tempp2->filename;
    while ((t->next)!=NULL)
    t=t->next;
    if (strcmp(t->filename,filename)==0)
    {
        (t->re)++;
        return t;
    }
    struct inp2* tf;
    tf=(struct inp2*) malloc (sizeof(struct inp2));
    t->next=tf;
    strcpy(tf->filename,filename);
    tf->next=NULL;
    return tf;
};
//creating the binary search tree for all words
void bst()
{
    struct p* temp=first;
    struct p2* temp2=firstp2;
    firstp2->filename=(struct inp2*) malloc (sizeof(struct inp2));
    {
        strcpy(firstp2->word,temp->word);
        strcpy(firstp2->filename->filename,temp->filename);
        firstp2->filename->next=NULL;
        firstp2->left=NULL;
        firstp2->right=NULL;
    }
    temp2=firstp2;
    lastp2=firstp2;
    temp=temp->next;
    while (temp!=NULL)
    {
        if (strcmpi(temp->word,temp2->word)<0)
        {
            if ((temp2->left)==NULL)
            {
                temp2->left=fillnodep2(temp2->left,temp->word,temp->filename);
            }
            else if ((temp2->left)!=NULL)
            {
                temp2=temp2->left;
                continue;
            }
        }
        else if (strcmpi(temp->word,temp2->word)>0)
        {
            if ((temp2->right)==NULL)
            {
                temp2->right=fillnodep2(temp2->right,temp->word,temp->filename);
            }
            else if ((temp2->right)!=NULL)
            {
                temp2=temp2->right;
                continue;
            }
        }
        //ignoring "capital and little" letters
        else if (strcmpi(temp->word,temp2->word)==0 &&
                strcmpi(temp->filename,temp2->filename->filename)!=0 &&
                strcmpi(temp->filename,firstp2->filename)!=0 )
        {
            fillnodeinp2(temp2,temp->filename);
        }
    temp=temp->next;
    temp2=firstp2;
    }

}
void order(struct p2* root)
{
    if (root->left!=NULL)
        {
        order(root->left);
        printf("%s : %s\n",root->word,root->filename);
        order(root->left);
        }
}
//a custom function to show words and their addresses (optional)
void inorder(struct p2* first)
{
    struct inp2 * cur=first->filename;
    printf("%s : %s",first->word,cur->filename);
    while(cur!=NULL)
    {
        printf("\nrepeat\n : %s ",cur->filename);
        cur=cur->next;
    }
    printf("\n\n");
    if(first->left!=NULL)
    {
        printf("left of %s =",first->word);
        inorder(first->left);
    }

    if(first->right!=NULL)
    {
        printf("right %s =",first->word);
        inorder(first->right);
    }
}
//determine if the entry is one word or not (1 is returned if it is)
int isone (char entry[])
{
    int i;
    for(i=0;i<strlen(entry);i++)
        if (entry[i]==' ')
            return 0;
    return 1;
}
//printing suggested word if the searched word didn't exist.
char * sim(struct p2* root,char word[], int j)
{
    if (root!= NULL&&f<4)
    {
        sim (root->left,word,j);
        if (guess(root->word,word)==j&&f<4)
        {
            printf("%d) : %s\n",f,root->word);
            f++;
        }
        sim (root->right,word,j);
    }
}
//determining how many "parts" the entry string ,consists of
tokeniz(char entry[])
{
    int i=strlen(entry),j=0,token=0;
    char temp;
    while(i>=0)
            {
                temp=entry[j];
                if (temp==' ')
                {
                    token++;
                }
                j++;
                i--;
            }
            token++;
    return token;
}
// searching through binary search tree for entry
//this is the base of the search
search(char entry[])
{
    char check[200],jomle [100][100];
    int i=0,j=0;
    //setting all items of the arry to NULL
    for(i=0;i<100;i++)
        for(j=0;j<100;j++)
            jomle[i][j]=NULL;
    j=0;
    //if the entry is one , this is our way of searching
    if (isone(entry))
    {
        struct p2 * temp=firstp2;
        while(temp!=NULL)
        {
            i=0;
            //if entry is on the right side of the current tree member
            if (strcmpi(entry,temp->word)>0)
            {
                temp=temp->right;
                continue;
            }
            //if entry is on the left side of the current tree member
            if (strcmpi(entry,temp->word)<0)
            {
                temp=temp->left;
                continue;
            }
            //if entry is the current tree member
            if ((strcmpi(entry,temp->word))==0)
            {
                printf("%s found in :\n",entry);
                struct inp2 * fn=temp->filename;
                fn->re=0;
                while(fn!=NULL)
                {
                    //printing the addresses of the .txt in which the entry word , exist
                    fn->re=0;
                    printf("%s:\n\n",fn->filename);
                    FILE *fp=fopen(fn->filename,"r");
                    {
                        fseek(fp,0,SEEK_SET);
                        while (!feof(fp))
                        {
                             i=0;
                             j=0;
                             fscanf(fp,"%s",check);
                             while((strcmpi(check,".")!=0))
                             {
                                strcpy(jomle[i],check);
                                i++;
                                fscanf(fp,"%s",check);
                             }
                        while(j<i)
                        {
                            if((strcmpi(jomle[j],entry)==0))
                            {
                                j=-1;
                                break;
                            }
                            j++;
                        }
                        if(j==-1)
                        // here we put the statements in which the word exists, and hold them in an arry to print afterwards
                        {
                            (fn->re)++;
                            for(j=0;j<i;j++)
                            {
                                if (strcmpi(jomle[j],entry)==0)
                                    color(12);
                                printf("%s ",jomle[j]);
                                    color(15);
                            }
                            printf(".\n");
                            for(i=0;i<100;i++)
                                for(j=0;j<100;j++)
                                    jomle[i][j]=NULL;
                        }
                        else
                            for(i=0;i<100;i++)
                                for(j=0;j<100;j++)
                                    jomle[i][j]=NULL;
                        }
                    }
                    fclose(fp);
                    //printing the repeats of the word in a single file.txt
                    printf("repeat = %d\n",fn->re);
                    fn=fn->next;
                    printf("\n\n");
                }
            }
            printf("\n\n");
            i++;
            break;
        }
        //in case the word didn't exist
        if (i==0)
        {
            j=1;
            printf("sorry ! we could not find any thing !\n\ntry something else ! \n");
            printf("you might have been looking for :\n");
            struct p2* tem=firstp2;
            while(f<4)
            {
                while (tem!=NULL&&j<8)
                {
                    sim(tem,entry,j);
                    j++;
                }
            }
            f=1; //just a flag
        printf("\n\n"); //just a space
        }
    }
    //if entry is more than just one word , this is what we do
        else
        {
            //first tokennizing the entry string and putting it in a 2d arry
            char stack [100][100];
            char temp ;
            int i=0,j=0,k=0,token=0;
            while(entry[i]!=NULL)
            {
                if (entry[i]==' ')
                {
                    j++;
                    k=0;
                    i++;
                }
                stack[j][k]=entry[i];
                stack[j][k+1]=NULL;
                k++;
                i++;
            }
            i=0; j=0; k=0;
            token=tokeniz(entry);
            temp=stack[i][j];
            //turning the prefix into a postfix string
            while(token>0)
            {
                //if the last tokken is a character
                if (isop(temp)==0)
                {
                    push(postfix[top],stack[i],&top);
                }
                //if the last tokken is a symbol
                else if (isop(temp)==1)
                {
                    if (top_t>0)
                    {
                        if ((stack_temp[(top_t)-1][0]>temp)|(stack_temp[(top_t)-1][0])=='(')
                        {
                            push(stack_temp[top_t],stack[i],&top_t);
                        }
                        else
                        {
                            push(postfix[top],pop(stack_temp[(top_t)-1],&top_t),&top);
                            push(stack_temp[top_t],stack[i],&top_t);
                        }
                    }
                    else if (top_t==0)
                    {
                        push(stack_temp[top_t],stack[i],&top_t);
                    }
                }
                //if the last tokken is "("
                else if (isop(temp)==2)
                {
                    push(stack_temp[top_t],stack[i],&top_t);
                }
                //if the last tokken is ")"
                else if (isop(temp)==3)
                {
                    while(stack_temp[(top_t)-1][0]!='(')
                    {
                        push(postfix[top],pop(stack_temp[(top_t)-1],&top_t),&top);
                    }
                    pop(stack_temp[(top_t)-1],&top_t);
                }
                i++;
                temp=stack[i][j];
                token--;
            }
            //emptying stack_temp
            while(top_t>0)
            {
                push(postfix[top],pop(stack_temp[(top_t)-1],&top_t),&top);
            }
            //postfix[] contains the postfixed string
            //printing the postfixed string (optional)
            token=tokeniz(entry);
            color(4);
            printf("the postfix of the string you entered : ");
            color(2);
            for(i=0;i<token;i++)
                printf("%s ",postfix[i]);
            printf("\n");
            color(15);
            //solving the entry string and printing it
            struct inp2 * end;
            end=bk(pop(postfix[top-1],&top));
            end=end->next;
            while(end!=NULL)
            {
                printf("%s\n",end->filename);
                end=end->next;
            }
        }
        //reseting the flags
        top=0; top_t=0;
}
//Levenshtein's Algorithm for determining the distance on two words, the distance is returned
int guess(char word1[],char word2[])
{
    int i=0,j=0,min=0,c=0;
    char a[3],b[3];
    char string [strlen(word1)+1][strlen(word2)+1] ;
    for (i=0;i<=strlen(word1);i++)
        string[i][0]=i;
    for (j=0;j<=strlen(word2);j++)
        string[0][j]=j;
    for(i=1;i<=strlen(word1);i++)
        for(j=1;j<=strlen(word2);j++)
        {
            if((word1[i-1]==word2[j-1])||(word1[i-1]+32==word2[i-1])||(word1[i-1]==word2[j-1]+32))
                c=0;
            else
                c=1;
            if ((string[i-1][j]+1)<(string[i][j-1]+1))
                min=string[i-1][j]+1;
            else
                min=string[i][j-1]+1;
            if (min>string[i-1][j-1]+c)
                min=string[i-1][j-1]+c;
            string[i][j]=min;
        }
   return string[strlen(word1)][strlen(word2)];
}
//finding a word in the binary search tree for solving it later in solve() function
struct inp2 * find(char entry[])
{
    int i=-1;
    struct p2 * temp=firstp2;
    while(temp!=NULL)
        {
            i=-1;
            if (strcmpi(entry,temp->word)>0)
            {
                temp=temp->right;
                continue;
            }
            if (strcmpi(entry,temp->word)<0)
            {
                temp=temp->left;
                continue;
            }
            if ((strcmpi(entry,temp->word))==0)
            {
                return temp->filename;
                i++;
                break;
            }
        }
            if (i==-1)
                return NULL;
}
//the function to solve the logical string given by the user

struct inp2 * bk(char op[80])
{
    struct inp2 * t1;
    struct inp2 * t2;
    t1=(struct inp2 *) malloc (sizeof(struct inp2));
    t2=(struct inp2 *) malloc (sizeof(struct inp2));
    char t[80];
    printf("%s",op);
    if (isop(op[0])!=0)
    {
    t[0]=op[0];
    t[1]=NULL;
    t1=bk(pop(postfix[top-1],&top));
    t2=bk(pop(postfix[top-1],&top));
    return solve(t1,t2,t);
    }
    else
       return find(op);
}
//putting "NULL" at the end of the entry's string
void nuller(char entry[])
{
    int i=0;
    while(entry[i]!='\n')
        i++;
    entry[i]=NULL;
}
struct inp2 * creatres(struct inp2 * temp,char filename[])
{
    struct inp2 * tep;
    tep=(struct inp2 *) malloc (sizeof(struct inp2));
    tep->next=temp->next;
    strcpy(tep->filename,filename);
    temp->next=tep;
    return tep;
};
struct inp2 * solve(struct inp2 * temp1,struct inp2 * temp2,char op[])
{
    struct inp2 * s=temp1;
    struct inp2 * e=temp2;
    struct inp2 * resf,*rese;
    resf=(struct inp2*) malloc (sizeof (struct inp2 ));
    rese=(struct inp2*) malloc (sizeof (struct inp2 ));
    resf->next=resf;
    rese->next=NULL;
    strcpy(resf->filename,"NULL");
    strcpy(resf->filename,"");
    if (strcmp(op,"&")==0)
    {
        while(s!=NULL)
        {
            while(e!=NULL)
            {
               if (strcmpi((e->filename),(s->filename))==0)
               {
                   rese=creatres(rese,s->filename);
                   break;
               }
            e=e->next;
            }
        e=temp2;
        s=s->next;
        }
    }
    else if (strcmp(op,"|")==0)
    {
        int x=0;
        while (s!=NULL)
        {
            rese=creatres(rese,s->filename);
            s=s->next;
        }
        s=temp1;
        while (s!=NULL)
        {
            while (e!=NULL)
            {
                if (strcmpi(e->filename,s->filename)!=0)
                    x++;
                e=e->next;
            }
            if (x==0)
                rese=creatres(rese,s->filename);
            e=temp2;
            s=s->next;
            x=0;
        }
    }
    else if (strcmp(op,"!")==0)
    {
        int x=0;
        struct inp2* fn;
        fn=first;
        while (fn!=NULL)
        {
            while (s!=NULL)
            {
                if (strcmp(s->filename,fn->filename)==0)
                    x++;
                s=s->next;
            }
            s=temp1;
            if (x==0)
                rese->next=creatres(rese,fn->filename);
            fn=fn->next;
            x=0;
        }
    }
    else if (strcmp(op,"^")==0)
    {
        struct inp2* fn,*ft;
        fn=solve(s,e,"|");
        ft=solve(s,e,"&");
        int x=0;
        struct inp2* f;
        f=fn;
        while (fn!=NULL)
        {
            while (ft!=NULL)
            {
                if (strcmp(ft->filename,fn->filename)==0)
                    x++;
                ft=ft->next;
            }
            ft=solve(s,e,"&");
            if (x==0)
                rese->next=creatres(rese,fn->filename);
            fn=fn->next;
            x=0;
        }
    }
    return resf;
}
int main()
{
    //just mallocing some space for further need !
        struct timeb start;
        struct timeb end;
        first=(struct p*) malloc (sizeof(struct p));
        firstp2=(struct p2*) malloc (sizeof(struct p2));
        last=(struct p*) malloc (sizeof(struct p));
        lastp2=(struct p2*) malloc (sizeof(struct p2));
        first->next=NULL;
        last=first;
        firstp2->left=NULL;
        firstp2->right=NULL;
        lastp2=firstp2;
    //the main code starts here
    char tempp[100],path[300]="e:\\files",skippath[300]="e:\\skipword.txt";
    printf("please enter the files directory\n");
    fgets(path,300,stdin);
    nuller(path);
    printf("please enter the skipwords directory\n");
    fgets(skippath,300,stdin);
    nuller(skippath);
    //phase one
    readfile (path,skippath);
    //phase two (binary search tree)
    bst();
    // entering the search word
    char entry[100]="search";
    draw();
    while(1)
    {
        color(11);
        printf("please enter what you seek !!!\n\n");
        color(15);
        fgets(entry,100,stdin);
        ftime(&start);
        //adding "NULL"  at the end of the entry word
        nuller(entry);
        if(strcmpi(entry,"terminate")==0)
                break;
        // searching for the word
        search(entry);
        ftime(&end);
        printf("it took %d milliseconds\n",(end.millitm)-(start.millitm));
        // continue on getting words until "terminate" is entered
        printf("\t\t\t\t\t   ");
    }
    //order(first);
    //inorder(firstp2);
}
void push (char stack[],char entry[],int *top)
{
    strcpy(stack,entry);
    (*top)++;
}
char * pop(char stack[],int * top)
{
    if (top<0)
    {
        printf("stack underflow !\n");
        return 0;
    }
    (*top)--;
    return stack;
}
