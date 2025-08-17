#include <stdio.h>
#include <sqlite3.h>

// Fonction de callback pour afficher les résultats
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    for(int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *errMsg = 0;

    // Ouvrir la base
    if (sqlite3_open("test.db", &db)) {
        fprintf(stderr, "Erreur ouverture base: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Créer une table
    char *sql = "CREATE TABLE IF NOT EXISTS Clients("
                "ID INT PRIMARY KEY NOT NULL,"
                "Nom TEXT NOT NULL,"
                "Age INT NOT NULL);";
    sqlite3_exec(db, sql, 0, 0, &errMsg);

    // Insérer des données
    sql = "INSERT INTO Clients (ID,Nom,Age) VALUES (1,'Ali',30);"
          "INSERT INTO Clients (ID,Nom,Age) VALUES (2,'Sara',25);";
    sqlite3_exec(db, sql, 0, 0, &errMsg);

    // Lire la table
    sql = "SELECT * FROM Clients;";
    sqlite3_exec(db, sql, callback, 0, &errMsg);

    sqlite3_close(db);
    return 0;
}
