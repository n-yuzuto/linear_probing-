#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "double_hashing.h"

int main(void) {
  double start_time,end_time;
  const int trynum = 100000; // max of number //
  int len = 3001; //size of dict//
  DictOpenAddr *test_dict = create_dict(len);

  float occupancy = 1.0;
  int limit = len * occupancy;
  int i;
  srand(10);
  for (i = 0;i < limit; i++){
      int d = rand() % trynum;
      insert_hash(test_dict,d);
  }
  srand(10);
  int target_number = rand() % trynum;
  int s,j;
  start_time=get_realtime();
  for (j=0;j<=trynum;j++){
      s=search_hash(test_dict,target_number);
    } 
  end_time=get_realtime();
  double n=100000;
  printf("占有率:%f  ",occupancy);
  printf("実行時間: %g s\n",(end_time-start_time) / n );
  printf("%dの探索結果 %d\n",target_number,s);
  delete_dict(test_dict);
  return EXIT_SUCCESS;
}
