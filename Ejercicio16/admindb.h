#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    explicit AdminDB( QObject * parent = 0 );
    ~AdminDB();

    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();
    bool isConnected();
    void mostrarTabla( QString tabla );

private:
    QSqlDatabase db;
};

#endif // ADMINDB_H
