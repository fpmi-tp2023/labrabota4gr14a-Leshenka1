#include <sqlite3.h>
#include <stdio.h>

int main() {
    
    sqlite3 *db;
    char *err_msg = 0; 
  
    int rc = sqlite3_open("test.db", &db);
	
      
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", 
                sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }    
    
    printf("Autocommit: %d\n", sqlite3_get_autocommit(db));
    
    char *sql = "DROP TABLE IF EXISTS Friends;" 
                "CREATE TABLE Friends(Id INTEGER PRIMARY KEY, Name TEXT);" 
                "INSERT INTO Friends(Name) VALUES ('Tom');" 
                "INSERT INTO Friends(Name) VALUES ('Rebecca');" 
                "INSERT INTO Friends(Name) VALUES ('Jim');" 
                "INSERT INTO Friend(Name) VALUES ('Robert');";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    
    return 0;
}

