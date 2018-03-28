#include<bits/stdc++.h>
using namespace std;


void wicket(void)
{
    int wicket_check;

    wicket_check=(rand()%100000 +1);
    if(wicket_check%13==1||wicket_check%18==0||wicket_check%17==0)
    {
        cout<<"Run Out\n";
    }
    else if(wicket_check%12==0||wicket_check%50==0||wicket_check%101==0)
    {
        cout<<"Catch out!\n";
    }
    else
    {
        cout<<"Bold!\n";
    }
}


int ball_check(int ball)
{
    int Ball_Check;
    Ball_Check=(rand()%10000+ball)%5000+1;
    if(Ball_Check%2==1&&Ball_Check%7==0) return 2;
    else if(Ball_Check%11==0&&Ball_Check%2==0) return 3;
    else if(Ball_Check%13==0&&Ball_Check%21==0||Ball_Check%12==0) return 4;

    return 1;
}



int game(void)
{

    int check, others;
    check = (rand()%100000 +1);
    others= (rand()%3 +1);
    if(check%2==0&&check%3==0) return 4;
    if(check%7==1) return 6;
    return others;

}


int free_hit(void)
{

    int check, others;
    check = (rand()%100000 +1);
    others= (rand()%3 +1);
    if(check%2==0||check%3==0) return 4;
    if(check%7==1&&check%2!=0) return others;
    return 6;



}

int main()
{
    srand(time(0));


    int ball, over, level, players, over_count, oover, runn, End, fh,f, r, i, j, k, l, x, y, c, final_run[100], run[100];
    string name[100];


    while(1)
{


    cout<<"Select overs :\n1 Overs\n2 Overs\n5 Overs\n";
    cin>>over;


    if(over==1) over=1;
    else if(over==2) over =2;
    else if(over==5) over=5;
    else over=1;



    cout<<"\n\nNumbers of Players: \n";
    cin>>players;
    cout<<"\n\nEnter their name: \n";
    for(i=0; i<players; i++)
    {
        cout<<"Player "<<i+1<<" : ";
        cin>>name[i];
    }


    getchar();

    cout<<"\n\nThe Players are : \n";
    for(i=0; i<players; i++)
    {
        cout<<i+1<<" : "<<name[i]<<"\n";
    }
    getchar();



    runn=0;

    for(i=0; i<players; i++)
    {
        cout<<"\n\n"<<i+1<<" Your Turn "<<name[i]<<"\n\n";
        over_count=0;
        oover=0;
        fh=0;
        run[i]=0;
        End=0;

        for(ball=1; ball<=over*6; ball++)
        {
            getchar();
            r=game();

            if(ball_check(ball)==2)
            {
                 cout<<"1Wd\n";
                 ball--;
                 run[i]++;
                 cout<<run[i]<<"/"<<oover<<"."<<ball%6<<"\n";

            }
            else if(ball_check(ball)==3)
            {
                cout<<r<<"NB\n";
                fh=1;
                ball--;
                run[i]+=r+1;
                {
                    cout<<run[i]<<"/"<<oover<<"."<<ball%6<<"\n";
                }

            }
            else if(ball_check(ball)==4)
            {
                if(fh==1)
                {
                    fh=0;
                    f=free_hit();
                    run[i]+=f;

                    if(ball%6==0)
                        {
                            cout<<"Free Hit!\n"<<f<<"\n";

                            oover++;
                            cout<<run[i]<<"/"<<oover<<"."<<"0\n";
                            cout<<"OVER!\n";
                        }


                        else
                        {
                            cout<<"Free Hit\n"<<f<<"\n";
                            cout<<run[i]<<"/"<<oover<<"."<<ball%6<<"\n";
                        }
                }
                else
                {
                    wicket();

                    if(ball%6==0)
                        {

                            oover++;
                            cout<<run[i]<<"/"<<oover<<"."<<"0\n";
                            cout<<"OVER!\n";
                        }


                        else
                        {
                            cout<<run[i]<<"/"<<oover<<"."<<ball%6<<"\n";
                        }

                    break;
                }


            }
            else
            {
                fh=0;
                cout<<r<<"\n";
                run[i]+=r;
                if(ball%6==0)
                {

                    oover++;
                    cout<<run[i]<<"/"<<oover<<"."<<"0\n";
                    cout<<"\nOVER!\n\n";
                }


                else
                {
                    cout<<run[i]<<"/"<<oover<<"."<<ball%6<<"\n";
                }

            }
            if(i!=0&&i==players-1)
            {
                if(run[i]>runn)
                {
                    final_run[i]=run[i];
                    End=1;
                    break;

                }
                else End=0;
            }
            if(run[i]>runn) runn=run[i];

        }


        final_run[i]=run[i];

        if(End==0) cout<<"\n\nEnd of your innings "<<name[i]<<"!\n\n";

    }



    sort(run, run+players);
    reverse(run, run+players);

    for(i=0; i<players; i++)
        {
            int x=0;
            for(j=0; j<players; j++)
            {
                if(run[i]==final_run[j])
                {
                    x=1;
                    y=j;
                   break;
                }
            }
            if(x>0) break;
        }



        cout<<"\n\n\t\t"<<name[y]<<"\n\n\t\tWins!\n\n";
        getchar();

        cout<<"\nScore Board: \n\n";

        l=0;
        for(i=0; i<players; i++)
        {
            for(j=0; j<players; j++)
            {
                if(run[i]==final_run[j])
                {
                    if(i!=0&&run[i]==run[i-1])
                    {
                        l++;
                        j+=l;
                        break;
                    }
                    else
                    {
                        l=0;
                        break;
                    }


                }

            }

            cout<<""<<i+1<<".\t"<<name[j]<<"\t---- "<<run[i]<<"\n";

        }



        cout<<"\n\nPress: \n\n";
        cout<<"ANOTHER GAME ==> 1\n"<<"QUIT         ==> 0\n";
        cin>>c;
        if(c==0) break;


}

}

