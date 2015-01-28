#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 250

void main()
{

	char input_file[MAX];
	char output_file[MAX];
	char line[MAX];
	FILE *ifp, *ofp;
	int i =0;
	char dest2[2000];

	printf("Please enter input file: \n:");
	scanf("%s", &input_file);


	printf("Please enter output file: \n");
	scanf("%s", &output_file);

	if((ifp = fopen(input_file, "r")) == NULL)
	{
		printf("Error opening file!\n");
		return;
	}

	if((ofp = fopen(output_file, "w")) == NULL)
	{
		printf("Error opening file\n");
		return;
	}


	while( fgets(line, sizeof line, ifp) != NULL)
	{
		fputs(line, stdout);

		char answer[25];

		printf("\nEnter position of word to delete (start counting at 0). Enter -1 to skip deletion:  ");
		scanf("%s", &answer);

		char *big_token;
		char t[] = " ";
		int Answer;
		Answer = atoi(answer);
		i=0;
		big_token = strtok(line, t);

		while(big_token != NULL)
		{
			char dest[20000] = " ";

			if(answer != "-1")
			{
				if( i != Answer)
				{	
					strcat(dest, big_token);
					fputs(dest, ofp);
				}
				else
				{
					strcat(dest2, big_token);
					strcat(dest2, " ");
				}

				big_token = strtok(NULL, t);
				i++;

			}

			if(answer == -1)
			{
				strcat(dest, big_token);
				fputs(dest, ofp);
				continue;
			}
		}


	}
	printf("\n%s\n", dest2);
	fclose( ifp);
	fclose(ofp);
}

