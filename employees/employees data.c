//
//  employees data.c
//  employees
//
//  Created by Kirolos Esmat on 5/23/20.
//  Copyright © 2020 Kirolos Esmat. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void choose(void);
void screen(void);
void function_one(void);
void function_two(void);
void serch(void);
void zero(void);

int number,num,id,percent;
int *employees;
float *salaries;

int main(){
    int i,j;

    printf(" Number of employees : ");
    scanf("%d",&number);
    printf("*-----------------------*\n");
    
    employees = (int*)malloc(number*sizeof(int*));
    salaries = (float*)malloc(number*sizeof(float*));
    
    printf("Employees ID : ");
    scanf("%d",&employees[0]);
    printf("%d salaries : ",1);
    scanf("%f",&salaries[0]);

    for(i=1;i<number;i++)
    {
        printf("Employees ID : ");
        scanf("%d",&employees[i]);
        
        for(j=i-1;j>=0;j--)
           {
               if (employees[i]==employees[j])
               {
                   printf("The id must be unique.\n");
                   while (employees[i]==employees[j])
                   {
                       printf("Enter unique ID : ");
                       scanf("%d",&employees[i]);
                   }
               }
           }
        
        printf("%d salaries : ",i+1);
        scanf("%f",&salaries[i]);
        
        if (employees[i]<0 || salaries[i]<0)
        {
            i=number;
            zero();
            printf("ID or salarie can't be negative.\n");
        }
    }
    
    choose();
    while (num!=0){
        if (num==1){
            function_one();
            choose();
        }
        if (num==2){
            function_two();
            choose();
        }
        if (num==3){
            screen();
            choose();
        }
    }
    if (num==0){
        printf("Done...\n");
        free(employees);
        free(salaries);
    }
    return 0;
}
void choose(void){
    printf("\n");
    printf("1)Returning the subset of ids.\n");
    printf("2)Pay rise to a selected group of employees.\n");
    printf("3)Print.\n");
    printf("0)Done.\n");
    scanf("%d",&num);
}
void screen(void){
    int i;
    
    printf("IDs  Salaries\n");
    for(i=0;i<number;i++)
    {
        printf("%d    %.1f $\n",employees[i],salaries[i]);
    }
}
void function_one(void){
    int i,salarie;
    
    printf("Enter the salarie : ");
    scanf("%d",&salarie);
    
    for(i=0;i<number;i++)
    {
        if (salaries[i]>=salarie)
        {
            printf("Employee ID --> %d\n",employees[i]);
        }
    }
}
void function_two(void){
    int i;
    float total;
    
    screen();
    serch();
    for(i=0;i<number;i++)
       {
           if(employees[i]==id)
           {
               total= salaries[i]*(percent+100)/100;
               printf("The salarie = %.1f $",total);
               printf("\n");
               salaries[i]=total;
           }
       }
}
void serch(void){
    int i,found = 0;
    
    printf("Enter the Id : ");
    scanf("%d",&id);
    
    for(i=0;i<number;i++)
    {
        if (employees[i]==id){
            found=1;
            printf("Enter the percent : ");
            scanf("%d",&percent);
            break;
        }
    }
    
    if (found==0)
    {
        printf("ID not found..\n");
    }
}
void zero(void){
    int i;
    
    for(i=0;i<number;i++)
       {
           employees[i]=0;
           salaries[i]=0;
       }
}
