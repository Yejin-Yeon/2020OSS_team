#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"
#include "manager.h"

//메인함수
int main(void){
  Book b[100];// 데이터를 저장하는 구조체변수배열

  count=loadData(b);
  curcount=count;
  while (1){
    menu = selectMenu();

    if (menu == 0) break;
    if (menu == 1){
      if(count>0) listBook(b, curcount);
      else printf("데이터가 없습니다.\n");
    }
    else if (menu == 2){
    count+=creatBook(&b[curcount++]);
    }
    else if (menu == 3){
      int no=selectDataNo(b,curcount);
      if(no==0){
        printf("취소됨!\n");
        continue;
      }
      updateProduct(&b[no-1]);
    }
    else if (menu == 4){
      int no= selectDataNo(b,curcount);
      int deleteok;// 삭제실행 여부
      if(no==0){
        printf("=> 취소됨!\n");
        continue;
      }
      printf("정말로 삭제하시겠습니까 (삭제 :1)? ");
      scanf("%d",&deleteok);
      if(deleteok==1){
        if(deleteBook(&b[no-1])) count--;
      }
    }
    else if(menu==5){
      if(count==0) printf("데이터가 없습니다!\n");
      else saveData(b,curcount);
    }
    else if(menu==6){
      searchFunction(b, curcount);
    }
  }
  printf("종료됨!\n");
  return 0;
}


