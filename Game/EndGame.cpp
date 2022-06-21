# include "iGraphics.h"
#define screenheight 663
#define screenwidth 1200
#define bgspeed 120
#include<stdlib.h>
#include<string.h>
#include<math.h>
int posx=0, posy, ind=0, mode=0, attack=1, deadenemy=0, health=100, level=0, plevel=0, menu=1, bosx=1000, bosy=0, bossl=0, boss=0, baind=0, icnt=0, battack=5, bhealth=100, scoret=0, prev_level=0, txtbox=0;

char bgi[40][15]= {"bg\\bg1.bmp", "bg\\bg2.bmp", "bg\\bg3.bmp", "bg\\bg4.bmp", "bg\\bg5.bmp", "bg\\bg6.bmp", "bg\\bg7.bmp", "bg\\bg8.bmp", "bg\\bg9.bmp", "bg\\bg10.bmp", "bg\\bg11.bmp", "bg\\bg12.bmp", "bg\\bg13.bmp", "bg\\bg14.bmp", "bg\\bg15.bmp", "bg\\bg16.bmp", "bg\\bg17.bmp", "bg\\bg18.bmp", "bg\\bg19.bmp", "bg\\bg20.bmp", "bg\\bg21.bmp", "bg\\bg22.bmp", "bg\\bg23.bmp", "bg\\bg24.bmp", "bg\\bg25.bmp", "bg\\bg26.bmp", "bg\\bg27.bmp", "bg\\bg28.bmp", "bg\\bg29.bmp", "bg\\bg30.bmp", "bg\\bg31.bmp", "bg\\bg32.bmp", "bg\\bg33.bmp", "bg\\bg34.bmp", "bg\\bg35.bmp", "bg\\bg36.bmp", "bg\\bg37.bmp", "bg\\bg38.bmp", "bg\\bg39.bmp", "bg\\bg40.bmp"};
char bg2i[40][15]= {"bg2\\bg1.bmp", "bg2\\bg2.bmp", "bg2\\bg3.bmp", "bg2\\bg4.bmp", "bg2\\bg5.bmp", "bg2\\bg6.bmp", "bg2\\bg7.bmp", "bg2\\bg8.bmp", "bg2\\bg9.bmp", "bg2\\bg10.bmp", "bg2\\bg11.bmp", "bg2\\bg12.bmp", "bg2\\bg13.bmp", "bg2\\bg14.bmp", "bg2\\bg15.bmp", "bg2\\bg16.bmp", "bg2\\bg17.bmp", "bg2\\bg18.bmp", "bg2\\bg19.bmp", "bg2\\bg20.bmp", "bg2\\bg21.bmp", "bg2\\bg22.bmp", "bg2\\bg23.bmp", "bg2\\bg24.bmp", "bg2\\bg25.bmp", "bg2\\bg26.bmp", "bg2\\bg27.bmp", "bg2\\bg28.bmp", "bg2\\bg29.bmp", "bg2\\bg30.bmp", "bg2\\bg31.bmp", "bg2\\bg32.bmp", "bg2\\bg33.bmp", "bg2\\bg34.bmp", "bg2\\bg35.bmp", "bg2\\bg36.bmp", "bg2\\bg37.bmp", "bg2\\bg38.bmp", "bg2\\bg39.bmp", "bg2\\bg40.bmp"};
char bg3i[40][15]= {"bg3\\bg1.bmp", "bg3\\bg2.bmp", "bg3\\bg3.bmp", "bg3\\bg4.bmp", "bg3\\bg5.bmp", "bg3\\bg6.bmp", "bg3\\bg7.bmp", "bg3\\bg8.bmp", "bg3\\bg9.bmp", "bg3\\bg10.bmp", "bg3\\bg11.bmp", "bg3\\bg12.bmp", "bg3\\bg13.bmp", "bg3\\bg14.bmp", "bg3\\bg15.bmp", "bg3\\bg16.bmp", "bg3\\bg17.bmp", "bg3\\bg18.bmp", "bg3\\bg19.bmp", "bg3\\bg20.bmp", "bg3\\bg21.bmp", "bg3\\bg22.bmp", "bg3\\bg23.bmp", "bg3\\bg24.bmp", "bg3\\bg25.bmp", "bg3\\bg26.bmp", "bg3\\bg27.bmp", "bg3\\bg28.bmp", "bg3\\bg29.bmp", "bg3\\bg30.bmp", "bg3\\bg31.bmp", "bg3\\bg32.bmp", "bg3\\bg33.bmp", "bg3\\bg34.bmp", "bg3\\bg35.bmp", "bg3\\bg36.bmp", "bg3\\bg37.bmp", "bg3\\bg38.bmp", "bg3\\bg39.bmp", "bg3\\bg40.bmp"};
char run[6][15]= {"run\\r1.bmp", "run\\r2.bmp", "run\\r3.bmp", "run\\r4.bmp", "run\\r5.bmp", "run\\r6.bmp"};
char flys[2][15]= {"fly\\f1.bmp", "fly\\f2.bmp"};
char fly[4][15]= {"fly\\f3.bmp", "fly\\f4.bmp", "fly\\f5.bmp", "fly\\f6.bmp"};
char enm[7][15]= {"e\\e1.bmp", "e\\e2.bmp","e\\e3.bmp","e\\e4.bmp","e\\e5.bmp","e\\e6.bmp","e\\e7.bmp"};
char bosp[7][15]= {"bth\\p1.bmp", "bth\\p2.bmp","bth\\p3.bmp","bth\\p4.bmp","bth\\p5.bmp","bth\\p6.bmp","bth\\p7.bmp"};

