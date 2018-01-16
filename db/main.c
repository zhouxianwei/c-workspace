#include <stdio.h>
#include <sqlite3.h>

int printf_record(void * , int , char **, char **);

int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;

   rc = sqlite3_open("test.db", &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   }else{
      // fprintf(stderr, "Opened database successfully\n");
   }
   char *sql;
   // sql = "DROP TABLE USER";
   // rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
   sql = "CREATE TABLE USER(" \
         "ID integer PRIMARY KEY autoincrement," \
         "USERNAME TEXT);";
   rc = sqlite3_exec(db, sqld, NULL, 0, &zErrMsg);
   if(rc != SQLITE_OK){
      // fprintf(stderr, "error : %s\n", zErrMsg);
   }
   // sql = "INSERT INTO USER (USERNAME) VALUES('zhouxianwei')";
   // rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
   // if(rc != SQLITE_OK){
   //    fprintf(stderr, "error : %s\n", zErrMsg);
   // }
   sql = "SELECT * FROM USER";
   rc = sqlite3_exec(db, sql, printf_record, 0, &zErrMsg);
   sqlite3_close(db);
   return 1;
}

int printf_record(void * params, int cols, char **column_value, char **column_name){
   for (int i = 0; i < cols; i++){
      printf("%s---%s---", column_name[i] ,column_value[i]);
   }
   printf("\n");
   return 0;
}