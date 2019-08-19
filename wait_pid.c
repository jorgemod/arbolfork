#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	pid_t pid1, pid2,pid3,pid4,pid5,pid6,pid7,pid8,pid9;
	int status1, status2,status3,status4,status5,status6,status7,status8,status9;
	
	if ( (pid1=fork()) == 0 )
	{ /* hijo */
		
		
		
	
		if ( (pid5=fork()) == 0 )
 		{ /* nieto de 1 */
 			printf("H  (%d, hijo de %d)\n",  getpid(), getppid());
			 
			 
		}
		else
		{ 	waitpid(pid5, &status5, 0);
			if ( (pid6=fork()) == 0 )
			{ /* nieto de 2  */
				printf("o  (%d, hijo de %d)\n",  getpid(), getppid());
			}
			else
			{ 
				waitpid(pid6, &status6, 0);
				printf("1 (%d, hijo de %d)\n",  getpid(), getppid());
				sleep(1);
			}
			sleep(1);
			
		}
		

	}
	else
 	{ /*  padre */
	 	waitpid(pid1, &status1, 0);
		 
 		if ( (pid2=fork()) == 0 )
 		{ /* segundo hijo  */
 			
			if ( (pid7=fork()) == 0 )
			{ /* segundo hijo  */
				printf("a  (%d, hijo de %d)\n",  getpid(), getppid());
			}
			else
			{
				waitpid(pid7, &status7, 0);
				printf("m  (%d, hijo de %d)\n",  getpid(), getppid());
			}
		}
		else
		{ /* padre */
			waitpid(pid2, &status2, 0);
			if ( (pid3=fork()) == 0 )
 				{ /* tercer hijo  */
 					printf("u  (%d, hijo de %d)\n",  getpid(), getppid());
				}
				else{
					waitpid(pid3, &status3, 0);
					if ( (pid4=fork()) == 0 )
 					{ /* tercer hijo  */
 						
						if((pid8=fork())==0)
						{
							printf("n  (%d, hijo de %d)\n",  getpid(), getppid());
						}
						else
						{
							sleep(1);
							if((pid9=fork())==0)
							{
								printf("d  (%d, hijo de %d)\n",  getpid(), getppid());
							}
							else
							{
								waitpid(pid9, &status9, 0);
								printf("0  (%d, hijo de %d)\n",  getpid(), getppid());
								sleep(1);
							}
							sleep(1);
						}
					}
					else{
						sleep(1);
						
			waitpid(pid4, &status4, 0);	
/* Esperamos al tercer hijo */
			waitpid(pid3, &status3, 0);
/* Esperamos al primer hijo */
			
			waitpid(pid1, &status1, 0);
/* Esperamos al segundo hijo */
			waitpid(pid2, &status2, 0);
			
						printf("Padre (%d, hijo de %d)\n", getpid(), getppid());
						
					}


		
				}
		
 		}
				 
	}

	return 0;
}
