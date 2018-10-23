#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QProgressBar>
#include <QTabWidget>
#include <QTimer>
#include <QGridLayout>
#include <QFileDialog>
#include <ctime>

// локальные файлы
#include "dialog.h"
#include "matrix.h"

namespace Ui {
class MainWindow;
}

namespace Di {
class Dialog;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_menuCreate_triggered();
    void step(); // Метод для регулярной обработки условий
    void on_pushButton_clicked();
    void resizeEvent(QResizeEvent * event);

    void on_saveFile_triggered();

    void on_openFile_triggered();

private:
    Ui::MainWindow* ui;
    QProgressBar* progressBar; // Прогресс бар в строке состояния
    QTabWidget* mainTabWidget; // создание нескольких вкладок для работы с несколькими матрицами
    QTimer* actionTimer; // Таймер для регулярной обработки условий
    Matrix* matrixes; // Массив матриц
    QWidget * currentTab;

    QString get_values(QLayout *layout);
    QString get_values(QWidget *widget);
    int currentNumberOfTabs;

};

#endif // MAINWINDOW_H
