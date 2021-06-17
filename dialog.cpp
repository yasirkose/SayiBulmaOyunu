#include "dialog.h"
#include "ui_dialog.h"
#include "iostream"
#include "ctime"
#include "string"
#include "QMessageBox"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonRastgeleSayiUret_clicked()
{
    QString maxdeger=ui->labelAralikUSt->text();
    int enFazla = maxdeger.toInt(), enAz = 10;
    srand(time(0));
    int sayi=rand() % (enFazla - enAz + 1 ) + enAz;
    QString sayial= QString::number(sayi);
    ui->labelUretilenSayi->setText(sayial);
}
int oyuncuSayisi=0;

void Dialog::on_radioButton1_clicked()
{
    ui->listOyuncu1Tahmin->setEnabled(1);
    oyuncuSayisi=1;
    ui->listOyuncu2Tahmin->setDisabled(1);
}

void Dialog::on_radioButton2_clicked()
{
    oyuncuSayisi=2;
    ui->listOyuncu2Tahmin->setEnabled(1);
    ui->listOyuncu1Tahmin->setEnabled(1);
}

void Dialog::on_buttonBaslat_clicked()
{
    ui->listOyuncu1Tahmin->clear();
    ui->listOyuncu2Tahmin->clear();

    QString maxdeger=ui->labelAralikUSt->text();
    int enFazla = maxdeger.toInt();
    QString degerAl=ui->labelUretilenSayi->text();
    int deger = degerAl.toInt();
    if(oyuncuSayisi==1)
    {
        int adim=0;
        while(1==1)
        {
            int sayi=rand() % ( enFazla- 10 + 1 ) + 10;
            adim=adim+1;
            ui->listOyuncu1Tahmin->addItem(QString::number(sayi));
            if(deger==sayi)
            {
                ui->listOyuncu1Tahmin->addItem("Deneme Sayisi: "+(QString::number(adim)));
                break;
            }

        }
    }
    if(oyuncuSayisi==2)
    {
        int adimSayisi1=0;
        int adimSayisi2=0;
        while(1==1)
        {
            int sayi=rand() % ( enFazla- 10 + 1 ) + 10;
            adimSayisi1=adimSayisi1+1;
            ui->listOyuncu1Tahmin->addItem(QString::number(sayi));
            if(deger==sayi)
            {
                ui->listOyuncu1Tahmin->addItem("Deneme Sayisi: "+(QString::number(adimSayisi1)));
                break;
            }
        }
        while(1==1)
        {
            int sayi=rand() % ( enFazla- 10 + 1 ) + 10;
            adimSayisi2=adimSayisi2+1;
            ui->listOyuncu2Tahmin->addItem(QString::number(sayi));
            if(deger==sayi)
            {
                ui->listOyuncu2Tahmin->addItem("Deneme Sayisi: "+(QString::number(adimSayisi2)));
                break;
            }
        }
        QMessageBox::StandardButton reply;
        if(adimSayisi1>adimSayisi2)
        {
            reply = QMessageBox::information(this, "TEBRIKLER", ("Tebrikler!!! Oyuncu 2, "+(QString::number(adimSayisi2))+"Adimda Kazandi!!"),QMessageBox::Ok);
        }
        if(adimSayisi1<adimSayisi2)
        {
            reply = QMessageBox::information(this, "TEBRIKLER", ("Tebrikler!!! Oyuncu 1, "+(QString::number(adimSayisi1))+"Adimda Kazandi!!"),QMessageBox::Ok);
        }

    }
}

void Dialog::on_spinBox_textChanged(const QString &args)
{
    QString maxdeger=ui->spinBox->text();
    ui->labelAralikUSt->setText(maxdeger);
}
