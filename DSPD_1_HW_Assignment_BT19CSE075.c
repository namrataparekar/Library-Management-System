#include<stdio.h>
#include<string.h>
#define SIZE 100
#define ISSUED 0
#define AVAILABLE 1 


struct book_details{
	char name[100],subject[50],author[50];
	
	int seq_num,print_year, status, hall_num,rack_num,row_num;
	
};

struct member{
	char designation[10];
	struct faculty{
	 char fname[50],dept[50];
	 int id,booknum;		
	}F[SIZE];
	struct student{
		char sname[50],dept[50];
		int id,booknum;
	}S[SIZE];
};

void insert_book(int p);
void new_member(int q);
void max_book(struct member list[]);
void fine_section();
void borrower_list(struct member a[],int n);
void options(int k, int p, int q, struct member list[]);	

int main()
{
	struct book_details record[SIZE];
	struct member list[SIZE];
	int i, j, k,p,q,seq=0;
	char ans;
	
	
	printf("Enter book details:\n");
	for(i=0; i<3; i++)//initially giving some input,i.e. creating records for 3 books
	{
		int seq=seq+1;
		record[i].seq_num=seq;
		
		printf("Enter book name:\n");
		gets(record[i].name);
		
		printf("Enter book subject:\n");
		gets(record[i].subject);
		
		printf("Enter book author:\n");
		gets(record[i].author);
		
		print("Enter year of print/reprint of book:\n");
		scanf("%d",&record[i].print_year);
		
	}
	
	printf("Enter member details:\n");
	for(j=0; j<2; j++)
	{
		printf("Enter designation(student or faculty)");
		gets(ans);
		
		if (ans=='student')
		{
			printf("Enter student name:\n");
			gets(list[j].S[j].sname);
			
			printf("Enter student dept:\n");
			gets(list[j].S[j].dept);
			
			printf("Enter student ID:\n");
			scanf("%d",&list[j].S[j].id);
			
			printf("Enter numbers of books issued by student:\n");//can issue upto 2 books
			scanf("%d",&list[j].S[j].booknum);
		}
		else
		{
			printf("Enter faculty name:\n");
			gets(list[j].F[j].fname);
			
			printf("Enter faculty dept:\n");
			gets(list[j].F[j].dept);
			
			printf("Enter faculty ID:\n");
			scanf("%d",&list[j].F[j].id);
			
			printf("Enter numbers of books issued by faculty:\n");//can issue upto 4 books
			scanf("%d",&list[j].F[j].booknum);
		}
		
	}
	
	printf("\n");
	printf("1.Insert a book\n");
	printf("2.Create a new member\n");
	printf("3.Display name of the faculty & student member having maximum books\n");
	printf("4.Calculate fine and display name of borrower having maximum fine till date\n");
	printf("5.Display names of borrowers\n");
	 p=3,q=2;
	options(k,p,q, struct member list[]);
	return 0;
}
void options(int k, int p, int q, struct member list[])
{
		
	switch (k)
	{	
	case 1:
	printf("this is for insertion of a book\n");
	insert_book(p);
	break;
 	}
	{
	case 2:
	printf("This is to create a new member\n");
	new_member(q);
	break;
	}
	{
	case 3:
	printf("this is for display of borrower having max books\n");
	max_book(struct member list[]);
	break;
	}
	{
	case 4:
	printf("This is for calculating fine\n");
	fine_section();
	break;
	}
	{
	case 5:
	printf("This is list of borrowes\n");
	borrower_list(struct member list[], int);
	break;
	}
		
}
void insert_book(int p)//to insert a book in library
{
		printf("Enter book name:\n");
		gets(record[p].name);
		
		printf("Enter book subject:\n");
		gets(record[p].subject);
		
		printf("Enter book author:\n");
		gets(record[p].author);
		
		print("Enter year of print/reprint of book:\n");
		scanf("%d",&record[p].print_year);
}
void new_member(int q)//to create a new member
{
	char ans;
	printf("Enter designation(student or faculty)");
		gets(ans);
		
		if (ans=='student')
		{
			printf("Enter student name:\n");
			gets(list[q].S[q].sname);
			
			printf("Enter student dept:\n");
			gets(list[q].S[q].dept);
			
			printf("Enter student ID:\n");
			scanf("%d",&list[q].S[q].id);
			
			
		}
		else
		{
			printf("Enter faculty name:\n");
			gets(list[q].F[q].fname);
			
			printf("Enter faculty dept:\n");
			gets(list[q].F[q].dept);
			
			printf("Enter faculty ID:\n");
			scanf("%d",&list[q].F[q].id);
			
			
		}
}
void max_book(struct member list[]);//to display names of members having maximun issued books
{
	int i=0,j,m=0,k=0,a[100];
    while(list[i].S[i].id)// for student member
    {
        if(list[i].S[i].booknum>=m)
            m = list[i].S[i].num;
        i++;
    }
    for(j=0;j<i;j++)
    {
        if(list[j].S[j].booknum==m)
            a[k++] = j;
    }
    printf("Names of the students issued maximum book:\n");
    for(i=0;i<k;i++)
        puts(list[a[i]].S[a[i]].sname);
    
	int n=0,l,g=0,h=0,b[100];
    while(list[g].F[g].id)//for faculty member
    {
        if(list[g].F[g].booknum>=n)
            n = list[g].F[g].num;
        g++;
    }
    for(l=0;l<g;l++)
    {
        if(list[l].S[l].booknum==m)
            b[h++] = l;
    }
    printf("Names of the faculty issued maximum book:\n");
    for(g=0;g<h;g++)
        puts(list[b[g]].F[b[g]].fname);
    
}
void fine_section()//to calculate fine and display member having maximum amount of fine
{
	print("This section is not coded\n");
	//take input issue date and for faculty after 30 days 50 paise/day fine for books and for students after 14 days 50 paise/day fine for books   
}
void borrower_list(struct member a[],int n)//to display list of borrowers  
{
	int i,j,flag,temp,m;
    char ctemp[100];
    for(i=0;i<n-1;i++)
    {
        j=0;
        do{
        	if(a[j].S[j].booknum>a[j+1].S[j].booknum)  //sorting for student member
            {
                temp = a[j].S[j].booknum;
                a[j].S[j].booknum = a[j+1],S[j].booknum;
                a[j+1]S[j].booknum = temp;

                strcpy(ctemp,a[j].S[j].sname);
                strcpy(a[j].S[j].sname,a[j+1].S[j].sname);
                strcpy(a[j+1].S[j].sname,ctemp);
            }
            if(a[j].S[j].booknum == a[j+1].S[j].booknum)
            {
                m = strcmp(a[j].S[j].sname,a[j+1].S[j].sname);
                if(m>0)
                {
                    strcpy(ctemp,a[j].S[j].sname);
                    strcpy(a[j].S[j].sname,a[j+1].S[j].sname);
                    strcpy(a[j+1].S[j].sname,ctemp);

                    temp = a[j].S[j].sname;
                    a[j].S[j].sname = a[j+1].S[j].sname;
                    a[j+1].S[j].sname = temp;
                }
            }
            flag=1;
            j++;
        	
		}while(j<n-i-1 && flag==1)
        
    }
}
