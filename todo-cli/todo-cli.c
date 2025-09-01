#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DONE "done\n"
#define UNDONE "undone\n"

void readFile(int *, char*); 
void addTask(char*, int *, char*);
void showAllList(char*);
void removeTask(int, char*, int*);
void clearFile(char*, int*);
void printHelp();
void showDoneList(char*);
void showUndoneList(char*);
void setTaskStatus(int,char*,char* );
int checkAlpha(char*);
void copyFile(char* ,char*);
void reindexTasks(char*);

int main()
{
    printf("Welcome to todo:\nfor help use [help]\n\n");

    int countline = 0;
    printf("Enter filename [create or open]: ");
    char filename[100];
    scanf("%99s", filename);
    char command[20];
    char task[100];
    FILE *file = NULL;
    readFile(&countline, filename);
    while (1)
    {
        printf("\ntodo list>");
        scanf("%19s",command);
        getchar();
        fgets(task,sizeof(task),stdin);
        task[strcspn(task,"\n")]='\0';
        int lenTask=strlen(task);
        if(strcmp(command,"add")==0)
        {
            if(checkAlpha(task)==0)
            {
                printf("Invalid Command!");
                
            }
            else
                addTask(task,&countline,filename);
        }
        else if(strcmp(command,"list")==0)
        {
            if(lenTask!=0)
            {   
                if(strcmp(task,"--done")==0)
                {
                    showDoneList(filename);
                }
                else if(strcmp(task,"--undone")==0)
                {
                    showUndoneList(filename);
                }
                else
                {

                    printf("Invalid option! Use --done or --undone\n");
                }
            }
            else
            {
                 showAllList(filename);
            }
        }
        else if(strcmp(command,"remove")==0)
        {
            if(checkAlpha(task)==0)
            {
                printf("Invalid option! Use remove [number task]\n");
                continue;
            }
            else
            {
                int  tasknum=atoi(task);
                if(tasknum>countline||tasknum<0)
                {
                    printf("\n\nnumber of  line is  invalid!");
                }
                else
                    removeTask(tasknum,filename,&countline);
            }
        }
        else if(strcmp(command,"help")==0)
        {
            if(checkAlpha(task)!=0)
            {
                printf("Invalid option! Use help\n");
            }
            else
            {
                printHelp();
            }
        }
        else if(strcmp(command,"clear")==0)
        {
            if(checkAlpha(task)!=0)
            {
                printf("Invalid option! Use clear\n");
            }
            else
                clearFile(filename,&countline);
        }
        else if(strcmp(command,"done")==0)
        {
            if(checkAlpha(task)==0)
            {
                printf("Invalid option! Use done [number task]\n");
            }
            else
            {
                int  tasknum=atoi(task);
                if(tasknum>countline||tasknum<0)
                {
                    printf("\n\nnumber of  line is  invalid!");
                }
                else
                    setTaskStatus(tasknum,filename,DONE);
            }
        }
        else if(strcmp(command,"undone")==0)
        {
            if(checkAlpha(task)==0)
            {
                printf("Invalid option! Use undone [number task]\n");
            }
            else
            {
                int  tasknum=atoi(task);
                if(tasknum>countline||tasknum<0)
                {
                    printf("\n\nnumber of  line is  invalid!");
                }
                else
                    setTaskStatus(tasknum,filename,UNDONE);
            }
        }
        else if(strcmp(command,"exit")==0)
        {
            break;
        }
        else{
            printf("\n\nInvalid option! Use help -> see commands\n");
        }
    }
    return 0;
}

void  readFile(int  *count,char *filename)
{
    FILE* file=fopen(filename,"r");
    if (!file) {
    *count = 0;
    return;
    }
    char line[100];
    while (fgets(line,100,file)!=NULL)
    {
        (*count)++;
    }
    fclose(file);
}

void  addTask(char * task ,int *count ,char* filename)
{
    FILE*file =fopen(filename,"a"); //w  means  write  to file 
    fprintf(file,"%d- %s\tStatus:undone\n",++(*count),task);
     fclose(file);
     printf("\nAdd is Successfully.");
}

void  showAllList(char* filename)
{
    char  buffer[100];
    FILE* file=fopen(filename,"r");

    if(file)
    {
         while (fgets(buffer,100,file))
        {
            printf("%s",buffer);
        }
    }
    else
    {
        printf("\nfile  not opened !");
    }
}

