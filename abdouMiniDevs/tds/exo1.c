#include<stdio.h>
#include <string.h>
struct TEMPS
{
    int heure ;
    int min ;
    int second;
};
struct athlete {
    int Number;
    char Name[50];
    struct TEMPS Result;
};
int TRANSFORM (struct TEMPS t){
    return t.second + t.min * 60 + t.heure * 60 *60;
}
void display(struct athlete a){
    {
    printf("Name   : %s\n", a.Name);
    printf("Number : %d\n", a.Number);
    printf("Time   : %02d:%02d:%02d\n",
        a.Result.heure,
        a.Result.min,
        a.Result.second);
    printf("------------------\n");

}
}
struct TEMPS DECOMPOS(int t){
    struct TEMPS tem;
    tem.heure = t / 3600;
    t %= 3600;
    tem.min = t / 60;
    tem.second = t % 60;
    return tem;
}

int main(){
    int n ;
    struct TEMPS time;
    struct athlete athletes[100];
    int tIs = 0;
    int ave = 0;
    do
    {
        printf("Enter number of athletes (<=100): ");
        scanf("%d",&n);
    } while (n <= 0 || n > 100);
    for(int i =0 ; i<n ; i++){
        printf("Entr the number of athlat\n");
        scanf("%d",&athletes[i].Number);
        fgetchar();
        printf("Entr the name of athlat\n");
        fgets(athletes[i].Name,50,stdin);
        athletes[i].Name[strcspn(athletes[i].Name,"\n")] = "\0";
        do
        {
            scanf("%d",&tIs);
        } while (tIs < 0);
        athletes[i].Result = DECOMPOS(tIs);
        int tims = TRANSFORM(athletes[i].Result);
        ave += tims;
    }
    ave /= n; 
    for (int i = 0 ; i < n ; i++){
        int tims = TRANSFORM(athletes[i].Result);
        if(tims <= ave){
            display(athletes[i]);
        }
    }
    return 0 ;
}
