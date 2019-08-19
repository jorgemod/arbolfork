#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	pid_t pid1, pid2,pid3,pid4,pid5,pid6,pid7,pid8,pid9;
	int status1, status2,status3,status4,status5,status6,status7,status8,status9;

	if ( (pid1=fork()) == 0 )
	{ /* hijo */
        printf("Hijo 1 (%d, hijo de %d :L:)\n",  getpid(), getppid());
        if ( (pid5=fork()) == 0 )
        {
            /*nieto*/
            printf("nieto 1 (%d, hijo de %d :H:)\n",  getpid(), getppid());
        }
        else
        {
            if ( (pid6=fork()) == 0 )
            {
                printf("nieto 2 (%d, hijo de %d :O:)\n",  getpid(), getppid());
            }
            else
            {
                waitpid(pid5, &status5, 0);
                waitpid(pid6, &status6, 0);
            }
        }
        	

	}
	else
 	{ 
         /*  padre */
 		if ( (pid2=fork()) == 0 )
 		{ 
            /* segundo hijo  */
 			printf("Hijo 2 (%d, hijo de %d     :M:)\n",  getpid(), getppid());
             if ( (pid7=fork()) == 0 )
             {
                 printf("nieto 3 (%d, hijo de %d     :A:)\n",  getpid(), getppid());
             }
             else
             {
                 waitpid(pid7, &status7, 0);
             }
             waitpid(pid1, &status1, 0);
		}
		else
		{ 
           
            /* padre */
            if ( (pid3=fork()) == 0 )
 		    { 
                /* tercer hijo  */
 			    printf("Hijo 3 (%d, hijo de %d     :U:)\n",  getpid(), getppid());
		    }
            else
            {
                /*padre*/
                if ( (pid4=fork()) == 0 )
 		        { 
                    /* cuarto hijo  */
 			        printf("Hijo 4 (%d, hijo de %d     :O:)\n",  getpid(), getppid());
                     if ( (pid8=fork()) == 0 )
                     {
                         printf("nieto 4 (%d, hijo de %d     :N:)\n",  getpid(), getppid());
                     }
                     else
                     {
                         if ( (pid9=fork()) == 0 )
                         {
                             printf("nieto 5 (%d, hijo de %d     :D:)\n",  getpid(), getppid());
                         }
                         else
                         {
                             waitpid(pid8, &status8, 0);
                             waitpid(pid9, &status9, 0);
                         }
                     }
                     
		        }
            }
            waitpid(pid2, &status2, 0);
			
 		}
         printf("papisss");

         
	}
   
	return 0;
}