void removeTask(int taskNumber,char* filename,int*count)
{
    FILE * tempFile=fopen("temp.txt","w");
    FILE *file =fopen(filename,"r");
    
    if(!tempFile||!file)
    {
        printf("\nError in  open or  creat file !");
        if(file) fclose(file);
        if(tempFile) fclose(tempFile);
        return;
    }
    char line[256];
    int  currentLine=1;
    while (fgets(line,sizeof(line),file))
    {
        if(currentLine!=taskNumber)
        {
            fputs(line,tempFile);
        }
        currentLine++;
    }
    
    fclose(tempFile);
    fclose(file);
    copyFile(filename,"temp.txt");

    remove("temp.txt");
    printf("\n\nremove  sucessfully ");
    (*count)--;
    reindexTasks(filename);

}

void  clearFile(char* filename,int * count)
{
    *count=0;
    FILE* file=fopen(filename,"w");
    fclose(file);
    printf("\nAll data Clear Successfuly");
}

void printHelp()
{
    printf("Todo List  with  cli :\nCommands:\n"
        "1-add [your task]=>Add a task to your list\n"
       "2-list => show tasks list\n"
        "3-done [task number] => Done label on task number\n"
        "4-undone [task number] => Undone label on task number\n"
        "5-remove [task number] => remove task number\n"
        "6-list --undone =>show  List only uncompleted tasks\n"
        "7-list --done =>show  List only completed tasks\n"
        "8-clear  => clear all  data\n"
        "9-help => show  available  commands\n"
        "10-exit => exit program!\n");
}

void showDoneList(char* filename)
{
    char  buffer[100];
    FILE* file=fopen(filename,"r");

    if(file)
    {
         while (fgets(buffer,100,file))
        {
            char* str = strstr(buffer, DONE);
            if(str) printf("%s", buffer);
        }
    }
    else
    {
        printf("\nError  in  open  file!");
    }
    fclose(file);
}

void showUndoneList(char* filename)
{
    char  buffer[100];
    FILE* file=fopen(filename,"r");

    if(file)
    {
         while (fgets(buffer,100,file))
        {
            char* str = strstr(buffer, UNDONE);
            if(str) printf("%s", buffer);
        }
    }
    else
    {
        printf("\nError in  open  file!");
    }
    fclose(file);
}

void setTaskStatus(int tasknumber,char*filename,char* statusLabel)
{
    FILE * tempFile =fopen("temp.txt","w");
    FILE* file=fopen(filename,"r");

    if (!tempFile || !file) {
        printf("\nError opening file!\n");
        if (tempFile) fclose(tempFile);
        if (file) fclose(file);
        return;
    }


    char line[256];
    int  currentLine=1;

    while(fgets(line,sizeof(line),file))
    {
        if(currentLine==tasknumber)
        {
            char buffer[256];
            char *pos = strstr(line, "Status:");
            if (pos) {
                *pos = '\0';  // همه‌چی رو قبل از Status نگه می‌داریم
                sprintf(buffer, "%sStatus:%s", line, statusLabel);
                fputs(buffer, tempFile);
            }

        }
        else{
            fputs(line,tempFile);

        }
        currentLine++;
    }

    fclose(tempFile);
    fclose(file);

    copyFile(filename,"temp.txt");

    remove("temp.txt");

    printf("\nTask %d Change Status %s .",tasknumber,statusLabel);

}

int checkAlpha(char* str)
{
    int len=strlen(str);
    if (str == NULL || len == 0)
        return 0;
    
    for(int i = 0; i < len; i++)
    {
        if (str[i] >= 33 && str[i] <= 126) 
        {
            return 1; 
        }
    }
    return 0; 
}

void copyFile(char* destname,char* srcname)
{
    FILE* src = fopen(srcname,"r");
    FILE* dest = fopen(destname,"w");
    if(!src || !dest){
        printf("Error in copyFile!\n");
        if(src) fclose(src);
        if(dest) fclose(dest);
        return;
    }
    char buffer[256];
    while(fgets(buffer,sizeof(buffer),src))
    {
        fputs(buffer,dest);
    }
    fclose(src);
    fclose(dest);
}

void reindexTasks(char*filename)
{
    FILE * tempFile =fopen("temp.txt","w");
    FILE* file=fopen(filename,"r");

if (!tempFile || !file) {
    printf("\nError opening file!\n");
    if (tempFile) fclose(tempFile);
    if (file) fclose(file);
    return;
}


    char line[256];
    char Linestr[256];
    int  currentLine=1;

    while(fgets(line,sizeof(line),file))
    {
        char *pos = strchr(line, '-');
        if (pos) {
            snprintf(Linestr, sizeof(Linestr), "%d%s", currentLine, pos);
            fputs(Linestr, tempFile);
            currentLine++;
        }


    }

    fclose(tempFile);
    fclose(file);

    copyFile(filename,"temp.txt");

    remove("temp.txt");
}





























