#include <stdio.h> 
#include <stdlib.h> 

int Help();
#define CMD_MAX_LEN 128 
#define DESC_LEN   1024 
#define CMD_NUM     10 
typedef struct DataNode 
{    
 
 char*   cmd;   
 char*   desc;   
 int     (*handler)();
 struct   DataNode *next;
 } tDataNode;
static tDataNode head[]=
{
   {"help","this is help cmd",help,&head[1]}，
   {"version","menu program ",null,null  }
}
main()
{    
         
   while(1) 
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = head;
        while(p!=Null)
          {
             if(!strcmp(p->cmd,cmd))
               {
                 printf("%s - %s\n", p->cmd, p->desc);
                 if(p->handler != NULL)
                   {           
                      p->handler();
                    }  
                 break; 
                }
              p=p->next;
           }
        if( p == NULL)
         {
            printf("This is a wrong cmd!\n ");            
            
         }       
        
   }
} 
 int Help() 
{ 
    printf("Menu List:\n");
    tDataNode *p=head;
    while(p!=Null)
  { 
     printf("%s,%s\n",p->cmd,p->desc);
     p=p->next;
   }
    
    return 0;
 }
​
