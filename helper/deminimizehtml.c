#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace_str(const char *str, const char *old, const char *new)
{
    char *ret, *r;
    const char *p, *q;
    size_t oldlen = strlen(old);
    size_t count, retlen, newlen = strlen(new);

    if (oldlen != newlen) {
        for (count = 0, p = str; (q = strstr(p, old)) != NULL; p = q + oldlen)
            count++;
        /* this is undefined if p - str > PTRDIFF_MAX */
        retlen = p - str + strlen(p) + count * (newlen - oldlen);
    } else
        retlen = strlen(str);

    if ((ret = malloc(retlen + 1)) == NULL)
        return NULL;

    for (r = ret, p = str; (q = strstr(p, old)) != NULL; p = q + oldlen) {
        /* this is undefined if q - p > PTRDIFF_MAX */
        int l = q - p;
        memcpy(r, p, l);
        r += l;
        memcpy(r, new, newlen);
        r += newlen;
    }
    strcpy(r, p);

    return ret;
}
int main(int argc, char **argv)
{	
	char *filename; 
    char *filename2;
	FILE *fp, *fp2;
    char line[5];
	if(argc!=3){
		printf("Arguments incorrect. (./deminimizehtml your-source-html your-dest-html)\n");
		exit(1);	
	}

	filename = argv[1]; 
    fp = fopen(filename, "r");
    filename2 = argv[2];
    fp2 = fopen(filename2, "w");
	if(fp == NULL) {
		perror(filename);
		exit(1);
	}

    while(fgets(line, sizeof(line), fp)) {
        fprintf(fp2, "%s", replace_str(line,">",">\n"));
    }
	fclose(fp);
	fclose(fp2);
	return 0;
}