int enmset[30]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char a1[15]="A\\a1.bmp";
char ba[15]="bth\\a1.bmp";
char menui[15]="menu\\p1.bmp";
int a1set[30]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int baset[30]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int hscore[5];

char c[100];
char d[100];
char h1[100];
char h2[100];

void scoreup(int curscore)
{
    FILE *fout;
    fout=fopen("hs.txt", "r");
    fscanf(fout, "%d\n%d\n%d\n%d\n%d\n", &hscore[0],&hscore[1],&hscore[2],&hscore[3],&hscore[4]);
    fclose(fout);
    int temp,i,j;
    if(curscore!=hscore[0] && curscore!=hscore[1] && curscore!=hscore[2] && curscore!=hscore[3] && curscore>hscore[4])
    {
        printf("%d\n%d\n%d\n%d\n%d\n", hscore[0],hscore[1],hscore[2],hscore[3],hscore[4]);
        hscore[4]=curscore;

        for(i=0; i<4; i++)
        {
            for(j=0; j<5-i-1; j++)
                if(hscore[j]<hscore[j+1])
                {
                    temp=hscore[j];
                    hscore[j]=hscore[j+1];
                    hscore[j+1]=temp;
                }
        }



        fout=fopen("hs.txt", "w");
        fprintf(fout, "%d\n%d\n%d\n%d\n%d\n", hscore[0],hscore[1],hscore[2],hscore[3],hscore[4]);
        fclose(fout);

    }
}

