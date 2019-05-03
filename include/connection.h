#ifndef CHEM_TANK_MANAGER_CONNECTION_HPP_
#define CHEM_TANK_MANAGER_CONNECTION_HPP_

#include <QSqlDatabase>

namespace ctm {

bool createConnection() {
  // an instance of QSqlDatabase represents the connection to the database
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("chem-tank-db");
  db.setDatabaseName("../db/database.db");

  // must call open() to activate connection to database
  bool ok = db.open();
  if(!ok) {
    return false;
  }
  return true;
}

}  // namespace ctm

#endif // header guard
