#include <stdio.h>
#include <cstring>

struct _birth{
    int year;
    int month;
    int day;
} typedef birth;

struct _statement{
    char name[20];
    birth myBirth;
    char gender[7];
    char address[31];
    char phoneNumber[14];
} typedef statement;
/*
늙은순
이름빠른순
 *
 */
struct _birth integerToBirth(int tempBirth);
struct _statement inputStatement();
int birthToInteger(struct _birth birth1);
void printStatementArr(struct _statement *myStatement, int index);
void sortingStatement(struct _statement *arrStatement, int sortType, int sizeArrStatement);

void printStatement(_statement statement);

int main() {
    int state;
    statement arrStatement[10];

    // 예시 input입니다.
    /*
    arrStatement[0] = {"ac",{1999, 12, 10}, "male", "Gwangju seo-gu majaero 65", "010-5778-4824"};
    arrStatement[1] = {"f",{1999, 5, 12}, "male", "Gwangju seo-gu majaero 65", "010-5778-4824"};
    arrStatement[2] = {"abc",{1992, 1, 10}, "male", "Gwangju su majaero 65", "010-5778-4824"};
    arrStatement[3] = {"f",{2009, 12, 30}, "male", "Gwangju seo-gu majaero 65", "010-5778-4824"};
    arrStatement[4] = {"g",{1399, 4, 10}, "male", "Gwangju seo-gu majaero 65", "010-5778-4824"};
    arrStatement[5] = {"dsmsd",{1929, 1, 11}, "male", "Gwangju seo-gu majaero 65", "010-5778-4824"};
    arrStatement[6] = {"dfkask",{1899, 10, 12}, "male", "Gwangju seo-gu majaero 65", "010-5778-4824"};
    */


    int arrStatementIndex = 5;
    while (1){
        printf("수행 할 작업을 선택하세요(0 = 종료, 1 = 입력, 2 = 출력):");
        scanf("%d", &state);
        switch(state){
            case 0:
                return 0;
            case 1:
                arrStatement[arrStatementIndex++] = inputStatement();
                break;
            case 2:
                printStatementArr(arrStatement, arrStatementIndex);
                break;
        }

    }

}

struct _statement inputStatement(){
    statement myStatement;
    int tempBirth;
    printf("name:");
    scanf("%s", myStatement.name);
    printf("birth:");
    scanf("%d", &tempBirth);
    myStatement.myBirth = integerToBirth(tempBirth);
    printf("gender:");
    scanf("%s",myStatement.gender);
    printf("address:");
    scanf("%s",myStatement.address);
    printf("PhoneNumber:");
    scanf("%s",myStatement.phoneNumber);
    return myStatement;
}

void printStatementArr(struct _statement *myStatement, int index){
    printf("original_data\n");
    printf("\tname\t\t\t  birth\t\t   gender\t\t\t\t\taddress\t\t\t\t\tPhoneNumber\t\t\t\n");
    for(int i = 0; i < index; i++){
        printStatement(myStatement[i]);
    }

    sortingStatement(myStatement, 0, index);
    printf("name_sorting_data\n");
    printf("\tname\t\t\t  birth\t\t   gender\t\t\t\t\taddress\t\t\t\t\tPhoneNumber\t\t\t\n");
    for(int i = 0; i < index; i++){
        printStatement(myStatement[i]);
    }

    printf("\n\nage_sorting_data\n");
    sortingStatement(myStatement, 1, index);
    printf("\tname\t\t\t  birth\t\t   gender\t\t\t\t\taddress\t\t\t\t\tPhoneNumber\t\t\t\n");
    for(int i = 0; i < index; i++){
        printStatement(myStatement[i]);
    }
}

void printStatement(_statement myStatement) {

        printf("%12s", myStatement.name);
        printf("\t\t%d.%d.%d",myStatement.myBirth.year,myStatement.myBirth.month,myStatement.myBirth.day);
        printf("\t\t%s",myStatement.gender);
        printf("\t\t\t%30s",myStatement.address);
        printf("\t%10s\n", myStatement.phoneNumber);

}

void sortingStatement(struct _statement *arrStatement, int sortType, int sizeArrStatement){
    statement temp;
    switch(sortType){
        case 0: //이름순
            for(int i = 0; i < sizeArrStatement; i++){
                for(int j = 0; j <= i; j++){
                    if((strcmp(arrStatement[i].name, arrStatement[j].name)) < 0){
                        temp = arrStatement[i];
                        arrStatement[i] = arrStatement[j];
                        arrStatement[j] = temp;
                    }
                }
            }
             break;

        case 1: //나이순
            for(int i = 0; i < sizeArrStatement; i++){
                for(int j = 0; j <= i; j++){
                    if(birthToInteger(arrStatement[i].myBirth) > birthToInteger(arrStatement[j].myBirth)){
                        temp = arrStatement[i];
                        arrStatement[i] = arrStatement[j];
                        arrStatement[j] = temp;
                    }

                }
            }
            break;

        default : break;

    }
}

int birthToInteger(struct _birth birth1){
    return birth1.year*10000 + birth1.month*100 + birth1.day;
}
struct _birth integerToBirth(int tempBirth){
    birth returnBirth;

    returnBirth.year = tempBirth / 10000;
    returnBirth.month = (tempBirth % 10000 /100);
    returnBirth.day = tempBirth%100;

    return returnBirth;
}
