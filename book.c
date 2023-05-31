#include<stdio.h>
#include<stdlib.h>
#include"bk.h"
struct book bk[5]={{"Alistair MacLean","Ice Station Zebra",3,3,1},{"J K Rowling","Harry Potter - Deathly Hallows",1,1,2},{"James Dashner","Maze Runner",4,4,3},{"Fredrick Forsyth","The Ngotiator",3,3,4},{"Enid Blyton","Five Get Together Again",2,2,5}};
struct book b;
void write()
{
	FILE *fp=fopen("books.txt","w");
	fwrite(&bk,sizeof(struct book), 5, fp);
	fclose(fp);		
}
/*void main()
{
	write();
}*/
void display_books()
{
	FILE *fp=fopen("books.txt","r");
	int i;
	for(i=0;i<5;i++)
	{
		fseek(fp,sizeof(b)*i ,SEEK_SET);
		fread(&b.auth,100, 1, fp);
	    fread(&b.title,100, 1, fp);
	    fread(&b.qty, sizeof(int), 1, fp);
	    fread(&b.qty_available, sizeof(int), 1, fp);
		fread(&b.sno, sizeof(int), 1, fp);
		printf("Sno:%d Title:%30s    Author:%20s   Qty:%2d   Qty Available:%2d \n",b.sno,b.title,b.auth,b.qty,b.qty_available);	
	}
	fclose(fp);
}
void display_ind(int n)
{
	FILE *fp=fopen("books.txt","r");
	fseek(fp,sizeof(b)*n,SEEK_SET);
	fread(&b,sizeof(b),1,fp);
	printf("Sno:%d   Title:%30s Author:%s \n",b.sno,b.title,b.auth);	
	fclose(fp);
}
int book_borrow(int n)
{
		FILE *fp=fopen("books.txt","r+");
		fseek(fp,0,SEEK_END);
		int f=ftell(fp);
		int flag=0;
		int h=-1;
		fseek(fp,0,SEEK_SET);
		while(ftell(fp)!=f&&flag==0)
		{
			h++;
			fseek(fp,sizeof(b)*h ,SEEK_SET);
			fread(&b,sizeof(b),1, fp);
			if(n==b.sno)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			if(b.qty_available>0)
			{
				b.qty_available--;
				fseek(fp,sizeof(b)*h ,SEEK_SET);
				fwrite(&b,sizeof(struct book),1, fp);
				fclose(fp);
				return h;
			}
			return -1;
		}
		return -1;
}
int return_book(int n)
{
	FILE *fp=fopen("books.txt","r+");
	fseek(fp,sizeof(b)*n,SEEK_SET);
	fread(&b,sizeof(b),1,fp);
	b.qty_available++;
	fseek(fp,sizeof(b)*n,SEEK_SET);
	fwrite(&b,sizeof(struct book),1,fp);
	fclose(fp);
	printf("Book returned successfully!");
	getch();
	return 1;
}