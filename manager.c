#include "manager.h"


//데이터 저장하는 함수
void saveData(Book* b, int count){
  fp= fopen("book.txt","wt");
  for(int i=0;i<count;i++){
    if(b[i].cost !=-1)
      fprintf(fp,"%d %d %d %s\n", b[i].cost,b[i].page,b[i].star,b[i].name);
  }
  fclose(fp);
  printf("저장됨!");
}

//파일에서 데이터 가져오는 함수
int loadData(Book* b){
  loadcount=0;

  fp=fopen("book.txt","rt");
  if(fp==NULL){
  printf("=> 파일없음\n");
  return 0;
  }
  else{
    while(1){
      fscanf(fp,"%d",&b[loadcount].cost);
      fscanf(fp,"%d",&b[loadcount].page);
      fscanf(fp,"%d",&b[loadcount].star);
      fscanf(fp,"%[^\n]",b[loadcount++].name);
      if(feof(fp)){break;}
    }
  }
  fclose(fp);
  printf("=> 로딩 성공!\n");
  return loadcount-1;
}

//사용자가 원하는번호를 입력하는 함수
int selectDataNo(Book* b, int count){
  listBook(b,count);
  printf("번호는 (취소 :0)? ");
  scanf("%d",&no);
  return no;
}
  if(searchnumber==1) searchName(b,count);
  else if(searchnumber==2) searchPrice(b, count);
  else if(searchnumber==3) searchStar(b, count);
  else printf("취소되었습니다!");
}*/
