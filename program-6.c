#include <stdio.h>
int main()
{
int s1, s2;
int co=0,cc=0,k=0;
	printf("\nEnter the size of first set:");
	scanf("%d", &s1);
	printf("\nEnter the size of second set:");
	scanf("%d", &s2);
int a[s1],b[s2],c[s1+s2];
int unionofSet[s1+s2];
int diffA[s1],diffB[s2];
	printf("\nEnter elements of the first set: ");
for(int i=0;i<s1;i++){
	scanf("%d", &a[i]);
    }
	printf("\nEnter elements of the second set: ");

for(int i=0;i<s2;i++) {
scanf("%d",&b[i]);
}
printf("The Elements of Set A are: ");
for(int i=0;i<s1;i++){
        printf("\t%d",a[i]);
}

printf("\nThe Elements of Set B are: ");
for(int i=0;i<s2;i++){
        printf("\t%d",b[i]);
}

for(int i=0; i<s1; i++){
	for(int j=0; j<s2; j++) {
		if(a[i]==b[j]){
		int found=0;
		for(int m=0; m<k; m++){
		 if(c[m]==a[i]){
			found=1;
			break;
                    }
			}
		if(!found){
                    c[k]=a[i];
                    k++;
                    cc++;
			}
                break;
		}
	}
}
    if (k!=0) {
        printf("\n(INTERSECTION)Common elements present in both sets are: ");
        for (int l = 0; l<k; l++) {
            printf("%d\t", c[l]);
        }

    }
	else{
		printf("\nNo common elements exist!!!!\n");
    }

int uIndex=0;
    for(int i=0; i<s1; i++){
        unionofSet[uIndex++] = a[i];
    }
    for(int i=0; i<s2; i++){
        int found=0;
        for (int j=0; j<uIndex; j++){
            if (b[i]==unionofSet[j]){
                found = 1;
                break;
            }
        }
        if (!found) {
            unionofSet[uIndex++] = b[i];
        }
    }
    printf("\nUnion(A+B) of both sets is: ");
    for (int i = 0; i<uIndex; i++) {
        printf("%d\t", unionofSet[i]);
    }

int diffAIndex=0;
    for (int i =0; i<s1; i++) {
        int found=0;
        for (int j=0; j<s2; j++) {
            if (a[i] == b[j]) {
                found=1;
                break;
            }
        }
        if (!found) {
            diffA[diffAIndex++] = a[i];
        }
    }
    printf("\nThe DIFFERENCE, A - B is: ");
    if (diffAIndex>0){
        for (int i=0; i<diffAIndex; i++) {
            printf("%d\t", diffA[i]);
        }

    }
 else{
        printf("No elements in A - B\n");
    }

int diffBIndex = 0;
    for (int i=0; i<s2; i++) {
        int found=0;
        for (int j=0; j<s1; j++) {
            if (b[i] == a[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            diffB[diffBIndex++] = b[i];
        }
    }
    printf("\nThe DIFFERENCE, B - A is: ");
    if (diffBIndex > 0) {
        for (int i=0; i<diffBIndex; i++) {
            printf("%d\t", diffB[i]);
        }
	printf("\n");

    }
 else{
        printf("No elements present in B - A\n");
    }
return 0;
}
