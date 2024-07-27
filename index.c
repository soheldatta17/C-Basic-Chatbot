#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
//gcc -o proj.exe proj.c -lwinmm
//.\proj.exe
char a[20],b[490],c[20]; int s=0,flag=0,l=0,i,n,m=0,x=0;
char ch;

void reset(FILE *fp,FILE *fs)
{
    while(1)
    {
        ch=fgetc(fs);
        if(ch==EOF)
        {
            break;
        }
        fputc(ch,fp);
    }
}
void include(FILE *fp,FILE *fs,char *d)
{
    
    while(1)
        {
        ch=fgetc(fp);
        if(ch==EOF)
        {
            fputc('\n',fs);
            for(x=0;x<strlen(d);x++)
            {
                fputc(d[x],fs);
            }
            fputc('\n',fs);
            fputc('\n',fs);
            break;
        }
        fputc(ch,fs);
        }
        x=0;
}
void check(FILE *fs)
{
while(1)
    {
        ch=fgetc(fs);
        if(ch==EOF)
        {
            break;
        }
        if(ch==' ')
        {
            flag=1;
            continue;
        }
        if(ch=='\n')
        {
            flag=0;
            s=0;
            c[0]='\0';
        }
        if(ch=='@')
        {
            c[s]='\0';   
            if(strcmp(c,b)==0)
            {
                printf("\nUsername Found: %s\n",c);
                x=1;
                break;
            }
            c[0]='\0';
            continue;
        }
        if(flag==1)
        {
            c[s]=ch;
            s=s+1;
        }
    }
    c[0]='\0';
    flag=0;
    s=0;
    if(x==1)
    {
        while(1)
        {
            ch=fgetc(fs);
            if(ch=='\n')
            {
                flag=flag+1;
            }
            if(flag==2)
            {
                break;
            }
            if(flag==1)
            {
                c[s]=ch;
                s=s+1;
            }
        }
        printf("%s\n\n",c);
    }
    c[0]='\0';
    flag=0;
    s=0;
}

void login(FILE *fp)
{
while(1)
    {
        ch=fgetc(fp);
        if(ch=='\n')
        {
            a[s]='\0';
            m=m+1;
            s=0;
            flag=0;
            x=0;
        }
        if(ch=='@') // CHECKS FOR '@' SUCH AS TO TAKE THE USERNAME FROM THE MAIL
        {
            b[s]='\0'; // STORES THE USERNAME
            s=0;
            break;
        }
        if(ch==' ' && x==0)
        {
            flag=1;
            x++;
            continue;
        }
        if(flag==1 && m==0)
        {
            a[s]=ch; // STORES THE NAME
            s=s+1;
        }
        if(flag==1 && m==1)
        {
            b[s]=ch;
            s=s+1;
        } 
    }
    x=0;
    strupr(a);
    flag=0;
    m=0;
    
}

void replace_space(char *c) 
{
    char *space_ptr = strchr(c, ' ');
    if (space_ptr == NULL) 
    {
        return;
    }
    *space_ptr = '+';
    replace_space(space_ptr + 1);
}

