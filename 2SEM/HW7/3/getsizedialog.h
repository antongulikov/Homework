#ifndef GETSIZEDIALOG_H
#define GETSIZEDIALOG_H

#include <QObject>
#include <QDialog>
/// Класс для изменения размеров игры
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
	/// устанавливает итоговое значение после изменения
	void on_GetSizeDialog_accepted();	
	/// устанавливает итоговое значение перед выходом
	void on_GetSizeDialog_finished(int result);
	
private:
	Ui::GetSizeDialog *ui;
};

#endif // GETSIZEDIALOG_H