void fileup()
{
    FILE*fout;
    fout=fopen("cg.txt", "w");
    if(level!=0)
    {
        fprintf(fout, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", level, posx, posy, mode, deadenemy, health,  plevel, bossl, boss, bhealth, scoret);

    }
    fclose(fout);
}

void gmsave(int i)
{
    int tempvar[11];
    FILE*fout;
    FILE*gm;
    if(i==1) gm=fopen("sg1.txt", "w");
    if(i==2) gm=fopen("sg2.txt", "w");
    if(i==3) gm=fopen("sg3.txt", "w");
    fout=fopen("cg.txt", "r");
    for(int k=0; k<11; k++)
    {
        fscanf(fout, "%d", &tempvar[k]);
        fprintf(gm, "%d\n", tempvar[k]);
    }
    fclose(fout);
    fclose(gm);
}

void gmload(int i)
{
    int tmp;
    FILE*gm;
    if(i==1) gm=fopen("sg1.txt", "r");
    if(i==2) gm=fopen("sg2.txt", "r");
    if(i==3) gm=fopen("sg3.txt", "r");
    fscanf(gm, "%d", &tmp);
    if(tmp==0) txtbox=1;
    else
    {
        menu=0;
         level=tmp;
    }
    fscanf(gm, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &posx, &posy, &mode, &deadenemy, &health, &plevel, &bossl, &boss, &bhealth, &scoret);
    fclose(gm);
}

void filedown()
{
    FILE*fout;
    fout=fopen("cg.txt", "r");
    fscanf(fout, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &level, &posx, &posy, &mode, &deadenemy, &health, &plevel, &bossl, &boss, &bhealth, &scoret);
    fclose(fout);
}


void score()
{
    if(bossl==1)
    {
        strcpy(d, "THANOS: ");
        itoa(bhealth, c, 10);
        strcat(d, c);
        strcpy(h1, "IRONMAN: ");
        itoa(health, h2, 10);
        strcat(h1, h2);

    }
    else
    {
        strcpy(d, "SCORE: ");
        if(level==1)
            itoa(scoret, c, 10);
        if(level==2)
            itoa(scoret, c, 10);
        if(level==3)
            itoa(scoret, c, 10);
        strcat(d, c);
        //hscore[5]=scoret;
        strcpy(h1, "HEALTH: ");
        itoa(health, h2, 10);
        strcat(h1, h2);

    }


    //printf("%s\n", d);
}


struct bg
{
    int x;
    int y;
};

struct enemy
{
    int x;
    int y;
    int eind;
    int eshow;
};

struct atck
{
    int ax;
    int ay;
    int ashow;
};

struct batck
{
    int bax;
    int bay;
};

bg bg[40];
enemy enemy[15];
atck atck1[30];
batck batck1[30];


/*
	function iDraw() is called again and again by the system.

	*/

void enemyset(int i)
{
    enemy[i].x=1200;
    enemy[i].y=i*130/level+(rand()%80);
    enemy[i].eind=(rand()%7);
    enemy[i].eshow=1;
    enmset[i]=1;
}

void atckset(int i)
{
    a1set[i]=1;
    atck1[i].ashow=1;
    if(mode==11 || mode==0)
    {
        atck1[i].ax=posx+90;
        atck1[i].ay=90;
    }
    else if(mode==21)
    {
        atck1[i].ax=posx+180;
        atck1[i].ay=posy+45;
    }

}

void batckset(int i)
{
    baset[i]=1;
    batck1[i].bax=bosx-100;
    batck1[i].bay=bosy+50;
}


void iDraw()
{
    //place your drawing codes here
    iClear();

    if(menu==1)
    {
        scoret=0;
        iShowBMP(0,0, menui);
        iShowBMP(25, 25, "menu\\b1.bmp");
        iShowBMP(200, 25, "menu\\b13.bmp");
        iShowBMP(400, 25, "menu\\b6.bmp");
        iShowBMP(600, 25, "menu\\b7.bmp");
        iShowBMP(800, 25, "menu\\b9.bmp");
        iShowBMP(1000, 25, "menu\\b5.bmp");
    }

    if(menu==2)
    {
        scoreup(scoret);
        iShowBMP(0,0, "menu\\p2.bmp");
        iShowBMP(25, 25, "menu\\b8.bmp");
        iShowBMP(1000, 25, "menu\\b5.bmp");
    }

    if(menu==3)
    {
        iShowBMP(0,0, "menu\\p3.bmp");
        iShowBMP(25, 550, "menu\\b8.bmp");
    }

    if(menu==4)
    {
        bhealth=100;
        scoreup(scoret);
        iShowBMP(0,0, "menu\\p4.bmp");
    }

    if(menu==5)
    {
        iShowBMP(0,0, "menu\\p5.bmp");
        iShowBMP(25, 25, "menu\\b8.bmp");
        iShowBMP(1000, 25, "menu\\b5.bmp");
    }

    if(menu==6)
    {
        iShowBMP(0,0, "menu\\p6.bmp");
        iShowBMP(400, 400, "menu\\b10.bmp");
        iShowBMP(400, 250, "menu\\b11.bmp");
        iShowBMP(400, 100, "menu\\b12.bmp");
    }

    if(menu==7)
    {
        txtbox=0;
        scoreup(scoret);
        iShowBMP(0,0, "menu\\p7.bmp");
        iShowBMP(25, 25, "menu\\b8.bmp");
        iShowBMP(1000, 25, "menu\\b3.bmp");
        iShowBMP(525, 25, "menu\\b14.bmp");
    }

    if(menu==8)
    {
        iShowBMP(0,0, "menu\\p8.bmp");
        iShowBMP(25, 25, "menu\\b8.bmp");
        iShowBMP(1000, 25, "menu\\b5.bmp");
    }

    if(menu==9)
    {
        iShowBMP(0,0, "menu\\p9.bmp");
        iShowBMP(25, 25, "menu\\b8.bmp");
        iShowBMP(1000, 25, "menu\\b5.bmp");


        char n[5][10];
        iSetColor(255,255,255);
        for(int k=0; k<5; k++)
        {
            itoa(hscore[k], n[k], 10);
            if(k==0)
            {
                iText(100,500, "1.");
                iText(125,500, n[k]);
            }
            else if(k==1)
            {
                iText(100,450, "2.");
                iText(125,450, n[k]);
            }
            else if(k==2)
            {
                iText(100,400, "3.");
                iText(125,400, n[k]);
            }
            else if(k==3)
            {
                iText(100,350, "4.");
                iText(125,350, n[k]);
            }
            else if(k==4)
            {
                iText(100,300, "5.");
                iText(125,300, n[k]);
            }
        }
    }

    if(menu==10)
    {

        iShowBMP(0,0, "menu\\p10.bmp");
        iShowBMP(400, 400, "menu\\b15.bmp");
        iShowBMP(400, 250, "menu\\b16.bmp");
        iShowBMP(400, 100, "menu\\b17.bmp");
        iShowBMP(25, 25, "menu\\b3.bmp");
        if(txtbox==1)
        {
            iSetColor(0,0,0);
            iFilledRectangle(400, 25, 400, 50);
            iSetColor(255,255,255);
            iText(405,35, "GAME SAVED SUCCESSFULLY");
        }

    }

    if(menu==11)
    {


        iShowBMP(0,0, "menu\\p11.bmp");
        iShowBMP(400, 400, "menu\\b15.bmp");
        iShowBMP(400, 250, "menu\\b16.bmp");
        iShowBMP(400, 100, "menu\\b17.bmp");
        iShowBMP(25, 25, "menu\\b8.bmp");
        iShowBMP(1000, 25, "menu\\b5.bmp");
        if(txtbox==1)
        {
            iSetColor(0,0,0);
            iFilledRectangle(400, 25, 400, 50);
            iSetColor(255,255,255);
            iText(405,35, "NO DATA WAS SAVED IN THIS SLOT");
        }

    }

    if(level == 1)
    {
        for(int i=0; i<40; i++)
        {
            iShowBMP(bg[i].x, bg[i].y, bg2i[i]);
        }
        if(mode==11)
        {
            iShowBMP2(posx, 0, run[ind], 1);
        }

        if(mode==0)
        {
            iShowBMP2(posx, 0, "run\\s11.bmp", 1);
        }

        if(mode==21)
        {
            if(ind>3)
                ind=ind%4;
            iShowBMP2(posx, posy, fly[ind], 1);
        }

        if(plevel==1)
        {
            for(int i=0; i<5; i++)
            {
                if(enmset[i]==0)
                    enemyset(i);
                else
                    iShowBMP(enemy[i].x, enemy[i].y, enm[enemy[i].eind]);
            }

            for(int j=2; j<30; j++)
            {

                if(a1set[j]==1)
                {
                    //printf("i= %d bool=%d\n", j, a1set[j]);
                    iShowBMP(atck1[j].ax, atck1[j].ay, a1);
                }
            }

            for(int j=2; j<30; j++)
            {
                for(int i=0; i<5; i++)
                {
                    if( a1set[j]==1 && (atck1[j].ax+100>enemy[i].x) && (atck1[j].ay+10>enemy[i].y && atck1[j].ay<enemy[i].y+50))
                    {
                        a1set[j]=0;
                        enmset[i]=0;
                        deadenemy++;
                        scoret+=(health*2);
                        if(deadenemy==25)
                        {
                            deadenemy=0;
                            prev_level=level;
                            menu=4;
                            plevel=0;
                            level=0;
                        }
                    }
                }
            }

            for(int i=0; i<5; i++)
            {
                if(mode==21 && (posx+180>enemy[i].x) && (posy+90>enemy[i].y && posy<enemy[i].y+50))
                {
                    enmset[i]=0;
                    health-=5;
                    if(health<=0)
                    {
                        level=0;
                        menu=2;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }
                }

                else if((mode==0 || mode==11) && (posx+90>enemy[i].x) && (120>enemy[i].y && 0<enemy[i].y+50))
                {
                    enmset[i]=0;
                    health-=5;
                    if(health<=0)
                    {
                        level=0;
                        menu=2;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }
                }
            }
            iShowBMP(530, 600, "menu\\p.bmp");
            iSetColor(255,255,255);
            iFilledRectangle(0, 600, 420, 40);
            iFilledRectangle(700, 600, 420, 40);
            iSetColor(0,0,0);
            iFilledRectangle(10, 610, 400, 20);
            iSetColor(0,0,0);
            iFilledRectangle(710, 610, 400, 20);
            iSetColor(0,0,255);
            iFilledRectangle(710,610, 4*health, 20);
            iSetColor(255,0,0);
            iFilledRectangle(10,610, 16*deadenemy, 20);
            iSetColor(255,255,255);
            iText(20, 615, d);
            iText(720, 615, h1);
        }

        if(bossl==1)
        {
            for(int j=2; j<30; j++)
            {

                if(a1set[j]==1)
                {
                    //printf("i= %d bool=%d\n", j, a1set[j]);
                    iShowBMP(atck1[j].ax, atck1[j].ay, a1);

                }

                if(baset[j]==1)
                {
                    //printf("i= %d bool=%d\n", j, a1set[j]);
                    iShowBMP(batck1[j].bax, batck1[j].bay, ba);
                }
            }

            if(boss==1)
            {

                iShowBMP(bosx,bosy,"bth\\b1.bmp");

            }

            else if(boss==2)
            {
                icnt++;
                if(icnt%3==0)
                    baind=(baind+1)%7;
                iShowBMP(bosx, bosy, bosp[baind]);
                if(baind==6)
                {
                    boss=1;
                    baind=0;
                    batckset(battack);
                    battack=(battack+1)%30;
                    if(battack<5)
                        battack=5;
                }
            }

            for(int j=2; j<30; j++)
            {
                for(int i=5; i<30; i++)
                {
                    if( a1set[j]==1 && baset[i]==1 && (atck1[j].ax+100>batck1[i].bax) && (atck1[j].ay+10>batck1[i].bay && atck1[j].ay<batck1[i].bay+107))
                    {
                        a1set[j]=0;
                        baset[i]=0;
                    }
                }
            }

            for(int i=5; i<30; i++)
            {
                if(mode==21 && baset[i]==1 && (posx+180>batck1[i].bax) && (posy+90>batck1[i].bay && posy<batck1[i].bay+107))
                {
                    baset[i]=0;
                    health-=10;
                    if(health<=0)
                    {
                        level=0;
                        bossl=0;
                        menu=2;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }

                }

                else if((mode==0 || mode==11) && baset[i]==1 &&  (posx+180>batck1[i].bax) && (120>batck1[i].bay))
                {
                    baset[i]=0;
                    health-=10;
                    if(health<=0)
                    {
                        level=0;
                        bossl=0;
                        menu=2;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }

                }
            }

            if(mode==21 && (posx+180>bosx) && (posy+90>bosy && posy<bosy+142))
            {
                health-=5;
                bhealth-=2;
                if(health<=0)
                {
                    level=0;
                    bossl=0;
                    menu=2;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }

                if(bhealth<=0)
                {
                    bhealth=0;
                    level=0;
                    bossl=0;
                    menu=5;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }




            }

            else if((mode==0 || mode==11) && (posx+180>bosx) && (120>bosy))
            {
                health-=5;
                bhealth-=2;
                if(health<=0)
                {
                    level=0;
                    bossl=0;
                    menu=2;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }

                if(bhealth<=0)
                {
                    bhealth=0;
                    level=0;
                    bossl=0;
                    menu=5;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }


            }

            for(int j=2; j<30; j++)
            {
                if( a1set[j]==1 && (atck1[j].ax+100>bosx) && (atck1[j].ay+10>bosy && atck1[j].ay<bosy+142))
                {
                    bhealth-=2;
                    a1set[j]=0;

                    if(bhealth<=0)
                    {
                        bhealth=0;
                        level=0;
                        bossl=0;
                        menu=5;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }
                }
            }


            iShowBMP(530, 600, "menu\\p.bmp");

            iSetColor(255,255,255);
            iFilledRectangle(0, 600, 420, 40);
            iFilledRectangle(700, 600, 420, 40);
            iSetColor(0,0,0);
            iFilledRectangle(10, 610, 400, 20);
            iSetColor(0,0,0);
            iFilledRectangle(710, 610, 400, 20);
            iSetColor(0,0,255);
            iFilledRectangle(710,610, 4*health, 20);
            iSetColor(0,0,255);
            iFilledRectangle(10,610, 4*bhealth, 20);
            iSetColor(255,255,255);
            iText(20, 615, d);
            iText(720, 615, h1);
        }





    }

    else if(level == 2)
    {
        for(int i=0; i<40; i++)
        {
            iShowBMP(bg[i].x, bg[i].y, bg3i[i]);
        }
        if(mode==11)
        {
            iShowBMP2(posx, 0, run[ind], 1);
        }

        if(mode==0)
        {
            iShowBMP2(posx, 0, "run\\s11.bmp", 1);
        }

        if(mode==21)
        {
            if(ind>3)
                ind=ind%4;
            iShowBMP2(posx, posy, fly[ind], 1);
        }

        if(plevel==1)
        {
            for(int i=0; i<10; i++)
            {
                if(enmset[i]==0)
                    enemyset(i);
                else
                    iShowBMP(enemy[i].x, enemy[i].y, enm[enemy[i].eind]);
            }

            for(int j=2; j<30; j++)
            {

                if(a1set[j]==1)
                {
                    //printf("i= %d bool=%d\n", j, a1set[j]);
                    iShowBMP(atck1[j].ax, atck1[j].ay, a1);
                }
            }

            for(int j=2; j<30; j++)
            {
                for(int i=0; i<10; i++)
                {
                    if( a1set[j]==1 && (atck1[j].ax+100>enemy[i].x) && (atck1[j].ay+10>enemy[i].y && atck1[j].ay<enemy[i].y+50))
                    {
                        a1set[j]=0;
                        enmset[i]=0;
                        scoret+=(health*2);
                        deadenemy++;
                        if(deadenemy==50)
                        {
                            deadenemy=0;
                            prev_level=level;
                            menu=4;
                            plevel=0;
                            level=0;
                        }
                    }
                }
            }

            for(int i=0; i<10; i++)
            {
                if(mode==21 && (posx+180>enemy[i].x) && (posy+90>enemy[i].y && posy<enemy[i].y+50))
                {
                    enmset[i]=0;
                    health-=5;
                    if(health<=0)
                    {
                        level=0;
                        menu=2;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }
                }

                else if((mode==0 || mode==11) && (posx+90>enemy[i].x) && (120>enemy[i].y && 0<enemy[i].y+50))
                {
                    enmset[i]=0;
                    health-=5;
                    if(health<=0)
                    {
                        level=0;
                        menu=2;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }
                }
            }
            iShowBMP(530, 600, "menu\\p.bmp");

            iSetColor(255,255,255);
            iFilledRectangle(0, 600, 420, 40);
            iFilledRectangle(700, 600, 420, 40);
            iSetColor(0,0,0);
            iFilledRectangle(10, 610, 400, 20);
            iSetColor(0,0,0);
            iFilledRectangle(710, 610, 400, 20);
            iSetColor(0,0,255);
            iFilledRectangle(710,610, 4*health, 20);
            iSetColor(255,0,0);
            iFilledRectangle(10,610, 8*deadenemy, 20);
            iSetColor(255,255,255);
            iText(20, 615, d);
            iText(720, 615, h1);
        }

        if(bossl==1)
        {
            for(int j=2; j<30; j++)
            {

                if(a1set[j]==1)
                {
                    //printf("i= %d bool=%d\n", j, a1set[j]);
                    iShowBMP(atck1[j].ax, atck1[j].ay, a1);

                }

                if(baset[j]==1)
                {
                    //printf("i= %d bool=%d\n", j, a1set[j]);
                    iShowBMP(batck1[j].bax, batck1[j].bay, ba);
                }
            }

            if(boss==1)
            {

                iShowBMP(bosx,bosy,"bth\\b1.bmp");

            }

            else if(boss==2)
            {
                icnt++;
                if(icnt%2==0)
                    baind=(baind+1)%7;
                iShowBMP(bosx, bosy, bosp[baind]);
                if(baind==6)
                {
                    boss=1;
                    baind=0;
                    batckset(battack);
                    battack=(battack+1)%30;
                    if(battack<5)
                        battack=5;
                }
            }

            for(int j=2; j<30; j++)
            {
                for(int i=5; i<30; i++)
                {
                    if( a1set[j]==1 && baset[i]==1 && (atck1[j].ax+100>batck1[i].bax) && (atck1[j].ay+10>batck1[i].bay && atck1[j].ay<batck1[i].bay+107))
                    {
                        a1set[j]=0;
                        baset[i]=0;
                    }
                }
            }

            for(int i=5; i<30; i++)
            {
                if(mode==21 && baset[i]==1 && (posx+180>batck1[i].bax) && (posy+90>batck1[i].bay && posy<batck1[i].bay+107))
                {
                    baset[i]=0;
                    health-=15;
                    if(health<=0)
                    {
                        level=0;
                        bossl=0;
                        menu=2;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }

                }

                else if((mode==0 || mode==11) && baset[i]==1 &&  (posx+180>batck1[i].bax) && (120>batck1[i].bay))
                {
                    baset[i]=0;
                    health-=15;
                    if(health<=0)
                    {
                        level=0;
                        bossl=0;
                        menu=2;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }

                }
            }

            if(mode==21 && (posx+180>bosx) && (posy+90>bosy && posy<bosy+142))
            {
                health-=15;
                bhealth-=2;
                if(health<=0)
                {
                    level=0;
                    bossl=0;
                    menu=2;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }

                if(bhealth<=0)
                {
                    bhealth=0;
                    level=0;
                    bossl=0;
                    menu=5;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }




            }

            else if((mode==0 || mode==11) && (posx+180>bosx) && (120>bosy))
            {
                health-=15;
                bhealth-=2;
                if(health<=0)
                {
                    level=0;
                    bossl=0;
                    menu=2;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }

                if(bhealth<=0)
                {
                    level=0;
                    bossl=0;
                    menu=5;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }


            }

            for(int j=2; j<30; j++)
            {
                if( a1set[j]==1 && (atck1[j].ax+100>bosx) && (atck1[j].ay+10>bosy && atck1[j].ay<bosy+142))
                {
                    bhealth-=2;
                    a1set[j]=0;

                    if(bhealth<=0)
                    {
                        level=0;
                        bossl=0;
                        menu=5;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        bhealth=0;
                        deadenemy=0;
                    }
                }
            }

            iShowBMP(530, 600, "menu\\p.bmp");

            iSetColor(255,255,255);
            iFilledRectangle(0, 600, 420, 40);
            iFilledRectangle(700, 600, 420, 40);
            iSetColor(0,0,0);
            iFilledRectangle(10, 610, 400, 20);
            iSetColor(0,0,0);
            iFilledRectangle(710, 610, 400, 20);
            iSetColor(0,0,255);
            iFilledRectangle(710,610, 4*health, 20);
            iSetColor(0,0,255);
            iFilledRectangle(10,610, 4*bhealth, 20);
            iSetColor(255,255,255);
            iText(20, 615, d);
            iText(720, 615, h1);
        }





    }
    else if(level == 3)
    {
        for(int i=0; i<40; i++)
        {
            iShowBMP(bg[i].x, bg[i].y, bgi[i]);
        }
        if(mode==11)
        {
            iShowBMP2(posx, 0, run[ind], 1);
        }

        if(mode==0)
        {
            iShowBMP2(posx, 0, "run\\s11.bmp", 1);
        }

        if(mode==21)
        {
            if(ind>3)
                ind=ind%4;
            iShowBMP2(posx, posy, fly[ind], 1);
        }

        if(plevel==1)
        {
            for(int i=0; i<15; i++)
            {
                if(enmset[i]==0)
                    enemyset(i);
                else
                    iShowBMP(enemy[i].x, enemy[i].y, enm[enemy[i].eind]);
            }

            for(int j=2; j<30; j++)
            {

                if(a1set[j]==1)
                {
                    //printf("i= %d bool=%d\n", j, a1set[j]);
                    iShowBMP(atck1[j].ax, atck1[j].ay, a1);
                }
            }

            for(int j=2; j<30; j++)
            {
                for(int i=0; i<15; i++)
                {
                    if( a1set[j]==1 && (atck1[j].ax+100>enemy[i].x) && (atck1[j].ay+10>enemy[i].y && atck1[j].ay<enemy[i].y+50))
                    {
                        a1set[j]=0;
                        enmset[i]=0;
                        scoret+=(health*2);
                        deadenemy++;
                        if(deadenemy==100)
                        {
                            deadenemy=0;
                            prev_level=level;
                            menu=4;
                            plevel=0;
                            level=0;
                        }
                    }
                }
            }

            for(int i=0; i<15; i++)
            {
                if(mode==21 && (posx+180>enemy[i].x) && (posy+90>enemy[i].y && posy<enemy[i].y+50))
                {
                    enmset[i]=0;
                    health-=10;
                    if(health<=0)
                    {
                        level=0;
                        menu=2;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }
                }

                else if((mode==0 || mode==11) && (posx+90>enemy[i].x) && (120>enemy[i].y && 0<enemy[i].y+50))
                {
                    enmset[i]=0;
                    health-=10;
                    if(health<=0)
                    {
                        level=0;
                        menu=2;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }
                }
            }

            iShowBMP(530, 600, "menu\\p.bmp");

            iSetColor(255,255,255);
            iFilledRectangle(0, 600, 420, 40);
            iFilledRectangle(700, 600, 420, 40);
            iSetColor(0,0,0);
            iFilledRectangle(10, 610, 400, 20);
            iSetColor(0,0,0);
            iFilledRectangle(710, 610, 400, 20);
            iSetColor(0,0,255);
            iFilledRectangle(710,610, 4*health, 20);
            iSetColor(255,0,0);
            iFilledRectangle(10,610, 4*deadenemy, 20);
            iSetColor(255,255,255);
            iText(20, 615, d);
            iText(720, 615, h1);
        }

        if(bossl==1)
        {
            for(int j=2; j<30; j++)
            {

                if(a1set[j]==1)
                {
                    //printf("i= %d bool=%d\n", j, a1set[j]);
                    iShowBMP(atck1[j].ax, atck1[j].ay, a1);

                }

                if(baset[j]==1)
                {
                    //printf("i= %d bool=%d\n", j, a1set[j]);
                    iShowBMP(batck1[j].bax, batck1[j].bay, ba);
                }
            }

            if(boss==1)
            {

                iShowBMP(bosx,bosy,"bth\\b1.bmp");

            }

            else if(boss==2)
            {
                icnt++;
                if(icnt%1==0)
                    baind=(baind+1)%7;
                iShowBMP(bosx, bosy, bosp[baind]);
                if(baind==6)
                {
                    boss=1;
                    baind=0;
                    batckset(battack);
                    battack=(battack+1)%30;
                    if(battack<5)
                        battack=5;
                }
            }

            for(int j=2; j<30; j++)
            {
                for(int i=5; i<30; i++)
                {
                    if( a1set[j]==1 && baset[i]==1 && (atck1[j].ax+100>batck1[i].bax) && (atck1[j].ay+10>batck1[i].bay && atck1[j].ay<batck1[i].bay+107))
                    {
                        a1set[j]=0;
                        baset[i]=0;
                    }
                }
            }

            for(int i=5; i<30; i++)
            {
                if(mode==21 && baset[i]==1 && (posx+180>batck1[i].bax) && (posy+90>batck1[i].bay && posy<batck1[i].bay+107))
                {
                    baset[i]=0;
                    health-=20;
                    if(health<=0)
                    {
                        level=0;
                        bossl=0;
                        menu=2;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }

                }

                else if((mode==0 || mode==11) && baset[i]==1 &&  (posx+180>batck1[i].bax) && (120>batck1[i].bay))
                {
                    baset[i]=0;
                    health-=20;
                    if(health<=0)
                    {
                        level=0;
                        bossl=0;
                        menu=2;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }

                }
            }

            if(mode==21 && (posx+180>bosx) && (posy+90>bosy && posy<bosy+142))
            {
                health-=20;
                bhealth-=2;
                if(health<=0)
                {
                    level=0;
                    bossl=0;
                    menu=2;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }

                if(bhealth<=0)
                {
                    bhealth=0;
                    level=0;
                    bossl=0;
                    menu=5;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }




            }

            else if((mode==0 || mode==11) && (posx+180>bosx) && (120>bosy))
            {
                health-=20;
                bhealth-=2;
                if(health<=0)
                {
                    level=0;
                    bossl=0;
                    menu=2;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }

                if(bhealth<=0)
                {
                    level=0;
                    bossl=0;
                    menu=5;
                    plevel=0;
                    mode=0;
                    posx=0;
                    posy=0;
                    health=100;
                    deadenemy=0;
                }


            }

            for(int j=2; j<30; j++)
            {
                if( a1set[j]==1 && (atck1[j].ax+100>bosx) && (atck1[j].ay+10>bosy && atck1[j].ay<bosy+142))
                {
                    bhealth-=2;
                    a1set[j]=0;

                    if(bhealth<=0)
                    {
                        level=0;
                        bossl=0;
                        menu=5;
                        plevel=0;
                        mode=0;
                        posx=0;
                        posy=0;
                        health=100;
                        deadenemy=0;
                    }
                }
            }

            iShowBMP(530, 600, "menu\\p.bmp");



            iSetColor(255,255,255);
            iFilledRectangle(0, 600, 420, 40);
            iFilledRectangle(700, 600, 420, 40);
            iSetColor(0,0,0);
            iFilledRectangle(10, 610, 400, 20);
            iSetColor(0,0,0);
            iFilledRectangle(710, 610, 400, 20);
            iSetColor(0,0,255);
            iFilledRectangle(710,610, 4*health, 20);
            iSetColor(0,0,255);
            iFilledRectangle(10,610, 4*bhealth, 20);
            iSetColor(255,255,255);
            iText(20, 615, d);
            iText(720, 615, h1);
        }





    }



}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(menu==1 && (mx>24 && mx<177) && (my>24 && my<88))
        {
            menu=6;

        }

        else if((menu==1 || menu==2 || menu==5 || menu==8 || menu==9 || menu==11)&& (mx>999 && mx<1150) && (my>24 && my<88))
        {
            exit(0);
        }

        else if((menu==2 || menu==5 || menu==8 || menu==9 || menu==11) && (mx>24 && mx<177) && (my>24 && my<88))
        {
            menu=1;
            level=0;
            plevel=0;
            bhealth=0;
            bossl=0;
        }

        else if(menu==1 && (mx>799 && mx<950) && (my>24 && my<88))
        {
            menu=3;
            level=0;
            plevel=0;
        }

        else if(menu==3 && (mx>24 && mx<177) && (my>549 && my<613))
        {
            menu=1;
            level=0;
            plevel=0;
        }

        else if(menu==4 && (mx>0 && mx<1200) && (my>0 && my<665))
        {
            boss=1;
            bossl=1;
            level=prev_level;
            plevel=0;
            menu=0;
        }

        else if(menu==6)
        {
            deadenemy=0;
            if(mx>400 && mx<800 && my>400 && my<496)
            {
                menu=0;
                level=1;
                plevel=1;
                posx=0;
                posy=0;
            }
            else if(mx>400 && mx<800 && my>250 && my<346)
            {
                menu=0;
                level=2;
                plevel=1;
                posx=0;
                posy=0;
            }

            else if(mx>400 && mx<800 && my>100 && my<196)
            {
                menu=0;
                level=3;
                plevel=1;
                posx=0;
                posy=0;
            }
        }

        else if(level!=0)
        {
            if(mx<560 && mx>530 && my<630 && my>600)
            {
                fileup();
                menu=7;
                level=0;
            }
        }

        else if(menu==7)
        {

            if((mx>999 && mx<1150) && (my>24 && my<88))
            {
                menu=0;
                filedown();
            }

            else if((mx>24 && mx<177) && (my>24 && my<88))
            {
                menu=1;
                level=0;
                plevel=0;
                bhealth=0;
                bossl=0;
            }

            else if((my>24 && my<88) && (mx>525 && mx<678))
            {
                menu=10;
            }
        }
        else if(menu==1 && (my>24 && my<88) && (mx>400 && mx<553))
        {
            menu=8;
        }

        else if(menu==1 && (my>24 && my<88) && (mx>600 && mx<753))
        {
            menu=9;
            scoreup(scoret);
        }

        else if(menu==1 && (my>24 && my<88) && (mx>200 && mx<453))
        {
            menu=11;
            txtbox=0;
        }

        else if(menu==10)
        {
            if((mx>24 && mx<177) && (my>24 && my<88)) menu=7;
            if((mx>400 && mx<800) && (my>400 && my<495))
            {
                 gmsave(1);
                 txtbox=1;
            }

            else if((mx>400 && mx<800) && (my>250 && my<345))
            {
                 gmsave(2);
                 txtbox=1;
            }

            else if((mx>400 && mx<800) && (my>100 && my<195))
            {
                 gmsave(3);
                 txtbox=1;
            }
        }

        else if(menu==11)
        {
            if((mx>400 && mx<800) && (my>400 && my<495))
            {
                 gmload(1);
            }

            else if((mx>400 && mx<800) && (my>250 && my<345))
            {
                 gmload(2);
            }

            else if((mx>400 && mx<800) && (my>100 && my<195))
            {
                 gmload(3);
            }
        }


    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
    if (key == 'r')
    {
        mode=11;
        posy=0;
    }

    if (key == 's')
    {
        mode=0;
        posy=0;
    }

    if(key == 'f')
    {
        mode=21;
    }

    if(key == 'a')
    {
        if(attack<2)
            attack=2;
        else
            attack=(attack+1)%30;
        atckset(attack);
    }


    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_RIGHT)
    {
        if(mode==0 && posx<1080)
            posx+=10;
        if(mode==21 && posx<960)
            posx+=10;

    }

    else if(key == GLUT_KEY_LEFT)
    {
        if(mode==0 && posx>0)
            posx-=10;
        if(mode==21 && posx>0)
            posx-=10;
    }

    else if(key == GLUT_KEY_UP)
    {
        if(mode==21 && posy<543)
            posy+=30;
    }
    else if(key == GLUT_KEY_DOWN)
    {
        if(mode==21 && posy>0)
            posy-=30;
    }

    //place your codes for other keys here
}

