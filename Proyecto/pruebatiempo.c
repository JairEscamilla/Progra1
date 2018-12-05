#include <stdio.h>
#include <string.h>
#include <time.h>
int main(){
  time_t rawtime;
  struct tm *timeinfo;
  char Timestamp[100];
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  printf("Current local time and date: %s", asctime(timeinfo));
  sprintf(Timestamp, "[%d %d %d %d:%d:%d]\n", timeinfo->tm_mday, timeinfo->tm_mon+1, timeinfo->tm_year+1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
  Timestamp[strlen(Timestamp)-1] = '\0';
  puts(Timestamp);
  return 0;
}
