#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *fp;

	int i=0,m=0,g=0,r=0,c=0,d=0;
	int input,_break,number[250],n1,n2;

	char *ptr,str[40],str2[40],temp[250],temp2[250],placement[30],preword[3],postword[40],preword2[3],one[5]=" ",two[5]="  ",three[5]="   ",nothing[5]="";
	char array[2000][40],word[2000][40];
    
    fp=fopen("Ranking List.txt","a+"); //open txt file
	if(fp==NULL)
    {
	    printf("ERROR\n");
	    return 1;
    }

    fseek(fp,0,SEEK_SET); //set filepointer to beginning

    while(fgets(temp, 2000, fp)) //read all lines (max. 1999)
    {
		fputs(temp, stdout); //output line in console
        strcpy(array[i],temp); //copies line to array
		g++;
    }

do
{
    printf("\nPress 1 to add a new entry. Press 0 to end.:");
    scanf("%d",&input);
    fflush(stdin);
	if(input != 0 && input != 1)
    {
		printf("Either press 1 or 0.\n");
    }
}while(input != 0 && input != 1);

if(input==1)
{ 
    do
    {
        printf("Name:"); //type the name
        fgets(str, 40, stdin);
		fflush(stdin);

	    printf("Placement in the Ranking:"); //type the placement in the ranking
	    scanf("%s",placement);
        fflush(stdin);

        //indent the placement numbers to have a universal 4-digit format style
        if(strlen(placement)==1) //case of one digit
	    {
		    strcat(three,placement); //indent + placement
		    strcpy(placement,three); //placement variable gets indent
		    strcpy(three,"   "); //reset three string
	    }
        else if(strlen(placement)==2) //case of two digit
		{
		    strcat(two,placement);
		    strcpy(placement,two);
		    strcpy(two,"  ");
		}
        else if(strlen(placement)==3) //case of three digit
		{
		    strcat(one,placement);
		    strcpy(placement,one);
		    strcpy(one," ");
		}

	    strcat(placement,"."); //add point to placement
	    strcat(placement,str); // add name to placement
        printf("%s----------\n",placement);

	    g++;
		 
	    for(i=0;i<g;i++) // go through every line up until the current one
	    {
            strcpy(preword,array[i]); //extract the number of the placement there
            n1=atoi(preword);

            strcpy(preword2,placement); //extract the number of the current placement
		    n2=atoi(preword2);

            if(n1>=n2) //find the first placement number that is equal or larger than the current one to add
			{
				strcpy(temp,array[i]); //remove the old entry and add the new to this place
				strcpy(array[i],placement);
				c=i;

				while(c<g) //move all entries after that by one position
                {
                    strcpy(temp2,temp);
				    strcpy(temp,array[c+1]);
				    strcpy(array[c+1],temp2);
				    c++;
				}
				break; //disrupt for loop because the entry is already inserted
			}
		    else
			{
			    d++; //count how many entries will be before the current new entry
			}
	    }

	    if(d==g) //if placement number is larger than all the others->attach it to the end of the array
        {
            ptr=strchr(placement,'\n'); //remove its new line
            if(ptr)
            {
		        *ptr='\0';
		    }
		    strcat(array[g-2],"\n"); //current last entry receives new line
		    strcpy(array[g-1],placement); //current entry to add is attached to the end
        }

        for(i=0;i<g;i++)
		{
		    strcpy(preword,array[i]);
            strcpy(postword,array[i]);

		    for(m=5;m<sizeof(preword);m++) //store placements in number-array
	        {
		        preword[m]='\0';
		    }
            number[i] = atoi(preword);
	
	        for(r=5;r<sizeof(postword);r++) //store names in word-array
	        {
		        postword[r-5]=postword[r];
	        }
            strcpy(word[i],postword);
	    }

        fseek(fp,0,SEEK_SET); //set file pointer to beginning

        for(i=0;i<g;i++) //find duplicate placements
	    {
            if(number[i]==number[i+1]) //increment the placement of the second entry if duplicate was found
            {
              number[i+1]++;
            } 
            
			//write back to the main array
            if(number[i]<10) //when single digit
            {
		        sprintf(str2,"%d",number[i]);
                strcat(three,str2);
		        strcat(three,".");
                strcat(three,word[i]);
		        strcpy(array[i],three);
		    }

		    else if(number[i]<100) //when double digit
            {
		        sprintf(str2,"%d",number[i]);
                strcat(two,str2);
		        strcat(two,".");
                strcat(two,word[i]);
		        strcpy(array[i],two);
		    }

		    else if(number[i]<1000) //when three digits
            {
		        sprintf(str2,"%d",number[i]);
                strcat(one,str2);
		        strcat(one,".");
                strcat(one,word[i]);
		        strcpy(array[i],one);
		    }

		    else //when four digits
            {
		        sprintf(str2,"%d",number[i]);
                strcat(nothing,str2);
		        strcat(nothing,".");
                strcat(nothing,word[i]);
		        strcpy(array[i],nothing);
		    }

            strcpy(one," "); //restores the string values
		    strcpy(two,"  ");
		    strcpy(three,"   ");
		    strcpy(nothing,"");
        }

        fclose(fp); //close .txt file

        fp=fopen("Ranking List.txt","w"); //open file again only to write in
        for(i=0;i<g;i++)
        {
            printf("%s",array[i]); //write the entries again
            fprintf(fp,"%s",array[i]);
        }
	    d=0;
        
		do
	    {
	        printf("\nPress 0 to break. Press 1 to continue: "); //stop adding new entries
	        scanf("%d",&_break);
            fflush(stdin);
			if(_break != 0 && _break != 1)
			{
				printf("Either press 0 or 1\n");
		    }
	    } while(_break != 0 && _break != 1);

    }while(_break!=0);

    fclose(fp); //close .txt file
}
else
{
	fclose(fp);
}
	return 0;
}
