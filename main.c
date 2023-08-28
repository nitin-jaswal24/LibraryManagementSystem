

#ifndef lib_management
#define lib_management

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct library
{
    int book_id;
    char book_name[20];
    char author_name[20];
} book;

typedef enum test_values
{
    pass = 1,
    fail = 0
} test_values;
test_values searchbook(int id);

test_values addition(int id, char name[], char author[]);

test_values deletebook(int id);

test_values issuebook(int id);

test_values viewbook(void);

#endif

// code for addition of the book in the library

test_values addition(int id, char name[], char author[])
{
    FILE *fp = NULL;
    fp = fopen("bookLibrary.dat", "ab+"); // this means in append binary and read and write mode

    if (fp == NULL)
    {
        printf("\n Error: could not open the file");
    }
    else
    {
        book *newBook = NULL;
        newBook = malloc(sizeof(book));

        newBook->book_id = id;

        strcpy(newBook->book_name, name);

        strcpy(newBook->author_name, author);

        fwrite(newBook, sizeof(book), 1, fp);
        fclose(fp);

        free(newBook);

        return pass;
    }
}

// now lets write for deleting the book
test_values deleteBook(int id)
{
    FILE *fp = NULL;
    FILE *ft = NULL;

    fp = fopen("bookLibrary.dat", "rb"); // this rb means reading and binary
    ft = fopen("temp.dat", "wb");

    if (fp == NULL || ft == NULL)
    {
        printf("\n Error: could not open the file");
        return fail;
    }
    else
    {
        rewind(fp);

        book *discardedBook = (book *)malloc(sizeof(book));

        while (fread(discardedBook, sizeof(book), 1, fp) == 1)
        {
            if (id != discardedBook->book_id)
            {
                fwrite(discardedBook, sizeof(book), 1, ft);
            }
        }
        fclose(fp);
        fclose(ft);
        free(discardedBook);

        remove("bookLibrary.dat");
        rename("temp.dat", "bookLibrary.dat");
        return pass;
    }
}

// code to search the books in the library
test_values searchBook(int id)
{
    FILE *fp = NULL;
    fp = fopen("bookLibrary.dat", "rb"); // read and binary file

    if (fp == NULL)
    {
        printf("\n Error : could  not open the file");
        return fail;
    }
    else
    {
        book *book_to_find = (book *)malloc(sizeof(book));
        while (fread(book_to_find, sizeof(book), 1, fp))
        {
            if (book_to_find->book_id == id)
            {
                printf("\n Book_Id: %d\t\tBook_Name: %s\t\tBook_Author: %s", book_to_find->book_id, book_to_find->book_name, book_to_find->author_name);
                fclose(fp);
                free(book_to_find);
                return pass;
            }
        }
        fclose(fp);
        free(book_to_find);
        printf("\n specified book is not present\n");
        return fail;
    }
}

// code to issue the book

test_values issueBook(int id)
{
    char name1[20];
    FILE *fp = NULL;
    fp = fopen("bookLibrary.dat", "rb");
    if (fp == NULL)
    {
        printf("\n Error : could not open the file");
        return fail;
    }
    else
    {
        scanf("%19s student_name", name1);
        book *book_to_find = (book *)malloc(sizeof(book));

        while (fread(book_to_find,sizeof(book),1,fp))
        {
            if (book_to_find->book_id == id)
            {
                printf("\nBook_Id: %d\t\tBook_name: %s\t\tBook_Author: %s", book_to_find->book_id, book_to_find->book_name, book_to_find->author_name);
                printf("\n Book is issued to %s",name1);
                fclose(fp);
                free(book_to_find);
                return pass;
            }
        }
        fclose(fp);
        free(book_to_find);
        printf("\n book specified is not present");
        return fail;

    }
}

//code to view the book
test_values viewBook(){
    FILE *fp=NULL;

    fp=fopen("bookLibrary.dat","rb");

    if(fp==NULL){
        printf("\n Error: could not open the file");
        return fail;
    }
    else{
        book *book_to_find=(book*)malloc(sizeof(book));
        while(fread(book_to_find,sizeof(book),1,fp)){
    printf("\n%d\t\t\t%s\t\t\t%s", book_to_find->book_id, book_to_find->book_name, book_to_find->author_name);

        }
        fclose(fp);
        free(book_to_find);
        return pass;
    }
}




int main()
{
    
    int id,choice,success; 
    
    char name[20],authorname[20];
    
        
while(1){

    printf("\n\t\t\t\t\t\t*************** MAIN MENU ***************\n");
    printf("\n\t\t\t\t\t\t1. Add Books");
    printf("\n\t\t\t\t\t\t2. Delete books");
    printf("\n\t\t\t\t\t\t3. View Books");
    printf("\n\t\t\t\t\t\t4. Search book");
    printf("\n\t\t\t\t\t\t5. Issue books");
    printf("\n\t\t\t\t\t\t6. Close Application");
    printf("\n\t\t\t\t\t\t******************************************\n");
    printf("\n\t\t\t\t\t\tEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("\nBookId: ");
        scanf("%d",&id);
        fflush(stdin);
        printf("\nBook name:");
        //gets(name);
	scanf("%19s",name);
       printf("Authorname: ");
        fflush(stdin);
        //gets(author);
	scanf("%19s",authorname);
        success=addition(id,name,authorname);
        break;
        case 2:
        printf("\nBookId: ");
        scanf("%d",&id);
        success=deleteBook(id);
        break;
        case 3:
        success=viewBook();
        break;
        case 4:
        printf("\nBookId:");
        scanf("%d",&id);
        success=searchBook(id);
        break;
        case 5:
        printf("\nBookId: ");
        scanf("%d",&id);
        success=issueBook(id);
        break;
        case 6:
        printf("\n\n\n");
        exit(1);
        default:
        printf("\n\t\t\t\t\t\tInvalid input");
        break;
     }
    if(success == pass)
    {
        printf("Successful\n");
    }
    else if(success==fail)
    {
        printf("Unsuccessful\n");
    }
    else{
        printf("Error\n");
    }
}
return 0;
}