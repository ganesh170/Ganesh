//Name:Ganesh Roy
//roll 1702055
//L:2;S:1
#include<stdio.h>
#include<string.h>

#define N 1000000

int i, j, sge, n = 0;

void show_list(){
    printf("0....Exit\n");
    printf("1....View all elements\n");
    printf("2....Insert new element\n");
    printf("3....Search an element\n");
    printf("4....Delete an element\n");
    printf("5....Sort elements in ascending order\n");
    printf("6....Sort elements in descending order\n");
    printf("7....Find memory location of an element\n");
}

void View(int* ar){
    printf("Current elements are: ");
    for(i=1; i<=n; i++) printf("%d ", ar[i]);
    printf("\n");
}

void Insert(int* ar){
    printf("Please, enter a integer type data to be inserted: ");
    int x;
    scanf("%d", &x);
    ar[++n] = x;
    printf("%d is inserted successfully!\n", ar[n]);
}

void Search(int* ar){
    printf("Enter a data to be searched: ");
    int x;
    scanf("%d", &x);
    for(i=1; i<=n; i++){
        if(x==ar[i]){
            printf("%d is found.\n", x);
            return;
        }
    }
    printf("%d is not found!\n", x);
}

void Delete(int* ar){
    printf("Enter a data to be deleted: ");
    int x, idx = 0;
    scanf("%d", &x);
    for(i=1; i<=n; i++){
        if(x==ar[i]){
            idx = i;
            n--;
            break;
        }
    }
    if(idx){
        for(i=idx; i<=n; i++){
            ar[i] = ar[i+1];
        }
        printf("%d is deleted successfully!\n", x);
    }
    else printf("%d is not found!\n", x);
}

void Sort_asc(int* ar){
    for(i=1; i<=n; i++){
        for(j=i+1; j<=n; j++){
            if(ar[i]>ar[j]){
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    printf("Elements are sorted in ascending order!\n");
}

void Sort_des(int* ar){
    for(i=1; i<=n; i++){
        for(j=i+1; j<=n; j++){
            if(ar[i]<ar[j]){
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    printf("Elements are sorted in descending order!\n");
}

void MemLoc(int* ar){
    printf("Enter the index for what you want to know memory location: ");
    int x;
    scanf("%d", &x);
    if(x<1 || x>n) printf("Sorry! No such index is present!\n");
    else printf("Desired memory location is = %d\n", ar+x+1);
}

void perform(int* ar){
    printf("\n");
    if(sge<1 || sge>7) printf("Sorry! You entered an invalid keyword!\n");
    else if(sge==1) View(ar);
    else if(sge==2) Insert(ar);
    else if(sge==3) Search(ar);
    else if(sge==4) Delete(ar);
    else if(sge==5) Sort_asc(ar);
    else if(sge==6) Sort_des(ar);
    else if(sge==7) MemLoc(ar);
    printf("\n");
}

void clear_screen(){
    char ch = getchar();
    printf("Press any key to clear screen: ");
    char chh = getchar();
    system("CLS");
}

int main()
{
    int *arr = malloc(N * sizeof(int)); //dynamic memory allocation of 10^6 elements

    while(1){
        show_list();

        printf("Please, enter a valid keyword from the given list: ");
        scanf("%d", &sge);

        if(sge == 0) break;

        perform(arr);
        clear_screen();
    }

    printf("\nThank you for using this system! :)\n");

    return 0;
}
