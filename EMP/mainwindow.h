#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define DATABASE_NAME       "Employ.db"
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QMainWindow>
#include <QtSql>                                // For using the SQL database
#include <QDebug>                               // For using the qDebug function
#include <QFileInfo>                            // For using the function to access the path and database file
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

Q_PROPERTY(QString dbState READ dbState)
public:
    QSqlDatabase Employ;
    // employeeData -> name of the database file where data from here is stored

    void connectionClose()
    // function to close the connection with the database
    {
        Employ.close();
        Employ.removeDatabase(QSqlDatabase::defaultConnection);
    }


 
    bool connectionOpen()
    // function to open the connection to the database
    {
        Employ = QSqlDatabase::addDatabase("QSQLITE");                        // add the database into the project
        Employ.setHostName("localhost");
        Employ.setDatabaseName("C:/Users/pc/Documents/MAX/EMP/Employ.db");   // sets the database name in the file destintaion

        //Condition  -> for the messages to print when the onnection is made with the database
        if(!Employ.open()){
            qDebug()<<("Database Disconnected ...");
            return false;
        }
        else {
            qDebug()<<("Database Connected ...");
            return true;
        }
        }



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
        QString m_dbState;

    QString dbState() const {

           return m_dbState;
       }


private slots:





    void on_UpButton_clicked();

    void on_SearchButton_clicked();

    void on_DelButton_clicked();

    void on_AddButton_clicked();

    void on_Exp_clicked();

    void on_Seach_clicked();

    void  connect();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