void main()
{
    system("cls"); // CLEARS THE TERMINAL WINDOW
    printf("\n*********I AM AN ASSISTANT CREATED BY SOHEL********\n\n");
    PlaySound(TEXT("intro.wav"),NULL,SND_SYNC);
    system("notepad user.txt"); 
    
    FILE *fp,*fs;
    fp=fopen("user.txt","r"); // OPENS THE FILE IN READ ONLY MODE
    fs=fopen("data.txt","r"); // OPENS THE FILE IN READ ONLY MODE
    int size=0;
    size=fgetc(fs); // IF THE FILE IS EMPTY IT RETURNS -1 OR ELSE THE ACTUAL SIZE OF THE FILE
    fclose(fs);
    login(fp);
    fclose(fp);
    char d[50]="FIRST SIGN UP: ";
    time_t now;
    struct tm *current_time;
    time(&now);
    current_time = localtime(&now);
    strcat(d,asctime(current_time));
    if(size!=-1)
    {
    fs=fopen("data.txt","r");
    check(fs);
    fclose(fs);
    fp=fopen("user.txt","r");
    fs=fopen("data.txt","a");
    if(x==0)
    {
    include(fp,fs,d);
    }
    fclose(fp);
    fclose(fs);
    }
    else
    {
    fp=fopen("user.txt","r");
    fs=fopen("data.txt","w");
    include(fp,fs,d);
    fclose(fp);
    fclose(fs);
    }
    
    fp=fopen("user.txt","w");
    fs=fopen("u.txt","r");
    
    reset(fp,fs);
    fclose(fp);
    fclose(fs);
    c[0]='\0';
    printf(" Hi %s (username: %s )!!! NICE TO MEET YOU\n\n",a,b);
    b[0]='\0';
    fflush(stdin);
    printf(" HOW ARE YOU ... GOOD OR BAD ?\n\n");
    flag=1;
    while(flag)
    {
    PlaySound(TEXT("how are you.wav"),NULL,SND_SYNC);
    printf("----> ");
    gets(b);
    int n=strlen(b);
    b[n]=' ';
    b[n+1]='\0';
    strupr(b);
    s=0;
    for(int i=0;i<strlen(b);i++)
    {
        if(b[i]!=' ')
        {
            c[s]=b[i];
            s=s+1;
        }
        else
        {
            c[s]='\0';
            if(strcmp(c,"GOOD")==0)
            {
                printf("\n\n THAT'S AMAZING !!!\n\n");
                flag=0;
                PlaySound(TEXT("amazing.wav"),NULL,SND_SYNC);
                break;
            }
            if(strcmp(c,"BAD")==0)
            {
                printf("\n\n PLEASE TAKE CARE OF YOURSELF !!!\n\n");
                flag=0;
                PlaySound(TEXT("take care.wav"),NULL,SND_SYNC);
                system("start https://www.youtube.com/watch?v=cimAEwQmMiQ");
                break;
            }
            if(strcmp(c,"QUIT")==0)
            {
                printf("\n\n BYE BYE\n\n");
                Sleep(1000);
                exit(1);
            }
            c[0]='\0';
            s=0;
        }
    }
        if(flag==1)
        {
            printf("\n\n SORRY COULD NOT UNDERSTAND YOUR TEXT... TRY AGAIN\n\n");
            PlaySound(TEXT("sorry.wav"),NULL,SND_SYNC);
            c[0]='\0';
            b[0]='\0';
        }
    }
    b[0]='\0';
    c[0]='\0';
    x=1;
    flag=0;
    printf(" WANNA RUN A NEW APP OR LISTEN TO A SOOTHING SONG... APPLICATION OR SONG ?\n\n");
    while(x)
    {
    printf("----> ");
    gets(b);
    n=strlen(b);
    b[n]=' ';
    b[n+1]='\0';
    strupr(b);
    s=0;
    for(int i=0;i<strlen(b);i++)
    {
        if(b[i]!=' ')
        {
            c[s]=b[i];
            s=s+1;
        }
        else
        {
            c[s]='\0';
            if(strcmp(c,"APP")==0)
            {
                flag=1;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                x=0;
                break;
            }
            if(strcmp(c,"SONG")==0)
            {
                flag=2;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                x=0;
                break;
            }
            if(strcmp(c,"QUIT")==0)
            {
                printf("\n\n BYE BYE\n\n");
                Sleep(1000);
                exit(1);
            }
            c[0]='\0';
            s=0;
        }
    }
    if(x==1)
    {
        printf("\n\n SORRY COULD NOT UNDERSTAND YOUR TEXT... TRY AGAIN\n\n");
        PlaySound(TEXT("sorry.wav"),NULL,SND_SYNC);
        c[0]='\0';
        b[0]='\0';
    
    }
    }
    c[0]='\0';
    s=0;
    x=0;
    b[0]='\0';
    if(flag==2)
    {
        printf("PLAYING THE SONG...\n\n");
        printf("******LYRICS******\n\n");
        
    printf("A broken heart is all that's left\n");
    printf("I'm still fixing all the cracks\n");
    printf("Lost a couple of pieces when\n");
    printf("I carried it, carried it, carried it home\n\n");

    printf("I'm afraid of all I am\n");
    printf("My mind feels like a foreign land\n");
    printf("Silence ringing inside my head\n");
    printf("Please, carry me, carry me, carry me home\n\n");

    printf("I've spent all of the love I saved\n");
    printf("We were always a losing game\n");
    printf("Small-town boy in a big arcade\n");
    printf("I got addicted to a losing game\n\n");

    printf("Oh-oh-oh, oh-oh\n");
    printf("All I know, all I know\n");
    printf("Loving you is a losing game\n\n");

    printf("How many pennies in the slot?\n");
    printf("Giving us up didn't take a lot\n");
    printf("I saw the end before it begun\n");
    printf("Still, I carried, I carried, I carried on\n\n");

    printf("Oh-oh-oh, oh-oh\n");
    printf("All I know, all I know\n");
    printf("Loving you is a losing game\n\n");

    printf("I don't need your games, game over\n");
    printf("Get me off this rollercoaster\n");

    printf("Oh-oh-oh, oh-oh\n");
    printf("All I know, all I know\n");
    printf("Loving you is a losing game\n\n");

    PlaySound(TEXT("beth.wav"),NULL,SND_SYNC);
    }
    if(flag==1)
    {
     printf("\n THE PROGRAMS YOU CAN RUN ARE: \n\n");
     printf(" 1) NOTEPAD\n 2) SPOTIFY\n 3) SEARCH GOOGLE\n 4) SETTINGS\n 5) SEARCH YOUTUBE\n 6) PLAY MUSIC\n 7) RESSO\n 8) COMMAND PROMT\n 9) CALCULATOR\n 10) BINARY TO DECIMAL\n 11) WHATSAPP\n 12) PIANO\n");
     printf("\n WHICH ONE ?\n\n");
     while(1)
     {
     printf("----> ");
     gets(b);
     n=strlen(b);
     b[n]=' ';
     b[n+1]='\0';
     strupr(b);
     l=0;
    for(int i=0;i<strlen(b);i++)
    {
        if(b[i]!=' ')
        {
            c[s]=b[i];
            s=s+1;
        }
        else
        {
            c[s]='\0';
            if(strcmp(c,"SPOTIFY")==0)
            {
                l=2;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"SONG")==0 || strcmp(c,"MUSIC")==0 || strcmp(c,"PLAY")==0)
            {
                l=6;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"WHATSAPP")==0)
            {
                l=11;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"GOOGLE")==0)
            {
                l=3;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"SETTINGS")==0)
            {
                l=4;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"YOUTUBE")==0)
            {
                l=5;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"RESSO")==0)
            {
                l=7;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"NOTEPAD")==0)
            {
                l=1;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"CALCULATOR")==0)
            {
                l=9;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"BINARY")==0 || strcmp(c,"DECIMAL")==0)
            {
                l=10;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"PIANO")==0)
            {
                l=12;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"COMMAND PROMPT")==0 || strcmp(c,"CMD")==0)
            {
                l=8;
                PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
                c[0]='\0';
                s=0;
                b[0]='\0';
                break;
            }
            if(strcmp(c,"QUIT")==0)
            {
                printf("\n\n BYE BYE\n\n");
                Sleep(1000);
                exit(1);
            }
            c[0]='\0';
            s=0;
        }
    }
    if(l==0)
    {
        c[0]='\0';
        s=0;
        b[0]='\0';
        printf("\n\n SORRY COULD NOT UNDERSTAND YOUR TEXT... TRY AGAIN\n\n");
        PlaySound(TEXT("sorry.wav"),NULL,SND_SYNC);
    }
    if(l==1)
    {
        printf(" OPENING NOTEPAD\n");
        system("start notepad.exe");
        break;
    }
    if(l==2)
    {
        printf(" OPENING SPOTIFY\n");
        system("start https://open.spotify.com/");
        break;
    }
    if(l==3)
    {
        strcpy(b,"start https://www.google.com/search?q=");
        printf("\n ENTER YOUR SEARCH IN GOOGLE: ");
        gets(c);
        replace_space(c);
        strlwr(c);
        strcat(b,c);
        strcat(b,"&sxsrf=APwXEdcOQ_7JGEL_0AWuXFDP9E0JoLcPCQ%3A1683578667555&source=hp&ei=K19ZZOX7H-yF4-EPi62D4Ag&iflsig=AOEireoAAAAAZFltO8MufGcCBduzF-snC1Zzc9oVlCTK&gs_ssp=eJzj4tTP1TcwjDfMzjZg9GIuKE4HACSLBG4&oq=&gs_lcp=Cgdnd3Mtd2l6EAEYADIHCC4Q6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCC4Q6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJ1AAWABgkQdoAXAAeACAAQCIAQCSAQCYAQCwAQo&sclient=gws-wiz");
        printf("\n OPENING GOOGLE\n");
        system(b);
        break;
    }
    if(l==4)
    {
        printf(" OPENING SETTINGS\n");
        system("start control");
        break;
    }
    if(l==5)
    {
        strcpy(b,"start https://www.youtube.com/results?search_query=");
        printf("\n ENTER YOUR SEARCH IN YOUTUBE: ");
        gets(c);
        replace_space(c);
        strlwr(c);
        strcat(b,c);
        printf("\n OPENING YOUTUBE\n");
        system(b);
        break;
    }
    if(l==6)
    {
        printf(" OPENING SEARCH BAR\n");
        system("start https://wynk.in/music/search");
        break;
    }
    if(l==7)
    {
        printf(" OPENING RESSO\n");
        system("start https://www.resso.com/in/");
        break;
    }
    if(l==8)
    {
        printf(" OPENING COMMAND PROMPT\n");
        system("start cmd.exe");
        break;
    }
    if(l==9)
    {
        printf(" OPENING CALCULATOR\n");
        system("start 2.exe");
        break;
    }
    if(l==10)
    {
        printf(" OPENING\n");
        system("binary.exe");
        break;
    }
    if(l==11)
    {
        printf(" OPENING WHATSAPP\n");
        system("start https://web.whatsapp.com/");
        break;
    }
    if(l==12)
    {
        printf(" OPENING PIANO\n");
        system("start piano.exe");
        break;
    }
       
    } 
    }
    flag=0;
    while(1)
    {
    printf("\n\n DO YOU WANNA LOG ONCE AGAIN ?\n PRESS 1 TO CONTINUE AND 0 TO QUIT \n\n");
    scanf("%d",&flag);
    if(flag==0)
    {
        printf("\n\n BYE BYE\n\n");
        Sleep(1000);
        exit(1);
    }
    else if(flag==1)
    {
        PlaySound(TEXT("alright.wav"),NULL,SND_SYNC);
        a[0]='0';
        b[0]='\0';
        x=0;
        flag=0;
        l=0;
        m=0;
        s=0;
        main();
    }
    else
    {
        printf("INVALID CHOICE\n\n");
        flag=0;
        PlaySound(TEXT("sorry.wav"),NULL,SND_SYNC);
    }
    }
    
}