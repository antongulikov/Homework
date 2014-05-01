#ifndef GETSIZEDIALOG_H
#define GETSIZEDIALOG_H

#include <QObject>
#include <QDialog>
/// ����� ��� ��������� �������� ����
namespace Ui {
	class GetSizeDialog;
}

class GetSizeDialog : public QDialog
{
	Q_OBJECT
	
public:
	explicit GetSizeDialog(QWidget *parent = 0);
	~GetSizeDialog();
private slots:
	/// ������������� �������� �������� ����� ���������
	void on_GetSizeDialog_accepted();	
	/// ������������� �������� �������� ����� �������
	void on_GetSizeDialog_finished(int result);
	
private:
	Ui::GetSizeDialog *ui;
};

#endif // GETSIZEDIALOG_H
