#include "getsizedialog.h"
#include "ui_getsizedialog.h"
#include <QDebug>

GetSizeDialog::GetSizeDialog(QWidget *parent) :
QDialog(parent),
ui(new Ui::GetSizeDialog)
{
	ui->setupUi(this);	
}

GetSizeDialog::~GetSizeDialog()
{
	delete ui;
}


void GetSizeDialog::on_GetSizeDialog_accepted()
{
    setResult(ui->sizeBox->value());
}

void GetSizeDialog::on_GetSizeDialog_finished(int result)
{
    setResult(ui->sizeBox->value());
}
