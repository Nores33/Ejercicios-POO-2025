#include "admindb.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

AdminDB::AdminDB( QObject * parent ) : QObject( parent )  {
    qDebug() << "Drivers disponibles:" << QSqlDatabase::drivers();

    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

AdminDB::~AdminDB()  {
    if ( db.isOpen() )
        db.close();
}

bool AdminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );

    return db.open();
}

QSqlDatabase AdminDB::getDB()  {
    return db;
}

bool AdminDB::isConnected()  {
    return db.isOpen();
}

void AdminDB::mostrarTabla( QString tabla )  {
    if ( this->isConnected() )  {
        QSqlQuery query = db.exec( "SELECT * FROM " + tabla );

        if ( query.size() == 0 || query.size() == -1 )
            qDebug() << "La consulta no trajo registros";

        while( query.next() )  {
            QSqlRecord registro = query.record();  // Devuelve un objeto que maneja un registro (linea, row)
            int campos = registro.count();  // Devuleve la cantidad de campos de este registro

            QString informacion;  // En este QString se va armando la cadena para mostrar cada registro
            for ( int i = 0 ; i < campos ; i++ )  {
                informacion += registro.fieldName( i ) + ":";  // Devuelve el nombre del campo
                informacion += registro.value( i ).toString() + " - ";
            }
            qDebug() << informacion;
        }
    }
    else
        qDebug() << "No se encuentra conectado a la base";
}
