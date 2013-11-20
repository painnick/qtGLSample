#include "mainwindow.h"
#include "ui_mainwindow.h"

// using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QRect rect = QRect(0, 0, 600, 600); //ui->centralWidget->geometry();
    ui->glViewer->setGeometry(rect);
}

void MainWindow::on_action_New_triggered()
{
//    QString fileName = QFileDialog::getOpenFileName(this,
//                                                    tr("이미지 선택"),
//                                                    tr("/home/painnick/사진/"),
//                                                    tr("jpeg (*.jpeg *.jpg)\npng (*.png)"));
//    cv::Mat mat = cv::imread(fileName.toStdString());

//    if(!mat.data)
//    {
//        QMessageBox::information(this,
//                                 QString(tr("파일 읽기 실패")),
//                                 fileName,
//                                 QMessageBox::Ok
//                                 );
//        return;
//    }

//    ui->scrollAreaWidgetContents->setGeometry(0, 0, mat.cols, mat.rows);

//    // Convert Image dta format
//    cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);

//    QImage img = QImage((const uchar*)mat.data, mat.cols, mat.rows, mat.step1(), QImage::Format_RGB888);
//    QPalette p(ui->scrollAreaWidgetContents->palette());
//    p.setBrush(QPalette::Background, img);
//    ui->scrollAreaWidgetContents->setPalette(p);
//    ui->scrollAreaWidgetContents->repaint();
//    // Update window-title
//    this->setWindowTitle(fileName);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int result = QMessageBox::warning(this,
                                      tr("프로그램 종료"),
                                      tr("정말 프로그램을 종료하시겠습니까?"),
                                      QMessageBox::Yes | QMessageBox::No);

    if(result != QMessageBox::Yes)
    {
        event->ignore();
    }
}