void setall()
{
    int sum=0;
    for(int i=0; i<40; i++)
    {
        bg[i].y=0;
        bg[i].x=sum;
        sum+=120;
    }
}

void change()
{
    for(int i=0; i<40; i++)
    {
        bg[i].x-=bgspeed;
        if(bg[i].x==(-120))
        {
            bg[i].x=4680;
        }
    }
}

void runchng()
{
    ind=(ind+1)%6;
    if(mode==11 && posx<1080)
        posx+=20;
}

void flychng()
{
    if(ind>3)
        ind=ind%4;
    ind=(ind+1)%4;
    //if(mode==21 && posx<960) posx+=10;
}

void enemychng()
{
    for(int i=0; i<15; i++)
    {
        if(enemy[i].x > 0)
        {
            enemy[i].x-=(rand()%(40*level));
            enemy[i].y+=(pow(-1,(rand()%2)))*(rand()%(40*level));
            if(enemy[i].y<0)
                enemy[i].y=0;
            if(enemy[i].y>565)
                enemy[i].y=565;
        }
        else
            enemyset(i);
        enemy[i].eind=(enemy[i].eind+1)%7;
    }
}

void atck1chng()
{
    for(int j=2; j<30; j++)
    {
        if(a1set[j]==1)
        {
            atck1[j].ax = atck1[j].ax + 100;
            //printf("i=%d %d\n", j, atck1[j].ax);
            if( atck1[j].ax>=1200 )
                a1set[j]=0;

        }
    }

}

