#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
#include<openssl/md5.h>

static FILE *file;

void printCombo(char arr[], int n, int r, unsigned char *digest, char *mdString)
{  
    unsigned char data[r];
    combo(arr, data, 0, n-1, 0, r, digest, mdString);
}


void combo(char arr[], unsigned char data[], int start, int end, int index, int r, unsigned char *digest, char *mdString)
{

   
 int j = 0;
    
    if (index == r)
    {
	data[16] = '\0';
	fprintf(file, "Password = %s\n", data);
	MD5(data, strlen(data), digest);    
 
	for(j = 0; j < 16; j++)
       		sprintf(&mdString[j*2], "%02x", digest[j]);
 
	filerintf(file, "MD5 Hash = %s\n\n", mdString);
   
        return;
    }
    
    int i = 0;
 

    for (i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combo(arr, data, i+1, end, index+1, r, digest, mdString);
    }
}

int main(void)
{

    unsigned char *digest;
    char *mdString;
   
    digest = (unsigned char *) malloc (MD5_DIGEST_LENGTH * sizeof(unsigned char));   
    mdString = (char *) malloc (33 * sizeof(char));

    file = fopen("out.txt", "w+");
    char arr[94];
    int i = 0;
    int j = 33;
    for(i=0; i<94; i++)
    {
	if(j<127)
	{
    		arr[i] = j;
		j++;
	}
    }

    int r = 16;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 0;
    for(k = 0; k<n; k++)
	{
		printf("%c", arr[k]);
	}
    printf("\n\n");
    printCombo(arr, n, r, digest, mdString);
    
    fclose(file);

    return 0;
}
