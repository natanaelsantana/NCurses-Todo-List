#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int user_found = 0;

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        if (argv[i] != NULL)
        {
            return user_found = 1;
        }
    }
    printf("\n");
    return 0;
}

int inserirUsuario(char *login, char *senha)
{
    sqlite3 *db;
    int call = sqlite3_open("test.db", &db);
    char sql[256];

    // Cria a tabela se ela não existir
    strcpy(sql, "CREATE TABLE IF NOT EXISTS users (login TEXT, senha TEXT);");
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return rc;
    }

    // Insere um usuário na tabela
    sprintf(sql, "INSERT INTO users (login, senha) VALUES ('%s', '%s');", login, senha);
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return rc;
    }

    printf("Usuário inserido com sucesso\n");
    sqlite3_close(db);
    return 0;
}

int procurarUsuario(char *login, char *senha)
{
    sqlite3 *db;
    int call = sqlite3_open("test.db", &db);
    char sql[256];

    // Cria a tabela se ela não existir
    strcpy(sql, "CREATE TABLE IF NOT EXISTS users (login TEXT, senha TEXT);");
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return rc;
    }

    // Procura um usuário na tabela
    sprintf(sql, "SELECT * FROM users WHERE login='%s' AND senha='%s';", login, senha);
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return rc;
    }

    sqlite3_close(db);
    return 0;
}