void batckchng()
{
    for(int j=5; j<30; j++)
    {
        if(baset[j]==1)
        {
            int dhorsi=posy- batck1[j].bay;
            batck1[j].bax = batck1[j].bax - (level*100);
            batck1[j].bay = batck1[j].bay + (dhorsi*level/3);

            //printf("i=%d %d\n", j, atck1[j].ax);
            if( atck1[j].ax>=1200 )
                a1set[j]=0;

        }
    }

}
void bosmove()
{
    if(bosx >= 500)
    {
        bosx+=(pow(-1,(rand()%2))*(rand()%100));
        bosy+=(pow(-1,(rand()%2))*(rand()%100));
        if(bosy<0)
            bosy=0;
        if(bosy>565)
            bosy=565;
        if(bosx<500)
            bosx=500;
        if(bosx>1000)
            bosx=1000;
    }
}

void bpow()
{
    boss=2;
}

int main()
{
    //place your own initialization codes here.

    setall();
    iSetTimer(200,change);
    iSetTimer(200, runchng);
    iSetTimer(200, enemychng);
    iSetTimer(200, atck1chng);
    iSetTimer(200, batckchng);
    iSetTimer(200, score);
    //iSetTimer(200, fileup);
    iSetTimer(200, bosmove);
    iSetTimer(3000, bpow);
    PlaySound("snd2.wav", NULL,  SND_LOOP | SND_ASYNC);
    iInitialize(screenwidth, screenheight, "Avengers");
    return 0;
}
